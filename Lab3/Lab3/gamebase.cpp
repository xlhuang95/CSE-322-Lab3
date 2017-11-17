/*
gamebase.cpp

Purpose: Definition of base class GameBase

Author: 
Roy Huang   xiaolin.huang@wustl.edu; 
Jerry Kong  jerry.kong@wustl.edu;
Fangchen Li fangchen.li@wustl.edu

Date: 11/16/2017
*/

#include "stdafx.h"
#include "helper.h"
#include "gamebase.h"
#include "tictactoe.h"
#include "gomoku.h"
#include <sstream>
#include <algorithm>

using namespace std;


// move struct constructor
Move::Move(int c, int r) {
	col = c;
	row = r;
};

// prompt method, ask user to enter next move
int GameBase::prompt(unsigned int &col, unsigned int &row) {
	while (true) {
		cout << "Please enter a valid move in column,row or enter quit to end game." << endl;
		string line;
		getline(cin, line);

		if (line == "quit") {	// quit detected, abort
			throw invalid_argument("User entered quit");
		}
		replace(line.begin(), line.end(), ',', ' ');	// replace every ',' with ' '
		istringstream iss(line);
		unsigned int tCol, tRow;
		if (iss >> tCol >> tRow) {	// if successfully extracted a col and a row number
			if (tCol >= 1 && tCol <= col && tRow >= 1 && tRow <= row) {	// if the coordinate is within range
				if (pieces[tCol][tRow] == empty) {	// if the position is not occupied yet
					col = tCol;
					row = tRow;
					return SUCCESS;	// move validated
				}
			}
		}
	}
}

// play method, start the game
int GameBase::play() {
	print();	// print board
	longestString = max(symbol1.length(), symbol2.length());

	// take turns
	do {
		// quit detected, abort
		if (turn() == QUIT) {	
			cout << player1.size() + player2.size() << " turns were played. "
				<< "Player quit.";
			return QUIT;
		}
	} while (!(done() || draw()));	// as long as not draw or done

	// done detected
	if (done()) {
		// O wins
		if (currentPlayer == 1) {	
			cout << "Player "<< symbol2 << " wins.";
		}
		// X wins
		else {					
			cout << "Player " << symbol1 << " wins.";
		}
		return SUCCESS;
	}
	// draw detected
	else {	
		cout << player1.size() + player2.size() << " turns were played. "
			<< "No winning moves remain.";
		return DRAW;
	}
}

// check user input and create game according to user input
GameBase * GameBase::checkInput(int n, char * c[]) {
	string gameName;
	if (n >= MIN_NUMBER_OF_ARGUMENTS) {
		gameName = c[GAMENAME];
	}
	// if user input is TicTacToe, return a new TicTacToe game object
	if (gameName == "TicTacToe" && n == NUMBER_OF_ARGUMENTS) {
		return new TicTacToe;
	}
	// if user input is Gomoku, return a new Gomoku game object
	else if (gameName == "Gomoku") {
		// user enter no additional argumenmt, enter default mode
		if (n == NUMBER_OF_ARGUMENTS)
		{
			return new Gomoku;
		}
		// user enter one additional argument, specify the game dimensions
		else if (n == NUMBER_OF_ARGUMENTS_GOMOKU_BOARD)
		{
			string s = c[DIMENSION];
			istringstream iss(s);
			int dim;
			if (iss >> dim) {
				if (dim < 5) {
					return new Gomoku(dim, dim);
				}
				else {
					return new Gomoku(dim, 5);
				}
			}
		}
		// user enter two additional argument, specify the game dimensions and winning streak
		else if (n == NUMBER_OF_ARGUMENTS_GOMOKU_BOARD_STREAK)
		{
			string d = c[DIMENSION];
			string s = c[STREAK];
			istringstream iss(d);
			istringstream iss0(s);
			int dim;
			int streak;
			if (iss >> dim && iss0 >> streak) {
				if (dim >= streak) {
					return new Gomoku(dim, streak);
				}
			}
		}
	}
	return 0;
}





