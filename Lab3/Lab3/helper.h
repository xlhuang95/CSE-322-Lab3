/*
helper.h

Author: Roy Huang xiaolin.huang@wustl.edu; Jerry Kong jerry.kong@wustl.edu; Fangchen Li fangchen.li@wustl.edu

Purpose: Declaration of enumeration for command argument indeces and return values
		 Definition of usage function
*/

#ifndef HELPER_H
#define HELPER_H

#include <string>

enum index {
	PROGRAM = 0,
	INPUT_FILE = 1,
	NUMBER_OF_ARGUMENTS = 2,
	NUMBER_OF_ARGUMENTS_GOMOKU_BOARD = 3,
	NUMBER_OF_ARGUMENTS_GOMOKU_BOARD_STREAK = 4,
	DIMENSION = 2,
	STREAK = 3
};

enum state {
	SUCCESS = 0,
	DRAW = 1,
	QUIT = 2,
	WRONG_NUMBER_OF_ARGUMENTS = 3,
	WRONG_ARGUMENTS = 4,
	BAD_ALLOCATION = 5
};

// print out usage message
void usage(char * program_name);

#endif
