# 🔄 Push_swap

![42 Project](https://img.shields.io/badge/42-Project-blue)
![Language](https://img.shields.io/badge/Language-C-brightgreen)
![Norm](https://img.shields.io/badge/Norm-3.3.3-orange)

Un projet de tri de données utilisant deux piles et un ensemble limité d'opérations, avec l'objectif de trouver l'algorithme le plus efficace.

---

## 📋 Table des matières

- [Description](#-description)
- [Règles](#-règles)
- [Opérations](#-opérations)
- [Installation](#-installation)
- [Usage](#-usage)
- [Algorithmes](#-algorithmes)
- [Structure du projet](#-structure-du-projet)
- [Compilation](#-compilation)
- [Exemples](#-exemples)

---

## 📝 Description

**Push_swap** est un projet de l'école 42 qui consiste à trier des nombres entiers en utilisant deux piles (`a` et `b`) et un ensemble restreint d'opérations. Le but est de trier la pile `a` dans l'ordre croissant avec le minimum d'opérations possible.

### Objectifs
- ✅ Trier des nombres entiers
- ✅ Utiliser deux piles (`a` et `b`)
- ✅ Optimiser le nombre d'opérations
- ✅ Gérer les erreurs d'entrée

---

## 📏 Règles

1. Au début, la pile `a` contient une quantité aléatoire de nombres (positifs et/ou négatifs) sans doublons
2. La pile `b` est vide
3. Le but est de trier les nombres de la pile `a` dans l'ordre croissant
4. Vous disposez d'un ensemble limité d'opérations

---

## 🔧 Opérations

### Push
- `pa` : **push a** - Prend le premier élément au sommet de `b` et le met sur `a`
- `pb` : **push b** - Prend le premier élément au sommet de `a` et le met sur `b`

### Swap
- `sa` : **swap a** - Intervertit les 2 premiers éléments au sommet de la pile `a`
- `sb` : **swap b** - Intervertit les 2 premiers éléments au sommet de la pile `b`
- `ss` : `sa` et `sb` en même temps

### Rotate
- `ra` : **rotate a** - Décale tous les éléments de la pile `a` d'une position vers le haut
- `rb` : **rotate b** - Décale tous les éléments de la pile `b` d'une position vers le haut
- `rr` : `ra` et `rb` en même temps

### Reverse rotate
- `rra` : **reverse rotate a** - Décale tous les éléments de la pile `a` d'une position vers le bas
- `rrb` : **reverse rotate b** - Décale tous les éléments de la pile `b` d'une position vers le bas
- `rrr` : `rra` et `rrb` en même temps

---

## 🚀 Installation

```bash
# Cloner le repository
git clone https://github.com/bhyant/42-Push_swap.git
cd 42-Push_swap

# Compiler le projet
make
```

---

## 💻 Usage

```bash
# Trier des nombres
./push_swap 4 67 3 87 23

# Avec une chaîne de caractères
./push_swap "4 67 3 87 23"

# Combiner les deux
./push_swap 4 "67 3" 87 23
```

### Gestion d'erreurs

Le programme affiche `Error` et retourne un code d'erreur dans les cas suivants :
- ❌ Arguments non numériques
- ❌ Nombres en dehors de la plage d'un `int`
- ❌ Doublons
- ❌ Aucun argument

```bash
./push_swap abc        # Error
./push_swap 1 2 3 2    # Error (doublon)
./push_swap            # Error (pas d'arguments)
```

---

## 🧠 Algorithmes

Le projet implémente plusieurs algorithmes de tri en fonction de la taille de la pile :

### 🔹 Tri de 2 éléments
- Simple swap si nécessaire

### 🔹 Tri de 3 éléments
- Algorithme optimisé avec un maximum de 2 opérations

### 🔹 Tri de 4 éléments
- Push du minimum vers `b`
- Tri de 3 éléments restants
- Push du minimum de retour vers `a`

### 🔹 Tri de 5 éléments
- Push des 2 minimums vers `b`
- Tri de 3 éléments restants
- Push des minimums de retour vers `a`

### 🔹 Tri de plus de 5 éléments : Radix Sort
- Algorithme de tri par base binaire
- Tri bit par bit
- Très efficace pour de grandes quantités de nombres

---

## 📁 Structure du projet

```
42-Push_swap/
├── Makefile                    # Fichier de compilation
├── README.md                   # Ce fichier
├── includes/
│   └── push_swap.h            # Header principal
├── libft/                     # Bibliothèque libft
│   ├── Makefile
│   ├── includes/
│   │   └── libft.h
│   ├── ft_*.c                 # Fonctions libft
│   ├── 42-get_next_line/      # Get Next Line
│   └── 42-printf/             # Printf
└── srcs/
    ├── push_swap.c            # Fichier main
    ├── commands/              # Opérations sur les piles
    │   ├── push.c
    │   ├── swap.c
    │   ├── rotate.c
    │   └── reverse_rotate.c
    ├── parsing/               # Parsing des arguments
    │   ├── parsing.c
    │   └── create_array.c
    ├── sort/                  # Algorithmes de tri
    │   ├── choose_sort.c
    │   └── radix_sort.c
    └── utils/                 # Utilitaires
        ├── lst_utils.c
        ├── lst_utils2.c
        ├── parsing_utils.c
        ├── sort_utils.c
        └── clean_utils.c
```

---

## 🔨 Compilation

### Commandes disponibles

```bash
make          # Compile le projet
make clean    # Supprime les fichiers objets
make fclean   # Supprime les fichiers objets et l'exécutable
make re       # Recompile tout le projet
```

### Flags de compilation

```makefile
-Wall -Wextra -Werror    # Tous les warnings sont des erreurs
-MMD -MP                  # Gestion automatique des dépendances
-g3                       # Informations de debug
```

---

## 📊 Exemples

### Exemple 1 : 3 nombres
```bash
$ ./push_swap 2 1 3
sa
```

### Exemple 2 : 5 nombres
```bash
$ ./push_swap 5 4 3 2 1
rra
pb
rra
pb
ra
sa
pa
pa
```

### Exemple 3 : Avec une chaîne
```bash
$ ./push_swap "3 2 1 0"
sa
rra
sa
```

### Vérification avec un checker
```bash
$ ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
# Affiche le nombre d'opérations utilisées
```

---

## 🎯 Objectifs de performance

Pour réussir le projet avec tous les points :

| Taille | Nombre d'opérations |
|--------|---------------------|
| 3      | ≤ 3                 |
| 5      | ≤ 12                |
| 100    | ≤ 700 (5 points)    |
| 100    | ≤ 900 (4 points)    |
| 100    | ≤ 1100 (3 points)   |
| 100    | ≤ 1300 (2 points)   |
| 100    | ≤ 1500 (1 point)    |
| 500    | ≤ 5500 (5 points)   |
| 500    | ≤ 7000 (4 points)   |
| 500    | ≤ 8500 (3 points)   |
| 500    | ≤ 10000 (2 points)  |
| 500    | ≤ 11500 (1 point)   |

---

## 👨‍💻 Auteur

**tbhuiyan** - [GitHub](https://github.com/bhyant)

---

## 📄 Licence

Ce projet fait partie du cursus de l'école 42.

---

## 🙏 Remerciements

- École 42 pour le sujet
- La communauté 42 pour les ressources et l'entraide

---

**Note** : Ce projet respecte la norme de l'école 42 (Norminette v3.3.3)