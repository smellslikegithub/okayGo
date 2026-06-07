#include<iostream>
#include<clocale>
#include<array>
#include<filesystem>
#include<cstdlib>
#include<ctime>

#include "WordHelper.hpp"

class HangMan
{
public:
	HangMan(std::string wordToGuess, int maxTries) {
		this->wordToGuess = wordToGuess;
		this->maxTries = maxTries;
	}



private:
	std::string wordToGuess;
	int maxTries;

};




int main() {

	std::setlocale(LC_ALL, "");
	
	
	std::filesystem::path filePath = std::filesystem::current_path() / "resources" / "words.txt";

	std::vector<std::string> words = WordHelper::loadFromFile(filePath.string());

	int randomNumber;

	srand(time(0));

	int option{};
	
	while (true) {
		std::cout << "[1]: Play Hangman!\n";
		std::cout << "[2]: Quit!\n";
		std::cin >> option;

		switch (option)
		{
		case 1:
			std::cout << "Hang man game ran!\n\n";
			break;
		
		case 2:
			std::cout << "Quitting game!\n\n";
			break;
			
		default:
			std::cout << "Invalid option selected!";
			break;
		}

		if (option == 2) break;
	}

	//if (!words.empty()) {
	//	for (int i = 0; i < 20; i++) {
	//		randomNumber = rand() % words.size() + 1;
	//		std::cout << "Random Number : " << randomNumber <<"\n";
	//	}
	//	

	//	
	//}


}