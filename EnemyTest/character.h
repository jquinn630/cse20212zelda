/* Defines a class that all characters in the game will derive from
  John Quinn
  character.h
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
  Character(int,int, const QString &);  // constructor
  int getHealth() const;  // returns health as an int
  int getSpeed() const;   // returns speed as an int
  void setHealth(int);    // sets health
  void setSpeed(int);     // sets speed
private:
  int health;             // contains character health
  int speed;              // contains character speed
};

#endif // CHARACTER_H
