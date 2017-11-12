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
	shared_ptr<TicTacToeGame> spttt = make_shared<GameBase>(GameBase::doIt(argc, argv));
	if (spttt == 0) {
		usage(argv[PROGRAM], "TicTacToe");
		return WRONG_ARGUMENTS;
	}
	spttt->play();
	return 0;
}

