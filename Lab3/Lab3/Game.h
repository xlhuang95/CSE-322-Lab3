
#ifndef GAME_H
#define GAME_H


#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Move {
	Move(int col, int row);
	int col_;
	int row_;
};

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
	~GameBase() { cout << "destroy GameBase" << endl; };
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	int prompt(unsigned int &col, unsigned int &row);
	virtual int turn() = 0;
	virtual int play();
	static GameBase * doIt(int n, char * c[]);
};



class TicTacToeGame : public GameBase
{
public:
	TicTacToeGame();
	~TicTacToeGame() { cout << "destroy tictactoe" << endl; };
	friend ostream & operator<< (ostream &, const TicTacToeGame &);
	virtual void print();
	virtual bool done();
	virtual bool draw();
	virtual int turn();
};


#endif // !GAME_H