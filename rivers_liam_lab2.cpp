/*
	Title:  Lab2.cpp
	Author: Liam Rivers
	Date:  9/11/2023
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include<string>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				//print out the result of the sumOfNumbers function here
				cout << sumOfNumbers(num);
				
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				num1 = 0; //initializing counter outside
				if(isMember(myArray, num, num1)){ 
					cout << num << "is in the list!" << endl;
				}
				else{
					cout << num << " is not in the list." << endl;
				}
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				//call string reverser function here done, length declared outside scope or else function will loop when intializing inside function
				num = userString.length();
				stringReverser(userString, num);
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				//taking in userstrmodified, printing userstring
				if(isPalindrome(userStrModified)){ //this means that if isPalindrome is true, print that its a palindrome
					cout << userString << " is a palindrome!" << endl;
				}
				else{ // if isPalindrome is not true, print its not a palindrome
					cout << userString << " is not a palindrome." << endl;
				}
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << multiply(num1, num2);
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!


int sumOfNumbers(int num){ // take in number, we will take number and add by the number minus one
	if(num==0){ //this means we have finished counting down and thus cant add anymore
		return 0;
	}
	else{
		return num + sumOfNumbers(num -1); // moves down from number to 0, so we jump down to 0 from user number and go 0 + 1, + 2, + 3, + 4, etc...
										   // until we reach the user number, at which point the function has reached the top and ends
	}
}

bool isMember(int* myArray, int num, int num1){
	if(num1 == 11){ //this means if youve checked the whole array and user number doesnt match any members, its not in the array
		return false;
	}
	else if(num != myArray[num1]){ //if user number doesnt match the number at marker, call function to check next element
		return isMember(myArray, num, num1+1);
	}
	else{
		return true; //if you havent reached the end of array, and the usernumber is not-not equal to element at marker, it must match so return true
	}//																					^apologies for improper grammar

}

void stringReverser(string userString, int num){
	if(num == 1){
		cout << userString.at(num-1); //this prints the first character of the string, after we are done counting down
	}
	else{
	    num-=1; //this moves the marker from the last character of the string backwards to the first character
	    cout << userString.at(num); //prints the character at the marker
	    stringReverser(userString, num); //sends in the string and marker (marker will be moved down inside function)
	}
}

bool isPalindrome(string userStrModified){
	//if string at pos 0 and pos end == then remove those characters and call again, have function return the end value of true/false
	//base case if string position at front and back equal or if the string is empty
    
    if(userStrModified.length() <= 1){ //this means there are 1 or 0 characters left, meaning the word is a palindrome so we return true
        return true;
    }
    else if(userStrModified.at(0) == userStrModified.at(userStrModified.length()-1)){ //checking if the first and last character match
        return isPalindrome(userStrModified.substr(1, userStrModified.length()-2)); //send in a substring that removes the first and last character
    }
	else{
    return false; // this means all other conditions failed, so the word is NOT a palindrome
	}
}

int multiply(int num1, int num2){ //num1 * num2 ex: 3*4 == 3 + 3 + 3 + 3 or 4 + 4 + 4, so we simply add num2 to num2, num1 times
	if(num1 == 1){
		return num2; //this means that we cannot add any more of num2, so we simply return num2
	}
	else{
		return num2 + multiply(num1 - 1, num2); //counting down num1, this is the ticker that adds num2 the number of num1 times
	}

}

//TO FIX - NOTES
/*
Driver.cpp:
Line 155:
Note that this handles what we need it to for this lab, but we have no handle for negatives.

Line 165:
This only works for arrays of size 10, but note that if we take a top-down approach, we can find a number that always means we are done (aka if we do subtraction and start at last). -1

Line 178:
This will work, but note that there is a cleaner way to write this code.

Line 205:
Note that this also has no handle for negative numbers, but is ok for requirements.
*/