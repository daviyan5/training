/**
Word Search

Given a 2-D grid of characters board and a string word, return true if the word is present in the
grid, otherwise return false.

For the word to be present it must be possible to form it with a path in the board with horizontally
or vertically neighboring cells. The same cell may not be used more than once in a word.

Example 1:

Input:
board = [
  ["A","B","C","D"],
  ["S","A","A","T"],
  ["A","C","A","E"]
],
word = "CAT"

Output: true

Example 2:

Input:
board = [
  ["A","B","C","D"],
  ["S","A","A","T"],
  ["A","C","A","E"]
],
word = "BAT"

Output: false

Constraints:

    1 <= board.length, board[i].length <= 5
    1 <= word.length <= 10
    board and word consists of only lowercase and uppercase English letters.

*/

#include <string>
#include <vector>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '#';
                    if (recurse(1, i, j, board, word)) {
                        board[i][j] = word[0];
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
    bool recurse(const size_t letter, const size_t i, const size_t j,
                 std::vector<std::vector<char>>& board, const std::string word) {
        if (letter >= word.size()) {
            return true;
        }
        for (const auto& move : moves) {
            const size_t next_i = i + move.first;
            const size_t next_j = j + move.second;

            const bool valid_i = next_i >= 0 && next_i < board.size();
            const bool valid_j = next_j >= 0 && next_j < board[0].size();

            if (!valid_i || !valid_j || board[next_i][next_j] != word[letter]) {
                continue;
            }

            board[next_i][next_j] = '#';
            if (recurse(letter + 1, next_i, next_j, board, word)) {
                board[next_i][next_j] = word[letter];
                return true;
            }
            board[next_i][next_j] = word[letter];
        }
        return false;
    }

private:
    const std::vector<std::pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};
