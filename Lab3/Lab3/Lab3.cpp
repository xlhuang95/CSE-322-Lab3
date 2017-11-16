// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gamebase.h"
#include "tictactoe.h"
#include "gomoku.h"
#include "helper.h"
#include <string>
#include <memory>

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
			if (name == "TicTacToe") {
				TicTacToe * tictactoe = dynamic_cast<TicTacToe*>(game);
				g = make_shared<TicTacToe>(*tictactoe);
			}
			else if (name == "Gomoku") {
				Gomoku * gomoku = dynamic_cast<Gomoku*>(game);
				g = make_shared<Gomoku>(*gomoku);
			}
			g->play();
		}
	}
	catch (bad_alloc) { return BAD_ALLOCATION; }
	return 0;
}

