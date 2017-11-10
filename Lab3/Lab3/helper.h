#pragma once
// Header.h
//
// Author: Roy Huang xiaolin.huang@wustl.edu
//
// Purpose: Declare enum index for
// 				array indices in argv
//			    number of command line arguments
//
//			Declare enum state for
//				success and failure return values of the program

#ifndef HEADER_H
#define HEADER_H

enum index {
	PROGRAM = 0,
	INPUT_FILE = 1,
	NUMBER_OF_ARGUMENTS = 2
};

enum state {
	SUCCESS = 0,
	DRAW = 1,
	QUIT = 2,
	WRONG_NUMBER_OF_ARGUMENTS = 3,
	WRONG_ARGUMENTS = 4
};

#endif
