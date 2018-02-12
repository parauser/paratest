#ifndef TOGGLEGRID_H
#define TOGGLEGRID_H
#include "ToggleInt.h"
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Represents a grid of integer values that can be switched "on" and "off"
 * between a set value and zero
 */
class ToggleGrid
{
    protected:
        vector<vector<ToggleInt> > grid;
        int rows, cols;

    public:
        /**
         * @brief constructor to initialize the values of the grid
         * @param vals a 1-dimensional array of integers to initialize the grid
         */
        ToggleGrid(int vals[], int _rows, int _cols) : rows(_rows), cols(_cols) {
            for (int row = 0; row < rows; row++)
                grid.push_back(vector<ToggleInt>(cols));

            for (int nextRow = 0; nextRow < rows; nextRow++)
                for (int nextCol = 0; nextCol < cols; nextCol++)
                    grid[nextRow][nextCol] = vals[nextRow*cols + nextCol];
        }

        // Return text representation of grid
        string toString() {
            stringstream buf;

            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++)
                    buf << " " << grid[row][col].value();
                buf << '\n';
            }
            return buf.str();
        }

        // Toggle one of the squares of the grid
        void toggle(int row, int col) {
            grid[row][col].toggle();
        }

        /**
         * @brief sumRow computes the sum of all elements of a selected row that are "on"
         * @param row to add up
         * @return the sum
         */
        int sumRow(int row) {
            int sum = 0;
            for (int col = 0; col < cols; col++)
                sum += grid[row][col].value();
            return sum;
         }
        /**
         * @brief sumColumn computes the sum of all elements of a selected row that are "on"
         * @param column to add up
         * @return the sum
         */
        int sumColumn(int col) {
            int sum = 0;
            for (int row = 0; row < rows; row++)
                sum += grid[row][col].value();
            return sum;
         }
        /**
         * @brief 2 grids are equal if the sums of corresponding rows and columns are all equal
         * @param other
         * @return
         */
        bool operator==(ToggleGrid & other) {
            for (int row = 0; row < rows; row++) {
                    if (sumRow(row) != other.sumRow(row))
                        return false;
            }
            for (int col = 0; col < cols; col++) {
                if (sumColumn(col) != other.sumColumn(col))
                    return false;
            }
            return true;
        }
};


#endif // TOGGLEGRID_H
