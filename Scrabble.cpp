// Scrabble.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/**
*
* Solution to course project # 8
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Desislava Belcheva
* @idnumber 62608
* @compiler VC
*
* <this is the main file>
*
*/

#include <iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;
void Menu ();
int Options ();
bool OnlyLetters (string word1);
int CheckTheWords (string line, string word);
int NewGame (int number_of_currentline, int number_letters);
void Rounds (int number_of_lines, int number_of_letters);
void Words (string new_word);
void AddWord ();
int main()
{

}
void Menu ()
{
	cout << "Menu:" << endl;
	cout << "1.Start new game" << endl;
	cout << "2.Settings:" << endl;
	cout << " a.Change the number of rounds" << endl;
	cout << " b.Change the number of letters" << endl;
	cout << " c.Change the number of all rounds to more than 60" << endl;
	cout << "3.Enter a new word" << endl;
	cout << "4.Exit" << endl;
}
int Options ()
{
	int option_of_menu;
	do {
		cout << "Select one of the above options: ";
		cin >> option_of_menu;
		if (option_of_menu > 4) {
			cout << "Incorrect input.Please select one of the above options.";
		}
	} 
	while (option_of_menu > 4);
	return option_of_menu;
}


