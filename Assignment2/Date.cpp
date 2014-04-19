/******************************************************************************/
/*                       Author and Date                                      */
/*

Author: Claudius Christian 
Date: 1/28/2013 

/******************************************************************************/
/*                       Summary                                              */
/*

1) An object of type Date should represent a calendar date in terms of month, 
day, and year, as on a 12-month A.D. calendar. The valid months are January 
through December, a valid day must correspond to a valid day for the given 
month, and the year must be a positive number. Your object should also store 
a format setting, to be used for display of dates to the screen. There will 
be more than one possible format. The class features (public interface) should 
work exactly as specified, regardless of what program might be using Date 
objects.

Note: For purposes of easy input (from keyboard or into functions), date values 
will be specified with integers. Month values will be 1 for January, 2 for 
February, etc... on to 12 for December. A valid day value will be an integer 
between 1 and the number of days in the month. Valid year values are positive 
numbers.


2) Your Date class must provide the following services (i.e. member functions) 
in its public section. These functions will make up the interface of the Date 
class. Make sure you use function prototypes as specified here. (You may write 
any other private functions you feel necessary, but the public interface must
include all the functionality described here).


/******************************************************************************/
/*                       Input                                                */
/*

Prompt the user to enter a date, and then allow the user to input a date from 
the keyboard. User input is expected to be in the format month/day/year, 
where month, day, and year are integer values. Whenever the user attempts to 
enter an invalid date, the Input function should display an appropriate error 
message (like "Invalid date. Try again: ") and make the user re-enter the 
whole date. A few examples of some good and bad inputs:

Legal: 1/4/2000 , 2/28/1996 , 12/31/1845
Illegal: 13/12/1985, 11/31/2002, 8/30/-2000

/******************************************************************************/
/*                       Output                                               */
/*

output the date to the screen. There will be more than one possible format for 
this output, however, and your class will need to store a format setting. The 
Show function should use the format setting to determine the output. (There 
will be a member function that allows the setting to be changed). When a Date 
object is created, the format setting should start out at the "Default" 
setting. The possible formats are shown in the following table:

Default: M/D/Y -- 10/4/1998
Two-Digit: mm/dd/yy -- 10/04/98
Long month: D, Y -- Oct 4, 1998

/******************************************************************************/
/*                       Header Files                                         */

#include "Date.h"                          
#include <iostream>                      // for input and output
#include <string>                        // for strings
using namespace std;

/******************************************************************************/
/*                       Date Function                                        */
/*

Author: Claudius Christian
Date:  1/29/2013

Constructor for the Class Date
*/


Date::Date(int m, int d, int y) 
{

	format = 'D';
	
	// check values. If good, assign them. Otherwise default.
	if ( !Set( m, d, y )) 
	{       
		month = DEFAULTMONTH;  
		day = DEFAULTDAY;
		year = DEFAULTYEAR;
	}

} // end Date::Date ( const int m, const int d, const int y ) 

Date::Date(int m)
{
	Set(m, DEFAULTDAY, DEFAULTMONTH);

	format = 'D';
}	

Date::Date()
{
	Set( DEFAULTMONTH, DEFAULTDAY, DEFAULTYEAR );
		
	format = 'D';

} // end Date::Date()

/******************************************************************************/
/*                       Show Function                                        */
/*

Author: Claudius Christian
Date:  1/29/2013

Description: This function should simply output the date to the screen. There 
             will be more than one possible format for this output, however, 
			 and your class will need to store a format setting. The Show
             function should use the format setting to determine the output. 
			 (There will be a member function that allows the setting to be 
			 changed). When a Date object is created, the format setting should
             start out at the "Default" setting. The possible formats are:

			 Default   , M/D/Y      , 10/4/1998
			 Two-Digit , mm/dd/yy   , 10/04/98
			 Long      , month D, Y , Oct 4, 1998
*/

void Date::Show() const
{
	switch( format )
	{
	case 'D':  {
		cout << month << "/" << day << "/" << year << '\n';
        break;
	}
	case 'T': {
		cout << month << "/" << TWODIGITDAY[ day ] << "/" << TWODIGITYEARS[ year % 100 ] << '\n';
        break;
	}
	case 'L': {
		cout << MONTHCHARS[ month ] << " " << day << ", " << year << '\n';
        break;
	}
	default: {
		cout << "Something went wrong. Freak out." << '\n';
			 } // end default
	} // end switch statement
} // void Date::Show

/******************************************************************************/
/*                       Set Format Function                                  */
/*

Author: Claudius Christian
Date:  1/29/2013

Description: This function allows the caller to change the format setting. The 
             setting should be adjusted inside the object based on the character 
			 code passed in. This means that future uses of the Show function 
			 will display in this given format until the format is changed. The 
			 valid setting codes that can be passed in are:

             'D' = Default format
             'T' = Two-Digit format
             'L' = Long format
*/

bool Date::SetFormat( char f )
{
	if( (f == 'D') || (f == 'T') || (f == 'L') )
	{
		format = f;
		return true;

	} // end bool Date::SetFormat

	return false;

} // end bool Date::SetFormat

/******************************************************************************/
/*                       Compare Function                                     */
/*

Author: Claudius Christian
Date:  1/29/2013

Description: This function compares two Date objects (the calling object and 
             the parameter), and should return: -1 if the calling object comes 
			 first chronologically, 0 if the objects are the same date, and 1 
			 if the parameter object comes first chronologically. The function 
			 should not change either object.
*/


