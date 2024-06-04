# Rapport de projet *Données libres*

## Mentions importantes

Ce projet a été réalisé **en binôme** dans le cadre du module d'introduction à la programmation impérative du 1er semestre de licence portail mathématiques-informatique à l'[Université Paris-Saclay](https://www.universite-paris-saclay.fr/). Le sujet du projet et sa structure étaient fournis par l'équipe pédagogique du cours [Info111](https://nicolas.thiery.name/Enseignement/Info111/) de la [Faculté des Sciences d'Orsay](https://www.sciences.universite-paris-saclay.fr/). Les exercices ont ensuite été résolus par Souleimane EL QODSI et Lina AGOUDJIL. Le sujet des exercices se trouve dans le fichier ``projet.pdf``. Ce projet est soumis à licence CC-BY-SA.

## Auteurs

- Agoudjil, Lina, lina.agoudjil@universite-paris-saclay.fr, MI3
- El Qodsi, Souleimane, souleimane.el-qodsi@universite-paris-saclay.fr, MI4

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
### Exercice 14
Fichier cpp complété, ne compile pas, présence d'erreurs (identifiées) dans le code, mais non corrigé et incomplet par faute de temps (échéance des soutenances). Nous avons choisi d'implémenter l'évolution de l'air en calculant la moyenne de chaque particule fine polluante pour chaque année, puis en calculant le taux d'évolution de ces moyennes d'une année à l'autre. La difficulté majeure est donc de lire dans un fichier CSV dont les données sont disponibles sous une forme qui ne simplifie pas les choses &rarr; colonne contenant des valeurs mais à certaines heures à certains jours la donnée n'a pas été enregistrée et donc il faut gérer le cas où ce n'est pas un nombre mais une chaîne de caractères "ND" (Non défini), présence du caractère "<" devant certaines valeurs (il faut donc le retirer), année récupérable sur la première colonne mais fait partie d'une longue chaîne de caractères correspondant à la date (année, fuseau horaire, heure...) et il faut donc découper cette chaîne de caractères soit avec getline() (à trois paramètres) soit avec substr() de la bibliothèque standard C++,...etc.


## Démonstration

```{code-cell}
! make all
```

```{code-cell}
! make test
```

```{code-cell}
! make actes-civils
```

```{code-cell}
! make arbres-hauteur
```

```{code-cell}
! make arbres-platanus
```

```{code-cell}
! make tableau-donnees-avance-test
```

```{code-cell}
! make prenoms-tableau-avance
```

## Organisation du travail

Pour travailler sur ce projet, nous avons consacré environ 35 heures de travail intensif. Pour travailler en binôme, nous avons combiné la programmation en binôme et la programmation côte à côte, c'est-à-dire que nous avons travaillé seul sur les exercices chacun de son côté dans un premier temps, puis dans un second temps nous avons alterné les rôles de *driver* et d'*observer* afin de : refaire le code si aucun des deux n'a réussi à résoudre l'exercice, sinon améliorer la version fonctionnelle. Cela a permis d'aller plus vite, puisqu'avant de mettre en commun, chacun avait déjà réfléchi préalablement au problème. Pour l'échange des fichiers, nous avons échangé par mail dans un premier temps, puis nous nous sommes servis de la commande git clone (comme indiqué dans https://nicolas.thiery.name/Enseignement/Info111/collaboration.html), afin de récupérer le dossier projet et de l'un et de l'autre plus rapidement et avec moins d'erreur, puisqu'ensuite, il suffit pour le binôme de glisser les fichiers mis à jour dans son dossier Projet-DonneesLibres et enfin déposer. Quant à l'aide reçue, nous avons regardé une vidéo sur YouTube afin de mieux saisir le fonctionnement de la primitive, qui ne semblait pas clair au début.

## Prise de recul

La difficulté majeure que nous avons rencontrée, et c'est un problème commun en gestion de projets, est la maîtrise du temps. En effet, notre nombre d'heures de travail hebdomadaire sur le projet a augmenté à mesure que l'on approchait du jour des soutenances et nous avons eu du mal à être régulier dans le temps, ce qui nous a couté de ne pas réussir à finir l'exercice 14 à temps et donc de devoir rendre un fichier qui ne compile pas. Ce projet a sans aucun doute renforcé nos compétences en programmation, de manière générale, mais aussi et surtout en C++ (découverte de getline(), usage à plusieurs reprises des flux, découverte de substr() dans l'exercice 14...etc.). Si nous devions refaire ce projet, nous nous y prendrions différemment sur le plan de l'organisation. En effet, il ne faut jamais sous-estimer la charge de travail que peut représenter un projet, au début nous n'avions pas cru aux trente heures de travail recommandées, finalement nous y avons consacré beaucoup plus de temps que prévu...
