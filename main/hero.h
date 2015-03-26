/* Definition of Hero class for the game.  Inherits from Character class.
  John Quinn, Lindsey Sansone, Rob Wirthman
  hero.h

	This class is derived from character.  It contains functions that allow it to fire projectiles and swing a sword that does damage to enemies.  The sword swinging sets the fightcontrol variable to certain values.  The main program can then use getFightControl to get this value to check whether or not the hero can do damage to other object.  Likewise, the value of fire arrow can be changed depending on whether or not the hero is firing an arrow.  The virtual functions advance and keyPressEvent are overloaded in this class.  These are from the QGraphicsPixmapItem class.  Advance handles the animations of the hero, including movement and sword swinging.  KeyPressEvent handles user input from the keyboard to either move the hero, swing his sword, or fire a projectile.

*/  
  
#ifndef HERO_H
#define HERO_H
#include "character.h"
class Hero:public Character	// inherits from character
{
public:  Hero ();		// default constructor
  Hero (int, int, int, int, int, int, int);	// constructor
  int getFightControl();       // returns fight control member
  void setFocusPolicy (Qt::FocusPolicy policy);	// Sets the focus on the hero to allow keyboard access
  void setNumProjectiles(int);                 // sets number of projectile weapons after use.
    int getNumProjectiles();                     // returns number of projectile weapons user has
  int getFireArrow();     // returns fire arrow var
  void setFireArrow( int );  // sets fire arrow
  void setFightControl(int a);  // sets fight control
protected slots:  void advance (int step=1);   // protected slot for advancing hero
  void keyPressEvent (QKeyEvent * event);	//let's us know that a key has been pressed, handles keypress

private:
  int count;			// counts steps, used in advance function
  int state;			// keeps track of image state, used in advance function
  int fightcontrol;		// controllers whether or not a weapon is used on a keypress
  int numProjectiles;            // holds number of projectile weapons user has
  int firearrow;                 // sends a signal to fire an arrow;

};


#endif // HERO_H
