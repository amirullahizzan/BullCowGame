#include "FBullCowGame.h"



using int32 = int;


FBullCowGame::FBullCowGame(){	Reset();}
//Constructor (in the runtime overridden everything)

//define values in the early construct

int32 FBullCowGame::GetMaxTries() const 
{	return MyMaxTries;} //Constant <string> to prevent any future changes on the value

int32 FBullCowGame::GetCurrentTry() const
{	return MyCurrentTry;} //public returns a private variable

int32 FBullCowGame::GetHiddenWordLength() const
{	return MyHiddenWords.length();} //return = apa yang akan di hasilkan dari fungsi tsbt

bool FBullCowGame::IsGameWon() const
{	return bIsGameWon;}

void FBullCowGame::Reset()
{
	
	constexpr int32 MAX_TRIES = 7;
	const FString HIDDEN_WORDS = "planet";

	MyHiddenWords = HIDDEN_WORDS;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	bIsGameWon == false;
	return;
}




EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) //insert conditions to False for bypass
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_LowerCase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}

}

//Receives a valid guess, increments turn, return count. 
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{

	//increment the turn number
	MyCurrentTry++;
	//setup a return variable
	FBullCowCount BullCowCount;

	int32 WordLength = MyHiddenWords.length();

	//loop through all letters in the guess words
	for (int32 MyHiddenWordChar = 0; MyHiddenWordChar < WordLength; MyHiddenWordChar++)
	{
		//compare both between guess and the hidden answer
		for (int32 GuessChar = 0; GuessChar < WordLength; GuessChar++)
		{


			//if match then (correct)
			if (Guess[GuessChar] == MyHiddenWords[MyHiddenWordChar])
			{
				if (MyHiddenWordChar == GuessChar) //increments bulls if they are in the same place and correct
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}

		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bIsGameWon = true;
	}
	else
	{
		bIsGameWon = false;
	}
	return BullCowCount;
}
