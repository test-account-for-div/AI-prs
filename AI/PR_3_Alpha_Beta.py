# Alpha-Beta Pruning for the Given Tree

MAX = 1000
MIN = -1000

# Tree leaf values from left to right
# D -> 2,3
# E -> 5,9
# F -> 0,1
# G -> 7,5

values = [2, 3, 5, 9, 0, 1, 7, 5]


def alpha_beta(depth, node, maximizing, alpha, beta):

    # Leaf node
    if depth == 3:
        return values[node]

    # MAX player's turn
    if maximizing:
        best = MIN

        for i in range(2):

            value = alpha_beta(
                depth + 1,
                node * 2 + i,
                False,
                alpha,
                beta
            )

            best = max(best, value)
            alpha = max(alpha, best)

            # Pruning condition
            if beta <= alpha:
                break

        return best

    # MIN player's turn
    else:
        best = MAX

        for i in range(2):

            value = alpha_beta(
                depth + 1,
                node * 2 + i,
                True,
                alpha,
                beta
            )

            best = min(best, value)
            beta = min(beta, best)

            # Pruning condition
            if beta <= alpha:
                break

        return best


result = alpha_beta(
    depth=0,
    node=0,
    maximizing=True,
    alpha=MIN,
    beta=MAX
)

print("Optimal Value =", result)