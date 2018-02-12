#include <iostream>
#include "rullo.h"

using namespace std;

// Driver to start up the game of Rullo
int main()
{
    Rullo game;
    char again = 'y';
    cout << "This is a version of the game Rullo" << endl;
    while (again != 'n') {
        game.play();
        cout << "Do you want to play again? (n to stop, anything else to play again): ";
        cin >> again;
    }
    return 0;
}
