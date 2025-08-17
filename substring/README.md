# Substring with Concatenated Words

## 📖 Description

Ce projet implémente une fonction qui trouve tous les indices possibles dans une chaîne de caractères où l'on peut former une sous-chaîne en concaténant une liste de mots donnés. Chaque mot de la liste doit être utilisé exactement une fois, sans caractères d'espacement entre eux.

**Auteur**: Alexandre Gautier, Software Engineer at Holberton School  
**Niveau**: Amateur  
**Poids**: 1

## 🎯 Objectif

Développer une fonction C qui :

- Trouve tous les indices de sous-chaînes valides dans une chaîne donnée
- Valide que chaque sous-chaîne est une concaténation exacte des mots fournis
- Retourne un tableau dynamique contenant tous les indices trouvés

## 📋 Prérequis

### Environnement

- **OS**: Ubuntu 14.04 LTS ou supérieur
- **Compilateur**: gcc 4.8.4 ou supérieur
- **Editeurs autorisés**: vi, vim, emacs

### Standards de code

- **Style**: Betty (vérification avec `betty-style.pl` et `betty-doc.pl`)
- **Flags de compilation**: `-Wall -Werror -Wextra -pedantic`
- **Variables globales**: Interdites
- **Fonctions par fichier**: Maximum 5
- **Include guards**: Obligatoires pour les headers

## 🚀 Installation et compilation

### Clonage du repository

```bash
git clone https://github.com/holbertonschool/holbertonschool-interview.git
cd holbertonschool-interview/substring
```

### Compilation manuelle

```bash
gcc -Wall -Wextra -Werror -pedantic main.c substring.c -o substring
```

### Compilation avec Makefile

```bash
# Compilation simple
make

# Compilation avec tests
make test

# Nettoyage
make clean      # Supprime les fichiers objets
make fclean     # Supprime tous les fichiers générés
make re         # Recompilation complète

# Vérification du style
make betty

# Aide
make help
```

## 📁 Structure du projet

```
substring/
├── substring.h          # Fichier d'en-tête avec les prototypes
├── substring.c          # Implémentation principale
├── main.c              # Fichier de test (optionnel)
├── Makefile            # Script de compilation
└── README.md           # Documentation du projet
```

## 🔧 Utilisation

### Prototype de la fonction

```c
int *find_substring(char const *s, char const **words, int nb_words, int *n);
```

### Paramètres

- **s**: La chaîne de caractères à scanner
- **words**: Tableau de mots à concaténer
- **nb_words**: Nombre d'éléments dans le tableau `words`
- **n**: Pointeur pour stocker le nombre d'éléments retournés

### Valeur de retour

- **Succès**: Tableau alloué dynamiquement contenant les indices
- **Échec**: `NULL` si aucune solution trouvée

### Exemple d'utilisation

```c
#include "substring.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char const *s = "barfoothefoobarman";
    char const *words[] = {"foo", "bar"};
    int nb_words = 2;
    int n;
    int *indices;
    int i;

    indices = find_substring(s, words, nb_words, &n);

    printf("Indices trouvés: [");
    for (i = 0; i < n; i++)
    {
        if (i > 0) printf(", ");
        printf("%d", indices[i]);
    }
    printf("]\n");

    free(indices); // Important: libérer la mémoire
    return (0);
}
```

## 🧪 Tests

### Exemples fournis

1. **Test 1**:

   ```bash
   ./substring barfoothefoobarman foo bar
   # Résultat attendu: [0, 9]
   ```

2. **Test 2**:

   ```bash
   ./substring wordgoodgoodgoodbestword word good best word
   # Résultat attendu: []
   ```

3. **Test 3**:
   ```bash
   ./substring wordgoodgoodgoodbestword word good best good
   # Résultat attendu: [8]
   ```

### Explication des résultats

**Test 1**: `barfoothefoobarman` avec `["foo", "bar"]`

- Position 0: `bar` + `foo` = `barfoo` ✓
- Position 9: `bar` + `man` ≠ `barfoo` ❌
- Position 9: `foo` + `bar` = `foobar` ✓

**Test 2**: `wordgoodgoodgoodbestword` avec `["word", "good", "best", "word"]`

- Aucune position ne permet de former une concaténation valide avec tous les mots

**Test 3**: `wordgoodgoodgoodbestword` avec `["word", "good", "best", "good"]`

- Position 8: `good` + `good` + `best` + `word` ✓

## 🏗️ Architecture du code

### Fonctions principales

1. **`find_substring`**: Fonction principale qui orchestre la recherche
2. **`word_count`**: Vérifie si une sous-chaîne contient exactement chaque mot une fois
3. **`validate_input`**: Valide les paramètres d'entrée
4. **`resize_indices_array`**: Gère le redimensionnement dynamique du tableau de résultats

### Algorithme

1. **Validation**: Vérifier les paramètres d'entrée
2. **Parcours**: Pour chaque position possible dans la chaîne
3. **Extraction**: Extraire une sous-chaîne de longueur totale des mots
4. **Vérification**: Diviser en blocs et vérifier la correspondance avec les mots
5. **Stockage**: Sauvegarder les indices valides

### Complexité

- **Temporelle**: O(n × m × k)
  - n = longueur de la chaîne
  - m = nombre de mots
  - k = longueur d'un mot
- **Spatiale**: O(m + r)
  - m = nombre de mots (pour le tableau `used`)
  - r = nombre de résultats

## 🔍 Vérification du style

### Betty Style

```bash
# Vérification automatique
make betty

# Vérification manuelle
betty-style substring.c substring.h
betty-doc substring.c
```

### Standards respectés

- ✅ Moins de 80 caractères par ligne
- ✅ Moins de 40 lignes par fonction
- ✅ Documentation complète des fonctions
- ✅ Noms de variables explicites
- ✅ Gestion d'erreurs appropriée

## 🐛 Débogage

### Problèmes courants

1. **Segmentation fault**:

   - Vérifier que `n` n'est pas NULL
   - S'assurer que `words` et `s` ne sont pas NULL

2. **Résultats incorrects**:

   - Vérifier que tous les mots ont la même longueur
   - S'assurer que la logique de `word_count` est correcte

3. **Fuites mémoire**:
   - Toujours appeler `free()` sur le tableau retourné
   - Vérifier la gestion mémoire dans `resize_indices_array`

### Outils de débogage

```bash
# Compilation avec symboles de débogage
gcc -g -Wall -Wextra -Werror -pedantic main.c substring.c -o substring_debug

# Utilisation avec Valgrind
valgrind --leak-check=full ./substring_debug barfoothefoobarman foo bar
```

## 📚 Ressources

- [Holberton School Interview Repository](https://github.com/holbertonschool/holbertonschool-interview)
- [Betty Style Guide](https://github.com/holbertonschool/Betty)
- [C Programming Best Practices](https://www.kernel.org/doc/html/latest/process/coding-style.html)

## 📄 Licence

Ce projet fait partie du curriculum Holberton School et est destiné à des fins éducatives.

## 👥 Contribution

Ce projet fait partie d'un exercice d'entretien technique. Les contributions externes ne sont pas acceptées, mais les suggestions d'amélioration sont les bienvenues pour des fins pédagogiques.

---

**Note**: Ce README fait partie du projet "Substring with concatenated words" développé dans le cadre du programme Holberton School.
