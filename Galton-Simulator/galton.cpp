//course: CS215-005
//Project: Lab Assignment 8
//Date: 03/31/2015
//Purpose: To simulate falling balls in a Galton board
//         Print the number of balls at each peg
//         The average number of balls in bins approximate a bell-curve distribution.
//Author: Owen Tanner Wilkerson

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
void pause_215(bool have_newline);

int main()
{
	//defining the pointers to an array
	int *total=new int[10];
	int *average=new int[10];

	//allocating the 2 arrays defined above
	for(int t=0; t<10;t++)
	{
		total[t]=0;
		average[t]=0;
	}

	srand(unsigned int(time(0)));

	//2 variable to keep of loop and used in calculation and ouput texts
	int loop_number=1, rounds=0;

	while(loop_number<=50)
	{
		cout<<"The ouput for the No."<<loop_number<<" run:"<<endl;

		int* counts[10];

		// Allocate the rows
		for (int i = 0; i < 10; i++)
		{
			counts[i] = new int[i + 1];
			for (int j = 0; j <= i; j++)
			{
				counts[i][j] = 0;
			}
		}

		const int RUNS = 1000;

		// Simulate 1,000 balls
		for (int run = 0; run < RUNS; run++)
		{
			// Add a ball to the top
			counts[0][0]++;
			// Have the ball run to the bottom
			int j = 0;
			for (int i = 1; i < 10; i++)
			{
				int r = rand() % 2;
				// If r is even, move down, otherwise to the right
				if (r == 1)
				{
					j++; 
				}
				counts[i][j]++;
			}
		}

		// Print all counts
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cout << setw(4) << counts[i][j];
			}
			cout << endl;
		}

		//accumulating the number of balls in each bin among all the runs
		for(int y=0; y<10; y++)
		{
			total[y]+=counts[9][y];
		}


		// Deallocate the rows
		for (int i = 0; i < 10; i++)
		{
			delete[] counts[i];
		}
		cout<<endl;
		loop_number++;
		rounds++;
	}

	cout<<endl<<"The average counts over "<<rounds<<" times, each run contains 1000 balls."<<endl;

	//calculating the average of each bin and printing that number
	for(int p=0; p<10;p++)
	{
		average[p]=total[p]/rounds;
		cout<< average[p]<< " ";
	}

	//freeing the memory taken in the heap
	delete[] total;
	delete[] average;

	pause_215(false);
	return 0;
}

void pause_215(bool have_newline)
{
	if (have_newline) {
		// Ignore the newline after the user's previous input.
		cin.ignore(256, '\n');
	}

	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(256, '\n');
}
