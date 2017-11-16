/*
tictactoe.h

Purpose: Declaration of derived class TicTacToe

Author:
Roy Huang   xiaolin.huang@wustl.edu;
Jerry Kong  jerry.kong@wustl.edu;
Fangchen Li fangchen.li@wustl.edu

Date: 11/16/2017
*/

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "gamebase.h"

class TicTacToe : public GameBase
{
public:
	TicTacToe();
	friend ostream & operator<< (ostream &, const TicTacToe &);
	virtual void print() override;
	virtual bool draw() override;
	virtual bool done() override;
	virtual int turn() override;
};

#endif