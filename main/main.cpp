/* Main driver function to test enemy movement.
   John Quinn, Rob Wirthman, Lindsey Sansone
   main.cpp

   This is the driver program to run the game.  First all objects are declared and the qgraphicsscene is set up.  Levels are also created using the Level class.  Then a while loop handles the main game processes.  It controls damage dealt between the all graphics items on the scene, including enemies, the hero, and various projectiles.  It adds and removes items from the scene as necessary.  This loop loads each new level as the old one ends. See project report for more details.

*/  
  
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QImage>
#include <QPixmap>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QMainWindow>
#include <QTimer>
#include <QGraphicsSimpleTextItem>
#include "hero.h"
#include "transparentpixmap.h"
#include "enemy.h"
#include "TextStatus.h"
#include "level.h"
#include "ProjectileWeapon.h"
#include "Pellet.h"
  
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
  int
main (int argc, char *argv[]) 
{
  QApplication app (argc, argv);	// creates a QApplication
app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );  // makes program exit when you click the x in the upper corner
srand (time (NULL));		// seeds rand
  // defines parameters to be used for random enemy placement
  QGraphicsScene scene;	// creates a scene
  scene.setSceneRect (0, 0, 800, 800);	// defines a rectangle encasing the scene
  Hero link (100, 5, 5, 0, -1, 800, 800);	// instantiates the hero of the game.
  
    // sets hero position
    link.setPos (400, 400);
  
    // adds hero to scene
    scene.addItem (&link);

  // sets position arrays for levels
  int xpos1[4] = { 50, 750, 400, 400 };
  int ypos1[4] = { 400, 400, 50, 750 };
  int xpos2[6] = { 50, 750, 400, 400, 300, 200 };
  int ypos2[6] = { 400, 400, 50, 750, 200, 300 };
  int xpos3[8] = { 50, 750, 400, 400, 100, 300, 200, 200 };
  int ypos3[8] = { 400, 400, 50, 750, 100, 300, 200, 400 };

  // creates levels
  Level levelone (4, xpos1, ypos1, 10, 1.2, 5, 0);
  Level leveltwo (6, xpos2, ypos2, 10, 1.4, 5, 1);
  Level levelthree (8, xpos3, ypos3, 15, 1.45, 10, 0);
  Level levelfour (0, xpos1, ypos1, 10, 10, 10, 0);
  Level levelfive (4, xpos1, ypos1, 15, 1.2, 10, 1);
  Level levelsix  (6, xpos2, ypos2, 15, 1.4, 10, 1);
  Level levelseven (0, xpos1, ypos1, 1,1,0,0);
  Level leveleight (6, xpos2, ypos2, 20, 1.5, 15, 1);
  Level levelnine  (8, xpos3, ypos3, 20, 1.5, 15, 1);
  Level levelten   (0, xpos1, ypos1, 10,10,0,0);
  Level levelboss (1, xpos1, ypos1, 100, 1.2, 20, 1);

  // stores levels in array
  Level allLevels[11] =
    { levelone, leveltwo, levelthree, levelfour, levelfive, levelsix, levelseven, leveleight, levelnine, levelten, levelboss };
  QGraphicsView view (&scene);	// creates a view based on the scene
  view.setRenderHint (QPainter::Antialiasing);
  view.setBackgroundBrush (QPixmap ("titlescreen.png"));	// sets the background of the view
  view.setCacheMode (QGraphicsView::CacheBackground);	// caches the background
  view.resize (850, 850);	// resizes the window that is shown to the user
  view.show ();			// shows the view in window

  int newHealth;		// holds new health
  int isHit = 0;		// hit indicator
  int arrowHit = 0;		// projectile hit indicator
  int activePellet = 0;		// active pellet indicator
  int confirmPowerUp = 0;	// power up selection indicator
  int gameover = 0;		// gameover indicator

  // declare score, arrow, and health bars and power and speed level indicators.  adds them to scene
  TextStatus scorebar ("Current Points: ", 0, 0, 0);
  TextStatus lifebar ("Health Remaining:", link.getHealth (), 475, 0);
  TextStatus arrowsbar ("Arrows: ", link.getNumProjectiles (), 190, 0);
  TextStatus speedlevel ("Speed Lvl: ", 1, 320, 0);
  TextStatus powerlevel ("Power Lvl: ", 1, 700, 0);
  scene.addItem (&lifebar);
  scene.addItem (&scorebar);
  scene.addItem (&arrowsbar);
  scene.addItem (&speedlevel);
  scene.addItem (&powerlevel);

  // sets up projectile weapon for future use
  ProjectileWeapon arrow (5, 1, 0);
  // sets up pellet for future use
  Pellet ball (10);

  int LevelCount = 0;		//holds level number
  int ArrowOn = 0;		// holds number of arrows on scene

