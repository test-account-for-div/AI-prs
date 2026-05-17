# Sudoku Solver using CSP + Backtracking

board = [
    [3, 0, 6, 5, 0, 8, 4, 0, 0],
    [5, 2, 0, 0, 0, 0, 0, 0, 0],
    [0, 8, 7, 0, 0, 0, 0, 3, 1],
    [0, 0, 3, 0, 1, 0, 0, 8, 0],
    [9, 0, 0, 8, 6, 3, 0, 0, 5],
    [0, 5, 0, 0, 9, 0, 6, 0, 0],
    [1, 3, 0, 0, 0, 0, 2, 5, 0],
    [0, 0, 0, 0, 0, 0, 0, 7, 4],
    [0, 0, 5, 2, 0, 6, 3, 0, 0]
]


# Print board
def print_board():

    for row in board:
        print(row)


# Find empty cell
def find_empty():

    for i in range(9):
        for j in range(9):

            if board[i][j] == 0:
                return i, j

    return None


# Check if number is safe
def is_safe(row, col, num):

    # Row check
    for x in range(9):

        if board[row][x] == num:
            return False

    # Column check
    for x in range(9):

        if board[x][col] == num:
            return False

    # 3x3 box check
    start_row = row - row % 3
    start_col = col - col % 3

    for i in range(3):
        for j in range(3):

            if board[start_row + i][start_col + j] == num:
                return False

    return True


# CSP Backtracking Solver
def solve():

    empty = find_empty()

    # Puzzle solved
    if not empty:
        return True

    row, col = empty

    # Try numbers 1 to 9
    for num in range(1, 10):

        if is_safe(row, col, num):

            board[row][col] = num

            # Recur
            if solve():
                return True

            # Backtrack
            board[row][col] = 0

    return False


# Run solver
if solve():

    print("Solved Sudoku:\n")

    print_board()

else:
    print("No Solution")