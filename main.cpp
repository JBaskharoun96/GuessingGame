#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

void playGame();
void printVector(vector<int> guessVector);

int main()
{
    int choice;

    do {
        cout << "0. Quit" << endl << "1. Play Game" << endl;
        cin >> choice;

        switch (choice){
            case 0:
                cout << "\nSee you later, space cowboy" << endl;
                return 0;
            case 1:
                cout << "\nBegin game:" << endl;
                playGame();
                break;
        }
    } while (choice != 0);

    return 0;
}

void playGame(){

    random_device rd;
    mt19937 gen(rd());
    int maxGuess;
    cout << "\nWhat should be the maximum range?" << endl;
    cin >> maxGuess;
    uniform_int_distribution<> distrib(1, maxGuess);

    vector<int> guessVector;

    int randInt = distrib(gen);

    // cout << randInt << endl << endl;
    cout << "\nGuess a number between 1 and " << maxGuess << ":" << endl;

    while(true){
        int guess;
        cin >> guess;
        guessVector.push_back(guess);

        if(guess == randInt){
            cout << "Correct!" << endl << endl;
            break;
        }
        else if(guess < randInt){
            cout << "Too low, try again!" << endl;
        }
        else if (guess > randInt){
            cout << "Too high, try again!" << endl;
        }
    }
    printVector(guessVector);
}

void printVector(vector<int> guessVector){

    cout << "Your guesses:" << endl;
    for (int i = 0; i < guessVector.size(); i++){
        cout << guessVector[i] << "\t";
    }
    cout << endl << endl;
}






