# Prime Game

Ce projet fait partie de mon apprentissage en algorithmique dans le cadre de ma formation.
Détermination du vainqueur d’un jeu combinatoire basé sur les nombres premiers. Pour chaque manche de valeur `n`, les joueurs (Maria puis Ben) retirent à tour de rôle un **nombre premier** restant et **tous ses multiples** du set {1..n}. Le joueur qui ne peut plus jouer perd la manche. On répète sur `x` manches et on renvoie le joueur ayant gagné le plus de manches (ou `None` en cas d’égalité).

## Exigences (Holberton)

- Éditeurs autorisés : `vi`, `vim`, `emacs`
- Ubuntu 14.04 LTS, Python 3.4.3
- Tous les fichiers se terminent par une nouvelle ligne
- Première ligne exacte : `#!/usr/bin/python3`
- Respect du style **PEP 8 (version 1.7.x)**
- Tous les fichiers doivent être exécutables
- **Aucun import** autorisé

## Fichiers fournis

- `0-prime_game.py` : implémente `isWinner(x, nums)`.
- `main_0.py` : petit script de test (fourni pour reproduire l’exemple du sujet).

## Prototype

```python
def isWinner(x, nums):
    """
    x (int): nombre de manches
    nums (List[int]): liste des n pour chaque manche
    return: "Maria", "Ben", ou None si égalité/indéterminé
    """
```

## Règles et intuition

- À chaque coup, on choisit un premier p encore présent et on retire p et ses multiples.
- Le nombre total de coups possibles dans une manche n est exactement le **nombre de nombres premiers ≤ n**.
- Si ce nombre est impair, la première joueuse (Maria) joue le dernier coup → manche gagnée par Maria. S’il est pair → manche pour Ben.

## Approche / Algorithme

1. Pré-calcul d’un tableau `prefix` par **crible d’Ératosthène** jusqu’à `max(nums)`:
   - `prefix[i]` = nombre de premiers ≤ i.
2. Pour chaque manche `n`, on lit `prefix[n]` et on décide le gagnant de la manche selon sa parité.
3. On additionne les victoires et on renvoie "Maria", "Ben" ou `None`.

### Complexité

- Crible: O(N log log N) en temps, O(N) en mémoire, avec `N = max(nums)`.
- Décision par manche: O(1). Total: O(x) après le crible.

### Cas limites gérés

- `n < 2` → aucun premier → manche pour Ben.
- `x <= 0` ou `nums` invalide/vide → `None`.
- Valeurs non entières ou ≤ 0 dans `nums` → traitées comme sans premiers (Ben gagne la manche).

## Exemple (du sujet)

```
x = 3, nums = [4, 5, 1]
Round 1 (n=4): Ben
Round 2 (n=5): Maria
Round 3 (n=1): Ben
Résultat: Ben a le plus de victoires → "Ben"
```

## Exécution rapide

Avec pyenv (ex: environnement `formation-env`) :

```bash
pyenv activate formation-env
chmod +x 0-prime_game.py main_0.py
./main_0.py
```

Sortie attendue pour l’exemple intégré :

```
Winner: Ben
```

Sans `main_0.py`, depuis Python :

```bash
pyenv activate formation-env
python -c "from 0-prime_game import isWinner; print(isWinner(5, [2,5,1,4,3]))"
```

## Qualité / Conformité

- Shebang `#!/usr/bin/python3` présent.
- Aucun import.
- PEP 8 1.7.x (indentation 4 espaces, lignes raisonnables, docstrings).
- Fichiers exécutables.

Optionnel (local) : vérifier le style avec pep8 1.7.1 :

```bash
pep8 --version
pep8 0-prime_game.py
```
