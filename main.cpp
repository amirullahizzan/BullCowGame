/*Console Executable 

*/

#include <iostream>
#include <string>
#include "ConsoleColor.h"
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame PlayBCGame; //Instance of the game, IMPORTANT:The class gets renamed once its inside main

int main()
{
	
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	std::cout << white;

	return 0;
	//0 just fine for int type data
}

void PrintIntro()
{	

	std::cout << "\n\nSelamat datang di " << green << std::endl << std::endl << "=====SALTY SPITOOOON=====" << white << "!" << std::endl << std::endl;
	std::cout << "Anda harus menebak sebuah Isogram sebanyak " << green << PlayBCGame.GetHiddenWordLength() << white << " kata" << std::endl;
	std::cout << "Kesempatan Menebak : " << green << PlayBCGame.GetMaxTries() << white << std::endl;

	return;
}


void PlayGame()
{
	PlayBCGame.Reset();
	int32 MAXTRIES = PlayBCGame.GetMaxTries();
	
	while (!PlayBCGame.IsGameWon() && PlayBCGame.GetCurrentTry() <= MAXTRIES )
	{
		FText Guess = GetValidGuess();
		


		//submit valid guess to the game and receive counts
			FBullCowCount BullCowCount = PlayBCGame.SubmitValidGuess(Guess);

		//print bulls n cows
		std::cout << white << "Bulls = " << BullCowCount.Bulls << " ";
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;

		//TODO summarise the game
	}
	PrintGameSummary();
	return;
}


FText GetValidGuess()
{
	// Define the things before the loop
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::InvalidStatus; //declare bait and default value
	
	do {

	int32 CURRENTTRY = PlayBCGame.GetCurrentTry();
	std::cout << std::endl << red << "Attempt " << white << ": " << CURRENTTRY << std::endl;
	std::cout << "Insert lower case guess :" << std::endl << green << std::endl;
	std::getline(std::cin, Guess);

	
		Status = PlayBCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << red << "Jumlah huruf yang anda masukkan harus " << PlayBCGame.GetHiddenWordLength() << white << "\n";

			break;
		case EGuessStatus::Not_Isogram:
			std::cout << red << "Masukkan kata dengan tidak mengulangi huruf yang sama" << "\n";

			break;
		case EGuessStatus::NumberInput:
			std::cout << red << "Masukkan hanya karakter saja" << "\n";

			break;
		case EGuessStatus::Not_LowerCase:
			std::cout << red << "Karakter yang anda masukkan bukan huruf kecil" << "\n";

			break;
		default:

			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); //keep looping until OK valid input
	return Guess;
}


bool AskToPlayAgain()
{

	std::cout << std::endl << "Mau maen lagi kagak" << yellow << " (y/n)" << green << std::endl << white << std::endl;
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');

}

void PrintGameSummary()
{
	if (PlayBCGame.IsGameWon())
	{
		std::cout << "\nSelamat cuy lu menang\n";
	}
	else
	{
		std::cout << "\nBro lagi sial lu ya NOOB (n)";
	}
	return;
}
