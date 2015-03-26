// implementation of ProjectileWeapon class.  see .h file for more details.
//  John Quinn, Lindsey Sansone, Rob Wirthman
// ProjectileWeapon.cpp

#include "ProjectileWeapon.h"

using namespace std;

ProjectileWeapon::ProjectileWeapon(int p, int xd, int yd) :TransparentPixmap("proj1.png")
{
   // sets vars
   power=p;
   xdir=xd;
   ydir=yd;

   // sets appropriate pixmap based on direction
   if (xdir==1) setTransPix("proj4.png");
   else if (xdir==-1) setTransPix("proj3.png");
   else if (ydir==1) setTransPix("proj3.png");
   else if (ydir==-1) setTransPix("proj4.png");

}

int 
ProjectileWeapon::getPower()
{
   return power;
}  // returns power

void 
ProjectileWeapon::advance(int step)
{    
    setX(this->x()+6*xdir);  // updates x position
    setY(this->y()+6*ydir);  // updates y position
}  // handles movement

void 
ProjectileWeapon::setxdir(int xd)
{
   xdir=xd;
   if (xdir==1) setTransPix("proj4.png");
   else if (xdir==-1) setTransPix("proj3.png");
}    // sets x direction

void 
ProjectileWeapon::setydir(int yd)
{
   ydir=yd;
   if (ydir==1) setTransPix("proj1.png");
   else if (ydir==-1) setTransPix("proj2.png");
}  // sets y direction

void 
ProjectileWeapon::setpower(int p)
{
    power=p;
}  // sets power

