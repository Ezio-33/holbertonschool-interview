#!/usr/bin/python3
import sys


def is_safe(solution, row, col):
    """
    Vérifie si une reine peut être placée en (row, col)
    sans entrer en conflit avec les reines existantes.
    """
    for i in range(row):
        if solution[i] == col or abs(solution[i] - col) == row - i:
            return False
    return True


def solve_nqueens(n):
    """
    Génère toutes les solutions du problème des N Queens.
    Retourne une liste de solutions (chaque solution est
        une liste de [row, col]).
    """
    result = []

    def backtrack(row, current_solution):
        if row == n:
            result.append([[i, current_solution[i]] for i in range(n)])
            return
        for col in range(n):
            if is_safe(current_solution, row, col):
                backtrack(row + 1, current_solution + [col])

    backtrack(0, [])
    return result


def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = solve_nqueens(n)
    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
