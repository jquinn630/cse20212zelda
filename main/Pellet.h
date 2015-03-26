#ifndef PELLET_H
#define PELLET_H
/*
 *   John Quinn, Lindsey Sansone, Rob Wirthman
 * pellet.h
 * 4/16/12
*/
/*
	This class inherits from the TransparentPixmap class, which inherits from QGraphicsPixmapItem.  The advance virtual function from Qt is redefined here.  This class takes in a position and calculates an x and y direction toward that position based on its current location.  It then advances toward that position.  It also holds a power data member representing the item's strength  

*/

#include <QtGui>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QRectF>
#include "transparentpixmap.h"
#include "hero.h"
class Pellet : public TransparentPixmap
{
  public:
    Pellet(int);//default constructor
    bool shouldRemove();//returns true if main should remove from scene
    void setDirs(double xlocation, double ylocation);//set xdir and ydir
    int getPower();  // returns power
  protected slots:
    void advance(int step=1);//protected slot for advancing pellete
  private:
    double xdir;//x direction of movement
    double ydir;//y direction of movement
    int xmax;//max x location
    int ymax;//max y location
    int power; 
};
#endif
