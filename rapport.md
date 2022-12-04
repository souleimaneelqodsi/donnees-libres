---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.14.1
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
---

# Rapport de projet *Données libres*

+++

## Auteurs

- Agoudjil, Lina, lina.agoudjil@universite-paris-saclay.fr, MI3
- El Qodsi, Souleimane, souleimane.el-qodsi@universite-paris-saclay.fr, MI4

+++ {"tags": [], "jp-MarkdownHeadingCollapsed": true}

## Résumé du travail effectué

### Exercice 1
Fichier(s) .cpp complétés, compilent et produisent l'affichage demandé.
### Exercice 2
Fichier(s) .cpp complétés, compilent et produisent l'affichage demandé.
### Exercice 3
Fichier(s) .cpp complétés, compilent et passent les tests.
### Exercice 4
Fichier(s) .cpp complétés, compilent et passent les tests.
### Exercice 5
Fichier(s) .cpp complétés, compilent et passent les tests.
### Exercice 6
Fichier(s) .cpp complétés, compilent et passent les tests. Ici, la question la plus difficile était sans nul doute la (4) qui demandait de compléter la fonction main() afin de produire les affichages demandés. Ces affichages nécessitaient de combiner plusieurs appels de fonctions de différentes primitives définies aux questions précédentes, notamment groupByInt et distinct, et la difficulté se trouvait dans l'usage de la bonne fonction et du bon type pour chaque affichage : la question n'a pas été réussie du premier coup...
### Exercice 7 et exercice 8
Fichier(s) .cpp complétés, compilent et produisent l'affichage demandé.
La plus grande difficulté de ces exercices était de comprendre le fonctionnement de la primitive getline, qui n'est pas évident au premier abord. Cette fonction fait que la lecture d'un fichier CSV diffère fortement sur le plan syntaxique et sémantique de la lecture "classique" dans un fichier texte. Néanmoins, le principe fondamental reste le même : lecture dans un flux entrant et stockage dans une variable. Pour résoudre ces exercices, nous avons donc choisi de lire chaque ligne du fichier CSV en tant que flux et stocker cela dans une variable avec getline (avec deux paramètres formels), puis de convertir cette variable (de type string) elle-même en un flux, et enfin de lire ce flux avec getline de nouveau (avec trois paramètres formels), en spécifiant la ligne convertie en flux, une variable de parcours et le caractère séparateur (';').
### Exercice 9
Fichier(s) .cpp complétés, compilent et produisent l'affichage demandé.
Pour résoudre les questions de cet exercice, nous avons utilisé la fonction de lecture dans un fichier CSV, naturellement puisque c'est le type des fichiers contenant les données à traiter. Puis nous avons eu à appeler les fonctions de tableau-donnees.cpp et tableau-donnees-avance.cpp, notamment selectLignes, conversionInt, colonne, indiceMax et distinct.
### Exercice 11
### Exercice 12
### Exercice 13
### Exercice 14

+++

## Démonstration

*Soutenez ce que vous affirmez dans la section précédente au moyen des exemples ci-dessous.*

*Vous pouvez lancer des commades shell (terminal) depuis cette feuille en précédant la commande d'un point d'exclamation (mais cela ne permet pas l'ineteraction avec le terminal comme entrer une année ou un prénom). Les trois commandes ci-dessous lance la compilation de tous les exercices guidés puis l'ensemble des tests*

*Editez et complétez pour que cela corresponde à votre travail (par exemple en rajoutant la compilation et les tests qui correspondent aux exercices plus avancés). Indiquez aussi de quels programmes vous souhaitez nous faire la démonstration lors de la soutenance. Choisissez plutôt des exemples pertinents qui mettent en valeur votre
travail. Inutile de perdre du temps sur les premier niveaux si vous
avez fait les suivants plus compliqués (on se contentera des tests automatiques)*

```{code-cell}
---
jupyter:
  outputs_hidden: true
tags: []
---
! make all
```

```{code-cell}
---
jupyter:
  outputs_hidden: true
tags: []
---
! make test
```

```{code-cell}
// exercice 6, exercice 8, exercice 9 et exercice 11,12,13,14 ou 15
```

## Organisation du travail

*Décrire en quelques phrases comment vous vous êtes organisés pour
travailler sur le projet: nombre d'heures consacrées au projet,
répartition du travail dans le binôme, moyens mis en œuvre pour
collaborer, etc. Si vous avez bénéficié d'aide (en dehors de celle
de vos enseigants), précisez le.*

Pour travailler sur ce projet, nous avons consacré environ une vingtaine d'heures de travail intensif. Pour travailler en binôme, nous avons combiné la programmation en binôme et la programmation côte à côte, c'est-à-dire que nous avons travaillé seul sur les exercices chacun de son côté dans un premier temps, puis dans un second temps nous avons alterné les rôles de *driver* et d'*observer* afin de : refaire le code si aucun des deux n'a réussi à résoudre l'exercice, sinon améliorer la version fonctionnelle. Cela a permis d'aller plus vite, puisqu'avant de mettre en commun, chacun avait déjà réfléchi préalablement au problème. Pour l'échange des fichiers, nous avons simplement échangé via mail, pour ensuite glisser et déposer les fichiers mis à jour (par le binôme) dans l'explorateur de fichier Jupyter, ce qui entraîne l'écrasement des fichiers obsolètes et la possibilité de déposer directement sur GitLab.

+++

## Prise de recul

*Décrire en quelques phrases les difficultés rencontrées, ce que vous
avez appris à l'occasion du projet, le cas échéant comment vous vous y
prendriez si vous aviez à le refaire.*
