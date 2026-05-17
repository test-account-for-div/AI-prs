# N-Queen using Branch and Bound

N = 4

board = [[0] * N for _ in range(N)]

# Arrays for fast checking
left_row = [False] * N
upper_diagonal = [False] * (2 * N - 1)
lower_diagonal = [False] * (2 * N - 1)


def solve(col):

    # All queens placed
    if col >= N:
        return True

    for row in range(N):

        # Check conflicts
        if (left_row[row] == False and
            lower_diagonal[row + col] == False and
            upper_diagonal[N - 1 + col - row] == False):

            # Place queen
            board[row][col] = 1

            left_row[row] = True
            lower_diagonal[row + col] = True
            upper_diagonal[N - 1 + col - row] = True

            # Recur
            if solve(col + 1):
                return True

            # Backtrack
            board[row][col] = 0

            left_row[row] = False
            lower_diagonal[row + col] = False
            upper_diagonal[N - 1 + col - row] = False

    return False


# Solve
if solve(0):

    print("Solution Found:\n")

    for row in board:
        print(row)

else:
    print("No Solution")