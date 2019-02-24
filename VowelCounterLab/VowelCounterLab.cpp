// VowelCounterLab.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
Prompts the user to enter a string (allow for spaces in their input)
Stores the input as a C-String
Counts the number of vowels (a,e,i,o,u) including both capital and lower-case letters
Outputs the original C-String and the number of vowels: i.e. “The String ‘llama llama red pajama’ contains 8 vowels”
Gives the user the option to restart the program
 */

#include "pch.h"
#include <iostream>
#include <string>
#include <locale>

char vowel_bank[6] = { 'a','e','i','o','u','\0' };

int vowel_counter(char* c_string, char* const& vowel_bank)
{
	auto counter = 0;
	for (char* i = c_string; *i; ++i)
	{
		for (char* j = vowel_bank; *j; ++j)
		{
			if (*i == *j)
			{
				counter++;
			}
		}
	}
	return counter;
}

std::string output_result(const int vowel_count, char* c_string)
{
	auto output = "The String '" + std::string(c_string) + "' contains " + std::to_string(vowel_count) + " vowels.";
	return output;
}

int main()
{
	char c_string[128];
	char input_string[128];
	char restart_response[2];

	while (std::strncmp(restart_response, "N", 1) != 0)
	{
		const auto menu = "* Welcome to the Vowel Counter *\n*                              *\n*     Please enter a word      *\n";
		const auto restart = "\n\n* Do you want to restart the program? *\n* Any key to continue or 'N' to exit  *\n";

		std::cout << menu;
		std::cin.getline(input_string, 128);
		strcpy_s(c_string, input_string);

		const auto vowel_count = vowel_counter(c_string, vowel_bank);
		const auto menu_output = output_result(vowel_count, c_string);

		std::cout << menu_output;
		std::cout << restart;
		std::cin.getline(restart_response, 2);
	}
}

