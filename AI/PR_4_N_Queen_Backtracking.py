# N-Queen Problem using Backtracking (CSP)

N = 4

board = [[0] * N for _ in range(N)]


# Check if queen can be placed
def is_safe(row, col):

    # Check left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Upper diagonal
    i = row
    j = col

    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1

    # Lower diagonal
    i = row
    j = col

    while i < N and j >= 0:
        if board[i][j] == 1:
            return False
        i += 1
        j -= 1

    return True


# Backtracking function
def solve(col):

    # All queens placed
    if col >= N:
        return True

    # Try every row
    for row in range(N):

        if is_safe(row, col):

            board[row][col] = 1

            # Recur for next column
            if solve(col + 1):
                return True

            # Backtrack
            board[row][col] = 0

    return False


# Solve
if solve(0):

    print("Solution Found:\n")

    for row in board:
        print(row)

else:
    print("No Solution")