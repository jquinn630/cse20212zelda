   __                                        ______           
  /  )   /           _/_                       /              
 /--/ __/, __  ____  /  _  __  . . __  _    --/   o ______  _ 
/  (_(_/_\/</_/ / <_<__</_/ (_(_/_/ (_</_  (_/   <_/ / / <_</_

A game by John Quinn, Lindsey Sansone, and Robert Wirthman

Google Code:
To checkout the latest version of the code and view the release notes go to http://code.google.com/p/cse20212zelda/ and run an svn checkout.

Compile Instructions:
This game uses the Qt graphics framework and is optimized to run on Unix.  To run on one of the lab machines, download the source from googlecode and run the following commands:
qmake-qt4 -project
qmake-qt4
make
./main
This process generates a makefile, which can be used to build the game.
Since Qt is multiplatform, the game could probably be ported to Windows or Mac OS rather easily.  The code could be imported into QtCreator and compiled.  You would probably have to create a resource file for all the images.  The game has not been tested on either Windows or Mac OS, so none of this can be confirmed.

Playing the Game:
The game consists of eleven levels, with the last one being a boss stage.  You control a hero, who has both a sword and a projectile weapon.  You can press the space bar to use your sword and the alt key to fire a projectile.  The arrow keys are used to move the hero around the screen.  When all the enemies in a level are defeated, you advance to the next level.  Some enemies have projectile weapons, which you must dodge.  Roughly every three levels or so, powerups can be bought using points that are accumulated from defeated enemies.  Speed and attack power can be increased, and more arrows and health can be purchased.  Powerups can be purchased by moving the hero over the corresponding black square and pressing the space bar.  The appropriate quanties will be changed on the top of the screen, confirming that the powerup has been purchashed.  The game can be continued by moving the hero into the continue rectangle and pressing the spacebar.  If the hero runs out of health, a gameover screen is displayed.  If the hero beats the final boss, a congratulatory screen is displayed.  If after meeting either of these fates you wish to play again, simply restart the program.  
