#include <iostream>
#include <ctime>

void PrintIntroduction(int DifficultyLevel)
{
    std::cout << "\n Hello Advait, Welcome to the game. We are very excited to have you on board. I wish there were better circumstance when we meet but there has been a situation in our buliding. we have a hostage situation going on in our building and we need you to help us out.";
    std::cout << std::endl;
    std::cout << "Welcome to level " << DifficultyLevel;
    std::cout << std::endl;
    std::cout << "+ You need to input the correct code to open the gates of the building.";
}

bool PlayGame(int DifficultyLevel)
{
    PrintIntroduction(DifficultyLevel);

    const int CodeA = rand() % DifficultyLevel + 1;
    // std::cout << a;
    // std::cout << std::endl;
    const int CodeB = rand() % DifficultyLevel + 1;
    // std::cout << b;
    // std::cout << std::endl;
    const int CodeC = rand() % DifficultyLevel + 1;
    // std::cout << c;
    // std::cout << std::endl;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "+ Hints to get the code +";
    std::cout << std::endl;
    std::cout << "+ There are three digits in this code. ";
    std::cout << std::endl;
    std::cout << "+ If you add the three digits you get: " << CodeSum;
    std::cout << std::endl;
    std::cout << "+ If you multiply the three digits you get: " << CodeProduct;
    std::cout << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "Your guess was:" << GuessA << GuessB << GuessC;
    std::cout << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "You have won the round";
        return true;
    }
    else
    {
        std::cout << "You have lost the round";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    const int MaxDifficulty = 5;
    int LevelDifficulty = 1;
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool blevelcomplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (blevelcomplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "\nCongratulations on completing the game.";
    return 0;
}