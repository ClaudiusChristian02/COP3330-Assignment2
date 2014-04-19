/******************************************************************************/
/*                       Date Class                                           */

/******************************************************************************/
/*                       Author and Date                                      */
/*

Author: Claudius Christian 
Date: 1/28/2013 
*/

/******************************************************************************/
/*                       Description                                          */
/*

Description: Description: A class that provides the capability to manipulate
                          dates increasing the day by 1, find and setting the
						  appropriate date for leap years, and finding the 
						  Julian Day.
*/

/******************************************************************************/
/*                       Header Files                                         */

#include <iostream>          // for input and output
using namespace std;

/******************************************************************************/
/*                       Constants                                            */

const int DEFAULTMONTH = 1;
const int DEFAULTDAY = 1;
const int DEFAULTYEAR = 2000;
const int INCREMENTDAY = 1;
const string MONTHCHARS[ 13 ] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
	                              "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
const int DAYSINMONTH[ 13 ] = { 00, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 
	                            31 };
const string TWODIGITDAY[ 32 ] = {    "00", "01", "02", "03", "04", "05", "06", 
	                                  "07", "08", "09", "10", "11", "12", "13", 
									  "14", "15", "16", "17", "18", "19", "20", 
									  "21", "22", "23", "24", "25", "26", "27", 
									  "28", "29", "30", "31" };
const string TWODIGITYEARS[ 100 ] = { "00", "01", "02", "03", "04", "05", "06", 
	                                  "07", "08", "09", "10", "11", "12", "13", 
									  "14", "15", "16", "17", "18", "19", "20", 
									  "21", "22", "23", "24", "25", "26", "27", 
									  "28", "29", "30", "31", "32", "33", "34", 
									  "35", "36", "37", "38", "39", "40", "41", 
									  "42", "43", "44", "45", "46", "47", "48", 
									  "49", "50", "51", "52", "53", "54", "55", 
							          "56", "57", "58", "59", "60", "61", "62", 
									  "63", "64", "65", "66", "67", "68", "69", 
									  "70", "71", "72", "73", "74", "75", "76", 
									  "77", "78", "79", "80", "81", "82", "83", 
									  "84", "85", "86", "87", "88", "89", "90", 
									  "91", "92", "93", "94", "95", "96", "97", 
									  "98", "99" };


/******************************************************************************/
/*                       Class Date                                           */

class Date
{
	//friend istream &operator >> ( istream &S, Date & B );
	//friend ostream &operator << ( ostream &S, Date & B );


// **********************************************************
// * Public member functions.                               *
// **********************************************************

public:
	Date();
	Date(int m);
	Date ( int m, int d, int y);
	void Input();
	void Show() const;
	void Increment( int numDays = 1);
	int GetMonth() const; 
	int GetDay() const; 
	int GetYear() const;
	int GetFormat() const;
	int Compare( const Date& d ) const;
	bool Set (int m, int d, int y);
	bool SetFormat( char f );

	friend ostream& operator<< (ostream& stream, Date& my_date);
		
// **********************************************************
// * Public member functions.                               *
// **********************************************************	

private:
	char format;
	int month;
	int day;
	int year;

}; // end of class date

