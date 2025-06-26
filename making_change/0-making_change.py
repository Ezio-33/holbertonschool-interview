#!/usr/bin/python3
"""Module pour rendre la monnaie."""


def makeChange(coins, total):
    """Retourne le nombre minimal de pièces
    nécessaires pour faire le total."""
    if total <= 0:
        return 0

    # Initialiser dp avec une valeur supérieure au maximum possible
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for i in range(1, total + 1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1


if __name__ == "__main__":
    print(makeChange([1, 2, 25], 37))
    print(makeChange([1256, 54, 48, 16, 102], 1453))
