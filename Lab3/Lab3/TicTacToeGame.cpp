#include "TicTacToeGame.h"
#include <iomanip>
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
