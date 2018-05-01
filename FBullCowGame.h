#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//all values initialized to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;

};
//F is a UnrealEngine Class Format

/*We are now using header files classes as Contracts, 
it was put inside a header file 
to allow library extraction*/

//Classes -> Having Instances to work

enum class EGuessStatus //ENUM adalah type global tidak seperti ENUM class
{
	//Error Messages:
	InvalidStatus, //bait
	OK,
	Not_Isogram,
	Wrong_Length,
	NumberInput,
	Not_LowerCase

};

class FBullCowGame //F is for Unreal Class
{
public:
	//functions only
	FBullCowGame(); //Constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; 

	void Reset();	
	FBullCowCount SubmitValidGuess(FString); //counts bulls cows and submit valid guesses

	//To get a getter method: simply make a functions and return a private variables

private:
	//variables
	//Doesnt require parenthesis because is a variable
	
	//see constructor for values
	
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWords;
	bool bIsGameWon;
	
};



