#include <iostream>
#include <vector>

using namespace std;

// Function to preprocess the grid and convert to binary grid
void preprocessAndConvert(vector<vector<char>>& grid, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char cell = grid[i][j];
            if (cell == '>' || cell == '<' || cell == '^' || cell == 'v') {
                // Iterate in the direction specified by the character
                int dx = 0, dy = 0;
                if (cell == '>') dx = 1;
                else if (cell == '<') dx = -1;
                else if (cell == '^') dy = -1;
                else if (cell == 'v') dy = 1;

                int x = i + dx;
                int y = j + dy;

                while (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == '.') {
                    grid[x][y] = '!'; // Mark as visible
                    x += dx;
                    y += dy;
                }
            }
        }
    }

    // Convert grid to binary representation
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 'S' || grid[i][j] == 'G') {
                cout << grid[i][j];
            } else if (grid[i][j] == '.' || grid[i][j] == '!') {
                cout << '1';
            } else {
                cout << '0';
            }
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    preprocessAndConvert(grid, rows, cols);

    return 0;
}
