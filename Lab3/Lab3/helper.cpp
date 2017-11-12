
#include "stdafx.h"
#include <iostream>
#include <string>
#include "helper.h"

using namespace std;


void usage(char * program_name, string s) {
	cout << "Usage: " << program_name << " " << s << endl
		<< "This program starts a TicTacToe game"
		<< endl;
}