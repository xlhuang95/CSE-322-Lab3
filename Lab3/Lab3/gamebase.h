/*
gamebase.h

Author: Roy Huang xiaolin.huang@wustl.edu; Jerry Kong jerry.kong@wustl.edu; Fangchen Li fangchen.li@wustl.edu

Purpose: Declaration of base class GameBase
*/

#ifndef GAMEBASE_H
#define GAMEBASE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// struct to record move
struct Move {
	int row, col;
	Move(int, int);
};

// base class GameBase
class GameBase {
public:
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	int prompt(unsigned int&, unsigned int&);
	virtual int turn() = 0;
	int play();
	static GameBase * checkInput(int, char*[]);
protected:
	unsigned int row, col, numTurns, streak;
	vector<vector<string> > pieces;
	int longestString;
	vector<Move> player1;
	vector<Move> player2;
	string symbol1;
	string symbol2;
	string empty = "";
	int currentPlayer = 1;
};

#endif