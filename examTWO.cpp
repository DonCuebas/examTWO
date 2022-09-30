// Your Name: Don-Omar Cuebas
// Date: 9/30/22
// Program Title: Weighted Grade
// Program Description: This program calculates a student's grade based on weighted categories.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Named constants
const double HW_PERCENT = .35;
const double QUIZ_PERCENT = .25;
const double EXAM_PERCENT = .40;

int main()
{

	// Variable declaration
	int choice;
	string name;
	double hwAverage, quizAverage, examAverage;
	double hwWeight, quizWeight, examWeight;
	double grade, pointsNeeded;

	// Declare file stream variables
	ofstream outData;

	// Open the output file
	outData.open("grade_output.txt");

	//Program title and description for the user
	cout << "This program calculates a student's grade based on weighted categories." << endl;

	// User input
	cout << "\nWhat is your name?" << endl;
	getline(cin, name);

	cout << "\nWhat is the percentage of your grade average for homework?" << endl;
	cin >> hwAverage;

	cout << "\nWhat is the percentage of your grade average for quizzes?" << endl;
	cin >> quizAverage;

	cout << "\nWhat is the percentage of your grade average for exams?" << endl;
	cin >> examAverage;

	// Calculations
	hwWeight = hwAverage * HW_PERCENT;
	quizWeight = quizAverage * QUIZ_PERCENT;
	examWeight = examAverage * EXAM_PERCENT;
	grade = hwWeight + quizWeight + examWeight;
	pointsNeeded = 60 - grade;

	// Output to output file and screen
	outData << "Grade Report for " << name << endl;

	outData << "\nRecall that you need a grade of at least 60% to pass the class." << endl << endl;

	outData << fixed << showpoint << setprecision(1);
	outData << setw(11) << left << "Homework" << hwAverage << "%" << endl;
	outData << setw(11) << left << "Quizzes" << quizAverage << "%" << endl;
	outData << setw(11) << left << "Exams" << examAverage << "%" << endl;
	outData << setw(11) << left << "Grade" << grade << "%" << endl;

	if (grade >= 60) {
		outData << "\nYou are passing the class. Good job!" << endl;
		cout << "\nPlease check the 'grade_output.txt' file." << endl;
	}
	else if (grade < 60) {
		outData << "\nYou are not passing the class." << endl;
		outData << "You need to raise your grade percentage by " << pointsNeeded << " points to pass." << endl;
		cout << "\nPlease check the 'grade_output.txt' file." << endl;
	}
	else {
		cout << "\nInput error; program terminating" << endl;
		return 1;
	}

	return 0;
}
