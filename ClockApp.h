#pragma once

/*
* Hunter Brashears
* Clocks.cpp
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int hours;
int minutes;
int seconds;
int hours24;
int isAM;
string timeNotion;


// Function to let user set initial time
// Sets it for both 12 and 24 hour clock
void SetTime() {
	int clockChoice;
	cout << "Welcome! Please set the time." << endl;
	cout << "Set time for a 12 or 24 hour clock?" << endl;
	cout << "1 = 12 hour clock" << endl;
	cout << "2 = 24 hour clock" << endl;

	// User picks 12 or 24 hour clock
	while (true) {
		cin >> clockChoice;
		if (clockChoice == 1 || clockChoice == 2) {
			break;
		}
		else {
			cout << "Invalid choice. Please enter 1 or 2." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	// Get user input to set time for 12 hour clock starting with hours
	if (clockChoice == 1) {
		while (true) {
			cout << "Hour: " << endl;
			cin >> hours;
			if (hours >= 1 && hours <= 12) {
				break;
			}
			else {
				cout << "Invalid hour. Please enter a value between 1 and 12." << endl;
			}
		}

		// Get minuites 
		while (true) {
			cout << "Minutes: " << endl;
			cin >> minutes;
			if (minutes >= 0 && minutes <= 59) {
				break;
			}
			else {
				cout << "Invalid minutes. Please enter a value between 0 and 59." << endl;
			}
		}

		// Get seconds
		while (true) {
			cout << "Seconds: " << endl;
			cin >> seconds;
			if (seconds >= 0 && seconds <= 59) {
				break;
			}
			else {
				cout << "Invalid seconds. Please enter a value between 0 and 59." << endl;
			}
		}
		// Get AM or PM
		while (true) {
			cout << "******AM or PM******" << endl;
			cout << "1 = AM ****** 2 = PM" << endl;
			cout << "********************" << endl;
			cin >> isAM;
			if (isAM == 1 || isAM == 2) {
				// Set AM or PM and adjusts time for 24 hour clock 
				if (isAM == 1) {
					timeNotion = "AM";
					hours24 = hours; // Sets hours for 24 hour clock
				}
				else if (isAM == 2) {
					timeNotion = "PM";
					hours24 = hours + 12; // Adjust hour for 24 hour clock
				}
				break;
			}
			else {
				cout << "Invalid input. Please try again." << endl;
			}

		}


	}

	// Get user input to set time for 24 hour clock starting with hours
	else if (clockChoice == 2) {
		while (true) {
			cout << "Hour: " << endl;
			cin >> hours24;
			if (hours24 >= 0 && hours24 <= 23) {
				// Changes hour for 12 hour clock
				if (hours24 > 12) {
					hours = hours24 - 12;
					timeNotion = "PM";
				}
				else if (hours24 < 12) {
					hours = hours24;
					timeNotion = "AM";
				}
				break;
			}
			else {
				cout << "Invalid hour. Please enter a value between 0 and 23." << endl;
			}
		}

		// Get minuites 
		while (true) {
			cout << "Minutes: " << endl;
			cin >> minutes;
			if (minutes >= 0 && minutes <= 59) {
				break;
			}
			else {
				cout << "Invalid minutes. Please enter a value between 0 and 59." << endl;
			}
		}

		// Get seconds
		while (true) {
			cout << "Seconds: " << endl;
			cin >> seconds;
			if (seconds >= 0 && seconds <= 59) {
				break;
			}
			else {
				cout << "Invalid seconds. Please enter a value between 0 and 59." << endl;
			}
		}
	}

}

// Add 1 hour 
void AddHour() {
	// Upadates 12 hour clock
	if (hours == 11) {
		if (timeNotion == "AM") {
			timeNotion = "PM"; // Switch AM to PM
		}
		else {
			timeNotion = "AM"; // Switch PM to AM
		}
	} 
	// Reset clcokc to 1
	if (hours == 12) {
		hours = 01;
	}
	else {
		hours += 1;
	}
	// Updates 24 hour clock
	if (hours24 >= 23) {
		cout << "Hour has taken you to the next day." << endl;
		hours24 = 00;
	}
	else {
		hours24 += 1;
	}
}


// Adds 1 minute
void AddMinute() {
	if (minutes == 59) {
		minutes = 00; // Reset minutes
		AddHour(); // Calls function to add hour
	}
	else {
		minutes += 1;
	}
}

// Adds 1 second
void AddSecond() {
	if (seconds == 59) {
		seconds = 00; // Reset seconds
		AddMinute(); // Calls function to add minute
	}
	else {
		seconds += 1;
	}
}


// Prints the menu
void mainMenu() {
	string message1 = "1-Add One Hour     ";
	string message2 = "2-Add One Minute   ";
	string message3 = "3-Add One Second   ";
	string message4 = "4-Exit Program     ";


	cout << "            ***********************" << endl;
	cout << "            **" << message1 << "**" << endl;
	cout << "            **" << message2 << "**" << endl;
	cout << "            **" << message3 << "**" << endl;
	cout << "            **" << message4 << "**" << endl;
	cout << "            ***********************" << endl;

}

// Prints the 12 and 24 hour clock side by side 
void PrintClock() {

	cout << "*************************  *************************" << endl;
	cout << "*      12-Hour Clock    *  *       24-Hour Clock   *" << endl;
	cout << "*        " << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes; // 12 Hour Clock start
	cout << ":" << setw(2) << setfill('0') << seconds << " " << timeNotion << "    *";
	cout << "  *        " << setw(2) << setfill('0') << hours24 << ":" << setw(2) << setfill('0') << minutes; // 24 Hour Clock start
	cout << ":" << setw(2) << setfill('0') << seconds << "       *" << endl;
	cout << "*************************  *************************" << endl;
}


int main() {
	int userInput;

	// Allow user to set initial time
	SetTime();

	// Main program loop
	do {
		PrintClock();
		mainMenu();
		cin >> userInput;

		if (userInput == 1) {
			AddHour();

		}
		else if (userInput == 2) {
			AddMinute();

		}
		else if (userInput == 3) {
			AddSecond();

		}
		else if (userInput == 4) {
			cout << "Exited the program" << endl;
		}
		else {
			cout << "Invalid input." << endl;
		}
	} while (userInput != 4);

	return 0;
}

