#pragma once

#include<string>
#include<vector>

namespace WordHelper
{
    std::vector<std::string> loadWordsFromFile(const std::string& filePath);
	bool isWordValid(const std::string& word);
}