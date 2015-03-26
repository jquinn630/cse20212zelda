/* Base class for characters.  Creates a transparent Pixmap item for the QGrapicsView framework.  Inherits form QGraphicsPixmapItem.
  John Quinn
  transparentpixmap.h
  */


#ifndef TRANSPARENTPIXMAP_H
#define TRANSPARENTPIXMAP_H

#include <QPixmap>
#include <QtGui>
#include <QBitmap>

class TransparentPixmap : public QGraphicsPixmapItem  // inherits from QGraphicsPixmapItem
{
public:
    TransparentPixmap();  // default constructor
    TransparentPixmap(const QString &);  // constructor
    void setTransPix(const QString &);  // function to change Pixmap by loading one from a file
};

#endif // TRANSPARENTPIXMAP_H
