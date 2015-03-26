/* Definition of Enemy class for the game.  Inherits from Character class.
  John Quinn, Lindsey Sansone, Rob Wirthman
  enemy.h

	This class represents an enemy.  It inherits from character and contains all the built in qt functions for a QGraphicsPixmapItem.  This class has funtions that manage the enemy's pellet projectile, if it has one (determined by hasPellet member).  The virtual function advance that is built into Qt is redefined in this class.  This handles the movement of the enemy based on a timer and facilitates animation by changing the sprite images appropriately.
*/

#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"

class Enemy : public Character // inherits from character
{

public:
  Enemy();          // default constructor
  Enemy(int,int, int, int, int, int, int);  // constructor
  void resetPellet();     // resets pellet indicator
  void givePellet();     // gives the enemy a pellet
  void firePellet();     // sets firedPellet to 1
  int getCount();       // gets enemy step count
  int isFired();        // returns true if pellet is fired, false otherwise
  int canFire();    // returns has pellet

protected slots:
  void advance(int step=1);   // protected slot for advancing enemy

private:
  int count;   // counts steps, used in advance function
  int state;   // keeps track of image state, used in advance function
  int hasPellet; // value that stores wheter or not an enemy have a pellet
  int firedPellet; // keeps track of whether or not the pellet is currently fired
};

#endif // ENEMY_H
