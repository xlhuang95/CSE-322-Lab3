#include "stdafx.h"
#include "gomoku.h"
#include <iomanip>
#include "helper.h"

// default constructor with dimension of 19 and winning streak of 5
Gomoku::Gomoku(){
	symbol1 = "B";
	symbol2 = "W";
	row = 19;
	col = 19;
	streak = 5;
	for (unsigned int i = 0; i < row+1; ++i) {
		vector<string> temp;
		pieces.push_back(temp);
		for (unsigned int j = 0; j < col+1; ++j) {
			pieces[i].push_back(empty);
		}
	}
}

/**
*  Gomoku constructor.
*   
*  @ d is the dimension of the game board
*  @ s is winning streak 
*/
Gomoku::Gomoku(int d, int s) {
	symbol1 = "B";
	symbol2 = "W";
	row = d;
	col = d;
	streak = s;
	for (unsigned int i = 0; i < row + 1; ++i) {
		vector<string> temp;
		pieces.push_back(temp);
		for (unsigned int j = 0; j < col + 1; ++j) {
			pieces[i].push_back(empty);
		}
	}
}

// print out the game board
void Gomoku::print() {
	cout << *this;
}

// overload insertion operator
ostream & operator<<(ostream& out, Gomoku g) {
	cout << "print" << endl;
	for (unsigned int row = g.row; row >0; --row) {	// print rows in opposite
		out << left << setw(g.longestString + 1) << row ;
		for (unsigned int col = 1; col < g.col+1; col++) {
			out << left << setw(g.longestString + 1) << g.pieces[col][row];
		}
		out << endl;
	}
	out << left << setw(g.longestString + 1) << "X";
	for (unsigned int i = 1; i < g.col+1; i++) {
		out << left << setw(g.longestString + 1) << i;
	}
	out << endl;
	return out;
}

// check if the game is finished with a winner
bool Gomoku::done() {
	// test row
	for (unsigned int j = 1; j <= row; ++j) {
		for (unsigned int i = 1; i <= col - streak + 1; ++i) {
			bool win = true;
			for (unsigned int k = i + 1; k <= i + streak - 1; ++k) {
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
	for (unsigned int i = 1; i <= col; ++i) {
		for (unsigned int j = 1; j <= row - streak + 1; ++j) {
			bool win = true;
			for (unsigned int k = j + 1; k <= j + streak - 1; ++k) {
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
	for (unsigned int i = 1; i <= col - streak + 1; ++i) {
		for (unsigned int j = row; j >= streak; --j) {
			bool win = true;
			for (unsigned int k = 0; k <= streak - 2; ++k) {
				if ((pieces[i + k][j - k] != pieces[i + k + 1][j - k - 1]) || pieces[i + k][j - k] == empty) {
					win = false;
				}
			}
			if (win) {
				return true;
			}
		}
	}

	for (unsigned int i = col; i >= streak; --i) {
		for (unsigned int j = row; j >= streak; --j) {
			bool win = true;
			for (unsigned int k = 0; k <= streak - 2; ++k) {
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

// check if the game is a draw
bool Gomoku::draw()
{
	Gomoku temp1 = *this;
	Gomoku temp2 = *this;
	for (unsigned int i = 1; i <= col; ++i) {
		for (unsigned int j = 1; j <= row; ++j) {
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

// override turn method
int Gomoku::turn() {
	if (currentPlayer == 1) {	// Player 1's turn
		cout << "Now it's player B's turn" << endl;
	}
	else {				  	// O's turn
		cout << "Now it's player W's turn" << endl;
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
