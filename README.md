# Rapport de projet *Données libres* / Project Report *Open Data*

## Mentions importantes / Important Mentions

### Français
Ce projet a été réalisé **en binôme** dans le cadre du module d'introduction à la programmation impérative du 1er semestre de licence portail mathématiques-informatique à l'[Université Paris-Saclay](https://www.universite-paris-saclay.fr/). Le sujet du projet et sa structure étaient fournis par l'équipe pédagogique du cours [Info111](https://nicolas.thiery.name/Enseignement/Info111/) de la [Faculté des Sciences d'Orsay](https://www.sciences.universite-paris-saclay.fr/). Les exercices ont ensuite été résolus par Souleimane EL QODSI et Lina AGOUDJIL. Le sujet des exercices se trouve dans le fichier `projet.pdf`. Ce projet est soumis à licence CC-BY-SA.

### English
This project was carried out **as a team** as part of the imperative programming introduction module in the first semester of the Mathematics-Computer Science bachelor's program at [Université Paris-Saclay](https://www.universite-paris-saclay.fr/). The project topic and structure were provided by the teaching team of the [Info111](https://nicolas.thiery.name/Enseignement/Info111/) course from the [Faculty of Sciences of Orsay](https://www.sciences.universite-paris-saclay.fr/). The exercises were then solved by Souleimane EL QODSI and Lina AGOUDJIL. The exercise topic can be found in the `projet.pdf` file. This project is licensed under CC-BY-SA.

## Auteurs / Authors

- Agoudjil, Lina, lina.agoudjil@universite-paris-saclay.fr, MI3
- El Qodsi, Souleimane, souleimane.el-qodsi@universite-paris-saclay.fr, MI4

## Résumé du travail effectué / Summary of Work Done

### Exercice 1
Fichier(s) .cpp complétés, compilent et produisent l'affichage demandé. / .cpp file(s) completed, compile, and produce the requested output.

### Exercice 2
Fichier(s) .cpp complétés, compilent et produisent l'affichage demandé. / .cpp file(s) completed, compile, and produce the requested output.

### Exercice 3
Fichier(s) .cpp complétés, compilent et passent les tests. / .cpp file(s) completed, compile, and pass the tests.

### Exercice 4
Fichier(s) .cpp complétés, compilent et passent les tests. / .cpp file(s) completed, compile, and pass the tests.

### Exercice 5
Fichier(s) .cpp complétés, compilent et passent les tests. / .cpp file(s) completed, compile, and pass the tests.

### Exercice 6
Fichier(s) .cpp complétés, compilent et passent les tests. Ici, la question la plus difficile était sans nul doute la (4) qui demandait de compléter la fonction main() afin de produire les affichages demandés. Ces affichages nécessitaient de combiner plusieurs appels de fonctions de différentes primitives définies aux questions précédentes, notamment groupByInt et distinct, et la difficulté se trouvait dans l'usage de la bonne fonction et du bon type pour chaque affichage : la question n'a pas été réussie du premier coup... / .cpp file(s) completed, compile, and pass the tests. Here, the most difficult question was undoubtedly (4), which required completing the main() function to produce the requested outputs. These outputs required combining several function calls from different primitives defined in previous questions, notably groupByInt and distinct, and the difficulty lay in using the correct function and type for each display: the question was not successfully answered on the first try...

### Exercice 7 et exercice 8
Fichier(s) .cpp complétés, compilent et produisent l'affichage demandé. La plus grande difficulté de ces exercices était de comprendre le fonctionnement de la primitive getline, qui n'est pas évident au premier abord. Cette fonction fait que la lecture d'un fichier CSV diffère fortement sur le plan syntaxique et sémantique de la lecture "classique" dans un fichier texte. Néanmoins, le principe fondamental reste le même : lecture dans un flux entrant et stockage dans une variable. Pour résoudre ces exercices, nous avons donc choisi de lire chaque ligne du fichier CSV en tant que flux et stocker cela dans une variable avec getline (avec deux paramètres formels), puis de convertir cette variable (de type string) elle-même en un flux, et enfin de lire ce flux avec getline de nouveau (avec trois paramètres formels), en spécifiant la ligne convertie en flux, une variable de parcours et le caractère séparateur (';'). / .cpp file(s) completed, compile, and produce the requested output. The greatest difficulty in these exercises was understanding the getline primitive, which is not immediately clear. This function makes reading a CSV file significantly different in syntax and semantics from "classic" file reading. However, the fundamental principle remains the same: reading into an incoming stream and storing it in a variable. To solve these exercises, we chose to read each line of the CSV file as a stream and store it in a variable with getline (with two formal parameters), then convert this variable (of type string) itself into a stream, and finally read this stream with getline again (with three formal parameters), specifying the converted line as a stream, a traversal variable, and the separator character (';').

### Exercice 9
Fichier(s) .cpp complétés, compilent et produisent l'affichage demandé. Pour résoudre les questions de cet exercice, nous avons utilisé la fonction de lecture dans un fichier CSV, naturellement puisque c'est le type des fichiers contenant les données à traiter. Puis nous avons eu à appeler les fonctions de tableau-donnees.cpp et tableau-donnees-avance.cpp, notamment selectLignes, conversionInt, colonne, indiceMax et distinct. / .cpp file(s) completed, compile, and produce the requested output. To solve the questions in this exercise, we used the function to read from a CSV file, naturally since it is the type of files containing the data to be processed. Then we had to call the functions from tableau-donnees.cpp and tableau-donnees-avance.cpp, notably selectLignes, conversionInt, colonne, indiceMax, and distinct.

### Exercice 14
Fichier cpp complété, ne compile pas, présence d'erreurs (identifiées) dans le code, mais non corrigé et incomplet par faute de temps (échéance des soutenances). Nous avons choisi d'implémenter l'évolution de l'air en calculant la moyenne de chaque particule fine polluante pour chaque année, puis en calculant le taux d'évolution de ces moyennes d'une année à l'autre. La difficulté majeure est donc de lire dans un fichier CSV dont les données sont disponibles sous une forme qui ne simplifie pas les choses → colonne contenant des valeurs mais à certaines heures à certains jours la donnée n'a pas été enregistrée et donc il faut gérer le cas où ce n'est pas un nombre mais une chaîne de caractères "ND" (Non défini), présence du caractère "<" devant certaines valeurs (il faut donc le retirer), année récupérable sur la première colonne mais fait partie d'une longue chaîne de caractères correspondant à la date (année, fuseau horaire, heure...) et il faut donc découper cette chaîne de caractères soit avec getline() (à trois paramètres) soit avec substr() de la bibliothèque standard C++,...etc. / cpp file completed, does not compile, presence of errors (identified) in the code, but not corrected and incomplete due to time constraints (deadline for presentations). We chose to implement the evolution of air quality by calculating the average of each fine particulate pollutant for each year, then calculating the rate of change of these averages from one year to the next. The major difficulty was reading from a CSV file where the data is available in a form that does not simplify things → column containing values but at certain times on certain days the data was not recorded, so we had to handle the case where it is not a number but a string "ND" (Not Defined), presence of the character "<" in front of some values (so it had to be removed), year retrievable in the first column but part of a long string corresponding to the date (year, time zone, time...) so this string had to be split either with getline() (three parameters) or with substr() from the standard C++ library,...etc.

## Démonstration / Demonstration

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

## Organisation du travail / Work Organization

### Français
Pour travailler sur ce projet, nous avons consacré environ 35 heures de travail intensif. Pour travailler en binôme, nous avons combiné la programmation en binôme et la programmation côte à côte, c'est-à-dire que nous avons travaillé seul sur les exercices chacun de son côté dans un premier temps, puis dans un second temps nous avons alterné les rôles de *driver* et d'*observer* afin de : refaire le code si aucun des deux n'a réussi à résoudre l'exercice, sinon améliorer la version fonctionnelle. Cela a permis d'aller plus vite, puisqu'avant de mettre en commun, chacun avait déjà réfléchi préalablement au problème. Pour l'échange des fichiers, nous avons échangé par mail dans un premier temps, puis nous nous sommes servis de la commande git clone (comme indiqué dans https://nicolas.thiery.name/Enseignement/Info111/collaboration.html), afin de récupérer le dossier projet et de l'un et de l'autre plus rapidement et avec moins d'erreur, puisqu'ensuite, il suffit pour le binôme de glisser les fichiers mis à jour dans son dossier Projet-DonneesLibres et enfin déposer. Quant à l'aide reçue, nous avons regardé une vidéo sur YouTube afin de mieux saisir le fonctionnement de la primitive, qui ne semblait pas clair au début.

### English
To work on this project, we dedicated approximately 35 hours of intensive work. To work as a team, we combined pair programming and side-by-side programming, meaning we worked individually on the exercises at first, then alternated the roles of *driver* and *observer* to either redo the code if neither succeeded in solving the exercise or improve the functional version. This allowed us to move faster, as each of us had already thought about the problem before combining our efforts. For file exchange, we initially exchanged via email, then used the git clone command (as indicated in https://nicolas.thiery.name/Enseignement/Info111/collaboration.html) to retrieve the project folder from each other more quickly and with fewer errors, as afterwards, the teammate just needed to drag the updated files into their Projet-DonneesLibres folder and then commit. As for the help received, we watched a YouTube video to better understand the primitive's function, which was not clear at first.

## Prise de recul / Reflection

### Français
La difficulté majeure que nous avons rencontrée, et c'est un problème commun en gestion de projets, est la maîtrise du temps. En effet, notre nombre d'heures de travail hebdomadaire sur le projet a augmenté à mesure que l'on approchait du jour des soutenances et nous avons eu du mal à être régulier dans le temps, ce qui nous a couté de ne pas réussir à finir l'exercice 14 à temps et donc de devoir rendre un fichier qui ne compile pas. Ce projet a sans aucun doute renforcé nos compétences en programmation, de manière générale, mais aussi et surtout en C++ (découverte de getline(), usage à plusieurs reprises des flux, découverte de substr() dans l'exercice 14...etc.). Si nous devions refaire ce projet, nous nous y prendrions différemment sur le plan de l'organisation. En effet, il ne faut jamais sous-estimer la charge de travail que peut représenter un projet, au début nous n'avions pas cru aux trente heures de travail recommandées, finalement nous y avons consacré beaucoup plus de temps que prévu...

### English
The major difficulty we encountered, which is a common problem in project management, was time management. Our weekly hours of work on the project increased as the presentation day approached, and we struggled to be consistent over time, which cost us the ability to finish exercise 14 on time, forcing us to submit a file that does not compile. This project undoubtedly strengthened our programming skills, generally, but also specifically in C++ (discovery of getline(), repeated use of streams, discovery of substr() in exercise 14, etc.). If we were to redo this project, we would approach it differently in terms of organization. Indeed, one should never underestimate the workload a project can represent; at the beginning, we did not believe in the recommended thirty hours of work, but in the end, we spent much more time than expected...
