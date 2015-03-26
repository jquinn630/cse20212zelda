/* Definition of the Enemy class.  Defines constructor and member functions.
  John Quinn
  enemy.cpp
*/

#include "enemy.h"
#include <QList>
#include <iostream>

using namespace std;

Enemy::Enemy()
{

} // default constructor

Enemy::Enemy(int h ,int s, int p, int xd, int yd, int xm, int ym) : Character(h,s,":/images/enemy1.png")  // calls Character constructor
{
    // sets parameters to values in constructor
    power=p;
    xdir=xd;
    ydir=yd;
    xmax=xm;
    ymax=ym;
    count =0;
    state = 0;
}  // constructor

void Enemy::setPower(int p)
{
    power=p;
} // sets power

int Enemy::getPower()
{
    return power;
}  // returns power as an int

void Enemy::setxdir(int x)
{
    xdir=x;
}  // sets x direction

int Enemy::getxdir()
{
    return xdir;
}  // returns x directon

void Enemy::setydir(int y)
{
    ydir=y;
}  // sets y direction

int Enemy::getydir()
{
    return ydir;
}  // returns y direction

void Enemy::setymax(int y)
{
    ymax=y;
}  // sets max y location

int Enemy::getymax()
{
    return ymax;
}  // returns max y location

void Enemy::setxmax(int x)
{
    xmax=x;
}  // sets max x location

int Enemy::getxmax()
{
    return xmax;
}  // returns max x location

void Enemy::advance(int step)
{
    if (x()<0 || x() > xmax-10)
    {
        xdir*=-1;
    }  // if out of bounds on the x scale, reverse x direction

    else if (y() < 0 || y() > ymax - 10)
    {
        ydir*=-1;
    }  // if out of bounds on the y scale, reverse y direction

    QList<QGraphicsItem *> collisionList = collidingItems();  // make a list of all the colliding items using the QList container

    foreach (QGraphicsItem *item, collisionList )
    if (collidesWithItem(item))  // calls collidesWithItem functior for each member of the collisionList
    {
        xdir*=-1;
        ydir*=-1;
    } // if a collision is detected between to enemies, reverse their directions

    if (count %10 == 0)
    {
        // these statements allow the image representing the enemy to alternate between two image files, one with the right foot forward and one for with the left foot forward
        if (ydir > 0)
        {
           if (state % 2 ==0)
           {
               setTransPix(":/images/enemy2.png");
           }  // sets to first image
           else if (state %2 ==1)
           {
               setTransPix(":/images/enemy1.png");
           }  // sets to second image
        } // handles image changes for the positive y direction
        else if (ydir < 0)
        {
            if (state % 2 ==0)
            {
                setTransPix(":/images/enemy5.png");
            }  // sets to first image
            else if (state %2 ==1)
            {
                setTransPix(":/images/enemy6.png");
            }  // sets to second image
        }  // handles image change for negative y direction
        else if (xdir > 0)
        {
            if (state % 2 ==0)
            {
                setTransPix(":/images/enemy7.png");
            } // sets to first image
            else if (state %2 ==1)
            {
                setTransPix(":/images/enemy8.png");
            }  // sets to second image
        } // handles image change for positive x direction
        else if (xdir < 0)
        {
            if (state % 2 ==0)
            {
                setTransPix(":/images/enemy3.png");
            }  // sets to first image
            else if (state %2 ==1)
            {
                setTransPix(":/images/enemy4.png");
            }  // sets to second image
        }  // handles image change for negative x direction

        state++;// increments image state, if there is a change.
    }  // changes pixmap every ten frames


    this->setX(this->x()+getSpeed()*getxdir());  // updates x position
    this->setY(this->y()+getSpeed()*getydir());  // updates y position
    count ++;  // counts steps
}  // allows for enemy movement and advancing of the enemy

