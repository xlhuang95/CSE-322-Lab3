// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <memory>
#include "Game.h"
#include "helper.h"


using namespace std;

int main(int argc, char * argv[])
{
	GameBase * game = GameBase::doIt(argc,argv);
	if (game == 0) {
		usage(argv[PROGRAM], "TicTacToe");
		return WRONG_ARGUMENTS;
	}
	else {
		shared_ptr<GameBase> g;
		string name = argv[INPUT_FILE];
		if (name == "TicTacToe") {
			TicTacToeGame * tictactoe = dynamic_cast<TicTacToeGame*>(game);
			g = make_shared<TicTacToeGame>(*tictactoe);
			g->play();
		}
		else if (name == "Gomoku") {
			GomokuGame * tictactoe = dynamic_cast<GomokuGame*>(game);
			g = make_shared<GomokuGame>(*tictactoe);
			g->play();
		}
	}
	
	return 0;
}

