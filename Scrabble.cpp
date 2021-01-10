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
bool OnlyLetters (string word1)
{
	bool is_letter = 1;    //check if the character is letter
	for (int i = 0; word1[i] != '\0'; i++) {
		if (!(word1[i] <= 'z' && word1[i] >= 'a')) {
			is_letter = 0;
			break;
		}
	}
	return is_letter;
}
int CheckTheWords (string line, string word)
{
	int sizeof_line = line.size();
	int sizeof_inputword = word.size();
	int sum_of_points = 0;
	char letters_of_line[52] = {};
	char letters_of_word[52] = {};
	int count=0;
	int index1_of_letters = 0;
	int index2_of_count = 0;
	int freq_of_line[26] = { 0 };
	//finds the frequency of the letters in the word from the file
	for (int i = 97; i <= 122; i++) {
		for (int j = 0; j < sizeof_line; j++) {
			if (i == line[j]) {
				count++;
				if (count == 1) {
					letters_of_line[index1_of_letters] = line[j];
					index1_of_letters++;
				}
			}
		}
			if (count != 0) {
				freq_of_line[index2_of_count] = count;
				index2_of_count++;
				count = 0;
			}
	}
	int numberof_letters_in_word = 0;
	int indexof_freq_of_word = 0;
	int freq_of_word[26] = { 0 };
	//finds the frequency of the letters in the entered word
	for (int i = 97; i <= 122; i++) {
			count = 0;
			for (int j = 0; j < sizeof_inputword; j++) {
				if (i == word[j]) {
					count++;
					if (count == 1) {
						letters_of_word[numberof_letters_in_word] = word[j];
						numberof_letters_in_word++;
					}
				}
			}
			if (count != 0) {
				freq_of_word[indexof_freq_of_word] = count;
				indexof_freq_of_word++;
			}
	}
	//compare the frequencies of the letters of the two words
	int correct_letters;
	for (int i = 0; i < numberof_letters_in_word; i++) {
		correct_letters = 0;
		for (int j = 0; j < index1_of_letters; j++) {
			if (letters_of_word[i] == letters_of_line[j]) {
				if (freq_of_word[i] == freq_of_line[j]) {
					correct_letters++;
				}
				else {
					if (freq_of_word[i] < freq_of_line[j]) {
						correct_letters++;
					}
					if (freq_of_word[i] > freq_of_line[j]) {
						break;
					}
				}
			}
		}
		if (correct_letters == 0) {
			break;
		}
	}
	if (correct_letters == 0) {
		sum_of_points = 0;
	}
	else {
		sum_of_points = sizeof_inputword;
	}
	return sum_of_points;
}



