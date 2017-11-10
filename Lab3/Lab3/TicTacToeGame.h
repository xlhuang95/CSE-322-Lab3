#pragma once

#include "GameBase.h"
#include <iostream>
#include <string>

class TicTacToeGame : public GameBase
{
public:
	TicTacToeGame();
	TicTacToeGame() : GameBase(0);
	~TicTacToeGame();
	friend ostream & operator<< (ostream &, const TicTacToeGame &);
	virtual void print();
	virtual bool done();
	virtual void draw();
};