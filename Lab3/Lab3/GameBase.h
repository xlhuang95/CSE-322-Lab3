#pragma once

#include <string>
#include <vector>
using namespace std;

class GameBase {
protected:
	int row, col, numTurns, numTurnsRemain;
	vector<vector<string> > pieces;
	int longestString;
	vector<Move> player1;
	vector<Move> player2;
	string s_player1;
	string s_player2;
	int currentPlayer = 1;
public:
	GameBase(int, int);
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	int prompt(unsigned int &col, unsigned int &row);
	virtual int turn() = 0;
	virtual int play();
	static GameBase * doIt(int n, char * c[]);
};

struct Move {
	Move(int col, int row);
	int col_;
	int row_;
};