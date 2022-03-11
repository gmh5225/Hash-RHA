#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <thread>
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
	unsigned int rha_hash(string input) // Reversed Hash Algorithm (RHA)
	{
		// procedure 1 ( build the hash and scramble it as good as possible )
		srand(time_t(0)); // seed

		unsigned int semi_salt = (rand() % 256) * (rand() % 32000) * (rand() % 256 * rand() % 40000); // Some big numbers
		unsigned int hash = NULL; // init the hash var

		for (int i = 0; i < input.length(); i++)
		{
			input[i] = input[i % sizeof(semi_salt)] ^ sizeof(input.length()); // some more scrambling 
			input[i] = input[i] + random_string(250); // make it impossible to crack
			hash = hash ^ (input[i % sizeof(semi_salt)]); // XOR each byte of the input
			semi_salt = semi_salt ^ hash; // XOR the big number with the size of the hash
			hash = hash * semi_salt;  // multiply it by a random number
			
		}
		string normal_result = to_hex((unsigned int)random_string(50) + hash); // build the hash

		// procedure 2 ( take the hash and hash it even better )

		normal_result = normal_result += (hash ^ semi_salt) ^ hash;
		string scrabmled = to_hex((unsigned int)normal_result.c_str());
		return (unsigned int)rev_str(scrabmled); // return it

	}

}
