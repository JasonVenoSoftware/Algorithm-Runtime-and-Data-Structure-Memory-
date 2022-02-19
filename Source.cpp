// CS260 Project Two
// Jason Veno
// Chosen structure: Vector
// Submission date: 2/17/2022

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Course { // Courses
	string courseNumber;
	string courseName;
	vector<string> prereqs;
};

vector<Course> ReadFile(string file) { // Reads file, each line into Course struct, each Course into vector courses
	ifstream inFile;
	Course course;
	string line;
	vector<Course> courses;

	inFile.open(file);

	if (!inFile.is_open()) { // Error
		cout << "Couldn't open file" << endl;
	}

	while (!inFile.fail()) {
		getline(inFile, line);

		// Separate by comma start
		vector<string> result;
		stringstream s_stream(line);
		while (s_stream.good()) {
			string substr;
			getline(s_stream, substr, ',');
			result.push_back(substr);
		}
		// Separate by comma end

		course.courseNumber = result.at(0);
		course.courseName = result.at(1);	

		for (int i = 2; i < result.size(); i++) { // Loop to get all prereqs
			course.prereqs.push_back(result.at(i));
		}

		courses.push_back(course); // Adds each Course to courses vector, including prerequisites

		course.prereqs.clear(); // Prevents prereqs from storing elements from previous Node

		if (inFile.eof()) { // Makes last line not duplicate
			break;
		}
	}

	inFile.close();

	return courses;
}

bool Courses_Sorter(Course left, Course right) { // Comparison function, tells sort() how to sort Courses 
	return left.courseNumber < right.courseNumber;
}

void PrintCourseList(vector<Course> courses) { // Prints every Course's number and name
	for (int i = 0; i < courses.size(); i++) {
		cout << courses[i].courseNumber << ", " << courses[i].courseName << endl;
	}
}

void PrintCourse(vector<Course> courses, Course course) { // Search courses for course, print with prereqs		
	for (int i = 0; i < courses.size(); ++i) {
		if (courses[i].courseNumber == course.courseNumber) {
			cout << courses[i].courseNumber << ", " << courses[i].courseName << endl;
			if (courses[i].prereqs.size() > 0) {
				cout << "Prerequisites: ";
				for (int j = 0; j < courses[i].prereqs.size(); ++j) {
					cout << courses[i].prereqs[j] << " ";
				}
				cout << endl;
			}
		}
	}		
}

int main() {
	vector<Course> courses;

	int userChoice = 0;
	while (userChoice != 9) {
		cout << "Course planner: " << endl;
		cout << "1: Load Vector" << endl;
		cout << "2: Print Course List" << endl;
		cout << "3: Print Course" << endl;
		cout << "9: Exit" << endl;
		cout << "Choose an option: " << endl;
		cin >> userChoice;

		switch (userChoice) {
		case 1:
		{ // Brackets allows initialization inside of the switch
			cout << "Type name of file you wish to open: " << endl;
			string fileName;
			cin >> fileName;
			courses = ReadFile(fileName);

			cout << endl;
			cout << "File has been read" << endl;
			cout << endl;

			break;
		}
		case 2:
			cout << endl;

			sort(courses.begin(), courses.end(), Courses_Sorter); // Sorts vector
			PrintCourseList(courses);

			cout << endl;
			break;
		case 3:
			cout << "Type course number (mind the spelling and capitalization)" << endl;
			string userCourseNumber;
			cin >> userCourseNumber;

			cout << endl;

			Course key_course;
			key_course.courseNumber = userCourseNumber;

			PrintCourse(courses, key_course);
			cout << endl;
			break;
		}
	}
}
