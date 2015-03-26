/* Definition of the TransparentPixmap class.
  John Quinn
  transparetnpixmap.cpp
*/


#include "transparentpixmap.h"

TransparentPixmap::TransparentPixmap()
{

} // default constructor

TransparentPixmap::TransparentPixmap(const QString &filename)
{
    setTransPix(filename);  // sets the transparent pixmap from a file
}   // construction

void TransparentPixmap::setTransPix(const QString &filename)
{
    QColor & trans_color = QColor(255,255,255);  // creates a color to make transparent
    QPixmap image(filename);  // loads pixmap from file
    const QBitmap trans = image.createMaskFromColor(trans_color);  // creates a mask based on the transparent color
    image.setMask(trans);   // masks the transparent color in the QPixmap that was loaded
    this->setPixmap(image);  // sets the pixmap of the QGraphicsPixmapItem to the pixmap with the transparency included

}
