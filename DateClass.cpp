// DateClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Date.h";

#include <iostream>

int main()
{
    Date defaultDate; // Create a date object using the default constructor 
    defaultDate.printDate(1); // and display the date using the first date format.

    // LeBron James' debut NBA game
    Date parameterDate(10, 29, 2003); // Create a date object using the constructor with parameters 
    parameterDate.printDate(2); // and display the date using the second date format.

    // LeBron James' first NBA championship
    parameterDate.setDate(6, 21, 2012); // Use one of your date objects to test the setDate() function
    parameterDate.printDate(3); // and display the result using the third date format.

    parameterDate.setDate(13, 45, 2018); // Use setDate() to set the date to 13/45/2018 and verify that this date is not accepted.
    parameterDate.setDate(4, 31, 2000); // Use setDate() to set the date to 4/31/2000 and verify that this date is not accepted.
    parameterDate.setDate(2, 29, 2009); // Use setDate() to set the date to 2/29/2009 and verify that this date is not accepted.

    defaultDate.setDate(4, 10, 2014); // Set the first date object to 4/10/2014 
    parameterDate.setDate(4, 18, 2014); // and the second date object to 4/18/2014
    cout << parameterDate - defaultDate << endl; // subtract the second date from the first date, the result should be 8 days.

    defaultDate.setDate(2, 2, 2006); // Set the first date to 2/2/2006
    parameterDate.setDate(11, 10, 2003); // and the second date to 11/10/2003
    cout << defaultDate - parameterDate << endl; // subtract the second date from the first date, the result should be 815 days.

    // Set the date to 2/29/2008, use the pre-decrement operator, and print the date using one of the print formats, and verify that the date is set to 1/31/2008.
    defaultDate.setDate(2, 29, 2008);
    --defaultDate;
    cout << endl << "USING PREFIX" << endl;
    defaultDate.printDate(1); // I think Feb 28 should be correct here

    // Use the pre-increment operator, print the date using one of the print formats, and verify that it is set to back to 2 / 29 / 2008.
    ++defaultDate;
    defaultDate.printDate(2);

    // Repeat the previous two steps using the post-decrement and post-increment operators. 
    cout << endl << "USING POSTFIX" << endl;
    defaultDate.setDate(2, 29, 2008);
    defaultDate--;
    defaultDate.printDate(1);
    defaultDate++;
    defaultDate.printDate(2);

    // Set the date to 12/31/2024, use the post-increment operator, print the date using one of the 
    // print formats, and verify that the date is set to 1 / 1 / 2025.
    cout << endl << "USING POSTFIX" << endl;
    defaultDate.setDate(12, 31, 2024);
    defaultDate++;
    defaultDate.printDate(3);
    // Use the post-decrement operator, print the date using one of the print formats, and verify
    // that the date is set back to 12 / 31 / 2024.
    defaultDate--;
    defaultDate.printDate(3);

    //  Repeat the previous two steps using the pre-increment and pre-decrement operators. 
    cout << endl << "USING PREFIX" << endl;
    defaultDate.setDate(12, 31, 2024);
    ++defaultDate;
    defaultDate.printDate(3);
    --defaultDate;
    defaultDate.printDate(3);

    // Use cin and the >> operator to read a date typed in at the keyboard.
    cout << endl;
    Date inputDate;
    cout << "Enter a day (MM/DD/YYYY): ";
    cin >> inputDate;
    cout << "The date you entered was: " << inputDate << endl;

}