QTimer timer;		// creates a timer to control movement
  QObject::connect (&timer, SIGNAL (timeout ()), &scene, SLOT (advance ()));	// uses the advance slot defined in the hero class to get the heros to move
  timer.start (50);		// starts the timer

  while (1)
    {
      if (link.getFightControl () == 1)
	break;
      app.processEvents ();	// processes graphics
    }				// titlescreen, waits for space to start the game

  while (LevelCount < 11 && gameover == 0)
    {
      // reset hero position
      link.setX (400);
      link.setY (400);

      if (LevelCount % 3 == 0 && LevelCount > 2)
	{
	  view.setBackgroundBrush (QPixmap ("powerups.png"));	// changebackground
	  while (1)
	    {
	      if (link.x () > 200 && link.x () < 500 && link.y () > 500
		  && link.y () < 600 && link.getFightControl () == 1)
		break;
	      else if (link.x () > 100 && link.x () < 200 && link.y () > 200
		       && link.y () < 300 && link.getFightControl () == 1)
		{
		  if (scorebar.getNum () >= 400 && confirmPowerUp == 0)
		    {
		      link.setHealth (link.getHealth () + 20);	// sets new health
		      lifebar.setNum (link.getHealth ());	// updates healthbar
		      scorebar.setNum (scorebar.getNum () - 400);	// updates scorebar
		      confirmPowerUp = 1;	// sets confirm indicator
		    }
		}		// handles health powerup
	      else if (link.x () > 250 && link.x () < 350 && link.y () > 200
		       && link.y () < 300 && link.getFightControl () == 1)
		{
		  if (scorebar.getNum () >= 400 && confirmPowerUp == 0)
		    {
		      link.setNumProjectiles (link.getNumProjectiles () + 20);	// sets new number of projectiles
		      arrowsbar.setNum (link.getNumProjectiles ());	// updates arrow bar
		      scorebar.setNum (scorebar.getNum () - 400);	// updates scorebar
		      confirmPowerUp = 1;	// sets confirm indicator
		    }
		}		// handles projectile powerup
	      else if (link.x () > 400 && link.x () < 500 && link.y () > 200
		       && link.y () < 300 && link.getFightControl () == 1)
		{
		  if (scorebar.getNum () >= 1500 && confirmPowerUp == 0)
		    {
		      link.setPower (link.getPower () + 5);	// sets new power
		      scorebar.setNum (scorebar.getNum () - 1500);	// updates scorebar
	              powerlevel.setNum(powerlevel.getNum()+1);       // updates power level
		      confirmPowerUp = 1;	// sets confirm indicator
		    }
		}		// handles power powerup
	      else if (link.x () > 550 && link.x () < 650 && link.y () > 200
		       && link.y () < 300 && link.getFightControl () == 1)
		{
		  if (scorebar.getNum () >= 1000 && confirmPowerUp == 0)
		    {
		      link.setSpeed (link.getSpeed () + 1);	// sets new speed
		      scorebar.setNum (scorebar.getNum () - 1000);	// update scorebar
		      speedlevel.setNum(speedlevel.getNum()+1);
		      confirmPowerUp = 1;	// sets confirm indicator
		    }
		}		// handles speed powerup
	      else
		{
		  confirmPowerUp = 0;	// resets confirm powerup
		}
	      app.processEvents ();	// processes graphics
	    }
	}			// powerup stage control  

      else
	{
	  for (int i = 0; i < allLevels[LevelCount].getNumEnemies (); i++)
	    {
	      scene.addItem (&allLevels[LevelCount].enemies[i]);
	    }			// sets up current level by adding enemies to scene
	  view.setBackgroundBrush (QPixmap ("grass.png"));	// changebackground

	  if (LevelCount == 10)
	    {
	      allLevels[LevelCount].enemies[0].scale (5, 5);
	    }
	  while (allLevels[LevelCount].getNumEnemies () > 0)
	    {     
	      // makes sure collision is only counted once
              if (isHit>0) 
		isHit++;  // increments isHit to allow some waiting time for collisions.  helps hits only be counted once.
	      QList < QGraphicsItem * >collisionList = link.collidingItems ();
	      if (collisionList.size () == 0 && isHit >= 5000)
		isHit = 0; // isHit variable is used in if conditions to make sure hits are counted only once.

	      // handles status of hero
	      if (link.getHealth () <= 0)
		{
		  link.setOpacity (0.0);
		  gameover = 1;
		  break;
		}		// removes hero if out of health

	      if (link.getFireArrow () == 1 && link.getNumProjectiles () > 0)	// if fire arrow is asserted and link has arrows
		{
		  if (ArrowOn == 0)
		    {
		      arrow.setxdir (link.getxdir ());	// sets arrow direction
		      arrow.setydir (link.getydir ());
		      scene.addItem (&arrow);	// adds item to scene
		      arrow.setX (link.x () + 20 * (link.getxdir ()));	//sets arrow position
		      arrow.setY (link.y () + 20 * (link.getydir ()));
		      ArrowOn = 1;	// asserts arrow count
		      link.setNumProjectiles (link.getNumProjectiles () - 1);
		      arrowsbar.setNum (link.getNumProjectiles ());	//updates arrow number
		    }		// sets up arrow on scene
		  else if (ArrowOn == 1)
		    {
		      if (arrow.x () > 800 || arrow.x () < 0
			  || arrow.y () > 800 || arrow.y () < 0
			  || arrowHit == 1)
			{
			  scene.removeItem (&arrow);	// removes arrow
			  ArrowOn = 0;	// resets ArrowOn
			  link.setFireArrow (0);	// resets fire arrow
			  arrowHit = 0;	// resets arrow hit
			}	// handles arrow if it goes out of bounds or hits something
		    }
		}

	      // handles all enemies
	      for (int j = 0; j < allLevels[LevelCount].getMaxEnemies (); j++)
		{
		  if (allLevels[LevelCount].enemies[j].getHealth () <= 0
		      && allLevels[LevelCount].isActiveEnemy (j) == 1)
		    {
		      allLevels[LevelCount].deactivateEnemy (j);	// deactivates enemy if it is out of health
		      scene.removeItem (&allLevels[LevelCount].enemies[j]);	// removes enemy if it is out of health
		      scorebar.setNum (scorebar.getNum () + 20 * allLevels[LevelCount].enemies[j].getPower ());	// increases and updates score.
		    }		// removes enemies from the board if they are destroyed

		  if (link.getFightControl () > 0)
		    {
		      if (link.getFightControl () == 3
			  && link.
			  collidesWithItem (&allLevels[LevelCount].enemies[j])
			  && isHit == 0)
			{
			  newHealth = allLevels[LevelCount].enemies[j].getHealth () - link.getPower ();	// decreases health
			  allLevels[LevelCount].enemies[j].setHealth (newHealth);	// sets new health
			  allLevels[LevelCount].enemies[j].invertColors ();	// flashes enemy
			  isHit = 1;
			}
		    }		// if hero is swinging the sword, checks for enemy collision and deals damage
		  else if (allLevels[LevelCount].
			   enemies[j].collidesWithItem (&link)
			   && allLevels[LevelCount].isActiveEnemy (j) == 1
			   && isHit == 0)
		    {
		      newHealth = link.getHealth () - allLevels[LevelCount].enemies[j].getPower ();	// gets new health
		      link.setHealth (newHealth);	// sets new health
		      lifebar.setNum (link.getHealth ());	// updates lifebar
		      link.invertColors ();	//inverts colors
		      isHit = 1;
		    }		// handles enemy damage to hero

		  if (ArrowOn == 1
		      && arrow.
		      collidesWithItem (&allLevels[LevelCount].enemies[j])
		      && allLevels[LevelCount].isActiveEnemy (j) == 1)
		    {
		      newHealth = allLevels[LevelCount].enemies[j].getHealth () - link.getPower ();	// decreases health
		      allLevels[LevelCount].enemies[j].setHealth (newHealth);	// sets new health
		      allLevels[LevelCount].enemies[j].invertColors ();	// flashes enemy
		      arrowHit = 1;
		    }		// handles arrow damage to enemy.

		  if(allLevels[LevelCount].enemies[j].canFire()==1 && allLevels[LevelCount].enemies[j].getCount() %10==0)
			{
				allLevels[LevelCount].enemies[j].firePellet();  // sets fire pellet indicator in enemy to 1
			}  // fires pellet every 100 counts of advance if there is not already a pellet on the screen.


		  if (allLevels[LevelCount].enemies[j].isFired()==1 &&LevelCount!=0&&allLevels[LevelCount].isActiveEnemy(j)==1)
		    {
		      if (activePellet == 0)
			{
			  activePellet = 1;	// activates pellet
			  ball.setX (allLevels[LevelCount].enemies[j].x ());	// sets x position
			  ball.setY (allLevels[LevelCount].enemies[j].y ());	// sets y position
			  ball.setDirs (link.x (), link.y ());	// calculates directions
			  scene.addItem (&ball);	// adds ball to scene
			}
		      else if (ball.collidesWithItem (&link))
			{
			  newHealth = link.getHealth () - ball.getPower ();	// decreases health
			  link.setHealth (newHealth);	// sets new health
			  link.invertColors ();	// flashes enemy
			  lifebar.setNum (link.getHealth ());	// updates lifebar
			  scene.removeItem (&ball);	// removes ball from scene
			  activePellet = 0;	// deactivates pellet
			  allLevels[LevelCount].enemies[j].resetPellet ();	// resets pellet
			}
		      else if (ball.shouldRemove ())
			{
			  scene.removeItem (&ball);	// removes ball from scene
			  activePellet = 0;	// deactivates pellet
			  allLevels[LevelCount].enemies[j].resetPellet ();	// resets pellet
			}
		    }		// handles pellet firing                  

		}
	      app.processEvents ();	// processes graphical events
	    }
	}
      LevelCount++;		// once level is finished increments level count.
 
    }				// main game loop

  if (gameover == 1)
    view.setBackgroundBrush (QPixmap ("gameover.png"));	// sets the background of the view
  else
    view.setBackgroundBrush (QPixmap ("congratulations.png"));	// sets the background of the view

  link.setFightControl (0);	// resets button press    

  // end program
  return app.exec();
}
