/*
gamebase.h

Purpose: Declaration of base class GameBase

Author:
Roy Huang   xiaolin.huang@wustl.edu;
Jerry Kong  jerry.kong@wustl.edu;
Fangchen Li fangchen.li@wustl.edu

Date: 11/16/2017
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
	virtual int turn() = 0;
	int play();
	int prompt(unsigned int&, unsigned int&);
	static GameBase * checkInput(int, char*[]);
protected:
	unsigned int row, col, numTurns, streak;
	int longestString;
	int currentPlayer = 1;
	string symbol1, symbol2;
	string empty = "";
	vector<Move> player1, player2;
	vector<vector<string> > pieces;
};

#endif