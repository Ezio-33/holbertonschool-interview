#!/usr/bin/python3
"""Prime Game – détermination du vainqueur sur plusieurs manches.

Maria et Ben jouent sur un ensemble d'entiers {1, 2, ..., n}.
À tour de rôle, un joueur choisit un nombre premier p encore présent
et supprime p ainsi que tous ses multiples. Le joueur qui ne peut plus
jouer (aucun nombre premier restant) perd la manche.

Ce module expose la fonction : isWinner(x, nums)
- x (int) : nombre de manches
- nums (List[int]) : liste des n pour chaque manche
Retourne le nom du joueur qui gagne le plus de manches :
- "Maria" ou "Ben"
- None en cas d'égalité ou d'entrée invalide

Contraintes :
- Pas d'import autorisé
- Python 3.4.3 / PEP8 1.7.x
"""


def _sieve_prefix(max_n):
    """Construit un tableau de préfixes du nombre de nombres premiers ≤ i.

    Algorithme :
      1) Crible d'Ératosthène pour marquer les nombres premiers jusqu'à max_n.
      2) Tableau prefix[i] = nombre de premiers ≤ i.

    Args:
        max_n (int): borne maximale.

    Returns:
        list: tableau prefix de longueur max_n + 1, où prefix[i] est le
              nombre de nombres premiers ≤ i.
    """
    if max_n < 2:
        # Aucun premier ≤ 1
        return [0] * (max_n + 1)

    # Étape 1 : crible
    is_prime = [True] * (max_n + 1)
    is_prime[0] = False
    is_prime[1] = False

    p = 2
    while p * p <= max_n:
        if is_prime[p]:
            # Marque tous les multiples de p à partir de p*p
            m = p * p
            while m <= max_n:
                is_prime[m] = False
                m += p
        p += 1

    # Étape 2 : préfixes cumulés du nombre de premiers
    prefix = [0] * (max_n + 1)
    count = 0
    i = 0
    while i <= max_n:
        if is_prime[i]:
            count += 1
        prefix[i] = count
        i += 1

    return prefix


def isWinner(x, nums):
    """Détermine le vainqueur global après x manches, jeu optimal.

    Idée clé (raisonnement):
      - Dans une manche avec valeur n, le nombre de coups possibles
        correspond au nombre de nombres premiers ≤ n (car chaque coup
        choisit un premier encore disponible).
      - Si ce nombre est impair, la première joueuse (Maria) effectue
        le dernier coup ⇒ elle gagne la manche.
      - S'il est pair, Ben gagne la manche.
      - On agrège ensuite les victoires sur x manches.

    Args:
        x (int): nombre de manches.
        nums (list of int): liste des valeurs n pour chaque manche.

    Returns:
        str or None: "Maria", "Ben" ou None si indéterminé/égalité.
    """
    # Validation d'entrée minimale
    if (not isinstance(x, int)) or (x <= 0):
        return None
    if (nums is None) or (not isinstance(nums, list)) or (len(nums) == 0):
        return None

    # Borne pour le crible : max des n de toutes les manches
    max_n = 0
    i = 0
    ln = len(nums)
    while i < ln:
        n = nums[i]
        if isinstance(n, int) and n > max_n:
            max_n = n
        i += 1

    # Pré-calcul : nombre de premiers ≤ i pour tout i ≤ max_n
    prefix = _sieve_prefix(max_n)

    # Comptage des victoires
    maria_wins = 0
    ben_wins = 0

    i = 0
    while i < x and i < ln:
        n = nums[i]
        if not isinstance(n, int) or n < 1:
            # n invalide ⇒ pas de premiers ⇒ Ben gagne cette manche
            ben_wins += 1
        else:
            # Nombre de premiers ≤ n
            primes_up_to_n = prefix[n]
            if (primes_up_to_n % 2) == 1:
                maria_wins += 1
            else:
                ben_wins += 1
        i += 1

    # Décision finale
    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
