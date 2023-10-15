#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed the random number generator with the current time
    //ensuring that the random numbers generated are different each time the program is run
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 1 and 100
    //This line generates a random number between 1 and 100 using the std::rand() function. 
	//std::rand() % 100 generates a number between 0 and 99, and we add 1 to ensure the range is from 1 to 100.
    int random_number = rand() % 100 + 1;

    // Initialize variables
    int guess;
    int attempts = 0;

    cout << "-------------------- NUMBER GUESSING GAME --------------------" <<endl <<endl;
    cout << "                 RANDOM NUMBER HAS BEEN SELECTED" <<endl;
	cout << "                      RANGE 1 - 100 " <<endl; 
	cout << "                    TRY GUESSING IT" <<endl;

    while (true) {
        // Ask the user for their guess
        cout << "\nENTER YOUR GUESS: ";
        cin >> guess;

        // Increment the number of attempts
        attempts++;

        // Check if the guess is correct
        if (guess == random_number) {
        	cout << "                ___________________________________________";
            cout << "\n               |              CONGRATULATIONS !!!          |"<<endl;
			cout << "               |                 YOU DID IT                |" <<endl;
			cout << "               |                Number: " << random_number << "                 |"<<endl;
			cout << "               |          GUESSED IN " << attempts << " ATTEMPTS            |" <<endl;
			cout << "               |___________________________________________|";
            break;
        } else if (guess < random_number) {
            cout << "\nTOO LOW :(" << endl;
            cout << "       TRY AGAIN!!!" <<endl;
        } else {
            cout << "\nTOO HIGH :(" << endl;
            cout << "       TRY AGAIN!!!" <<endl;
        }
    }

    return 0;
}

