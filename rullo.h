#pragma once
#include "ToggleGrid.h"
#include <cstdlib>
#include <ctime>

// Represents a game of Rullo,
// where you try to switch off and on numbers
// in a grid so each row and column match
// desired sums
class Rullo {
protected:
    int rows, cols;
    int minVal, maxVal;
    ToggleGrid *solution, *playing;
    const int TOGGLE_CHANCE = 4; // 1/TOGGLE_CHANCE chance of toggling square for solution

    // Toggle off squares randomly
    void turnOffSquares() {
        for (int row = 0; row < rows; row++)
            for (int col = 0; col < cols; col++)
                if (0 == rand() % TOGGLE_CHANCE)
                    solution->toggle(row, col);
    }

    // initialize puzzle with random values
    void initGrids() {
        int * values = new int[rows * cols];
        for (int row = 0; row < rows; row++)
            for (int col = 0; col < cols; col++)
                values[row*cols + col] = rand() % (maxVal-minVal) + minVal;

        solution = new ToggleGrid(values, rows, cols);

        turnOffSquares();

        playing = new ToggleGrid(values, rows, cols);

        // Can uncomment for debugging purposes
        // cout << solution->toString() << endl;
        // cout << playing->toString() << endl;
    }

    // Display sums of rows and sums of columns for a grid
    void displaySums(ToggleGrid * grid) {
        for (int row = 0; row < rows; row++)
            cout << "row " << row << ": sum = " << grid->sumRow(row) << endl;
        for (int col = 0; col < cols; col++)
            cout << "col " << col << ": sum = " << grid->sumColumn(col) << endl;
    }

    // Have the player choose a square to toggle
    void makeMove() {
        int row, col;   // for square to toggle
        cout << "Enter the row and column of the square to toggle off: ";
        cin >> row >> col;
        playing->toggle(row, col);
    }
public:
    // Initialize random number generator for game
    Rullo() {
        srand(time(NULL));
    }

    // play one game of Rullo
    void play() {
        char quit = 'N';
        cout << "Indicate the desired size of puzzle, # rows and # columns, separated by a space:" << endl;
        cin >> rows >> cols;
        cout << "Indicate the minimum and maximum integers for the puzzle:" << endl;
        cin >> minVal >> maxVal;

        initGrids();
        while (quit != 'Y')
        {
            cout << "The grid looks like this: " << endl;
            cout << playing->toString() << endl;

            // Show goal vs. current sums for rows, columns
            cout << "The sums for the solution are: " << endl;
            displaySums(solution);
            cout << "The current sums are: " << endl;
            displaySums(playing);

            makeMove();
            if ((*solution) == (*playing))
            {
                cout << "Congratulations! You solved the puzzle!" << endl;
                return;
            }
            cout << "Do you want to quit? (Y to quit, anything else to continue): ";
            cin >> quit;
        }
    }
};
