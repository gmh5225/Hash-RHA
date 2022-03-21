#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <thread>
#include "md5.h"

using namespace std;


unsigned int rev_str(string& str) // reverses the string
{
	for (int i = str.length() - 1; i >= 0; i--)
		cout << str[i];

	
	return tolower((unsigned int)str.c_str());
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
			hash = hash ^ (input[i % sizeof(semi_salt)]); // XOR each byte of the input
			semi_salt = semi_salt ^ hash << 3; // XOR the big number with the size of the hash
			hash = hash * semi_salt << 5;  // multiply it by a random number

		}
		string normal_result = to_hex(hash); // build the hash

		// procedure 2 ( take the hash and make it so hash identifiers cant assosiate it with other algorithms )

		normal_result = normal_result += (hash ^ semi_salt) ^ hash;
		string scrambled = to_hex((unsigned int)normal_result.c_str());

		// procedure 3 ( get the hash and encode it with md5 , and the md5 result will be added to the hash )

		string md5_result = md5(scrambled); // encode it using md5

		string final_result = (scrambled + md5_result); // add it to the string

		return rev_str(final_result); // return it but reversed

	}

}