int Date::Compare( const Date &d ) const
{
	int date1 = 0,
		date2 = 0;
	
	date1 = ( d.GetYear() * 10000 + d.GetMonth() * 100 + d.GetDay() );
	date2 = ( d.GetYear() * 10000 + d.GetMonth() * 100 + d.GetDay() );

	if( date1 < date2)
	{
		return -1;
	} // end first if

	if( date1 == date2)
	{
		return 0;
	} // end second if

	if( date1 > date2)
	{
		return 1;
	} // end third if
} // end compare



/******************************************************************************/
/*                       Set Function                                         */
/*

Author: Claudius Christian
Date:  1/29/2013

Description: This function should set the date to the specified values (the 
             first parameter represents the month, the second represents the 
			 day, and the third represents the year). If the resulting date is 
			 an invalid date, the operation should abort (i.e. the existing 
			 stored date should not be changed). This function should return 
			 true for success and false for failure (i.e. invalid date sent in).
*/


bool Date::Set( int m, int d, int y )
{
	
	bool validdate = ( m >= 1 && m <= 12 ) &&
		             ( d >= 1 && d <= DAYSINMONTH[ m ] ) &&
					 ( y > 0 );

	if( validdate )
	{
		month = m;
		day = d;
		year = y;
	} // end of if

	return validdate;
} // end of bool date::set


/******************************************************************************/
/*                       Get Month Function                                   */
/*

Author: Claudius Christian
Date:  1/29/2013

*/

int Date::GetMonth() const
{
	return month;
} // end of int Date::GetMonth


/******************************************************************************/
/*                       Get Day Function                                     */
/*

Author: Claudius Christian
Date:  1/29/2013

Description: Return the day of the date entered.
*/

int Date::GetDay() const 
{
	return day; 

} // end of int Date::GetDay()

/******************************************************************************/
/*                       Get Day Format                                     */
/*

Author: Claudius Christian
Date:  1/29/2013

Description: Return the day of the date entered.
*/

int Date::GetFormat() const 
{
	return format; 

} // end of int Date::GetDay()


/******************************************************************************/
/*                       Get Year Function                                    */
/*

Author: Claudius Christian
Date:  1/29/2013

Description: Return the year of the date entered.
*/

int Date::GetYear() const
{
	return year;

} // end of int Date::GetDay()

/******************************************************************************/
/*                       Input Function                                       */
/*

Author: Claudius Christian
Date:  1/29/2013

Description: This function should prompt the user to enter a date, and then 
             allow the user to input a date from the keyboard. User input 
			 is expected to be in the format month/day/year, where month, day, 
			 and year are integer values. Whenever the user attempts to enter 
			 an invalid date, the Input function should display an appropriate 
			 error message (like "Invalid date. Try again: ") and make the user
             re-enter the whole date. A few examples of some good and bad 
			 inputs:

             Legal:     1/4/2000 , 2/28/1996  , 12/31/1845
             Illegal: 13/12/1985 , 11/31/2002 , 8/30/-2000
*/

void Date::Input()
{
	int m, d, y;
	char ch1, ch2;

	cout << "Please enter a date using the format month/day/year: " << endl;
	cin >> m >> ch1 >> d >> ch2 >> y;

	while (Set(m, d, y) == false)
	{
		cout << "Please enter a date using the format month/day/year: " << endl;
		cin >> m >> ch1 >> d >> ch2 >> y;

	} // end while
} // end void Date::Input

/******************************************************************************/
/*                       Increment Function                                   */
/*

Author: Claudius Christian
Date: 1/28/2013 

Description: This function should move the date forward by the number of 
             calendar days given in the argument. Default value on the 
			 parameter is 1 day. Examples:

			 Date d1(10, 31, 1998);    Oct 31, 1998
             Date d2(6, 29, 1950);     June 29, 1950
                                          
			 d1.Increment();           d1 is now Nov 1, 1998
             d2.Increment(5);          d2 is now July 4, 1950
*/

void Date::Increment( int numDays )
{


	if( (day + numDays) <=  DAYSINMONTH[ month ] )
	{
	
		day = day + numDays;
	} // end increment


	// determine if the day is a valid day for that month. If there are not enough
	// days in the month increment the month by one, and set the day to 1.
	while( (day+numDays) > DAYSINMONTH[month])
	{
		if(month==12&&(day+numDays)>DAYSINMONTH[month])
		{
			numDays=(numDays-(DAYSINMONTH[month]-day)-1);
			year++;
			month=1;
			day=1;
		} // end first if

		if((day+numDays)>DAYSINMONTH[month])
		{
			numDays=(numDays-(DAYSINMONTH[month]-day)-1);
			month++;
			day=1;
		} // end second if

		if((day+numDays)<=DAYSINMONTH[month])
		{
			day = day + numDays;
			break;
		} // end third if
	} // end while
} // end of void Date::Increment


ostream& operator << (ostream& stream, Date& my_date) {

	switch( my_date.format )
	{
	case 'D':  
		{
		stream << my_date.GetMonth() << "/" << my_date.GetDay() << "/" << my_date.GetYear() << '\n';
        break;
		} // end default case
	case 'T': 
		{
		stream << my_date.GetMonth() << "/" << my_date.GetDay() << "/" << TWODIGITYEARS[ my_date.GetYear() % 100 ] << '\n';
        break;
		} // end default case
	case 'L': 
		{
		stream << MONTHCHARS[ my_date.GetMonth() ] << " " << my_date.GetDay() << ", " << my_date.GetYear() << '\n';
        break;
		}
	default: 
		{
		stream << "Something went wrong. Freak out." << '\n';
		}
	} // end switch 

	return stream;
} // end ostream operator

 