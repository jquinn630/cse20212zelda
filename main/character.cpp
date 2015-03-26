/* Definition of the Character class.  Defines constructor and member functions.  See .h file for class description.
  John Quinn, Lindsey Sansone, Rob Wirthman
  character.cpp
*/

#include "character.h"

using namespace std;

Character::Character()
{

}  // default constructor

Character::Character(int h,int s,int xd, int yd, int xm, int ym, int p, const QString &file) : TransparentPixmap(file)  // calls TransparentPixmap constructor
{
  // sets health and speed
    xdir=xd;
    ydir=yd;
    xmax=xm;
    ymax=ym;
    setHealth(h);
    setSpeed(s);
    power=p;

}  // class constructor

int Character::getHealth() const
{
  return health;
}  // returns health as an int

double Character::getSpeed() const
{
  return speed;
}  // returns speed as an int

void Character::setHealth(int h)
{
  health=h;
}  // sets health

void Character::setSpeed(double s)
{
  speed=s;
}  // sets speed
void Character::setxdir(int x)
{
    xdir=x;
}  // sets x direction

int Character::getxdir()
{
    return xdir;
}  // returns x directon

void Character::setydir(int y)
{
    ydir=y;
}  // sets y direction

int Character::getydir()
{
    return ydir;
}  // returns y direction

void Character::setymax(int y)
{
    ymax=y;
}  // sets max y location

int Character::getymax()
{
    return ymax;
}  // returns max y location

void Character::setxmax(int x)
{
    xmax=x;
}  // sets max x location

int Character::getxmax()
{
    return xmax;
}  // returns max x location

void Character::setPower(int p)
{
    power=p;
} // sets power

int Character::getPower()
{
    return power;
}  // returns power as an int


