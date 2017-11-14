#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "helper.h"
#include "gamebase.h"
#include "tictactoe.h"
#include "gomoku.h"

using namespace std;


// move struct constructor
Move::Move(int r, int c) {
	row = r;
	col = c;
};

// prompt method
int GameBase::prompt(unsigned int &col, unsigned int &row) {
	while (true) {
		cout << "Please enter a valid move in column,row or enter quit to end game." << endl;
		string line;
		getline(cin, line);
		if (line == "quit") {	// quit detected, abort
			return QUIT;
		}
		replace(line.begin(), line.end(), ',', ' ');	// replace every ',' with ' '
		istringstream iss(line);
		int tCol, tRow;
		if (iss >> tCol >> tRow) {	// if successfully extracted a col and a row number
			if (tCol >= 1 && tCol <= 3 && tRow >= 1 && tRow <= 3) {	// if the coordinate is within range
				if (pieces[tCol][tRow] == "") {	// if the position is not occupied yet
					col = tCol;
					row = tRow;
					return SUCCESS;	// move validated
				}
			}
		}
		cout << "prompt" << endl;
	}
}

// play method
int GameBase::play() {
	print();	// print board
	longestString = (int)max(symbol1.length(), symbol2.length());
	do {	// take turns
		if (turn() == QUIT) {	// quit detected, abort
			cout << player1.size() + player2.size() << " turns were played. "
				<< "Player quit.";
			return QUIT;
		}
	} while (!(done() || draw()));	// as long as not draw or done

	if (done()) {	// done detected
		if (currentPlayer == 1) {	// O wins
			cout << "Player "<<symbol2<<" wins.";
		}
		else {					// X wins
			cout << "Player " << symbol1 << " wins.";
		}
		return SUCCESS;
	}

	else {	// draw detected
		cout << player1.size() + player2.size() << " turns were played. "
			<< "No winning moves remain.";
		return DRAW;
	}
}

// checkInput method
GameBase * GameBase::checkInput(int n, char * c[]) {
	if (n == NUMBER_OF_ARGUMENTS && (string)c[INPUT_FILE] == "TicTacToe") {
		cout << "doIt" << endl;
		return new TicTacToe;
	}
	else if (n == NUMBER_OF_ARGUMENTS && (string)c[INPUT_FILE] == "Gomoku") {
		return new Gomoku;
	}
	else {
		return 0;
	}
}





