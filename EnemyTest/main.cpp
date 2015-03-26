/* Main driver function to test enemy movement.
   John Quinn
   main.cpp
*/

#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QImage>
#include <QPixmap>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QMainWindow>
#include <QTimer>
#include "enemy.h"
#include "transparentpixmap.h"

#include <cmath>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);  // creates a QApplication

    srand(time(NULL));  // seeds rand
    // defines parameters to be used for random enemy placement
    int rx;
    int ry;
    int rspeed;
    int rydir;
    int rxdir;
    int rdir;

    QGraphicsScene scene;  // creates a scene
    scene.setSceneRect(0, 0, 800, 800);  // defines a rectangle encasing the scene

    Enemy enemies[10];  // creates an array of enemys.

    for (int i=0; i<6; i++)
    {
        // set random speeds and directions
        rspeed= rand() % 3 + 1;
        rdir = rand () % 4;

        // resets the rxdir and rydir parameters
        rxdir=0;
        rydir=0;

         // sets the x and y directions based on the random direction
        if (rdir==0)
        {
            rxdir=1;
        }
        else if (rdir==1)
        {
            rxdir=-1;
        }
        else if (rdir==2)
        {
            rydir=1;
        }
        else if (rdir==3)
        {
            rydir=-1;
        }

        // sets max x and y values, speed, directions, health, and power for each enemy
        enemies[i].setxmax(800);
        enemies[i].setymax(800);
        enemies[i].setSpeed(rspeed);
        enemies[i].setxdir(rxdir);
        enemies[i].setydir(rydir);
        enemies[i].setHealth(10);
        enemies[i].setPower(10);

         // selects a random x and y location
         rx= rand() % 780 + 10;
         ry= rand() % 780 + 10;

         // sets enemy position
         enemies[i].setPos(rx,ry);
         // adds enemy to scene
         scene.addItem(&enemies[i]);
    }  // randomly initializes six enemies and adds them to the scene

    QGraphicsView view(&scene);  // creates a view based on the scene
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap(":/images/grass.png"));  // sets the background of the view
    view.setCacheMode(QGraphicsView::CacheBackground);     // caches the background

   view.resize(850, 850);  // resizes the window that is shown to the user
   view.show();            // shows the view in window

   QTimer timer;           // creates a timer to control movement
   QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));  // uses the advance slot defined in the enemy class to get the enemies to move
   timer.start(50);  // starts the timer

   return app.exec();  // returns app.exec()

}
