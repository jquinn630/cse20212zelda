// Implementation of Pellet class.  See .h file for more details
//  John Quinn, Lindsey Sansone, Rob Wirthman
// Pellet.cpp


#include <iostream>
#include <cmath>
#include "Pellet.h"

using namespace std;

Pellet::Pellet(int p) : TransparentPixmap("pellet.png"){

// sets pellet power
power =p;

// sets max boundries
ymax=800;
xmax=800;

}// constructor
    
bool
Pellet::shouldRemove(){ 
  
  if (x()>xmax||y()>ymax||x()<0||y()<0) return 1;

  else return 0;

}//returns true if pellet should be removed from scene based on location
    
void 
Pellet::setDirs(double xlocation, double ylocation){

  double ratio=(x()-xlocation)/(y()-ylocation);  // gets tan value
  double angle=atan(ratio);  // calculates angle between enemy and hero

  // gets x and y based on angle
  xdir=sin(angle);
  ydir=cos(angle);
 
  // inverts if y distance is negative
  if (y()>ylocation) 
    {
	ydir*=-1;
  	xdir*=-1;
    }

}//set xdir and ydir

void 
Pellet::advance(int step){

 
  setX(this->x()+3*xdir);  // updates x position
  setY(this->y()+3*ydir);  // updates y position

}//protected slot for advancing pellete

int
Pellet::getPower()
{
  return power;
}  // returns power
