// Implementation of level class .  // see .h file for description.
//   John Quinn, Lindsey Sansone, Rob Wirthman
// level.cpp

#include <iostream>
#include "level.h"

using namespace std;

Level::Level (int num, int xp[], int yp[], int health, int speed, int power, int numpellets)
{
    // declare variables to set random direction
    int rydir;
    int rxdir;
    int rdir;

    // set the number of enemies and dynamically allocate array
    maxNumEnemies=num;
    curNumEnemies=num;
    enemies=new Enemy[maxNumEnemies];
    activeEnemies=new int[maxNumEnemies];

   for (int i=0; i<maxNumEnemies; i++)
     {
	rdir = rand () % 4; // calculates random direction

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

        //sets parameters of current enemy
        enemies[i].setxmax(800);
        enemies[i].setymax(800);
        enemies[i].setSpeed(speed);
        enemies[i].setxdir(rxdir);
        enemies[i].setydir(rydir);
        enemies[i].setHealth(health);
        enemies[i].setPower(power);
	enemies[i].setPos(xp[i],yp[i]);

        activeEnemies[i]=1; // sets enemy to active
	
     }

	for (int j=0; j<numpellets; j++)
	  {
		enemies[j].givePellet();  // gives the enemy a projectile weapon by changing its appropriate indicator
 	   }

}  //constructor
  
Level::~Level()
{
    delete[]activeEnemies;
    delete[]enemies;  // delete dynamically allocated arrays
}   // deconstructor 
  
int Level::getNumEnemies()
{
     return curNumEnemies;
}  // gets number of enemies
  
int Level::getMaxEnemies()
{
    return maxNumEnemies;
}  // returns max number of enemies

void Level::setNumEnemies(int n)
{
    curNumEnemies=n;
} // sets number of enemies

void Level::deactivateEnemy(int n)
{
    if(n<maxNumEnemies && n>=0)
    {
    activeEnemies[n]=0;  // deactivates enemy if enemy exists
    curNumEnemies -=1;
    }
    else
    cout<<"Error: enemy does not exist"<<endl;  // error message
}  // deactivates enemy

int Level::isActiveEnemy(int n)
{
   if (activeEnemies[n]==1) return 1;
   else return 0;
}// returns true if enemy is active, false otherwise
