#include "GameBase.h"
#include <iostream>
#include "helper.h"
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

GameBase::GameBase(int r, int c) {
	row = r;
	col = c;
}

Move::Move(int col, int row) : col_(col), row_(row) {};

// start new game
int GameBase::play() {
	print();	// print board
	do {	// take turns
		if (turn() == QUIT) {	// quit detected, abort
			cout << player1.size() + player2.size() << " turns were played. "
				<< "Player quit.";
			return QUIT;
		}
	} while (!(done() || draw()));	// as long as not draw or done

	if (done()) {	// done detected
		if (currentPlayer == 1) {	// O wins
			cout << "O wins.";
		}
		else {					// X wins
			cout << "X wins.";
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
	do {
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
				if (pieces[tCol][tRow] == " ") {	// if the position is not occupied yet
					col = tCol;
					row = tRow;
					return SUCCESS;	// move validated
				}
			}
		}
	} while (true);
}