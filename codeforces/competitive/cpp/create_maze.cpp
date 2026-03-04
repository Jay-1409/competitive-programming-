#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to create a random maze with explicit walls
void createMaze(vector<vector<int>>& maze, int rows, int cols) {
    // Initialize the maze with WALL cells
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            maze[i][j] = 0;  // 0 represents WALL
        }
    }

    // Use recursive backtracking to create paths
    vector<pair<int, int>> stack;
    stack.push_back({1, 1}); // Start at a non-corner cell to allow walls on borders

    while (!stack.empty()) {
        pair<int, int> currentCell = stack.back();
        int x = currentCell.first;
        int y = currentCell.second;

        // Get neighboring cells
        vector<pair<int, int>> neighbors = {{x, y + 2}, {x + 2, y}};

        // Filter valid neighbors
        vector<pair<int, int>> validNeighbors;
        for (const auto& neighbor : neighbors) {
            int nx = neighbor.first;
            int ny = neighbor.second;
            if (nx > 0 && nx < rows - 1 && ny > 0 && ny < cols - 1 && maze[nx][ny] == 0) {
                validNeighbors.push_back(neighbor);
            }
        }

        if (!validNeighbors.empty()) {
            // Shuffle the valid neighbors for randomness
            random_shuffle(validNeighbors.begin(), validNeighbors.end());

            // Choose a random neighbor
            pair<int, int> nextCell = validNeighbors.back();
            validNeighbors.pop_back();
            int nx = nextCell.first;
            int ny = nextCell.second;

            // Create a path
            maze[nx][ny] = 1;  // 1 represents PATH
            maze[x + (nx - x) / 2][y + (ny - y) / 2] = 1;  // Create a path cell

            // Move to the next cell
            stack.push_back(nextCell);
        } else {
            // Backtrack if there are no valid neighbors
            stack.pop_back();
        }
    }

    // Set start and end points
    maze[1][1] = 1;  // 1 represents START
    maze[rows - 2][cols - 2] = 1;  // 1 represents END
}

// Function to print the maze
void printMaze(const vector<vector<int>>& maze) {
    for (const auto& row : maze) {
        for (const int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    // Seed the random number generator
    srand(time(0));

    int rows = 10;
    int cols = 10;

    // Initialize the maze with WALL cells
    vector<vector<int>> maze(rows, vector<int>(cols, 0));  // 0 represents WALL

    // Create the maze
    createMaze(maze, rows, cols);

    // Print the maze
    printMaze(maze);

    return 0;
}
