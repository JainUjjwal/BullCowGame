#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game


int main()
{
	do
	{
		PrintIntro();

		PlayGame();
	}
	while (AskToPlayAgain());
	std::cout << std::endl;
	return 0;
}

void PrintIntro()
{
	// Intro to the game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to bulls and cows!\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	//printf("Can you guess the %d letter word im thinking of ? \n", WORD_LENGTH);
	return;
}

void PlayGame()
{
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	//Guess loop 
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		// Repeat the output
		std::cout << "your guess is : " << Guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "try " << CurrentTry << ": ";
	
	// User input
	std::cout << "enter your guess : ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "do you want to play again (y/n)? ";
	std::string response = "";
	std::getline(std::cin, response);
	return (response[0] == 'y') || (response[0] == 'Y');
}