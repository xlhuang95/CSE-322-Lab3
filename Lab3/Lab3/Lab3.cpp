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

int main(int argc, char * argv[])
{
	GameBase * game = GameBase::checkInput(argc, argv);
	if (game == 0) {
		usage(argv[PROGRAM], "TicTacToe");
		return WRONG_ARGUMENTS;
	}
	else {
		shared_ptr<GameBase> g;
		string name = argv[INPUT_FILE];
		if (name == "TicTacToe") {
			TicTacToe * tictactoe = dynamic_cast<TicTacToe*>(game);
			g = make_shared<TicTacToe>(*tictactoe);
			g->play();
		}
		else if (name == "Gomoku") {
			Gomoku * tictactoe = dynamic_cast<Gomoku*>(game);
			g = make_shared<Gomoku>(*tictactoe);
			g->play();
		}
	}
	
	return 0;
}

