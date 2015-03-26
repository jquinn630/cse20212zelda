/* Implementation of the enemy class.  Defines all necessary functions.  See .h file for a more detailed description.
  John Quinn, Lindsey Sansone, Rob Wirthman
  enemy.cpp
*/

#include "enemy.h"
#include <QList>
#include <iostream>

using namespace std;

Enemy::Enemy()
{

} // default constructor

Enemy::Enemy(int h ,int s, int p, int xd, int yd, int xm, int ym) : Character(h,s,xd,yd,xm,ym,p,"enemy1.png")  // calls Character constructor
{
    // sets parameters to values in constructor 
    count =0;
    state = 0;
    hasPellet=0;
    firedPellet=0;
}  // constructor


void Enemy::advance(int step)
{  
   int collision=0; // keeps track of collison
   if (collision==1 and count %20==0) collision=0;  // intended to prevent enemies from getting stuck on one another only allows one direction reversal every second

   if (!step) return;

    if (x()<0)
    {
        this->setX(this->x()+10);
        setxdir(getxdir()*-1);
    }  // if x is too small, reverse x direction

    else if ( x() > getxmax()-10)
    {
        this->setX(this->x()-10);
        setxdir(getxdir()*-1);
    }  // if x is too large, reverse x direction

    else if (y() < 25)
    {
        this->setY(this->y()+10);
        setydir(getydir()*-1);
    }  // if y is too small, reverse y direction

    else if  (y() > getymax() - 10)
    {
        this->setY(this->y()-5);
        setydir(getydir()*-1);
    }  // if y is too large, reverse y direction

    QList<QGraphicsItem *> collisionList = collidingItems();  // make a list of all the colliding items using the QList container

    foreach (QGraphicsItem *item, collisionList )
    {
      if (collidesWithItem(item)  && collision==0)  // calls collidesWithItem functior for each member of the collisionList
        {
           this->setX(this->x()+getxdir()*-1*5);
           this->setY(this->y()+getydir()*-1*5);
           setxdir(getxdir()*-1);
           setydir(getydir()*-1);
           collision=1;
        } // if a collision is detected between to enemies, reverse their directions
    }

    if (count %10 == 0 )
    {
        // these statements allow the image representing the enemy to alternate between two image files, one with the right foot forward and one for with the left foot forward
        if (getydir() > 0)
        {
           if (state % 2 ==0)
           {
               setTransPix("enemy2.png");
           }  // sets to first image
           else if (state %2 ==1)
           {
               setTransPix("enemy1.png");
           }  // sets to second image
        } // handles image changes for the positive y direction
       
       else if (getydir() < 0)
        {
            if (state % 2 ==0)
            {
                setTransPix("enemy5.png");
            }  // sets to first image
            else if (state%2 ==1)
            {
                setTransPix("enemy6.png");
            }  // sets to second image
        }  // handles image change for negative y direction

        else if (getxdir() > 0)
        {
            if (state%2 ==0)
            {
                setTransPix("enemy7.png");
            } // sets to first image
            else if (state%2 ==1)
            {
                setTransPix("enemy8.png");
            }  // sets to second image
        } // handles image change for positive x direction

        else if (getxdir() < 0)
        {
            if (state%2 ==0)
            {
                setTransPix("enemy3.png");
            }  // sets to first image
            else if (state%2 ==1)
            {
                setTransPix("enemy4.png");
            }  // sets to second image
        }  // handles image change for negative x direction
    
        state++;// increments image state, if there is a change.
        count=0;
    }  // changes pixmap every ten frames

    this->setX(this->x()+getSpeed()*getxdir()*2);  // updates x position
    this->setY(this->y()+getSpeed()*getydir()*2);  // updates y position
    ++count;  // counts steps
}  // allows for enemy movement and advancing of the enemy

void
Enemy::resetPellet()
{
   firedPellet=0;
}  // allows the pellet to be reset when it hits an object or goes off the screen

void
Enemy::givePellet()
{
   hasPellet=1;
}  // gives the enemy a projectile weapon by chaniging appropriate value

void 
Enemy::firePellet()
{
  firedPellet=1;
}  // sets fire pellet indicator to 1

int
Enemy::isFired()
{
  return firedPellet;
} // returns true if pellet is fired, false otherwise

int 
Enemy::getCount()
{
  return count;
}  // returns advance count

int
Enemy::canFire()
{
  return hasPellet;
}  // returns true if the enemy has a pellet

