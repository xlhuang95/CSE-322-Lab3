#include "stdafx.h"
#include "tictactoe.h"
#include "helper.h"
#include <iomanip>

// tictactoe constructor
TicTacToe::TicTacToe() {
	symbol1 = "X";
	symbol2 = "O";
	row = 5;
	col = 5;
	streak = 3;
	for (int i = 0; i < row + 2; ++i) {
		vector<string> temp;
		pieces.push_back(temp);
		for (int j = 0; j < col + 2; ++j) {
			pieces[i].push_back("");
		}
	}
}

// overload insertion operator
ostream & operator << (ostream &out, const TicTacToe &g) {
	cout << "print" << endl;
	for (int row = g.row + 1; row >= 0; --row) {	// print rows in opposite
		out << left << setw(g.longestString + 1) << row;
		for (int col = 0; col <= g.col + 1; col++) {
			out << left << setw(g.longestString + 1) << g.pieces[col][row];
		}
		out << endl;
	}
	out << setw(g.longestString + 1) << " ";
	for (int i = 0; i <= g.col + 1; i++) {
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
	size_t max_test = row - streak;
	for (size_t i = 0; i < max_test; i++)
	{
		for (size_t j = 0; j < max_test; j++)
		{
			int rowCt = 0;
			int colCt = 0;
			int lDCt = 0;
			int rDCt = 0;
			for (size_t k = 0; k < streak; k++)
			{
				// check row
				if (pieces[i][j + k] == pieces[i][j])
				{
					rowCt++;
					if (rowCt == streak)
					{
						return true;
					}
				}

				// check col
				if (pieces[i + k][j] == pieces[i][j])
				{
					colCt++;
					if (colCt == streak)
					{
						return true;
					}
				}

				// check diagonal from the left  
				if (pieces[i + k][j + k] == pieces[i][j])
				{
					lDCt++;
					if (lDCt == streak)
					{
						return true;
					}
				}

				// check diagonal from the right
				if (pieces[row - i - 1 - k][row - j - 1 - k] == pieces[row - i - 1][row - j - 1])
				{
					rDCt++;
					if (rDCt == row)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

// override draw
bool TicTacToe::draw() {
	bool empty = false;
	for (int i = 1; i <= col; ++i) {
		for (int j = 1; j <= row; ++j) {
			if (pieces[i][j] == "")
				empty = true;	// is empty as long as one position is empty
		}
	}
	return !(empty || done());	// if the game if not empty or done
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