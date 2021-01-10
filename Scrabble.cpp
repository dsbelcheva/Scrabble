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
void NewGame (int number_of_currentline, int number_letters);
void Words (string new_word);
void AddWord ();
int main()
{
	Menu();
	int option1_of_menu = Options();
	int number_of_rounds = 10;
	int numberofletters = 10;
	int numberof_roundstoinput;
	int input_numberofletters;
	int numberof_therest_ofrounds = 0;
	int sumof_allrounds_infile = 50;
	int all_rounds = 60;
	int new_allrounds;
	char option2_of_menu;
	while (option1_of_menu != 4) {
		switch (option1_of_menu) {
		case 1: {
			NewGame(number_of_rounds, numberofletters);
			cout << endl;
			cout << ">>Returning to menu.";
			cout << endl;
			break;
		}
		case 2: {
			cout << "Select one of the two sub-options: ";
			cin >> option2_of_menu;
			if (option2_of_menu == 'a') {
				do {
					cout << "Enter number of rounds: ";
					cin >> number_of_rounds;
					if (number_of_rounds > all_rounds) cout << "The maximum number of all rounds is " << all_rounds << " !" << endl;
				} 
				while (number_of_rounds > all_rounds);
				if (number_of_rounds > 50) {
					if (number_of_rounds != sumof_allrounds_infile) {
						numberof_roundstoinput = number_of_rounds - sumof_allrounds_infile;
						numberof_therest_ofrounds = all_rounds - number_of_rounds;
						cout << "You need to input " << numberof_roundstoinput << " words in the dictionary." << endl;
						for (int i = 0; i < numberof_roundstoinput; i++) {
							AddWord();
							sumof_allrounds_infile++;

						}
					}
				}
			}
			if (option2_of_menu == 'b') {
				do {
					cout << "Enter number of letters: ";
					cin >> input_numberofletters;
					if (input_numberofletters > 25) cout << "The maximum number of letters is 25!" << endl;
					numberofletters = input_numberofletters;
				} 
				while (input_numberofletters > 25);
			}
			if (option2_of_menu == 'c') {
				cout << "Enter the number of all rounds if you want to play more than 60 rounds: ";
				cin >> new_allrounds;
				if (new_allrounds > 60) all_rounds = new_allrounds;
			}
			cout << endl;
			cout << ">>Returning to menu.";
			cout << endl;
			break;
		}
		case 3: {
			if (number_of_rounds > 50) {
				if (numberof_therest_ofrounds != 0) {
					AddWord();
					sumof_allrounds_infile++;
					cout << ">>Returning to menu.";
					cout << endl;
				}
				else {
					cout << "You reach the maximum number of rounds.You can't add any words." << endl;
					cout << ">>Returning to menu.";
					cout << endl;
				}
			}
			else {
				AddWord();
				sumof_allrounds_infile++;
				cout << ">>Returning to menu.";
				cout << endl;
			}
			break;
		}
		}
		cout << endl;
		Menu();
		option1_of_menu = Options();
	}
	return 0;
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
void NewGame(int number_of_lines, int number_of_letters)
{
	ifstream read_letters;
	read_letters.open("Dictionary.txt", ios::in);
	int totalsum_of_points = 0;
	for (int i = 1; i <= number_of_lines; i++) {
		int line_number = i;
		int lines_read = 0;
		int size = 0; //in order to check for empty line
		string line;
		if (read_letters.is_open()) {
			while (read_letters) {
				getline(read_letters, line);
				size = line.size();
				if (size != 0) {                         //check if it is not empty line
					line.resize(2 * number_of_letters);   //it is multiplied by 2 because 
														//of the intervals between each letters
					lines_read++;
					if (lines_read == line_number) {
						cout << ">>Round " << line_number << "." << "Available letters: " << line << endl;
						break;
					}
				}
				else {
					continue;
				}
			}
		}
		else {
			cout << "File cannot be found!";
		}
		int size_of_line = line.size();
		string word;
		bool correct_word = 0;
		int size_of_inputword = word.size();
		cout << "Enter a word:" << endl << "<<";
		cin >> word;
		//check if the word entered by the user is correct
		do {
			if ((size_of_inputword > size_of_line) || (OnlyLetters(word) == 0) || (size_of_inputword > 100)) {
				cout << "Invalid word.Try again.Available letters: " << line << endl;
				cout << "<<";
				cin >> word;
			}
			else {
				correct_word = 1;
			}
		}
		while (correct_word == 0);
		//check if the word entered by the user is contained in the given word
		bool correct_input = 0;
		do {
			if (CheckTheWords(line, word) == 0) {
				cout << "Invalid word.Try again.Available letters: " << line << endl;
				cout << "<<";
				cin >> word;
			}
			else {
				cout << "Your points are: " << CheckTheWords(line, word);
				cout << endl;
				correct_input = 1;
			}
		} 
		while (correct_input == 0);
		totalsum_of_points = totalsum_of_points + CheckTheWords(line, word);
	}
	cout << "Your total points are: " << totalsum_of_points;
	read_letters.close();
}
void Words (string new_word)
{
	ofstream word2;
	word2.open("Dictionary.txt", ios::app);
	word2 << new_word << endl;
	word2.close();
}
void AddWord ()
{
	string addword;
	int size_of_addword = 0;      //in order to do the while-loop for first time
	do {
		cout << "Enter a new word with small latin letters: ";
		cin >> addword;
		size_of_addword = addword.size();
		if (size_of_addword != 25) {
			cout << "The number of letters must be 25!Try again." << endl;
			if (OnlyLetters(addword) != 1) {
				cout << "Enter only small latin letters." << endl;
			}
		}
		else {
			for (int i = 0; i < size_of_addword * 2; i++) {    //It is size_of_addword*2 because of 
				                                              //the intervals between every letters.
				if (addword[i] != ' ') {
					addword.insert(i + 1, " ");
				}
			}
		}
	} 
	while (size_of_addword != 25);
	Words (addword);
}



