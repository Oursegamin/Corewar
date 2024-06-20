---

# Corewar

Corewar est un projet de programmation en langage C où des programmes s'affrontent dans une arène virtuelle. Ce projet met en œuvre un assembleur, un désassembleur, une arène de jeu et un interpréteur de bytecode.

## Table des matières
1. [Introduction]
2. [Prérequis]
3. [Installation]
4. [Utilisation.
5. [Fonctionnalités]
6. [Structure du Projet]
7. [Contributeurs]
8. [Licence]

## Introduction

Corewar est basé sur le jeu décrit par A. K. Dewdney dans son article de Scientific American de 1984. Le but du jeu est de programmer des "guerriers" en assembleur qui se battent dans une machine virtuelle jusqu'à ce qu'il ne reste qu'un seul programme actif.

## Prérequis

- Un compilateur C (GCC recommandé)
- `make` pour la compilation
- Un système d'exploitation Unix (Linux, macOS, etc.)

## Installation

Clonez le dépôt Git et compilez les sources :

```bash
git clone git@github.com:florian-labadie/Corewar.git
cd corewar
make
```

## Utilisation

### Assembler un fichier source

Pour assembler un fichier source `.s` en bytecode `.cor` :
Fichier `.s` disponible dans le dossier Bonus.

```bash
./asm fichier.s
```

### Lancer une bataille dans l'arène

Pour lancer une bataille entre plusieurs programmes :

```bash
./corewar fichier1.cor fichier2.cor
```

### Options

- `-a N` : Placer le champion à une position précise N dans l'arène.
- `-dump N` : Dump de la mémoire après N cycles.
- `-n` : Assigner le numéro du champion.

## Fonctionnalités

- **Assembler** : Convertit le code assembleur en bytecode exécutable.
- **Désassembler** : Convertit le bytecode en code assembleur lisible.
- **Arène de jeu** : Simule l'environnement où les programmes s'affrontent.
- **Interpréteur** : Exécute le bytecode dans l'arène.

## Structure du Projet

Le projet est organisé comme suit :

```
corewar/ 
├── asm                 # Sources de l'assembleur
├── Bonus/              # Bonus graphique et champions '.s'
├── src/                # Fichiers du corewar 
├── includes/           # Fichiers d'en-tête (.h)
├── lib/                # Bibliothèques auxiliaires
├── Makefile            # Fichier de compilation
└── README.md           # Documentation du projet
```

## Contributeurs

- Labadie Florian ([GitHub](https://github.com/florian-labadie))
- Axel Lavrador ([GitHub](https://github.com/Oursegamin))
