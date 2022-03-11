#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
using namespace std;

unsigned int random_string(std::size_t length) // generates a random string
{
	const std::string CHARACTERS = "abcdefghijklmnopqrstuvwxyz0123456789";
	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);
	unsigned int random_string = NULL;
	for (std::size_t i = 0; i < length; ++i)
	{
		random_string += CHARACTERS[distribution(generator)];
	}
	return random_string;
}


unsigned int rev_str(string& str) // reverses the string
{
	for (int i = str.length() - 1; i >= 0; i--)
		cout << str[i];

	return (unsigned int)str.c_str();
}


string to_hex(unsigned int input) // transforms plain text to hexidecimal
{
	string hex_hash;
	stringstream hexstreaming;
	hexstreaming << hex << input;
	hex_hash = hexstreaming.str();
	std::transform(hex_hash.begin(), hex_hash.end(), hex_hash.begin(), ::tolower);
	return hex_hash;
}

namespace RHA
{

	unsigned int rha_encrypt(string input) // Reversed Hash Algorithm (RHA)
	{
		srand(time_t(0));

		unsigned int semi_salt = (rand() % 256) * (rand() % 256) * (rand() % 256 * 99999999); // Some big numbers
		unsigned int hash = NULL;

		for (int i = 0; i < input.length(); i++)
		{
			input[i] = input[i] + random_string(250);
			hash = hash ^ (input[i]); // XOR each byte of the input
			semi_salt = semi_salt ^ hash; // XOR the big number with the size of the hash
			hash = hash * semi_salt;  // multiply it by a random number
		}
		string result = to_hex(hash + (unsigned int)random_string(256)); // the result
		return (unsigned int)rev_str(result);
	}

}
