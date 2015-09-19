//course: CS215-005
//Project: program assignment 3
//Date: 04/15/2015
//Purpose: to simulate a game of tictactoe
//Author: Owen Tanner Wilkerson

#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main()
{
	bool winner=false;//bool to assist with running the loop
	TicTacToe grid;//construct
	grid.print();

	//runs the program continuously until someone has won or game is tied
	while(winner==false)
	{
		grid.play_by_user();
		grid.print();

		//interprets the return value of win_check to see if anyone has won or not
		if (grid.win_check()=='U')
		{
			cout<<"Congratulation! You won!";
			winner=true;
		}
		if (grid.win_check()=='N')
		{
			cout<<"Game is over with no winner!"<<endl;
			winner=true;
		}

		//if the user has won the the computer continues to play
		if(winner==false)
		{
			grid.play_by_computer();
			grid.print();

			//interprets the return value of win_check to see if anyone has won or not
			if (grid.win_check()=='C')
			{
				cout<<"Sorry, you lost!";
				winner=true;
			}
			if (grid.win_check()=='N')
			{
				cout<<"Game is over with no winner!"<<endl;
				winner=true;
			}
		}
	}

	system("pause");
	return 0;
}
