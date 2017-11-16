/*
helper.cpp

Author: Roy Huang xiaolin.huang@wustl.edu; Jerry Kong jerry.kong@wustl.edu; Fangchen Li fangchen.li@wustl.edu

Purpose: Definition of usage class
*/

#include "stdafx.h"
#include "helper.h"
#include <iostream>
#include <string>

using namespace std;

// print out usage message
void usage(char * program_name) {
	cout << "Usage: " << program_name << " TicTacToe" << endl 
		 << "or " << program_name << " Gomoku (Dimension) (Streak)" << endl
		 << "This program starts a boardgame."
		 << endl;
}