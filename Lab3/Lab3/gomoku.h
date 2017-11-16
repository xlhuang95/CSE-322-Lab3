/*
gomoku.h

Purpose: Declaration of derived class Gomoku

Author:
Roy Huang   xiaolin.huang@wustl.edu;
Jerry Kong  jerry.kong@wustl.edu;
Fangchen Li fangchen.li@wustl.edu

Date: 11/16/2017
*/

#ifndef GOMOKU_H
#define GOMOKU_H

#include "gamebase.h"

class Gomoku : public GameBase {
public:
	Gomoku();
	Gomoku(int, int);
	friend ostream & operator<<(ostream& out, Gomoku);
	virtual void print() override;
	virtual bool done() override;
	virtual bool draw() override;
	virtual int turn() override;
};

#endif
