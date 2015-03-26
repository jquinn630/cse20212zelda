/* Defines a class that all characters in the game will derive from
  John Quinn, Lindsey Sansone, Rob Wirthman
  character.h

  This class is a base class that is not mean to be instantiated.  It contains functions that will be common to both the enemy and hero class, including onese that handle, power, speed, and direction of motion.  It inherits from TransparentPixmap, which inherits from QGraphicsPixmapItem.  This allows functions that are built into this Qt class to be used in all derived classes.

  */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <QtGui>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QRectF>
#include "transparentpixmap.h"

class Character : public TransparentPixmap  // inherits from TransparentPixmap class
{
public:
  Character();                          // default constructor
  Character(int, int, int, int, int, int, int, const QString &);  // constructor
  int getHealth() const;  // returns health as an int
  double getSpeed() const;   // returns speed as an int
  void setHealth(int);    // sets health
  void setSpeed(double);     // sets speed
  void setxdir(int);   // sets the x direction
  int getxdir();       // returns the x direction
  void setydir(int);   // sets the y direction
  int getydir();      // returns the y direction
  void setymax(int);  // sets the max y location
  int getymax();      // returns the max y location
  void setxmax(int);   // sets the max x location
  int getxmax();       // returns the max x location
  void setPower(int);  // sets enemy power
  int getPower();      // returns enemy power

private:
  int health;             // contains character health
  double speed;              // contains character speed
   int xdir;    // x direction of movement
  int ydir;    // y direction of movement
  int xmax;    // max x location
  int ymax;    // max y location
  int power;   // power, used to calculate damage dealt
};

#endif // CHARACTER_H
