/**
Number of Islands

Given a 2D grid grid where '1' represents land and '0' represents water, count and return the number of islands.

An island is formed by connecting adjacent lands horizontally or vertically and is surrounded by water. You may assume water is surrounding the grid (i.e., all the edges are water).

Example 1:

Input: grid = [
    ["0","1","1","1","0"],
    ["0","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
  ]
Output: 1

Example 2:

Input: grid = [
    ["1","1","0","0","1"],
    ["1","1","0","0","1"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
  ]
Output: 4

Constraints:

    1 <= grid.length, grid[i].length <= 100
    grid[i][j] is '0' or '1'.


 */

#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        const size_t n = grid.size() * grid[0].size();
        std::vector<bool> visited(n, 0);
        int islands = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                const size_t index = i * grid[0].size() + j;
                if (grid[i][j] == '1' && !visited[index]) {
                    ++islands;
                    visitNeighboors(i, j, grid, visited);
                }
            }
        }
        return islands;
    }
    void visitNeighboors(const size_t i, const size_t j, std::vector<std::vector<char>>& grid,
                         std::vector<bool>& visited) {
        const size_t index = i * grid[0].size() + j;
        visited[index] = true;
        for (auto& [u, v] : neighboors) {
            const size_t new_i = i + u;
            const size_t new_j = j + v;
            if (new_i < 0 || new_i >= grid.size() || new_j < 0 || new_j >= grid[0].size() ||
                grid[new_i][new_j] == '0') {
                continue;
            }
            const size_t new_index = new_i * grid[0].size() + new_j;
            if (!visited[new_index]) {
                visitNeighboors(new_i, new_j, grid, visited);
            }
        }
    }

private:
    const std::vector<std::pair<int, int>> neighboors = {
        {1, 0},   // down
        {-1, 0},  // up
        {0, 1},   // right
        {0, -1}   // left
    };
};
