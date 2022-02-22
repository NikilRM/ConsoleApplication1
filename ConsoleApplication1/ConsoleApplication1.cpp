

#include <iostream>
#include<ctime>
void Intro(int Difficulty)
{
	std::cout << "  Breaking into a secure Terminal...."<<Difficulty;
	std::cout << std::endl;
	std::cout << "Enter the correct code to continue...";
	std::cout << std::endl;
	std::cout << "There are three numbers in the code..." << std::endl;
	
}
bool PlayGmae(int Difficulty)
{

	Intro(Difficulty);
	const int CodeA = rand() % Difficulty +Difficulty;
	const int CodeB = rand()% Difficulty + Difficulty;
	const int CodeC = rand()% Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;// Sum of Variable 
	const int CodeMul = CodeA * CodeB * CodeC;// Product of Variable
	std::cout << std::endl;
	std::cout << "The codes adds up to.." << CodeSum;
	std::cout << std::endl;
	std::cout << "The product of the code is..." << CodeMul << std::endl;

	int GuessCodeA, GuessCodeB, GuessCodeC;
	
	std::cin >> GuessCodeA >> GuessCodeB >> GuessCodeC;// Enter The guess

	int GuessSum = GuessCodeA + GuessCodeB + GuessCodeC;
	int GuessMul = GuessCodeA * GuessCodeB * GuessCodeC;

	if (GuessSum == CodeSum && GuessMul == CodeMul)// Checks if GuessSum/GuessMul = CodeSum/CodeMul
	{
		std::cout << "Good job finding the Sum and Product of the code..." << std::endl;
		std::cout << "Access Granted....." << std::endl; // Win statement
		return true;
	}
	else
	{
		std::cout << "Breach detected. Be Carefull!!" << std::endl;//lose statement
		return false;


	}
}

int main()
{
	srand(time(NULL));
	int LevelDifficult = 1;
	const int MaxDifficulty = 20;

	while (LevelDifficult <=MaxDifficulty)// Loop the game until all levels completed
	{
		bool bLevelComplete = PlayGmae(LevelDifficult);
		std::cin.clear();// Clears Any Errors
		std::cin.ignore();//Discards the Buffer
		if (bLevelComplete)
		{
			++LevelDifficult;
			std::cout << "\n\nInitializing next terminal. Please Wait!.....\n\n";
		}
		
	}
	std::cout << "\n\n Hack complete we got them!!...";
	return 0;
}

