#include "WordHelper.hpp"
#include<cwctype>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>

bool WordHelper::isWordValid(const std::string& word) {
	if (word.empty()) {
		return false;
	}

	for (const char& letter : word) {
		if (!std::iswalpha(letter)) {
			return false;
		}
	}

	return true;
}

std::vector<std::string> WordHelper::loadWordsFromFile(const std::string& filePath) {

	std::vector<std::string> words;

	std::ifstream file(filePath);

	if (!file) {
		std::cerr << "File: " << filePath << " failed to open!\n";
		return words;
	}

	std::string word;

	while (file >> word) {
		
		words.push_back(word);
	}
	
	return words;
}

