// definition of level class
//   John Quinn, Lindsey Sansone, Rob Wirthman
// level.h
/*
	This class allows for game levels to be predefined and stored in a structure.  This is possible the number of enemies, their locations, speeds, and powers are all input.  This class uses dynamic memory allocation to create an array of enemies.  It then creates all of these enemies, as well as an array that keeps track if they are active or not.  The class deconstructor handles the deleting of these dynamically allocated elements.

*/

#include <iostream>
#include "enemy.h"
#include "hero.h"

using namespace std;

class Level 
{
  public:
  Level (int, int [], int [], int, int, int, int);  //constructor
  ~Level();   // deconstructor 
  int getNumEnemies();  // gets current number of enemies
  void setNumEnemies(int); // sets number of enemies 
  void deactivateEnemy(int);  // deactivates enemies
  int isActiveEnemy(int);   // returns true if enemy is active
  int getMaxEnemies();     // returns max number of enemies
  Enemy *enemies;     // dynamically allocated array of enemies

  private:
  int maxNumEnemies;   // private data member that holds number of enemies
  int curNumEnemies;   // holds the current number of enemies
  int *activeEnemies; // private data member that holds whether or not an enemy is active  

};
