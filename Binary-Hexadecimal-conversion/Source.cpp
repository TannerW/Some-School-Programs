/*
Course: CS215
Project: program 2
Date: 3/1/2015
Purpose: to convert binary, decimal, and hexadecimal to each other
Author: Owen Tanner Wilkerson
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

/*
Purpose: to convert a binary number to a decimal number
description: reverses the binary number in order to step through the binary number to see what position the 1's are in and will calculate a decimal according to the "2^position" method
input:binary number
output:decimal number
*/
void binary_to_decimal()
{
	//stores the entered binary number
	string entered_binary;
	//vector that stores the binary number as individual digits
	vector <string> binary_vec;
	//accumulator to calculate the decimal number that the binary number equals
	double decimal=0;
	//flag used for input validation
	bool fail_flag=false;

	cout << "Enter a decimal number: ";
	cin >> entered_binary;

	//inputs the entered binary number into the vector backwards in order to use the stepping method for conversion
	for(int i=entered_binary.length(); i>=1; i--)
	{
		binary_vec.push_back(entered_binary.substr(i-1,1));
	}

	//steps through the vector to find the position of the 1's
	for (unsigned int k=0;k<binary_vec.size();k++)
	{
		if(binary_vec[k]=="1" || binary_vec[k] =="0")
		{
			//calculates the decimal of the 1's positions using the "2 raised to the power of the position" method and accumulating the decimals
			if(binary_vec[k]=="1")
			{
				decimal=decimal+pow(2,k);
			}
		}
		//input validation
		else
		{
			cout<< "Your binary number contains an invalid digit.";
			fail_flag=true;
			k=binary_vec.size();
		}
	}

	//outputs the result if inout is valid
	if (fail_flag==false)
	{
		cout << "Binary:" << entered_binary << " --> Decimal:"<< decimal;
	}
}

/*
Purpose: to convert a decimal number to a binary number
description: uses the "divide by 2" method to convert a decimal to binary
input:decimal number
output: binary number
*/
void decimal_to_binary()
{
	//stores decimal entered
	int entered_decimal;
	//flag used for input validation
	bool fail_flag=false;
	//vector used to store the generated binary number
	vector <int> binary_number;

	cout << "Enter a decimal number: ";
	cin >> entered_decimal;

	//loops while the decimal is greater than 0, necessary for the divide by 2 method
	while (entered_decimal>0)
	{
		//calculates the first digit of the binary number vector with the divide by 2 method in order to avoid a bound error
		if(binary_number.size()==0)
		{
			binary_number.push_back(entered_decimal%2);
		}
		//generates the binary number by adding the results to the vector
		else
		{
			//adds a zero at the end of the vector in order to shift every element over one position to the right to make room for the next digit
			binary_number.push_back(0);
			//shifts all elements right one position
			for(int i=binary_number.size()-1; i>=1; i--)
			{
				binary_number[i]=binary_number[i-1];
			}
			//calculates the next digit of the binary number
			binary_number[0]=(entered_decimal%2);
		}
		//divides remaining decimal number in order to continue the divide by 2 method
		entered_decimal=entered_decimal/2;
	}
	
	cout << "Decimal:" << entered_decimal << " --> Binary:";
	//outputs the resulting binary number
	for (unsigned int j=0;j<=binary_number.size()-1;j++)
	{
		cout << binary_number[j];
	}
}

/*
Purpose: to convert a binary number to a hexadecimal number
description: converts the binary number to hexadecimal using groupings of 4 binary digits to find each digit of the hexadecimal number
input:binary number
output:hexadecimal number
*/
void binary_to_hexa()
{
	//stores the inputted binary number
	string entered_binary;
	//stores each element of the binary number separately to assist with conversion
	vector<string> binary_vec;
	//flag used in input validation
	bool fail_flag=false;
	//used to store the decimal numbers needed for converting binary into hexadecimal
	int decimal=0;

	cout << "Enter a binary number: ";
	cin >> entered_binary;

	//loop to step through the inputted binary number for input validation
	for(unsigned int j=0;j<entered_binary.length();j++)
	{
		if (entered_binary.substr(j,1)!= "1" && entered_binary.substr(j,1)!= "0")
		{
			fail_flag=true;
		}
	}

	//if binary number is valid
	if(fail_flag==false)
	{
		cout<<"Binary:"<<entered_binary<<" --> Hexadecimal:";

		//used to store the binary number with zeros added to the beginning of the binary number in order
		//to correctly convert the number into hexadecimal
		string zero_added_binary=entered_binary;

		//adds zeros to the beginning of the binary number if the number of digits is not divisible by 4
		while(zero_added_binary.length()%4!=0)
		{
			zero_added_binary="0"+zero_added_binary;
		}

		//stores the number needed for the loop to step 4 positions
		unsigned int i=0;
		//adds the binary number with the zeros added to a vector in groupings of 4 digits to help with conversion
		while(i < zero_added_binary.length())
		{
			binary_vec.push_back(zero_added_binary.substr(i,4));
			i+=4;
		}

		//loops the steps through each element of the vector
		for (unsigned int k=0;k<binary_vec.size();k++)
		{
			//stores the value of the grouping of 4
			double decimal=0;
			//steps through the grouping of 4 digits backwards in order to calculate its decimal value with the
			//"2 to the power of the position" method for the hexadecimal conversion
			for (unsigned int l=binary_vec[k].length(); l>0;l--)
			{
				if(binary_vec[k].substr(l-1,1)=="1")
				{
					int x=l-4;
					decimal=decimal+pow(2,abs(x));
				}
			}
		//if statements to find the hexadecimal representation of each decimal number and prints each element of the hexadecimal number 
			if (decimal<10)
			{
				cout<<decimal;
			}
			if (decimal==10)
			{
				cout<<"A";
			}
			if (decimal==11)
			{
				cout<<"B";
			}
			if (decimal==12)
			{
				cout<<"C";
			}
			if (decimal==13)
			{
				cout<<"D";
			}
			if (decimal==14)
			{
				cout<<"E";
			}
			if (decimal==15)
			{
				cout<<"F";
			}
		}
	}
	//input validation
	else
	{
		cout << "Your binary number contains an invalid digit.";
	}
}

