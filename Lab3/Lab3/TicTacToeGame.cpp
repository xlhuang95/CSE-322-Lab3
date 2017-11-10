#include "TicTacToeGame.h"
#include <iomanip>
#include "helper.h"
using namespace std;

ostream & operator << (ostream &out, const TicTacToeGame &g) {
	for (int row = g.row; row >= 0; row--) {	// print rows in opposite
		out << row<<setw(1);
		for (int col = 0; col <= g.col; col++) {
			out << g.pieces[col][row]<<setw(g.longestString+1-g.pieces[col][row].size());
		}
		out << endl;
	}
	out << setw(2);
	for (int i = 0; i <= g.col; i++) {
		out <<  i<<setw(g.longestString);
	}
	out << endl;
	return out;
}

void TicTacToeGame::print() {
	cout << *this;
}

bool TicTacToeGame::done() {
	if (player1.size()+player2.size()<2) {
		return false;
	}
	bool result = false;
	int player1_count = 0;
	int player2_count = 0;
	for (int i = 1; i <= row; ++i) {
		player1_count = 0;
		player2_count = 0;
		for (int j = 1; j <= col; ++j) {
			if (pieces[i][j] == player1[0]) {
				player1_count++;
			}
			else if (pieces[i][j] == player2[0]) {
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
			if (pieces[i][j] == player1[0]) {
				player1_count++;
			}
			else if (pieces[i][j] == player2[0]) {
				player2_count++;
			}
		}
		if (player1_count == 3 || player2_count == 3) {
			result = true;
		}
	}
	player1_count = 0;
	player2_count = 0;
	for(int i = 1;i<=col;++i){
		if (pieces[i][i] == player1[0]) {
			player1_count++;
		}
		else if (pieces[i][i] == player2[0]) {
			player2_count++;
		}
	}
	if (player1_count == 3 || player2_count == 3) {
		result = true;
	}
	player1_count = 0;
	player2_count = 0;
	for (int i = 1; i <= col; ++i) {
		if (pieces[4-i][i] == player1[0]) {
			player1_count++;
		}
		else if (pieces[4-i][i] == player2[0]) {
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
			if (pieces[i][j] == " ")
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
		player1.push_back(Move( col, row ));	// push move in the sequence
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
		player2.push_back(Move( col, row ));
		cout << "Player "<<s_player2<<":";
		for (auto const& value : player2) {
			cout << value.col_ << "," << value.row_ << "; ";
		}
		cout << endl << endl;
		currentPlayer = 1;
		return SUCCESS;
	}
}
