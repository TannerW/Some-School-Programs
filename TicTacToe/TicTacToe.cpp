//course: CS215-005
//Project: program assignment 3
//Date: 04/15/2015
//Purpose: to simulate a game of tictactoe
//Author: Owen Tanner Wilkerson

#include <iostream>
#include "TicTacToe.h"
#include <cstdlib>
#include <ctime>

using namespace std;


//purpose: default constructor
//description: default constructor and place ?'s for all the elements of the array
//inputs:N/A
//outputs:creates a new object
TicTacToe::TicTacToe()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			ggrid[i][j]='?';
		}
	}
}

//purpose: print the current game table
//description: prints each element of the array in table format
//inputs:N/A
//outputs:the current game grid
void TicTacToe::print()
{
	cout<<"  0 1 2"<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<i<<' ';
		for(int j=0;j<3;j++)
		{
			cout<<ggrid[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}

//purpose: to allow the player to select where they want to place their icon
//description: takes an imput of coordinates and places a U at that spot
//inputs: no parameters but the function itself asks the user for coordinates of his desired spot
//outputs: manipulates the grid array
void TicTacToe::play_by_user()
{
	int x,y;
	bool valid_input=false;
	do
	{
		cout<<"Which cell would you like to mark (row and column)?";
		cin>>x;
		cin.ignore(256,' ');
		cin>>y;
		//validation that the spot is unmarked
		if(x<3 && x>=0 && y<3 && y>=0 && ggrid[x][y]!='C' && ggrid[x][y]!='U')
		{
			ggrid[x][y]='U';
			valid_input=true;
		}
		//input validation
		else
		{
			if(ggrid[x][y]=='C' || ggrid[x][y]=='U')
			{
				cout<<"The cell has been marked already! Please try again..."<<endl;
			}
			else
				cout<<"Invalid cell position! Please try again..."<<endl;
		}
	}while(valid_input==false);
}

//
//purpose: simulates the computer playing an icon
//description: randomly selects an open spot and places a C there
//inputs: N/A
//outputs: manipulates the grid array
void TicTacToe::play_by_computer()
{
	srand(unsigned int(time(0)));
	bool valid_cord=false;
	do
	{
		int x=rand()%3;
		int y=rand()%3;
		//checks to see if spot is unmarked
		if(ggrid[x][y]!='U' && ggrid[x][y]!='C')
		{
			ggrid[x][y]='C';
			valid_cord=true;
		}
	}while(valid_cord==false);
}

//
//purpose: checks to see if anyone has won or if it is a tie
//description: runs through the grid array to see if any C's or U's are in a line and if not then it checks for any remaining open spots
//inputs: N/A
//outputs: returns a characters that the main function interprets if someone has won, it is a tie, or to continue playing
char TicTacToe::win_check()
{
	char retVal='N'; //value that if remains unchanged by the algorithms below shows the game is a tie

	// check horizontally and vertically for a row of U's indicating that the player won
	for(int i=0;i<3;i++)
	{
		if (ggrid[i][0]=='U' && ggrid[i][1]=='U' && ggrid[i][2]=='U')
		{
			retVal='U';
		}
		if ((ggrid[0][i]=='U' && ggrid[1][i]=='U' && ggrid[2][i]=='U'))
		{
			retVal='U';
		}
	}
	//checks diagonally for a row of U's indicating that the player won
	if ((ggrid[0][0]=='U' && ggrid[1][1]=='U' && ggrid[2][2]=='U')
		||(ggrid[0][2]=='U' && ggrid[1][1]=='U' && ggrid[2][0]=='U'))
	{
		retVal='U';
	}


	// check horizontally and vertically for a row of C's indicating that the computer won
	for(int j=0;j<3;j++)
	{
		if ((ggrid[j][0]=='C' && ggrid[j][1]=='C' && ggrid[j][2]=='C')
			||(ggrid[0][j]=='C' && ggrid[1][j]=='C' && ggrid[2][j]=='C'))
		{
			retVal='C';
		}
	}
	//checks diagonally for a row of C's indicating that the computer won
	if ((ggrid[0][0]=='C' && ggrid[1][1]=='C' && ggrid[2][2]=='C')
		||(ggrid[0][2]=='C' && ggrid[1][1]=='C' && ggrid[2][0]=='C'))
	{
		retVal='C';
	}

	//checks to see if all the spaces are full indicating it is a tie
	if (retVal!='U'&&retVal!='C')
	{
		for(int l=0;l<3;l++)
		{
			for(int m=0;m<3;m++)
			{
				//if a ? is detected then the game continues as not a tie
				if(ggrid[l][m]=='?')
				{
					retVal='Y';
				}
			}
		}
	}
	return retVal;
}
