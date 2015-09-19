//course: CS215-005
//Project: program assignment 3
//Date: 04/15/2015
//Purpose: to simulate a game of tictactoe
//Author: Owen Tanner Wilkerson

#ifndef HEADERNAME_H_INCLUDED
#define HEADERNAME_H_INCLUDED

#include <iostream>
using namespace std;

class TicTacToe
{
public:
	TicTacToe(); // constructor

	void print(); // print the current content of the grid

	void play_by_user(); // userís turn to mark a cell of the grid

	void play_by_computer(); // computerís turn to mark a cell

	char win_check(); //to check if someone has won the game

private:
	
	char ggrid[3][3]; // SIZE should be 3
	// a SIZE * SIZE array to represent the grid
};

#endif
