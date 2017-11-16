#include "stdafx.h"
#include "tictactoe.h"
#include "helper.h"
#include <iomanip>

// tictactoe constructor
TicTacToe::TicTacToe() {
	symbol1 = "X";
	symbol2 = "O";
	row = 3;
	col = 3;
	streak = 3;
	// init game board
	for (unsigned int i = 0; i < row + 2; ++i) {
		vector<string> temp;
		pieces.push_back(temp);
		for (unsigned int j = 0; j < col + 2; ++j) {
			pieces[i].push_back(empty);
		}
	}
}

// overload insertion operator
ostream & operator << (ostream &out, const TicTacToe &g) {
	for (int row = g.row + 1; row >= 0; --row) {	// print rows in opposite
		out << left << setw(g.longestString + 1) << row;
		for (unsigned int col = 0; col <= g.col + 1; col++) {
			out << left << setw(g.longestString + 1) << g.pieces[col][row];
		}
		out << endl;
	}
	out << setw(g.longestString + 1) << " ";
	for (unsigned int i = 0; i <= g.col + 1; i++) {
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