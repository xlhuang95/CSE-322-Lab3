#ifndef GOMOKU_H
#define GOMOKU_H

#include "gamebase.h"

class Gomoku : public GameBase {
public:
	Gomoku();
	friend ostream & operator<<(ostream& out, Gomoku);
	virtual void print() override;
	virtual bool done() override;
	virtual bool draw() override;
	virtual int turn() override;
};

#endif
