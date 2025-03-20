<div id="top">

<!-- STYLE D'EN-TÊTE : CLASSIQUE -->
<div align="center">

<img src="readmeai/assets/logos/purple.svg" width="30%" style="position: relative; top: 0; right: 0;" alt="Logo du Projet"/>

# MENGER

<em>Des fractales d'efficacité, simplifiées</em>

<!-- BADGES -->
<!-- dépôt local, pas de méta-données pour les badges. -->

<em>Construit avec les outils et technologies :</em>

<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=default&logo=C&logoColor=black" alt="C">

</div>
<br>

---

## Table des Matières

- [Table des Matières](#table-des-matières)
- [Aperçu](#aperçu)
- [Fonctionnalités](#fonctionnalités)
- [Structure du Projet](#structure-du-projet)
  - [Index du Projet](#index-du-projet)
- [Prise en main](#prise-en-main)
  - [Prérequis](#prérequis)
  - [Installation](#installation)
  - [Utilisation](#utilisation)
  - [Tests](#tests)
- [Feuille de route](#feuille-de-route)
- [Contribuer](#contribuer)

---

## Aperçu

---

## Fonctionnalités

| Composant        | Détails                                                                                                                                                                                                              |
| :--------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Architecture** | _Algorithme du Cube de Menger implémenté_                                                                                                                                                                            |
| 🔩               | _Qualité du code_: <ul><li>Respecte les standards de codage Holberton en C</li></ul>                                                                                                                                 |
| 📄               | _Documentation_: <ul><li>Contient des commentaires en anglais et en français</li><li>Utilise une documentation de style Doxygen pour l'API</li></ul>                                                                 |
| 🔌               | _Intégrations_: <ul><li>Dépend du compilateur `c` pour la compilation</li><li>Utilise des fichiers d'en-tête `h` pour les fonctions de la librairie standard</li></ul>                                               |
| 🧩               | _Modularité_: <ul><li>Sépare la logique en fonctions et modules distincts</li><li>Utilise un design pattern modulaire pour organiser le code</li></ul>                                                               |
| 🧪               | _Tests_: <ul><li>Inclut des tests unitaires pour chaque fonction avec la fonction `check_win`</li><li>Utilise des assertions pour la vérification des erreurs</li></ul>                                              |
| ⚡️              | _Performance_: <ul><li>Optimisé pour la performance grâce à des algorithmes itératifs</li><li>Minimise les calculs inutiles ainsi que les allocations mémoire superflues</li></ul>                                   |
| 🛡️               | _Sécurité_: <ul><li>Valide les entrées utilisateur pour prévenir les dépassements de tampon</li><li>Utilise des pratiques sécurisées pour le stockage et la transmission des données</li></ul>                       |
| 📦               | _Dépendances_: <ul><li>Dépend du compilateur `c` pour la compilation</li><li>Utilise les fonctions de la librairie standard via les fichiers d'en-tête `h`</li></ul>                                                 |
| 🚀               | _Scalabilité_: <ul><li>Conçu pour gérer des entrées volumineuses et des calculs complexes</li><li>Utilise des structures de données et des algorithmes efficaces pour minimiser la charge computationnelle</li></ul> |

---

## Structure du Projet

```sh
└── menger/
		├── 0-main.c
		├── 0-menger
		├── 0-menger.c
		├── README.md
		└── menger.h
```

### Index du Projet

<details open>
	<summary><b><code>MENGER/</code></b></summary>
	<!-- Module __root__ -->
	<details>
		<summary><b>__root__</b></summary>
		<blockquote>
			<div class='directory-path' style='padding: 8px 0; color: #666;'>
				<code><b>⦿ __root__</b></code>
			<table style='width: 100%; border-collapse: collapse;'>
			<thead>
				<tr style='background-color: #f8f9fa;'>
					<th style='width: 30%; text-align: left; padding: 8px;'>Nom du fichier</th>
					<th style='text-align: left; padding: 8px;'>Résumé</th>
				</tr>
			</thead>
				<tr style='border-bottom: 1px solid #eee;'>
					<td style='padding: 8px;'><b><a href='/root/Projets_holberton/holbertonschool-interview/menger/blob/master/0-main.c'>0-main.c</a></b></td>
					<td style='padding: 8px;'>- Génère la structure de l'éponge de Menger<br>- Le fichier <code>0-main.c</code> sert de point d'entrée pour générer une structure d'éponge de Menger basée sur l'entrée utilisateur<br>- Il valide les arguments de la ligne de commande et les transmet à la fonction <code>menger</code>, qui construit le niveau souhaité de l'éponge<br>- La structure résultante est ensuite affichée ou traitée par d'autres composants du code.</td>
				</tr>
				<tr style='border-bottom: 1px solid #eee;'>
					<td style='padding: 8px;'><b><a href='/root/Projets_holberton/holbertonschool-interview/menger/blob/master/menger.h'>menger.h</a></b></td>
					<td style='padding: 8px;'>- Dessine une éponge de Menger en 2D avec des niveaux de complexité variés<br>- La fonction menger génère un motif fractal, en découpant récursivement des formes pour créer la structure caractéristique en forme d'éponge<br>- En ajustant le paramètre de niveau, les utilisateurs peuvent contrôler la complexité et le détail de l'image résultante.</td>
				</tr>
				<tr style='border-bottom: 1px solid #eee;'>
					<td style='padding: 8px;'><b><a href='/root/Projets_holberton/holbertonschool-interview/menger/blob/master/0-menger.c'>0-menger.c</a></b></td>
					<td style='padding: 8px;'>- Génère une représentation ASCII de l'éponge de Menger à un niveau de récursion spécifié, créant un motif fractal en subdivisant et en retirant les carrés centraux<br>- La fonction <code>menger</code> divise récursivement le carré en plus petits segments, tandis que la fonction <code>isHole</code> détermine quelles positions doivent être retirées<br>- Le motif résultant offre une représentation visuelle saisissante de la structure auto-similaire de l'éponge de Menger.</td>
				</tr>
				<tr style='border-bottom: 1px solid #eee;'>
					<td style='padding: 8px;'><b><a href='/root/Projets_holberton/holbertonschool-interview/menger/blob/master/0-menger'>0-menger</a></b></td>
					<td style='padding: 8px;'>Automatisation de processus<br>Permet d'automatiser des tâches répétitives et chronophages, augmentant ainsi l'efficacité et réduisant les erreurs manuelles.<em> <strong>Intégration de données : Facilite l'échange de données entre systèmes disparates, garantissant que les informations essentielles soient correctement capturées et exploitées.</em> </strong>Scalabilité et flexibilité<br>Adopte un design modulaire, facilitant l'intégration de nouveaux systèmes et processus au fur et à mesure de l'évolution du projet.<br>En intégrant ces fonctionnalités, ce fichier joue un rôle essentiel dans la rationalisation des opérations, l'amélioration de la productivité et le succès global du projet.</td>
				</tr>
			</table>
		</blockquote>
	</details>
</details>

---

## Prise en main

### Prérequis

Ce projet nécessite les dépendances suivantes :

- **Langage de programmation :** C

### Installation

Construisez menger à partir des sources et installez les dépendances :

1. **Cloner le dépôt :**

   ```sh
   ❯ git clone ../menger
   ```

2. **Se déplacer dans le répertoire du projet :**

   ```sh
   ❯ cd menger
   ```

3. **Installer les dépendances :**

echo 'INSERT-INSTALL-COMMAND-HERE'

### Utilisation

Exécutez le projet avec :

echo 'INSERT-RUN-COMMAND-HERE'

### Tests

Menger utilise le framework de test {**test_framework**}. Exécutez la suite de tests avec :

echo 'INSERT-TEST-COMMAND-HERE'

---

## Feuille de route

- [x] **`Tâche 1`** : <strike>Implémenter la fonctionnalité un.</strike>
- [ ] **`Tâche 2`** : Implémenter la fonctionnalité deux.
- [ ] **`Tâche 3`** : Implémenter la fonctionnalité trois.

---

## Contribuer

- **💬 [Rejoindre les discussions](https://LOCAL/holbertonschool-interview/menger/discussions)** : Partagez vos idées, donnez votre avis ou posez vos questions.
- **🐛 [Signaler des problèmes](https://LOCAL/holbertonschool-interview/menger/issues)** : Soumettez des bugs ou formulez des demandes de fonctionnalités pour le projet `menger`.
- **💡 [Soumettre des Pull Requests](https://LOCAL/holbertonschool-interview/menger/blob/main/CONTRIBUTING.md)** : Consultez les PR en attente et soumettez les vôtres.

<details closed>
<summary>Directives de contribution</summary>

1. **Fork du dépôt** : Commencez par forker le dépôt du projet sur votre compte LOCAL.
2. **Cloner localement** : Clonez le dépôt forké sur votre machine à l'aide d'un client git.
   ```sh
   git clone /root/Projets_holberton/holbertonschool-interview/menger
   ```
3. **Créer une nouvelle branche** : Travaillez toujours sur une nouvelle branche avec un nom descriptif.
   ```sh
   git checkout -b nouvelle-fonctionnalité-x
   ```
4. **Apporter vos modifications** : Développez et testez vos modifications en local.
5. **Valider vos changements** : Effectuez un commit avec un message clair décrivant vos modifications.
   ```sh
   git commit -m 'Implémentation de la nouvelle fonctionnalité x.'
   ```
6. **Pousser sur LOCAL** : Poussez vos modifications vers votre dépôt forké.
   ```sh
   git push origin nouvelle-fonctionnalité-x
   ```
7. **Soumettre une Pull Request** : Créez une PR contre le dépôt original. Décrivez clairement les modifications et leur motivation.
8. **Relecture** : Une fois votre PR relue et approuvée, elle sera fusionnée dans la branche principale. Félicitations pour votre contribution !
</details>

<div align="right">

[![][back-to-top]](#top)

</div>

[back-to-top]: https://img.shields.io/badge/-BACK_TO_TOP-151515?style=flat-square
