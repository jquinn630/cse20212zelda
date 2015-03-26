/* Definition of Enemy class for the game.  Inherits from Character class.
  John Quinn
  enemy.h
*/

#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"

class Enemy : public Character  // inherits from character
{
public:
  Enemy();          // default constructor
  Enemy(int,int, int, int, int, int, int);  // constructor
  void setPower(int);  // sets enemy power
  int getPower();      // returns enemy power
  void setxdir(int);   // sets the x direction
  int getxdir();       // returns the x direction
  void setydir(int);   // sets the y direction
  int getydir();      // returns the y direction
  void setymax(int);  // sets the max y location
  int getymax();      // returns the max y location
  void setxmax(int);   // sets the max x location
  int getxmax();       // returns the max x location

protected:
  void advance(int step);   // protected slot for advancing enemy

private:
  int power;   // power, used to calculate damage dealt
  int xdir;    // x direction of movement
  int ydir;    // y direction of movement
  int xmax;    // max x location
  int ymax;    // max y location
  int count;   // counts steps, used in advance function
  int state;   // keeps track of image state, used in advance function
};

#endif // ENEMY_H
