/* 
 * File:   main.cpp
 * Author: tannerwilkerson
 *
 * Created on September 26, 2016, 5:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#define N 4
#define subgroupSize sqrt(N)
using namespace std;

/*
 * 
 */

int findOptionsPosition(vector<int> options, int lookFor)
{
    for (int i = 0; i < options.size(); i++)
    {
        if (options[i] == lookFor)
        {
            return i;
        }
    }
    return -1;
}

vector<int> WhatsAvailOptions(vector< vector<int> > sudoku, int col, int row)
{
    vector<int> newOptions;
    //cout << "seeking options.." << endl;
    //cout << "populate options" << endl;
    for (int i = 1; i <= N; i++)
    {
        //cout << i << endl;
        newOptions.push_back(i);
    }
    int currCol = 0;
    int currRow = 0;
    
/************************************************
 *
 *              CHECKING ROW FOR OPTIONS
 *
 ************************************************/
    while (currRow < N)
    {
        if(currRow != row)
        {
            //cout << "Checking coordinate: " << col << " " << currRow << endl;
            //cout << "In current place: " << sudoku[currRow][col] << endl;
            if (sudoku[currRow][col] != 0) {
                int position = findOptionsPosition(newOptions, sudoku[currRow][col]);
                if (position != -1) {
                    if (newOptions.size() >= 1) {
                        newOptions.erase(newOptions.begin() + position);
                    } else {
                        return newOptions;
                    }
                }
            }
        }
//        cout << "Current Options for row " << currRow << endl;
//        for (int i = 0; i < newOptions.size(); i++)
//        {
//            cout << newOptions[i] << " ";
//        }
//        cout << endl;
        currRow++;
    }
    
//    cout << endl << "Options after row check:" << endl;
//    for (int i = 0; i < newOptions.size(); i++)
//    {
//        cout << newOptions[i] << " ";
//    }
//    cout << endl;
    
/************************************************
 *
 *              CHECKING COLUMN FOR OPTIONS
 *
 ************************************************/
    while (currCol < N)
    {
        if(currCol != col)
        {
            //cout << "Checking coordinate: " << currCol << " " << row << endl;
            //cout << "In current place: " << sudoku[row][currCol] << endl;
            
            if(sudoku[row][currCol] != 0)
            {
                int position = findOptionsPosition(newOptions, sudoku[row][currCol]);
                if (position != -1) {
                    if (newOptions.size() >= 1) {
                        newOptions.erase(newOptions.begin() + position);
                    } else {
                        return newOptions;
                    }
                }
            }
        }
//        cout << "Current Options for column " << currCol << endl;
//        for (int i = 0; i < newOptions.size(); i++)
//        {
//            cout << newOptions[i] << " ";
//        }
//        cout << endl;
        currCol++;
    }
    
//    cout << endl << "Options after column check:" << endl;
//    for (int i = 0; i < newOptions.size(); i++)
//    {
//        cout << newOptions[i] << " ";
//    }
//    cout << endl;

    /************************************************
     *
     *              CHECKING SUBSECTION FOR OPTIONS
     *
     ************************************************/
    int subCol = col / subgroupSize;
    int subRow = row / subgroupSize;
    int subgroup = ((subRow * subgroupSize) + subCol + 1);
    int startY = subRow*subgroupSize;
    int startX = subCol*subgroupSize;
    int checkedCells = 0;
    for (int i = startY; i < (startY + subgroupSize); i++) {
        for (int j = startX; j < (startX + subgroupSize); j++) {
            //cout << "Checking coordinate: " << j << " " << i << endl;
            //cout << "In current place: " << sudoku[i][j] << endl;
            if ((i != row) && (j != col)) {
                if (sudoku[i][j] != 0) {
                    int position = findOptionsPosition(newOptions, sudoku[i][j]);
                    if (position != -1) {
                        if (newOptions.size() >= 1) {
                            newOptions.erase(newOptions.begin() + position);
                        } else {
                            return newOptions;
                        }
                    }
                }
            }
//            cout << "Current Options for subgroup " << subgroup << endl;
//            for (int i = 0; i < newOptions.size(); i++) {
//                cout << newOptions[i] << " ";
//            }
//            cout << endl;
        }
    }
    return newOptions;
}

