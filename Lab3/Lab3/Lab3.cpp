// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <memory>
#include "gamebase.h"
#include "tictactoe.h"
#include "gomoku.h"
#include "helper.h"

using namespace std;

int main(int argc, char * argv[]) {
	try {
		GameBase * game = GameBase::checkInput(argc, argv);
		if (game == 0) {
			usage(argv[PROGRAM]);
			return WRONG_ARGUMENTS;
		}
		else {
			shared_ptr<GameBase> g;
			string name = argv[INPUT_FILE];
			if (name.compare("TicTacToe") == 0) {
				TicTacToe * tictactoe = dynamic_cast<TicTacToe*>(game);
				g = make_shared<TicTacToe>(*tictactoe);
			}
			else if (name.compare("Gomoku") == 0) {
				Gomoku * gomoku = dynamic_cast<Gomoku*>(game);
				g = make_shared<Gomoku>(*gomoku);
			}
			g->play();
		}
	}
	catch (bad_alloc) { return BAD_ALLOCATION; }
	return 0;
}

