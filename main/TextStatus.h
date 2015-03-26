// Text and number class
//  John Quinn, Lindsey Sansone, Rob Wirthman
// TextStatus.h
/*
	This class inherits from QGraphicsSimpleTextItem.  It makes it easier to create text objects that have a string followed by a number.  This is necessary to keep track of the player's life and score and convey this information to the user.  

*/

#ifndef TEXTSTATUS_H
#define TEXTSTATUS_H

#include<iostream>
#include<string>
#include<QGraphicsSimpleTextItem>

using namespace std;

class TextStatus : public QGraphicsSimpleTextItem
{
    public:
    TextStatus();                       // default constructor
    TextStatus(string, int, int, int);  // constructor
    void setString( string );  // sets the string text
    void setNum(int);         // sets the number text
    int getNum();            // returns number.

    private:
    void updateoutput();        // updates output
    string text;                // text of object varialble
    int number;                 // number of object variable

};

#endif
