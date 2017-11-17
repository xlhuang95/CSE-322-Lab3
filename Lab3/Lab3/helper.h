/*
helper.h

Purpose: Declaration of enumeration for command argument indices and return values
         Declaration of usage function

Author:
Roy Huang   xiaolin.huang@wustl.edu;
Jerry Kong  jerry.kong@wustl.edu;
Fangchen Li fangchen.li@wustl.edu

Date: 11/16/2017
*/

#ifndef HELPER_H
#define HELPER_H

#include <string>

enum index {
	PROGRAM = 0,
	GAMENAME = 1,
	DIMENSION = 2,
	STREAK = 3
};

enum argument {
	NUMBER_OF_ARGUMENTS = 2,
	NUMBER_OF_ARGUMENTS_GOMOKU_BOARD = 3,
	NUMBER_OF_ARGUMENTS_GOMOKU_BOARD_STREAK = 4,
	MIN_NUMBER_OF_ARGUMENTS = 2,
	MAX_NUMBER_OF_ARGUMENTS = 4
};

enum state {
	SUCCESS = 0,
	DRAW = 1,
	QUIT = 2,
	WRONG_ARGUMENTS = 3,
	BAD_ALLOCATION = 4,
	WRONG_DIMENSION = 5
};

// print out usage message
void usage(char * program_name);

#endif
