/*
tictactoe.cpp

Purpose: Definition of derived class TicTacToe

Author:
Roy Huang   xiaolin.huang@wustl.edu;
Jerry Kong  jerry.kong@wustl.edu;
Fangchen Li fangchen.li@wustl.edu

Date: 11/16/2017
*/

#include "stdafx.h"
#include "tictactoe.h"
#include "helper.h"
#include <iomanip>
#include <algorithm>

// tictactoe default constructor. init a 3 by 3 game board
TicTacToe::TicTacToe() {
	symbol1 = "X";
	symbol2 = "O";
	row = 3;
	col = 3;
	streak = 3;
	longestString = max(symbol1.length(), symbol2.length());
	// init game board
	for (size_t i = 0; i < row + 2; ++i) {
		vector<string> temp;
		pieces.push_back(temp);
		for (size_t j = 0; j < col + 2; ++j) {
			pieces[i].push_back(empty);
		}
	}
}

// overload ostream insertion operator
ostream & operator << (ostream &out, const TicTacToe &g) {
	for (size_t row = g.row + 1; row >= 0; --row) {	// print rows in opposite
		out << left << setw(g.longestString + 1) << row;
		for (size_t col = 0; col <= g.col + 1; col++) {
			out << left << setw(g.longestString + 1) << g.pieces[col][row];
		}
		out << endl;
	}
	out << setw(g.longestString + 1) << " ";
	for (size_t i = 0; i <= g.col + 1; i++) {
		out << left << setw(g.longestString + 1) << i;
	}
	out << endl;
	return out;
}


// override print
void TicTacToe::print() {
	cout << *this;
}

// override done
bool TicTacToe::done() {
	// test row
	for (size_t j = 1; j <= row; ++j) {
		for (size_t i = 1; i <= col - streak + 1; ++i) {
			bool win = true;
			for (size_t k = i + 1; k <= i + streak - 1; ++k) {
				if ((pieces[k][j] != pieces[k - 1][j]) || pieces[k][j] == empty) {
					win = false;
				}
			}
			if (win) {
				return true;
			}
		}
	}

	// test col
	for (size_t i = 1; i <= col; ++i) {
		for (size_t j = 1; j <= row - streak + 1; ++j) {
			bool win = true;
			for (size_t k = j + 1; k <= j + streak - 1; ++k) {
				if ((pieces[i][k] != pieces[i][k - 1]) || pieces[i][k] == empty) {
					win = false;
				}
			}
			if (win) {
				return true;
			}
		}
	}

	// test diagonal
	for (size_t i = 1; i <= col - streak + 1; ++i) {
		for (size_t j = row; j >= streak; --j) {
			bool win = true;
			for (size_t k = 0; k <= streak - 2; ++k) {
				if ((pieces[i + k][j - k] != pieces[i + k + 1][j - k - 1]) || pieces[i + k][j - k] == empty) {
					win = false;
				}
			}
			if (win) {
				return true;
			}
		}
	}

	for (size_t i = streak; i >= streak; --i) {
		for (size_t j = row; j >= streak; --j) {
			bool win = true;
			for (size_t k = 0; k <= streak - 2; ++k) {
				if ((pieces[i - k][j - k] != pieces[i - k - 1][j - k - 1]) || pieces[i - k][j - k] == empty) {
					win = false;
				}
			}
			if (win) {
				return true;
			}
		}
	}
	return false;
}

// override draw
bool TicTacToe::draw() {
	TicTacToe temp1 = *this;
	TicTacToe temp2 = *this;
	for (size_t i = 1; i <= col; ++i) {
		for (size_t j = 1; j <= row; ++j) {
			if (temp1.pieces[i][j] == empty) {
				temp1.pieces[i][j] = symbol1;
			}
			if (temp2.pieces[i][j] == empty) {
				temp2.pieces[i][j] = symbol2;
			}
		}
	}
	return !(temp1.done() || temp2.done());
}


// override turn
int TicTacToe::turn() {
	if (currentPlayer == 1) {	// Player 1's turn
		cout << "Now it's player X's turn" << endl;
	}
	else {				  	// O's turn
		cout << "Now it's player O's turn" << endl;
	}

	unsigned int col, row;
	int promptValue = prompt(col, row);	// return value from prompt
	if (promptValue == QUIT) {	// prompt returns quit, abort
		return QUIT;
	}

	if (currentPlayer == 1) {	// Player 1's turn
		pieces[col][row] = symbol1;			// mark piece in position
		cout << *this;					// print board
		player1.push_back(Move(col, row));	// push move in the sequence
		cout << "Player " << symbol1 << ":";
		for (auto const& value : player1) {
			cout << value.col << "," << value.row << "; ";	// print every move in the sequence
		}
		cout << endl << endl;
		currentPlayer = 2;	// change turn
		return SUCCESS;
	}
	else {				  	// O's turn
		pieces[col][row] = symbol2;
		cout << *this;
		player2.push_back(Move(col, row));
		cout << "Player " << symbol2 << ":";
		for (auto const& value : player2) {
			cout << value.col << "," << value.row << "; ";
		}
		cout << endl << endl;
		currentPlayer = 1;
		return SUCCESS;
	}
}