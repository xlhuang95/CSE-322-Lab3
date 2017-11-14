#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "gamebase.h"

class TicTacToe : public GameBase
{
public:
	TicTacToe();
	friend ostream & operator<< (ostream &, const TicTacToe &);
	virtual void print() override;
	virtual bool done() override;
	virtual bool draw() override;
	virtual int turn() override;
};

#endif