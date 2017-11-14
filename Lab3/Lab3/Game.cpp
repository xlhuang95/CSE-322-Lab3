#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "helper.h"
#include "Game.h"


using namespace std;

GameBase::GameBase(int r, int c) {
	row = r;
	col = c;

	cout << "game base constructor" << endl;
}

Move::Move(int col, int row) : col_(col), row_(row) {};

// start new game
int GameBase::play() {
	print();	// print board
	longestString = (int)max(s_player1.length(), s_player2.length());
	do {	// take turns
		if (turn() == QUIT) {	// quit detected, abort
			cout << player1.size() + player2.size() << " turns were played. "
				<< "Player quit.";
			return QUIT;
		}
	} while (!(done() || draw()));	// as long as not draw or done

	if (done()) {	// done detected
		if (currentPlayer == 1) {	// O wins
			cout << "Player "<<s_player2<<" wins.";
		}
		else {					// X wins
			cout << "Player " << s_player1 << " wins.";
		}
		return SUCCESS;
	}

	else {	// draw detected
		cout << player1.size() + player2.size() << " turns were played. "
			<< "No winning moves remain.";
		return DRAW;
	}
}


int GameBase::prompt(unsigned int &col, unsigned int &row) {
	while(true) {
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

GameBase * GameBase::doIt(int n, char * c[]) {
	if (n == NUMBER_OF_ARGUMENTS && (string)c[INPUT_FILE] == "TicTacToe") {
		cout << "doIt" << endl;
		return new TicTacToeGame;
	}
	else if (n == NUMBER_OF_ARGUMENTS && (string)c[INPUT_FILE] == "Gomoku") {
		return new GomokuGame;
	}
	else {
		return 0;
	}
}


TicTacToeGame::TicTacToeGame() : GameBase(3, 3){
	s_player1 = "X";
	s_player2 = "O";
	for (int i = 0; i < row + 2; ++i) {
		vector<string> temp;
		pieces.push_back(temp);
		for (int j = 0; j < col + 2; ++j) {
			pieces[i].push_back("");
		}
	}
}


ostream & operator << (ostream &out, const TicTacToeGame &g) {
	cout << "print" << endl;
	for (int row = g.row+1; row >= 0; --row) {	// print rows in opposite
		out << left<<setw(g.longestString+1)<<row;
		for (int col = 0; col <= g.col+1; col++) {
			out <<  left<<setw(g.longestString+1)<<g.pieces[col][row] ;
		}
		out << endl;
	}
	out << setw(g.longestString+1)<<" ";
	for (int i = 0; i <= g.col+1; i++) {
		out <<left<<setw(g.longestString+1)<<i ;
	}
	out << endl;
	return out;
}



void TicTacToeGame::print() {
	cout << *this;
}

bool TicTacToeGame::done() {
	if (player1.size() + player2.size()<2) {
		return false;
	}
	bool result = false;
	int player1_count = 0;
	int player2_count = 0;
	for (int i = 1; i <= row; ++i) {
		player1_count = 0;
		player2_count = 0;
		for (int j = 1; j <= col; ++j) {
			if (pieces[i][j] == s_player1) {
				player1_count++;
			}
			else if (pieces[i][j] == s_player2) {
				player2_count++;
			}
		}
		if (player1_count == 3 || player2_count == 3) {
			result = true;
		}
	}
	for (int i = 1; i <= col; ++i) {
		player1_count = 0;
		player2_count = 0;
		for (int j = 1; j <= row; ++j) {
			if (pieces[i][j] == s_player1) {
				player1_count++;
			}
			else if (pieces[i][j] == s_player2) {
				player2_count++;
			}
		}
		if (player1_count == 3 || player2_count == 3) {
			result = true;
		}
	}
	player1_count = 0;
	player2_count = 0;
	for (int i = 1; i <= col; ++i) {
		if (pieces[i][i] == s_player1) {
			player1_count++;
		}
		else if (pieces[i][i] == s_player2) {
			player2_count++;
		}
	}
	if (player1_count == 3 || player2_count == 3) {
		result = true;
	}
	player1_count = 0;
	player2_count = 0;
	for (int i = 1; i <= col; ++i) {
		if (pieces[4 - i][i] == s_player1) {
			player1_count++;
		}
		else if (pieces[4 - i][i] == s_player2) {
			player2_count++;
		}
	}
	if (player1_count == 3 || player2_count == 3) {
		result = true;
	}
	return result;
}


bool TicTacToeGame::draw() {
	bool empty = false;
	for (int i = 1; i <= col; ++i) {
		for (int j = 1; j <= row; ++j) {
			if (pieces[i][j] == "")
				empty = true;	// is empty as long as one position is empty
		}
	}
	return !(empty || done());	// if the game if not empty or done
}

int TicTacToeGame::turn() {

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
		pieces[col][row] = s_player1;			// mark piece in position
		cout << *this;					// print board
		player1.push_back(Move(col, row));	// push move in the sequence
		cout << "Player " << s_player1 << ":";
		for (auto const& value : player1) {
			cout << value.col_ << "," << value.row_ << "; ";	// print every move in the sequence
		}
		cout << endl << endl;
		currentPlayer = 2;	// change turn
		return SUCCESS;
	}
	else {				  	// O's turn
		pieces[col][row] = s_player2;
		cout << *this;
		player2.push_back(Move(col, row));
		cout << "Player " << s_player2 << ":";
		for (auto const& value : player2) {
			cout << value.col_ << "," << value.row_ << "; ";
		}
		cout << endl << endl;
		currentPlayer = 1;
		return SUCCESS;
	}
}


GomokuGame::GomokuGame() : GameBase(19, 19) {
	s_player1 = "B";
	s_player2 = "W";
	win_count = 5;
	for (int i = 0; i < row ; ++i) {
		vector<string> temp;
		pieces.push_back(temp);
		for (int j = 0; j < col; ++j) {
			pieces[i].push_back("");
		}
	}
	cout << "gomoku generator" << endl;
}


void GomokuGame::print() {
	cout << *this;
}

ostream & operator<<(ostream& out, GomokuGame g) {
	cout << "print" << endl;
	for (int row = g.row -1; row >= 0; --row) {	// print rows in opposite
		out << left << setw(g.longestString + 1) << row+1;
		for (int col = 0; col < g.col; col++) {
			out << left << setw(g.longestString + 1) << g.pieces[col][row];
		}
		out << endl;
	}
	out <<  left<< setw(g.longestString + 1)<<"X";
	for (int i = 0; i < g.col; i++) {
		out << left << setw(g.longestString + 1) << i+1;
	}
	out << endl;
	return out;
}

bool GomokuGame::done() {
	size_t max_test= row - win_count;
	for (size_t i = 0; i < max_test; i++)
	{
		for (size_t j = 0; j < max_test; j++)
		{
			int rowCt = 0;
			int colCt = 0;
			int lDCt = 0;
			int rDCt = 0;
			for (size_t k = 0; k < win_count; k++)
			{
				// check row
				if (pieces[i][j + k] == pieces[i][j])
				{
					rowCt++;
					if (rowCt == win_count)
					{
						return true;
					}
				}

				// check col
				if (pieces[i + k][j] == pieces[i][j])
				{
					colCt++;
					if (colCt == win_count)
					{
						return true;
					}
				}

				// check diagonal from the left  
				if (pieces[i + k][j + k] == pieces[i][j])
				{
					lDCt++;
					if (lDCt == win_count)
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

bool GomokuGame::draw()
{
	bool winable = false;
	for (int i = 1; i <= col; ++i) {
		for (int j = 1; j <= row; ++j) {
			if (pieces[i][j] == "") {
				pieces[i][j] = "B";
				if (done()) {
					winable = true;
				}
				pieces[i][j] = "W";
				if (done()) {
					winable = true;
				}
				pieces[i][j] = "";
			}	// is empty as long as one position is empty
		}
	}
	return !(winable || done());
}

int GomokuGame::turn() {
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
		pieces[col][row] = s_player1;			// mark piece in position
		cout << *this;					// print board
		player1.push_back(Move(col, row));	// push move in the sequence
		cout << "Player " << s_player1 << ":";
		for (auto const& value : player1) {
			cout << value.col_ << "," << value.row_ << "; ";	// print every move in the sequence
		}
		cout << endl << endl;
		currentPlayer = 2;	// change turn
		return SUCCESS;
	}
	else {				  	// O's turn
		pieces[col][row] = s_player2;
		cout << *this;
		player2.push_back(Move(col, row));
		cout << "Player " << s_player2 << ":";
		for (auto const& value : player2) {
			cout << value.col_ << "," << value.row_ << "; ";
		}
		cout << endl << endl;
		currentPlayer = 1;
		return SUCCESS;
	}
}
