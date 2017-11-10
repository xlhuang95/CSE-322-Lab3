#pragma once

#include <string>
#include <vector>
using namespace std;

class GameBase {
protected:
	int row, col, numTurns, numTurnsRemain;
	vector<vector<string> > pieces;
	int longestString;
	vector<string> player1;
	vector<string> player2;
	int currentPlayer = 1;
public:
	GameBase(int, int);
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual void draw() = 0;
	int prompt();
	virtual void turn() = 0;
	virtual int play();
	static GameBase * doIt(int n, char * c[]);
};