/*Programmer: Stephanie.stevens2002@gmail.com
Program: C8_PC6
Purpose: To check the weather
Start Date: 20180405
End Date: 20180410
Issues: waaaaaaaaay to many at the start
*/

//libraries
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//declare constants
const int NUM_MONTHS = 3,
DAYS_IN_MONTHS = 30;

//declare variables
int sunny,
rainy,
cloudy,
totalSunny,
totalRainy,
totalCloudy,
mostRainMonth, 
mostSunnyMonth,
mostCloudyMonth;

string rainiestMonth,
sunniestMonth, 
cloudiestMonth;

//declare functions
void readFileData(char[][DAYS_IN_MONTHS]);
int countDays(char[][DAYS_IN_MONTHS], int, char);

//main
int main()
{
	//main variables
	char weather[NUM_MONTHS][DAYS_IN_MONTHS];
	string lines;
	lines.assign(35, '_');
	string arrayMonthNames[NUM_MONTHS] = { "June", "July", "August" };
	int name;

	//header print out
	cout << "       Summer Weather Report" << endl << endl;
	cout << "MONTH" << "   -Rainy-" << " -Cloudy-" << " -Sunny-" << endl;
	cout << lines << endl;

	//open the weather file
	readFileData(weather);

	//first for loop for months
	for (int months = 0; months < NUM_MONTHS; months++)
	{ 
		//second for loop for days
		for (int days = 0; days < DAYS_IN_MONTHS; days++)
		{
			rainy = countDays(weather, months, 'R');
			cloudy = countDays(weather, months, 'C');
			sunny = countDays(weather, months, 'S');

			if (rainy > mostRainMonth)
			{
				mostRainMonth = rainy;
				rainiestMonth = arrayMonthNames[months];
			}

			if (cloudy > mostCloudyMonth)
			{
				mostCloudyMonth = cloudy;
				cloudiestMonth = arrayMonthNames[months];
			}

			if (sunny > mostSunnyMonth)
			{
				mostSunnyMonth = sunny;
				sunniestMonth = arrayMonthNames[months];
			}
		}

		//counter for totals
		totalRainy += rainy;
		totalCloudy += cloudy; 
		totalSunny += sunny;

		//output for main section
		cout << left << setw(6) << arrayMonthNames[months] 
		 << right << setw(6) << rainy << setw(9) << cloudy << setw(8) << sunny << endl;
	}

	//output for footer
	cout << lines << endl;
	cout << left << setw(6) << "Totals: " << right << setw(4) << totalRainy << setw(9) << totalCloudy << setw(8) << totalSunny << endl;
	cout << lines << endl << endl;
	cout << "The month with the most RAINY days was " << rainiestMonth << ", with " << mostRainMonth << " total rainy days." << endl;
	cout << "The month with the most CLOUDY days was " << cloudiestMonth << ", with " << mostCloudyMonth << " total cloudy days." << endl;
	cout << "The month with the most SUNNY days was " << sunniestMonth << ", with " << mostSunnyMonth << " total sunny days." << endl << endl;

	//system pause and end
	system("pause");
    return 0;
}


//first fundction for reading the file
void readFileData(char array[][DAYS_IN_MONTHS])
{
	ifstream weatherData;

	//open the weather file
	weatherData.open("RainOrShine.dat");

	//if to handle if it opens or not
	if (!weatherData)
	{
		cout << "ERROR: The file with the weather's data did not load. Please resolve this issue and try again.";
		exit(EXIT_FAILURE);
		system("pause");
	}

	for (int month = 0; month < NUM_MONTHS; month++)
	{
		for (int day = 0; day < DAYS_IN_MONTHS; day++)
			weatherData >> array[month][day];
	}

	//close the weather file
	weatherData.close();
}

//second function for counting the days
int countDays(char array[][DAYS_IN_MONTHS], int mo, char symbol)
{
	int count = 0;

	for (int day = 0; day < DAYS_IN_MONTHS; day++)
	{
		if (array[mo][day] == symbol)
			count++;
	}

	return count;
}