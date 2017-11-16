/*
helper.cpp

Purpose: Definition of usage class

Author:
Roy Huang   xiaolin.huang@wustl.edu;
Jerry Kong  jerry.kong@wustl.edu;
Fangchen Li fangchen.li@wustl.edu

Date: 11/16/2017
*/

#include "stdafx.h"
#include "helper.h"
#include <iostream>
#include <string>

using namespace std;

// print out usage message
void usage(char * program_name) {
	cout << "Usage: " << endl
		<< program_name << " TicTacToe" << endl
		<< "or " << endl
		<< program_name << " Gomoku [Dimension] [Streak]" << endl
		<< "Dimension > 0, Streak > 0, and Dimention >= Streal" << endl
		<< "This program starts a boardgame." << endl;
}