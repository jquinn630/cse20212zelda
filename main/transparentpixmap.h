/* Base class for characters.  Creates a transparent Pixmap item for the QGrapicsView framework.  Inherits form QGraphicsPixmapItem.
  John Quinn, Lindsey Sansone, Rob Wirthman
  transparentpixmap.h

	This class inherits from QGraphicsPixmapItem.  This allows all derived classes to use all of the functions that are already defined in this class.  TransparentPixmap is never meant to be instantiated.  It simply allows derived classes that use images to get rid of the white image backgrounds.  White is defined as a transparent color and therefore any white backgrounds in derived classes will be invisible when the items are added to a QGraphicsScene.

  */


#ifndef TRANSPARENTPIXMAP_H
#define TRANSPARENTPIXMAP_H

#include <QPixmap>
#include <QtGui>
#include <QBitmap>
#include <QObject>
#include <QImage>

class TransparentPixmap : public QGraphicsPixmapItem, public QObject  // inherits from QGraphicsPixmapItem
{
public:
    TransparentPixmap();  // default constructor
    TransparentPixmap(const QString &);  // constructor
    void setTransPix(const QString &);  // function to change Pixmap by loading one from a file
    void invertColors();
};

#endif // TRANSPARENTPIXMAP_H
