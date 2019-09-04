// Blake Wilson
// CMPS 1063
// 9/3/2019

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Struct: Student contains 
// fname = first name
// lname = last name
// numGrades = number of grades inputed from student
// grades[10] = grades from student

struct Student {
	string fname;
	string lname;
	int numGrades;
	int grades[10];
};

//	Function: loadClassList
// Opens file containing class listand grades.
// Read fileand load into array "students".
// Return Number of students

int loadClassList(Student* classList, string fileName) {
	ifstream infile;			//Stream Variable
	infile.open(fileName);		//Open file to be read
	int i = 0;					//Initialize index. # of students.

	// While we have not reached the end of file
	while (!infile.eof()) {
		
		//Read 1 student at a time into 1 struct at array location 'i'
		infile >> classList[i].fname >> classList[i].lname >> classList[i].numGrades;

		for (int x = 0; x < classList[i].numGrades; x++) {

			infile >> classList[i].grades[x];
		}
		i++;
	}
		
	// returns inputed student count
	return i;
}
void printClasslist(Student* classList, int classSize) {
	ofstream outfile("ofile.txt");
	outfile << "Students" << '\n';
	outfile << "=================================" << '\n';
	for (int i = 0; i < classSize; i++) {
		outfile << i+1 << ". "  << classList[i].fname << " "
			<< classList[i].lname << ": ";
		for (int y = 0; y < classList[i].numGrades; y++) {
			outfile << right << setw(2) << classList[i].grades[y] << " ";
		}
		outfile << '\n';
	}
}

int main() {
	Student classList[100];
	int classSize = 0;

	// Call the loadClassList function to open a file and load an array
    // of `Student` structs.
	classSize = loadClassList(classList, "hw1.txt");

	// Function to print out an array of students in a formatted way.
	printClasslist(classList, classSize);

	system("pause");
	return 0;
}
