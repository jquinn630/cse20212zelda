// implementation of TextStatus class.  see .h file for more.
//   John Quinn, Lindsey Sansone, Rob Wirthman
// TextStatus.cpp

#include <iostream>
#include <cstdio>
#include <string>
#include <QString>
#include <QFont>
#include "TextStatus.h"    

using namespace std;

TextStatus::TextStatus(){

} // default constructor

TextStatus::TextStatus(string a, int b, int x, int y):text(a){

        number=b;

	updateoutput();  // sets text

	setEnabled(0);   // disables item so it won't be collided with
	setX(x);	 // sets position
	setY(y);

        // sets font size and color
        QFont font;  
 	font.setPointSize(12);
	font.setBold(1);
	setFont(font);
	

} // constructor
   
void 
TextStatus::setString(string a)
{
     text=a;  // changes string
     updateoutput();  // updates output

}   // sets the string text
 
void 
TextStatus::setNum(int b)
{
      number=b;  // changes number
      updateoutput();  // updates output

}      // sets the number text

void
TextStatus::updateoutput()
{
  	string hold=text;   // adds string to output
	hold+=" ";

        // converts number to a string and updates output
        char numtostr[6];
	sprintf(numtostr, "%d", number);
	hold+=numtostr;
       
	QString qHold = QString::fromStdString(hold); 

        // sets output text
	setText(qHold);

} // updates the string output      

int 
TextStatus::getNum()
{
   return number;
}  // returns number
