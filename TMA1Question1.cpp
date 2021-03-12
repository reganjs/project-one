//Regan
//January 1st, 2021

//Write a program that opens a file and counts the whitespace-separated words in that file.

//Tests: 1. Created a text file for this program that contains some words and runs the program to count the words.
//2. Created a blank text file and runs the program to count the words.
//3. Checked whether the count should be 0 or -1 in this instance.

#include <iostream>
#include <fstream>
using namespace std;

int count_words(char filename[]) //function returns the total count of words in the given
{
    ifstream fin(filename); //opens the file
    if(!fin.is_open()) //if the file is not found then display an error message and return the function
    {
      cout << "\nSorry "<<filename <<" file not found!\n\n";
      return 0;
    }

    string word; //variable that holds a single word taken from the file
    int count = -1; //initially assigned -1 to counter
    while (!fin.eof()) //looping until the end of the file
    {
      fin >> word; //takes a word from the file
      count++; //increments word count by 1
    }
    fin.close(); //closes the file 
    if(count > 0) //if counter is greater than 0 this means that there are word(s) in the file 
    {
      count += 1; //increments the count by 1 as we initially assigned -1 to the counter
    }
    return count; //return word count
}

int main()
{
    char filename[100]; //character array that takes the input for the file name entered by the user

    //requests the user to enter the file name
    cout << "Enter file name: ";
    cin>>filename; //takes an input for the file name
    int count = count_words(filename); //function call returns the count of words in the given file
    cout << "The number of words in the file is " << count << endl; //Display user to number of words in the file.
    return 0;
}
