#include "GameBase.h"
#include <iostream>

using namespace std;

GameBase::GameBase(int r, int c) {
	row = r;
	col = c;
}

// start new game
int GameBase::play() {
	print();	// print board
	do {	// take turns
		if (turn() == QUIT) {	// quit detected, abort
			cout << p1.size() + p2.size() << " turns were played. "
				<< "Player quit.";
			return QUIT;
		}
	} while (!(done() || draw()));	// as long as not draw or done

	if (done()) {	// done detected
		if (currTurn == 1) {	// O wins
			cout << "O wins.";
		}
		else {					// X wins
			cout << "X wins.";
		}
		return SUCCESS;
	}

	else {	// draw detected
		cout << p1.size() + p2.size() << " turns were played. "
			<< "No winning moves remain.";
		return DRAW;
	}
}