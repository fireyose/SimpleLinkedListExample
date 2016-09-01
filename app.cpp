/* Author:            Youssef Almkari                                                */
/* Creation Date:     August 28th, 2014                                              */
/* Due Date:          September 4th, 2014                                            */
/* Course:            CSC237                                                         */
/* Professor Name:    Dr. Schaper                                                    */
/* Assignment:        #1                                                             */
/* File Name:          app.cpp                                                       */
/* Purpose:           To read in integers from external file to Object Linked List   */
/*                    then output to external file the integers larger than the last */
/*                    integer stored.                                                */

#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

/** Prototypes **/
void openInputFile(string &, ifstream &);
void readFile(LinkedList &, ifstream &);
void openOutputFile(string &, ofstream &);
void printToFile(ofstream &, LinkedList &);

int main() {
	string inputFilename = "data.txt";
	string outputFilename = "result.txt";
	ifstream infile;  
	ofstream outfile;
	LinkedList List;
	
	// Process Begin
	openInputFile(inputFilename, infile);
	readFile(List, infile);
	openOutputFile(outputFilename, outfile);
	printToFile(outfile, List);
	// Process End
	
	// close file streams
	infile.close();
	outfile.close();
}

/* Function name:  openFile                                         */
/* Description:    Open file input stream                           */
/* Parameters:     string   &file: file name         - input        */
/*                 ifstream &inf : input file stream - input/output */
/* Return Value:   void                                             */

void openInputFile(string &file, ifstream &inf) {
	inf.open(file.c_str());
	if (inf.fail())
		cout << "File was not found in directory.\n\n" << endl;
	else
		cout << "Input File Found.\n\n" << endl;
}

/* Function name:  readFile                                                */
/* Description:    Add integers to LinkedList                              */
/* Parameters:     LinkedList &list : represents LinkedList - input/output */
/*                 ifstream    &inf : input file stream     - input        */
/* Return Value:   void                                                    */

void readFile(LinkedList &list, ifstream &inf) {
	int num;
	while(!inf.eof()) {
		inf >> num;
		list.append(num);
	}
}

/* Function name:  openOutputFile                                    */
/* Description:    Open file output stream                           */
/* Parameters:     string  &file : file name          - input        */
/*                 ofstream &ofs : output file stream - input/output */
/* Return Value:   void                                              */

void openOutputFile(string &file, ofstream &ofs) {
	ofs.open(file.c_str());
	if (ofs.fail())
		cout << "File was not found in directory.\n\n" << endl;
	else
		cout << "Output File Found.\n\n" << endl;
}

/* Function name:  printToFile                                         */
/* Description:    Print LinkedList to file                            */
/* Parameters:     ofstream    &ofs : holds output file stream - input */
/*                 LinkedList &list : represents LinkedList    - input */
/* Return Value:   void                                                */

void printToFile(ofstream &ofs, LinkedList &list) {
	ofs << list;
	
	cout << "\nProcess Complete!\n";
	cout << "Check 'result.txt' file.\n";
}
