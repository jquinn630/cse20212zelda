// defininition of ProjectileWeapon Class
//  John Quinn, Lindsey Sansone, Rob Wirthman
// ProjectileWeapon.h
/*
	This class represetns a projectile weapon that is fired by the hero.  It's contructor sets the appropriate image and the direction and power can be taken in as parameters.  The advance virtual function from Qt is defined in this class to handle movement.  Collisions and damage are handled in the main program using built in collision functions.

*/

#include <iostream>
#include "transparentpixmap.h"

using namespace std;

class ProjectileWeapon : public TransparentPixmap
{
   public:
   ProjectileWeapon(int p, int xd, int yd);  // constructor
   int getPower();    // gets power of arrow
   void setxdir(int xd);     // sets x direction
   void setydir(int yd);     // sets y direction
   void setpower(int p);     // sets power

   protected slots:
   void advance(int step=1);  // advances arrow
 
   private:
   int power;   // damage arrow will do if it hits an enemy
   int xdir;    // x direction of arrow
   int ydir;    // y direction of arrow
};
