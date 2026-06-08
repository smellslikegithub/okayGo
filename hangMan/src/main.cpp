#include<iostream>
#include<clocale>
#include<array>
#include<cctype>
#include<filesystem>
#include<cstdlib>
#include<ctime>

#include "WordHelper.hpp"

class HangMan
{
public:
	HangMan(){
		std::filesystem::path filePath = std::filesystem::current_path() / "resources" / "words.txt";
		std::vector<std::string> wordsFromFile = WordHelper::loadWordsFromFile(filePath.string());
		this->words = wordsFromFile;
		this->wordToGuess = wordsFromFile[(rand() % wordsFromFile.size())];
	}

	HangMan(std::string wordsFilePath) {
		std::vector<std::string> wordsFromFile = WordHelper::loadWordsFromFile(wordsFilePath);
		this->words = wordsFromFile;
		this->wordToGuess = wordsFromFile[(rand() % wordsFromFile.size())];
	}

	int getMaxTries() {
		
		return this->MAXTRIES;
	}

	std::string reshuffleWord() {
		if (this->words.empty()) {
			std::cerr << "Nothing to reshuffle! Words list is empty";
			return "";
		}
		this->wordToGuess = this->words[(rand() % words.size())];
		return this->wordToGuess;
	}

	std::string getWordToGuess() {
		if(this->wordToGuess.empty()){
			std::cerr << "Word to guess has not been initialized yet!";
			return "";
		}

		return this->wordToGuess;
	}

	void runGame() {

		int option{};

		while (true) {
			std::cout << "[1]: Play Hangman!\n";
			std::cout << "[2]: Quit!\n";
			std::cin >> option;

			switch (option)
			{
			case 1:
				this->clearGame();
				this->engine();
				break;

			case 2:
				std::cout << "Quitting game!\n\n";
				break;

			default:
				std::cout << "Invalid option selected!\n\n";
				break;
			}

			if (option == 2) break;

		}

	}


private:
	std::string wordToGuess;
	std::vector<std::string> words;
	const int MAXTRIES = 6;
	int currentTries = 0;
	std::vector<char> guessedLetters;
	// implement highscore. Not sure if I should have a seperate Game class that deals with state management
	// But when I will include Graphics, I will need to refactor this. For now, keeping high score stack with this 
	// class.

	const std::array<std::string, 7> HANGMAN_STAGES = {
		R"(
 +---+
     |
     |
     |
     |
     |
=========
)",
R"(
 +---+
 |   |
 O   |
     |
     |
     |
=========
)",
R"(
 +---+
 |   |
 O   |
 |   |
     |
     |
=========
)",
R"(
 +---+
 |   |
 O   |
/|   |
     |
     |
=========
)",
R"(
 +---+
 |   |
 O   |
/|\  |
     |
     |
=========
)",
R"(
 +---+
 |   |
 O   |
/|\  |
/    |
     |
=========
)",
R"(
 +---+
 |   |
 O   |
/|\  |
/ \  |
     |
=========
)"
	};


	void clearGame(){
		this->currentTries = 0;
		this->guessedLetters = {};
	}

	void drawHangman() {

		std::cout << this->HANGMAN_STAGES[this->currentTries];
	
	}


	void drawUserInterface(const std::string& str = "") {
		if (str.empty()) {
			std::cerr << "Empty string. Cannot render characters!\n";
			return;
		}

		std::cout << "\n\n[====================HangMan Ultimate=============================]" << "\n";
		std::cout << "Tries Left: " << MAXTRIES - currentTries<<"\n\n";

		this->drawHangman();
		
		std::cout << "\n"<<"Word: ";
		
		for (char c : str) {
			std::cout << c << " ";

		}

		std::cout << "\n\n[====================++++++++++++++++=============================]" << "\n";
	}

	void engine() {
		char guessedLetter;
		int correctlyGuessedLetterCount = 0;
		std::string maskedGuessedWord(this->wordToGuess.size(), '_');
		std::vector<char> guessedLetters;
		bool foundCharInLoop = false;
		
		this->drawUserInterface(maskedGuessedWord);

		std::cout << "Sectre Word: " << this->wordToGuess << "\n";
		while (maskedGuessedWord != this->wordToGuess && currentTries < this->MAXTRIES){

			
			std::cout << "\n";

			std::cout << "Guess a letter: ";
			std::cin >> guessedLetter;

			if (isblank(guessedLetter)) {
				std::cerr << "You have not input any letter\n";
				continue;
			}

			if (std::find(guessedLetters.begin(), guessedLetters.end(), guessedLetter) != guessedLetters.end()) {
				std::cout << "The letter has already been guessed!\n";
				continue;
			}

			guessedLetters.push_back(guessedLetter);

			this->guessedLetters.push_back(guessedLetter);

			
			for (int i = 0; i < this->wordToGuess.size(); i++) {
				
				if (wordToGuess[i] == guessedLetter) {
					foundCharInLoop = true;

					correctlyGuessedLetterCount++;
					maskedGuessedWord[i] = guessedLetter;
					
				}

			}


			if (foundCharInLoop == false) {
				this->currentTries++;

			}
			foundCharInLoop = false;


			this->drawUserInterface(maskedGuessedWord);
			
		
		}

		if (maskedGuessedWord == this->wordToGuess) {
			std::cout << "You Guessed the word! Congrats" << "\n\n";
		}

		else {
			std::cout << "You ran out of chances!"<<" The word was "<<this->wordToGuess<<". Try playing again!" << "\n\n";
		}
		
	
	}

};




int main() {

	std::setlocale(LC_ALL, "");
	
	// This C-style random generator is giving some warnings. For now keep it as is. Not using 0 but static casting null ptr
	std::srand(time(0));
	HangMan hangmanGame;
	hangmanGame.runGame();

	/****** Bug Counter ******/
	// 1. Main menu crashes if non numeric value given
	// 2. 
	

	/****** TODOs ******/
	// ?. Solve this Please: warning C4244: 'argument': conversion from 'time_t' to 'unsigned int', possible loss of data
	// 1. Add tests
	// 
	// 2. Create statically linked binaries


	/****** Feat ******/
	// 1. Add score board
	// 2. Persist scores and user names
	// ?. Introduce OpenGl or SFML for graphics. Or RayLib. 
	
}