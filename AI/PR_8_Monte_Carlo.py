# Simple Monte Carlo Tree Search (MCTS)
# for Tic-Tac-Toe

import random
import math
import copy


# Tic-Tac-Toe State
class GameState:

    def __init__(self, board=None, player='X'):

        if board is None:
            self.board = [' '] * 9
        else:
            self.board = board

        self.player = player

    # Available moves
    def moves(self):

        return [i for i in range(9) if self.board[i] == ' ']

    # Apply move
    def next_state(self, move):

        new_board = copy.deepcopy(self.board)

        new_board[move] = self.player

        next_player = 'O' if self.player == 'X' else 'X'

        return GameState(new_board, next_player)

    # Check winner
    def winner(self):

        win_positions = [
            [0,1,2], [3,4,5], [6,7,8],
            [0,3,6], [1,4,7], [2,5,8],
            [0,4,8], [2,4,6]
        ]

        for pos in win_positions:

            a, b, c = pos

            if (self.board[a] ==
                self.board[b] ==
                self.board[c] != ' '):

                return self.board[a]

        return None

    # Game over
    def is_terminal(self):

        return (
            self.winner() is not None or
            ' ' not in self.board
        )


# Tree Node
class Node:

    def __init__(self, state, parent=None):

        self.state = state
        self.parent = parent

        self.children = []

        self.wins = 0
        self.visits = 0


# UCB Formula
def ucb(node, total_visits):

    if node.visits == 0:
        return float('inf')

    return (
        node.wins / node.visits +
        math.sqrt(2 * math.log(total_visits) / node.visits)
    )


# Selection
def select(node):

    while node.children:

        node = max(
            node.children,
            key=lambda child: ucb(child, node.visits)
        )

    return node


# Expansion
def expand(node):

    for move in node.state.moves():

        child = Node(
            node.state.next_state(move),
            node
        )

        node.children.append(child)

    return random.choice(node.children)


# Simulation
def simulate(state):

    current = state

    while not current.is_terminal():

        move = random.choice(current.moves())

        current = current.next_state(move)

    return current.winner()


# Backpropagation
def backpropagate(node, winner):

    while node:

        node.visits += 1

        if winner == 'X':
            node.wins += 1

        node = node.parent


# MCTS Algorithm
def mcts(root, iterations):

    for _ in range(iterations):

        node = select(root)

        if not node.state.is_terminal():
            node = expand(node)

        winner = simulate(node.state)

        backpropagate(node, winner)

    best_child = max(
        root.children,
        key=lambda child: child.visits
    )

    return best_child


# Print Board
def print_board(board):

    for i in range(0, 9, 3):
        print(board[i:i+3])


# Initial State
initial = GameState()

root = Node(initial)

best_move = mcts(root, 1000)

print("Best Board After AI Move:\n")

print_board(best_move.state.board)