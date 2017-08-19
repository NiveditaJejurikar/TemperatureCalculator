
/*
 * nsj8P1.cpp
 *
 * COSC 051 Summer 2015
 * Project #1
 *
 * Due on: JUL 13, 2015
 * Author: Nivu Jejurikar
 *
 *
 * In accordance with the class policies and Georgetown's
 * Honor Code, I certify that, with the exception of the
 * class resources and those items noted below, I have neither
 * given nor received any assistance on this project.
 *
 * References not otherwise commented within the program source code.
 * Note that you should not mention any help from the TAs, the professor,
 * or any code taken from the class textbooks.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()

{

//define the constants used in the calculations that convert Celsius
//temperatures into various temperature scales

const float KELVIN_CONVERTER = (273.15);
const float RANKINE_CONVERTER_MULTIPLIER = 1.8;
const float RANKINE_CONVERTER_CONSTANT = 273.15;
const float DELISLE_CONVERTER_INITIAL = 100;
const float DELISLE_CONVERTER_FINAL = 1.5;
const float NEWTON_CONVERTER = 0.33;
const float REAUMUR_CONVERTER = 0.8;
const float ROMER_CONVERTER_MULTIPLIER = 0.525;
const float ROMER_CONVERTER_CONSTANT = 7.5;
const float FAHRENHEIT_CONVERTER_MULTIPLIER = 1.8;
const float FAHRENHEIT_CONVERTER_CONSTANT = 32;
const float CELSIUS_CONVERTER_MULTIPLIER = 0.555555555;
const float CELSIUS_CONVERTER_CONSTANT = 32;

//define the variable temperatureScale as an array of characters

char temperatureScale[15];

//define the variables that will express various temperature scales

float temperatureInDegrees = 0;
float temperatureInCelsius = 0;
float temperatureInFahrenheit = 0;
float Kelvin_temp = 0;
float Rankine_temp = 0;
float Delisle_temp = 0;
float Newton_temp = 0;
float Reaumur_temp = 0;
float Romer_temp = 0;

//this variable stores 1 if the temperature entered is in Celsius
//and resets to 0 if the temperature entered is in Fahrenheit

bool ScaleIsCelsius = 1;

//prompt the user to enter a valid temperature in degrees Celsius or in degrees Fahrenheit

cout << "This program accepts a temperature reading (entered in either Fahrenheit or Celsius).\n";
cout << "Once a valid temperature reading has been entered, the software will convert \n";
cout << "that value to various other temperature scales.\n";
cout << "Please enter only the numeric value of the temperature value you want to convert.\n";

//this variable stores the temperature value entered by the user

cin >> temperatureInDegrees; 

cout << "Please enter the temperature scale:" << endl; 
cout << "If the value is in Celsius, enter C" << endl;
cout << "If the value is in Fahrenheit, enter F" << endl;

//store the scale of the temperature entered by the user

cin >> temperatureScale;

//if the first character of the temperature scale entered is either 'c' or 'C', then store the 
//value entered by the user into the variable temperatureInCelsius. Then, convert the variable 
//temperatureInCelsius into Fahrenheit degrees and store in the variable temperatureInFahrenheit.

if ((temperatureScale[0] == 'c') || (temperatureScale[0] == 'C'))
{ 

temperatureInCelsius = temperatureInDegrees;
cout << "Your entry was " << temperatureInCelsius << " degrees Celsius." << endl;
temperatureInFahrenheit = (temperatureInCelsius * FAHRENHEIT_CONVERTER_MULTIPLIER) + FAHRENHEIT_CONVERTER_CONSTANT;

}	

//if the first character of temperatureScale is lower or uppercase ‘f’, then the program will 
//display the value of the temperature entered in Fahrenheit.

else 
{
	if ((temperatureScale[0] == 'f') || (temperatureScale[0] == 'F'))

              {
                cout << "Your entry was " << temperatureInDegrees << " degrees Fahrenheit.\n";

//Convert the Fahrenheit temperature into Celsius degrees and store
//in the variable temperatureInCelsius. Then store the value entered by the user
//in the variable temperatureInFahrenheit. Finally, store the boolean variable as 0 
//to indicate that the temperature entered is in Fahrenheit.

                temperatureInCelsius = (CELSIUS_CONVERTER_MULTIPLIER) * (temperatureInDegrees - CELSIUS_CONVERTER_CONSTANT); 
		temperatureInFahrenheit = temperatureInDegrees;
		ScaleIsCelsius = 0;
		 
             }

//This is the block of code will execute if the user makes a
//mistake and enters a string that starts with neither ‘C’ nor ‘F’
//(lower or uppercase). The program will exit by warning the user about
//invalid input.

	else {
               cout << "Temperature scale must be either F for Fahrenheit or C for Celsius. Program will exit now.\n";
               return (-1);
              }  
}


////calculate the values of the temperatures in different scales by
//using the formulas given in the handout

Kelvin_temp = temperatureInCelsius + KELVIN_CONVERTER;
Rankine_temp = (RANKINE_CONVERTER_MULTIPLIER) * (temperatureInCelsius + RANKINE_CONVERTER_CONSTANT);
Delisle_temp = (DELISLE_CONVERTER_FINAL) * (DELISLE_CONVERTER_INITIAL - temperatureInCelsius);
Newton_temp = (temperatureInCelsius) * (NEWTON_CONVERTER);
Reaumur_temp = (temperatureInCelsius) * (REAUMUR_CONVERTER);
Romer_temp = (ROMER_CONVERTER_CONSTANT) + (ROMER_CONVERTER_MULTIPLIER * temperatureInCelsius);

//display the calculated temperatures in various temperature scales

cout << "The following table lists your entry converted to various temperature scales:" << endl;
cout << right << setw(10) << "Scale" << right << setw(10) << "Value" << endl;

if (ScaleIsCelsius)
{
cout << right << setw(10) << "Fahrenheit";
cout << right << setw (10) << fixed << setprecision(2);
cout << temperatureInFahrenheit << endl;
}
else 
{
cout << right << setw(10) << "Celsius";
cout << right << setw(10) << fixed << setprecision(2);
cout << temperatureInCelsius << endl;
}

cout << right << setw(10) << "Kelvin";
cout << right << setw(10) << fixed << setprecision(2);
cout << Kelvin_temp << endl;

cout << right << setw(10) << "Rankine";
cout << right << setw(10) << fixed << setprecision(2);
cout << Rankine_temp << endl;

cout << right << setw(10) << "Delisle";
cout << right << setw(10) << fixed << setprecision(2);
cout << Delisle_temp << endl;

cout << right << setw(10) << "Newton";
cout << right << setw(10) << fixed << setprecision(2);
cout << Newton_temp << endl;

cout << right << setw(10) << "Reaumur";
cout << right << setw(10) << fixed << setprecision(2);
cout << Reaumur_temp << endl;

cout << right << setw(10) << "Romer";
cout << right << setw(10) << fixed << setprecision(2);
cout << Romer_temp << endl;

//diplay the exit message to the user

cout << "Thank you for using the AllTemp Conversion Calculator" << endl;
cout << "Please contact Allegany Calculator Specialists again, Goodbye." << endl; 


return 0;

}
