#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <stdexcept>
using namespace std;

void askQuestion(int difficulty, int& score);
void askQuestion(string topic, int difficulty, int& score);
void startQuiz(string playerName, int difficulty = 1);
inline void insultPlayer();
bool isPassing(int correctAnswers);
void gameMenu();
int generateRandomQuestion(int difficulty);

/* forward declaration */
int generateRandomQuestion(int difficulty);

/*
This function presents a randomly generated math question based on the difficulty level.
It updates the player’s score if the answer is correct. It uses a try...catch block to
handle non-numeric inputs.
*/
void askQuestion(int difficulty, int& score) {
    try {
        int correctAnswer = generateRandomQuestion(difficulty);
        int playerAnswer;
        if (!(cin >> playerAnswer)) {
            throw runtime_error("Invalid input! Numbers only!");
        }
        if (playerAnswer == correctAnswer) {
            cout << "Correct!\n";
            ++score;
        } else {
            cout << "Wrong! ";
            insultPlayer();
        }
    }
    catch (runtime_error& e) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << e.what() << endl;
    }
}

/*
This overloaded function allows questions to be categorized by topic (e.g., “Math”,
“Logic”) while still maintaining difficulty scaling. It follows the same logic as the
basic askQuestion() but provides contextualized questions.
*/
void askQuestion(std::string topic, int difficulty, int& score) {
    cout << "[" << topic << "] ";
    askQuestion(difficulty, score);
}
/*
This function initiates the quiz for a specific player and difficulty level. It loops through
multiple questions and ensures the player answers at least a minimum (3) correct amount
before proceeding. I added extra if else statements so that if the character 'Stewie" is selected, 
the dialouge is not from Stewie himself.
*/
void startQuiz(std::string playerName, int difficulty) {
    if (playerName == "Stewie") {
        cout << "Brian: Alright Stew, let's see what YOU got!\n";
    }
    else {
    cout << "Stewie: Alright, " << playerName << ", let's see how smart you really are!\n";   
    }
    int score = 0;
    for (int i = 0 ; i < 5; i ++) {
        askQuestion(difficulty, score);
    }
    cout << "You got " << score << "/5 correct!\n";
    if (playerName == "Stewie") {
        if (isPassing(score)) {
            cout << "Stewie: HA! Was there really ever even any doubt?\n";
        } else {
            cout << "Brian: HA! You couldn't even pass your own quiz! In your own words 'Peter could even do better!' HA!\n";
        }
    } else {
    if (isPassing(score)) {
        cout << "Stewie: Fine, you win this round...\n";
    } else {
        cout << "Stewie: As expected, utterly pathetic.\n";
    }
    }
}
/* 
An inline function that randomly selects and displays one of Stewie’s signature insults
when a player provides a wrong answer. Here’s a list of signature insults to use: 
*/
inline void insultPlayer() {
    string insults[] = {
        "Moron!",
        "Pathetic!",
        "You disgust me!",
        "Even peter could answer this!"
    };
    int index = rand() % 4;
    cout << insults[index] << endl;
}

// A function that checks if a player has answered enough questions correctly to pass the quiz.
bool isPassing(int correctAnswers) {
    return correctAnswers >= 3;
}

/*
Displays a menu where the player can select a character. Uses a switch statement to
assign difficulty levels based on the chosen character.
*/
void gameMenu() {
    int choice;
    do {
        cout << "Choose a character:\n\n1. Peter\n2. Lois\n3. Meg\n4. Chris\n5. Brian\n6. Stewie\n7. Exit\n> ";
        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1: startQuiz("Peter", 1);
                break;
            case 2: startQuiz("Lois", 2);
                break;
            case 3: startQuiz("Meg", 3);
                break;
            case 4: startQuiz("Chris", 3);
                break;
            case 5: startQuiz("Brian", 4);
                break;
            case 6: startQuiz("Stewie", 5);
                break;
            case 7:
                cout << "Exiting...\n";
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
int generateRandomQuestion(int difficulty) {
    int a = rand() % (difficulty * 10 + 1);
    int b = rand() % (difficulty * 5 + 1);

    cout << "What is " << a << " + " << b << "? ";
    return a + b;
}
int main() {
    srand(37);
    gameMenu();
    return 0;
}

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