bool solveit(vector< vector<int> >& sudoku, int& current_cell, int& c_index, int col, int row, vector<int>& emptyCells, bool reevalOptions, vector<int> options)
{   
    //cout << col << row << endl;
    int k = emptyCells.size()/2;
    
    
    //is current_cell = 0?
    if(current_cell == 0)
    {
        //cout << "current_cell == 0" <<endl;
    //yes
        //the searching is exhausted
        return true;
    }
    //no
    else {
        //options list only evaluated after backtrack and on first run.
        if (reevalOptions) {
            //cout << "Checking options of position: " << col << " " << row << endl;
            //cout << "check 1" << endl;
            options = WhatsAvailOptions(sudoku, col, row);
            //c_num = the number of evaluated candidates for current cell
        }
        int c_num = options.size();
    
        //is c_index <= c_num?
        if (c_index <= c_num) {
            //cout << "c_index <= c_num" << "because " << c_index << "<=" << c_num << endl;
        //yes
            //update this candidate number into a tentative solution
            sudoku[row][col] = options[c_index - 1];
            //and
            c_index += 1;
            
            //is current_cell = k?
            if (current_cell == k) {
            //yes
                //cout << "current_cell == k, solution found!" <<endl;
                //one solution found
                //backtracking by letting current_cell -= 1
                //current_cell--;
                return true;//solveit(sudoku, current_cell, c_index, emptyCells[(current_cell - 1)*2], emptyCells[((current_cell - 1)*2) + 1], emptyCells, false, options);
            } 
            //no
            else {
                //cout << "current_cell != k" << endl;
                current_cell++;
                c_index = 1;
                return solveit(sudoku, current_cell, c_index, emptyCells[(current_cell - 1)*2], emptyCells[((current_cell - 1)*2) + 1], emptyCells, true, options);
            }
        }
        //no
        else {
            //cout << "c_index > c_num" <<endl;
            //dead-end
            //backtracking by letting current_cell -= 1
            current_cell--;
            
            //record some info for judging later
            options = WhatsAvailOptions(sudoku, emptyCells[(current_cell - 1)*2], emptyCells[((current_cell - 1)*2) + 1]);
            
            int position = findOptionsPosition(options, sudoku[emptyCells[(current_cell - 1)*2]][emptyCells[((current_cell - 1)*2) + 1]]);
            if (position != -1) {
                if (options.size() > 1) {
                    options.erase(options.begin() + position);
                } else {
                    options.clear();
                }
            }
            sudoku[emptyCells[(current_cell - 1)*2]][emptyCells[((current_cell - 1)*2) + 1]]=0;
            return solveit(sudoku, current_cell, c_index, emptyCells[(current_cell - 1)*2], emptyCells[((current_cell - 1)*2) + 1], emptyCells, false, options);
        }
    }
}


int main(int argc, char** argv) {
    string temp, currstr;
    int entry;
    string* rows;
    rows = new string[N];
    vector < vector <int> > sudoku(N,vector<int> (N,0));
    
    vector <int> emptyCells;
    cout << "Input a row of the sudoku with blanks marked as x" << endl;
    for (int i = 0; i < N; i++)
    {
        getline(cin, rows[i]);
    }
    string delimit = " ";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Parse each row, replace each x with a 0 because 0s are not traditionally used
                //in sudokus so it'll act as a friendly integer place hold for empty cells
            currstr=rows[i];
            temp = currstr.substr(0,currstr.find(delimit));
            if (temp == "x" | temp == "X")
            {
                entry = 0;
                emptyCells.push_back(j);
                emptyCells.push_back(i);
            }
            else
            {
                entry = stoi(temp);
            }
            rows[i]=currstr.substr(currstr.find(delimit)+1);
            sudoku[i][j]=entry;
        }
    }
    delete[] rows;
    
    
    //print entered matrix
    cout << "You entered the Sudoku matrix:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sudoku[i][j];
        }
        cout << endl;
    }
    
//    cout << "The empty cells are located at the following coordinates:" << endl;
//    for (int i = 0; i < emptyCells.size(); i=i+2)
//    {
//        cout << emptyCells[i] << " " << emptyCells[i+1] << endl;
//    }
//    cout << "Which are in the vector in the order:" << endl;
//    for (int i = 0; i < emptyCells.size(); i=i+2)
//    {
//        cout << emptyCells[i] << " " << emptyCells[i+1] << " ";
//    }
//    cout << endl;
    
    int current_cell=1;
    int c_index=1;
    vector<int> options;
    bool isSolved=solveit(sudoku, current_cell, c_index, emptyCells[0], emptyCells[1], emptyCells, true, options);
    
    cout << "Solved sudoku:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sudoku[i][j];
        }
        cout << endl;
    }
    return 0;
}