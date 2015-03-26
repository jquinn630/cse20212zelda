/* Definition of the Character class.  Defines constructor and member functions.
  John Quinn
  character.cpp
*/

#include "character.h"

using namespace std;

Character::Character()
{

}  // default constructor

Character::Character(int h,int s, const QString &file) : TransparentPixmap(file)  // calls TransparentPixmap constructor
{
  // sets health and speed
  setHealth(h);
  setSpeed(s);

}  // class constructor

int Character::getHealth() const
{
  return health;
}  // returns health as an int

int Character::getSpeed() const
{
  return speed;
}  // returns speed as an int

void Character::setHealth(int h)
{
  health=h;
}  // sets health

void Character::setSpeed(int s)
{
  speed=s;
}  // sets speed
