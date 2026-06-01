# TD : Résultats de course depuis un fichier binaire

## Description
Créer un programme en C permettant de gérer les résultats d'une course à pied.

Les résultats sont stockés dans un fichier binaire. Le programme doit :
1. Lire le fichier binaire passé en argument.
2. Stocker les résultats dans un tableau dynamique, **trié par ordre croissant sur le temps** (le coureur le plus rapide en premier).
3. Afficher le contenu du tableau.

## Structure de données

Un résultat est défini par une structure `RaceResult` qui contient :
- Un dossard `bib` (entier) : numéro du coureur.
- Un temps `time` (double) : temps de course en secondes.
- Un nom `name` (chaîne de caractères de taille fixe 20).
- Une catégorie `category` (enum) qui peut être `JUNIOR`, `SENIOR` ou `VETERAN`.

```c
#define NAME_LENGTH 20

typedef enum {
    JUNIOR = 0,
    SENIOR = 1,
    VETERAN = 2
} Category;

typedef struct {
    int bib;
    double time;
    char name[NAME_LENGTH];
    Category category;
} RaceResult;
```

## Organisation du code

Le projet doit être découpé en plusieurs fichiers :

```
.
├── main.c
├── race_array.h
├── race_array.c
├── binary_file.h
└── binary_file.c
```

### 1. Tableau dynamique — `race_array.h` / `race_array.c`

Définir une structure `RaceArray` qui contient le tableau dynamique de `RaceResult`, sa taille courante et sa capacité.

Implémenter les fonctions suivantes :
- `void initRaceArray(RaceArray* array, int initial_capacity)` : initialise le tableau avec une capacité donnée.
- `void freeRaceArray(RaceArray* array)` : libère la mémoire.
- `void addResult(RaceArray* array, RaceResult result)` : ajoute un résultat **en respectant le tri croissant sur le temps**. Si le tableau est plein, doubler sa capacité.
- `void printRaceArray(const RaceArray* array)` : affiche le contenu du tableau.
- `const char* categoryToString(Category c)` : retourne la chaîne correspondant à la catégorie.

La capacité initiale du tableau passée depuis le `main` sera de `3` pour bien tester le redimensionnement.

### 2. Gestion du fichier binaire — `binary_file.h` / `binary_file.c`

Implémenter les fonctions suivantes :
- `void createBinaryFile(const char* filename)` : crée un fichier binaire d'exemple (code fourni ci-dessous).
- `void extractFromBinary(const char* filename, RaceArray* array)` : lit le fichier binaire et remplit le tableau via `addResult` (le tri se fait donc à l'insertion).

#### Format du fichier binaire
- 1 entier (`int`) : nombre `n` de résultats.
- `n` structures `RaceResult` à la suite.

#### Contrôle d'intégrité

La fonction `extractFromBinary` doit **vérifier que le nombre de structures réellement présentes dans le fichier correspond bien à l'entier `n` lu en tête**. Si ce n'est pas le cas, le fichier est corrompu et le programme doit afficher une erreur et s'arrêter.

Pour effectuer ce contrôle, vous pouvez utiliser `fseek` et `ftell` afin de calculer la taille totale du fichier, puis vérifier que :

```
taille_fichier == sizeof(int) + n * sizeof(RaceResult)
```

Une autre approche consiste à vérifier la valeur de retour de `fread` (nombre d'éléments effectivement lus) et de la comparer à `n`.

#### Code fourni pour `createBinaryFile`

Recopiez ce code dans `binary_file.c`. Il permet de générer un fichier `race.bin` que votre programme devra ensuite relire.

```c
void createBinaryFile(const char* filename) {
    RaceResult results[] = {
        {12, 3245.78, "Dupont",   SENIOR},
        {47, 2987.12, "Martin",   VETERAN},
        {3,  3502.45, "Bernard",  JUNIOR},
        {28, 2845.90, "Lefebvre", SENIOR},
        {56, 3678.33, "Moreau",   JUNIOR},
        {91, 3120.05, "Garcia",   VETERAN},
        {7,  2756.88, "Rousseau", SENIOR}
    };
    int n = sizeof(results) / sizeof(results[0]);

    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Erreur création fichier binaire");
        exit(EXIT_FAILURE);
    }
    fwrite(&n, sizeof(int), 1, file);
    fwrite(results, sizeof(RaceResult), n, file);
    fclose(file);
}
```

## Cahier des charges

Le `main` doit :
1. Appeler `createBinaryFile("race.bin")` une fois pour générer le fichier d'exemple (à commenter une fois le fichier créé).
2. Récupérer le nom du fichier binaire en argument (`argv[1]`).
3. Accepter une option facultative `--desc` en second argument (`argv[2]`) : si elle est présente, l'affichage se fait en ordre **décroissant** sur le temps (le coureur le plus lent en premier). Sans option, l'affichage reste en ordre croissant.
4. Initialiser un `RaceArray` de capacité initiale 3.
5. Appeler `extractFromBinary` pour remplir le tableau (les éléments doivent être triés à l'insertion).
6. Afficher le contenu trié, dans l'ordre demandé.
7. Libérer la mémoire.

> **Indication** : le tableau est toujours stocké en ordre croissant. Pour l'affichage décroissant, c'est la fonction `printRaceArray` qui parcourt le tableau à l'envers — par exemple en lui passant un booléen ou en créant une variante `printRaceArrayDesc`.

### Exemple de sortie attendue

```
Résultats triés par temps croissant :
Dossard: 7,  Temps: 2756.88s, Nom: Rousseau, Catégorie: SENIOR
Dossard: 28, Temps: 2845.90s, Nom: Lefebvre, Catégorie: SENIOR
Dossard: 47, Temps: 2987.12s, Nom: Martin,   Catégorie: VETERAN
Dossard: 91, Temps: 3120.05s, Nom: Garcia,   Catégorie: VETERAN
Dossard: 12, Temps: 3245.78s, Nom: Dupont,   Catégorie: SENIOR
Dossard: 3,  Temps: 3502.45s, Nom: Bernard,  Catégorie: JUNIOR
Dossard: 56, Temps: 3678.33s, Nom: Moreau,   Catégorie: JUNIOR
```

## Compilation

```bash
gcc main.c race_array.c binary_file.c -o app -Wall -Wextra && ./app race.bin
```

Pour un affichage en ordre décroissant :

```bash
./app race.bin --desc
```

## Pour aller plus loin
- Ajouter une fonction qui affiche uniquement les coureurs d'une catégorie donnée.
- Ajouter une option `-o<fichier.csv>` qui écrit les résultats triés dans un fichier CSV dont le nom est passé en paramètre. Le fichier doit contenir une ligne d'en-tête `bib,time,name,category` puis une ligne par résultat. Exemple d'utilisation :

  ```bash
  ./app race.bin -o results.csv
  ./app race.bin --desc -o results.csv
  ```
