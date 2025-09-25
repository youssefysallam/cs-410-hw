#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
This function presents a randomly generated math question based on the difficulty level.
It updates the player’s score if the answer is correct. It uses a try...catch block to
handle non-numeric inputs.
*/
void askQuestion(int difficulty, int& score);{
    
}

/*
This overloaded function allows questions to be categorized by topic (e.g., “Math”,
“Logic”) while still maintaining difficulty scaling. It follows the same logic as the
basic askQuestion() but provides contextualized questions.
*/
void askQuestion(std::string topic, int difficulty, int& score);

/*
This function initiates the quiz for a specific player and difficulty level. It loops through
multiple questions and ensures the player answers at least a minimum (3) correct amount
before proceeding.
*/
void startQuiz(std::string playerName, int difficulty = 1);

/* 
An inline function that randomly selects and displays one of Stewie’s signature insults
when a player provides a wrong answer. Here’s a list of signature insults to use: 
*/
inline void insultPlayer();

// A function that checks if a player has answered enough questions correctly to pass the quiz.
bool isPassing(int correctAnswers); {
    return correctAnswers >= 3;
}

/*
Displays a menu where the player can select a character. Uses a switch statement to
assign difficulty levels based on the chosen character.
*/
void gameMenu(); {
    int choice;
    do {
        cout << "Choose a character:\n\n1. Peter\n2. Lois\n3. Meg\n4. Chris\n5. Brian\n Stewie\n7. Exit";
        cin >> choice
   
        switch (choice) {
            case 1: startQuiz("Peter", 1); 
                break;
            case 2: startQuiz("Lois", 2);
                break;
            case 3: startQuiz("Meg", 3);
                break;
            case 4: startQuiz("Chris", 4);
                break;
            case 5; startQuiz("Brian", 5);
                break;
            case 6: startQuiz("Stewie", 6);
                break;
            default: cout << "Invalid choice!\n";
                break; 
        }
    } while (choice != 7);
}

/*
Generates two random numbers based on difficulty and returns their sum as the correct
answer. This ensures a variety of randomized questions. The following difficulty level
should be used for each player: Peter (1), Lois (2), Meg (3), Chris (3), Brain (4) and
Stewie (5). Here is the function to randomly generate the two numbers:
*/
int generateRandomQuestion(int difficulty);{
    int a = rand() % (difficulty * 10);
    int b = rand() % (difficulty * 5);

    cout << "What is " << a << " + " << b << "?";
    return a + b;
}
int main() {}

/*
SAMPLE OUTPUT: 
Choose a character:
1. Peter
2. Lois
3. Meg
4. Chris
5. Brian
6. Stewie
7. Exit
> 3
Stewie: Alright, Meg, let's see how smart you really are!
What is 8 + 6? > 14
Correct!
What is 5 + 3? > 7
Wrong! Moron!
What is 12 + 9? > 21
Correct!
You got 2/3 correct!
Stewie: Fine, you win this round...
3
Choose a character:
1. Peter
2. Lois
3. Meg
4. Chris
5. Brian
6. Stewie
7. Exit
*/