/*
Purpose: to convert a hexadecimal number to a binary number
description: steps through the hexadecimal number generating the 4 binary digits that corresponds with each hexadecimal digit
input:hexadecimal number
output: binary number
*/
void hexa_to_binary()
{
	//stores the entered hexadecimal number
	string entered_hexa;
	//a vector to store each element of the hexadecimal number as separate elements
	vector<string> hexa_vec;
	
	cout<<"Enter a hexadecimal number: ";
	cin >> entered_hexa;
	cout << endl;

	//inputs the digits of the hexadecimal number to the vector as individual elements
	for (unsigned int i=0;i<entered_hexa.length();i++)
	{
		hexa_vec.push_back(entered_hexa.substr(i,1));
	}

	//stores the binary number generates
	string binary_num="";

	//loop that steps through the hexadecimal number vector
	//in order to find the grouping of 4 binary numbers that each element corresponds with
	for (unsigned int j=0;j<hexa_vec.size();j++)
	{
	//if statements to find the grouping of 4 binary numbers that the element corresponds with
	//and adds it to the generating binary number string
		if (hexa_vec[j] =="0")
		{
			binary_num+="0000";
		}
		if (hexa_vec[j] =="1")
		{
			binary_num+="0001";
		}
		if (hexa_vec[j] =="2")
		{
			binary_num+="0010";
		}
		if (hexa_vec[j] =="3")
		{
			binary_num+="0011";
		}
		if (hexa_vec[j] =="4")
		{
			binary_num+="0100";
		}
		if (hexa_vec[j] =="5")
		{
			binary_num+="0101";
		}
		if (hexa_vec[j] =="6")
		{
			binary_num+="0110";
		}
		if (hexa_vec[j] =="7")
		{
			binary_num+="0111";
		}
		if (hexa_vec[j] =="8")
		{
			binary_num+="1000";
		}
		if (hexa_vec[j] =="9")
		{
			binary_num+="1001";
		}
		if (hexa_vec[j] =="A" || hexa_vec[j] == "a")
		{
			binary_num+="1010";
		}
		if (hexa_vec[j] =="B" || hexa_vec[j] == "b")
		{
			binary_num+="1011";
		}
		if (hexa_vec[j] =="C" || hexa_vec[j] == "c")
		{
			binary_num+="1100";
		}
		if (hexa_vec[j] =="D" || hexa_vec[j] == "d")
		{
			binary_num+="1101";
		}
		if (hexa_vec[j] =="E" || hexa_vec[j] == "e")
		{
			binary_num+="1110";
		}
		if (hexa_vec[j] =="F" || hexa_vec[j] == "f")
		{
			binary_num+="1111";
		}
	}

	//outputs result
	cout<< "Hexadecimal:"<< entered_hexa << " --> Binary:"<<binary_num;


}

/*
Purpose: to pause the program before quitting
description: uses an if statement to wait for the user to press the newline button (enter)
input: bool parameter
output: exit prompt
*/
void pause_215(bool have_newline)
{
	if (have_newline)
	{
		// Ignore the newline after the user's previous input.
		cin.ignore(256, '\n');
	}
	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(256, '\n');
}

int main()
{
	//used the the pause function
	bool have_newline=true;
	//stores what the user selects
	string choice;

	cout << "==========================" << endl <<
		"1: Binary --> Decimal" << endl <<
		"2: Decimal --> Binary"<< endl <<
		"3: Binary --> Hexadecimal" << endl <<
		"4: Hexadecimal --> Binary" << endl <<
		"Others: Quit" << endl <<
		"==========================" << endl;
	cin >> choice;

	//loops while the user does not want to quit
	while (choice != "Quit" && choice != "quit" && choice != "q" && choice != "Q")
	{
	//if statements that will run the correct function correspondings to the user selection
		if(choice=="1")
		{
			binary_to_decimal();
		}

		if(choice=="2")
		{
			decimal_to_binary();
		}

		if(choice=="3")
		{
			binary_to_hexa();
		}

		if(choice=="4")
		{
			hexa_to_binary();
		}
		//input validation
		if(choice!="1" && choice!="2" && choice!="3" && choice!="4")
		{
			cout<<"Invalid selection";
		}

		cout<< endl;
		cout << "==========================" << endl <<
			"1: Binary --> Decimal" << endl <<
			"2: Decimal --> Binary"<< endl <<
			"3: Binary --> Hexadecimal" << endl <<
			"4: Hexadecimal --> Binary" << endl <<
			"Others: Quit" << endl <<
			"==========================" << endl;
		cin >> choice;
	}
	cout<<"Thanks for using the program."<<endl;
	//pauses program
	pause_215(have_newline);
	return 0;
}
