#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int numberToGuess = rand() % 100 + 1; 
    int guess;

    cout << "Welcome to the Number Guessing Game!" << endl;

    do {
        cout << "Enter your guess (1-100): ";
        cin >> guess;

        if (guess > numberToGuess)
            cout << "Too high! Try again.\n";
        else if (guess < numberToGuess)
            cout << "Too low! Try again.\n";
        else
            cout << "Congratulations! You guessed the correct number.\n";

    } while (guess != numberToGuess);

    return 0;
}
