#include "TicTacToeGame.h"
#include <iomanip>
using namespace std;

ostream & operator << (ostream &out, const TicTacToeGame &g) {
	for (int row = g.row; row >= 0; row--) {	// print rows in opposite
		out << setw(g.longestString) << row;
		for (int col = 0; col <= g.col; col++) {
			out << setw(g.longestString) << g.pieces[col][row];
		}
		out << endl;
	}
	for (int i = 0; i <= g.col; i++) {
		out << setw(g.longestString) << i;
	}
	out << endl;
	return out;
}

void TicTacToeGame::print() {
	cout << *this;
}


