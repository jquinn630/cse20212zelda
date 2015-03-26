/* Definition of the Hero class.  Defines constructor and member functions.  See .h file for a description
  John Quinn, Robert Wirthman, & Lindsey Sansone
  hero.cpp
*/  
  
#include "hero.h"
#include <QList>
#include <iostream>
#include <QKeyEvent>
  

{



Character (h, s, xd, yd, xm,ym,p, "hero1.png")	// calls Character constructor
{
  
    // sets parameters to values in constructor
    setFlags (QGraphicsItem::ItemIsFocusable);
  
  
    // initialize variables
    fightcontrol = 0;
    numProjectiles=30;
    firearrow=0;
  
}				// constructor


Hero::keyPressEvent (QKeyEvent * event) 
{
  QList < QGraphicsItem * >collisionList = collidingItems ();	// make a list of all the colliding items using the QList container
  
    {  
    }
     else
    { 
	{	  
      else if (event->key () == Qt::Key_Right)
	{  
      else if (event->key () == Qt::Key_Up)	
	{
      else if (event->key () == Qt::Key_Down)
	{
      else if (event->key() == Qt::Key_Space  && fightcontrol==0)
        {
	 fightcontrol=1;
        }  // handles sword swing, initiates swinging process
      else if (event->key() == Qt::Key_Alt)
        {
	   firearrow=1;
        }
   }
    {
      if (! (((x () < 0 && getxdir()== -1) || (x () > getxmax() - 10 && getxdir() == 1))
	   || ((y () < 25 && getydir() == -1) || (y () > getymax() - 10 && getydir() == 1))))
	{
	  this->setY (this->y () + getSpeed () * getydir ());	// updates y position      
	}			// if not out of bounds, allow move
    }
  else
    {
      if (firearrow==0)
      {
        this->setX (this->x () + getSpeed () * getxdir () * -1 * 10);
        this->setY (this->y () + getSpeed () * getydir () * -1 * 10);  // if  a collision is pending, bounce backwards
      } 
   }


Hero::advance (int step) 
{

  
    
    {
        // handles sword swing, sets fight control to allow time for sword to kill enemy
        if (fightcontrol==3)
           fightcontrol=4;
        else if (fightcontrol==4)
           fightcontrol=0;
	// these statements allow the image representing the enemy to alternate between two image files, one with the right foot forward and one for with the left foot forward

	if (getydir() > 0)
	{
	  if (fightcontrol == 1)
	    {
	      setTransPix ("hero9.png");
	      fightcontrol = 2;
	    }  // swinging sword image
	  else if (fightcontrol == 2)
	    {
	      setTransPix ("hero10.png");
              fightcontrol=3;
	    }  // swinging sword image
	  else if (state % 2 == 0)
	    {
	  else if (state % 2 == 1)
	    {
	}			// handles image changes for the positive y direction

      else if (getydir() < 0)
	{
	  if (fightcontrol == 1)
	    {
	      setTransPix ("hero13.png");
	      fightcontrol = 2;
	    }  // swinging sword image
	  else if (fightcontrol == 2)
	    {
              setOffset(0,-40);   // makes animation smooth, makes sure sword extends
	      setTransPix ("hero14.png");
	      fightcontrol = 3;
	    }  // swinging sword image
	  else if (state % 2 == 0)
	    {
              setOffset(0,0);     // resets offset
	      setTransPix ("hero5.png");
	    }			// sets to first image
	  else if (state % 2 == 1)
	    {      
                setOffset(0,0);   // resets offset
	}			// handles image change for negative y direction

      else if (getxdir() > 0)
	{
	  if (fightcontrol == 1)
	    {
	      setTransPix ("hero15.png");
	      fightcontrol = 2;
	    }  // swinging sword image
	  else if (fightcontrol == 2)
	    {
	      setTransPix ("hero16.png");
	      fightcontrol = 3;
	    }  // swinging sword image
	  else if (state % 2 == 0)
	    {
	    }			// sets to first image
	  else if (state % 2 == 1)    
	    {   
	 }			// handles image change for positive x direction

      else if (getxdir() < 0)
	{
	  if (fightcontrol == 1)
	    {
	      setTransPix ("hero11.png");
	      fightcontrol = 2;
	    }  // swinging sword image
	  else if (fightcontrol == 2)
	    {
              setOffset(-40,0);    // makes animation smooth, makes sure sword extends
	      setTransPix ("hero12.png");
	      fightcontrol = 3;
	    } // swinging sword image
	  else if (state % 2 == 0)
	    {
                setOffset(0,0);  // resets offset
	  else if (state % 2 == 1)    
	    {
                setOffset(0,0);  // resets offset
	}			// handles image change for negative x direction
      
    }				// changes pixmap every ten frames
  

}				// allows for hero movement and advancing of the hero

int Hero::getFightControl()
{

    return fightcontrol;

}  // returns state of fighting that the hero is in

void Hero::setFightControl(int a)
{
    fightcontrol=a;
}

int Hero::getNumProjectiles()
{
    return numProjectiles;
}  // returns number of projectiles that the hero has.

void Hero::setNumProjectiles(int n)   
{
    numProjectiles=n;
}

int Hero::getFireArrow()
{
    return firearrow;
}   // returns fire arrow var
 
void Hero::setFireArrow( int n )
{
    firearrow=n;
}  // sets fire arrow