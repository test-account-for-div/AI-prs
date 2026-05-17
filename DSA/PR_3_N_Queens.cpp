#include <iostream>
using namespace std;

int board[10][10];
int solutionCount = 0;

bool isSafe(int row, int col, int n) {
  for (int i = 0; i < col; i++)
    if (board[row][i] == 1)
      return false;

  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j] == 1)
      return false;

  for (int i = row, j = col; i < n && j >= 0; i++, j--)
    if (board[i][j] == 1)
      return false;

  return true;
}

void printBoard(int n) {
  cout << "\nSolution " << ++solutionCount << ":\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
}

bool solveNQueens(int col, int n) {
  if (col >= n) {
    printBoard(n);
    return true;
  }

  bool res = false;

  for (int row = 0; row < n; row++) {
    if (isSafe(row, col, n)) {
      board[row][col] = 1;

      //
      res = solveNQueens(col + 1, n) || res;

      board[row][col] = 0;
    }
  }

  return res;
}

int main() {
  int n;
  cout << "No of queens: ";
  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      board[i][j] = 0;

  if (!solveNQueens(0, n))
    cout << "No solution exists";
  else
    cout << "\nTotal solutions: " << solutionCount;

  return 0;
}
