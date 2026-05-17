# Simple Hill Climbing for 8 Puzzle Problem

goal = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 0]
]

start = [
    [1, 2, 3],
    [4, 0, 6],
    [7, 5, 8]
]


# Heuristic function
# Counts misplaced tiles
def heuristic(state):

    count = 0

    for i in range(3):
        for j in range(3):

            if state[i][j] != 0 and state[i][j] != goal[i][j]:
                count += 1

    return count


# Find blank position
def find_blank(state):

    for i in range(3):
        for j in range(3):

            if state[i][j] == 0:
                return i, j


# Generate neighboring states
def neighbors(state):

    x, y = find_blank(state)

    moves = [
        (-1, 0),  # Up
        (1, 0),   # Down
        (0, -1),  # Left
        (0, 1)    # Right
    ]

    result = []

    for dx, dy in moves:

        nx = x + dx
        ny = y + dy

        if 0 <= nx < 3 and 0 <= ny < 3:

            # Copy board
            new_state = [row[:] for row in state]

            # Swap blank tile
            new_state[x][y], new_state[nx][ny] = \
                new_state[nx][ny], new_state[x][y]

            result.append(new_state)

    return result


# Hill Climbing Algorithm
def hill_climbing(current):

    while True:

        print("\nCurrent State:")
        for row in current:
            print(row)

        current_h = heuristic(current)

        print("Heuristic =", current_h)

        # Goal reached
        if current_h == 0:
            print("\nGoal State Reached!")
            return

        next_state = None
        next_h = current_h

        # Find better neighbor
        for neighbor in neighbors(current):

            h = heuristic(neighbor)

            if h < next_h:
                next_state = neighbor
                next_h = h

        # No better state found
        if next_state is None:
            print("\nReached Local Optimum")
            return

        current = next_state


# Run algorithm
hill_climbing(start)