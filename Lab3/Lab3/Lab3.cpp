/*
Lab3.cpp

Purpose: Definition of the entry point for the console application.

Author:
Roy Huang   xiaolin.huang@wustl.edu;
Jerry Kong  jerry.kong@wustl.edu;
Fangchen Li fangchen.li@wustl.edu

Date: 11/16/2017
*/

#include "stdafx.h"
#include "gamebase.h"
#include "tictactoe.h"
#include "gomoku.h"
#include "helper.h"
#include <string>
#include <memory>

using namespace std;

int main(int argc, char * argv[]) {
	// check number of arguments and entered dimension and winning streak
	if (argc == NUMBER_OF_ARGUMENTS_GOMOKU_BOARD || argc == NUMBER_OF_ARGUMENTS_GOMOKU_BOARD_STREAK) {
		if (argv[DIMENSION] <= 0) {
			cout << "Error: Dimension is 0 or negative." << endl;
			return WRONG_DIMENSION;
		}
	}
	try {
		GameBase * game = GameBase::checkInput(argc, argv);

		// print out usage message if inputs are invalid
		if (game == 0) {
			usage(argv[PROGRAM]);
			return WRONG_ARGUMENTS;
		}
		else {
			shared_ptr<GameBase> g;
			string name = argv[GAMENAME];
			if (name == "TicTacToe") {
				TicTacToe * tictactoe = dynamic_cast<TicTacToe*>(game);
				g = make_shared<TicTacToe>(*tictactoe);
			}
			else if (name == "Gomoku") {
				Gomoku * gomoku = dynamic_cast<Gomoku*>(game);
				g = make_shared<Gomoku>(*gomoku);
			}
			// play game
			try {
				g->play();
			}
			// catch quit exception
			catch (const invalid_argument & e) {
				cerr << e.what() << endl;
				return QUIT;
			}
		}
	}
	// catch bad allocation exception
	catch (bad_alloc) {
		return BAD_ALLOCATION;
	}
	return SUCCESS;
}

