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


