# Programme de mesure

## Mesure
Il faut développer un programme pour sauvegarder des mesures dans un fichier binaire.

S'il est utilisé plusieurs fois, le nom du fichier doit être stocké dans une variable.

Afin de simuler une série de mesures journalière, il faut utiliser une boucle `for`.

Chaque jour, le fichier est ouvert pour l'écriture de la nouvelle mesure, puis fermé.

Le processus quotidien est donc le suivant :
- Initialiser une nouvelle structure `Data` pour le jour en cours.
- Remplir le tableau `Measure` dans la structure avec des valeurs aléatoires.
- Sauvegarder la structure dans le fichier des mesures.

Dans `Measure` :
- `x` : l'indice de la mesure, qui commence à `0` et s'incrémente de `1`.
- `value` : une valeur aléatoire comprise entre `0` et `100`.

Pour générer des nombres aléatoires, utiliser le générateur `srand`.

Il y a une série de mesure par jour, et la variable `day` dans la structure `Data` représente le numéro du jour, compris entre `1` et `365`.

Les mesures ne commencent pas au jour `1`. Le jour de départ est défini par un `#define` à `20`.

Le nombre de jours de mesure est défini par `#define NBR_DAY`.

## Taille du fichier
Une fois les mesures terminées, il faut afficher la taille du fichier en octets (`byte`).

## Lecture
### Une mesure
Développer une fonction permettant d'extraire une structure `Data` pour un jour donné en paramètre (voir le prototype de la fonction dans le code ci-dessous).
Cette fonction doit extraire la structure depuis le fichier précédemment créé.

Étant donné que le jour de départ est connu, il est possible d'utiliser un décalage (fseek) afin d'éviter de lire l'intégralité du fichier.

Pas de contrôle pour savoir si le jour existe.

### La série
Développer une fonction permettant d'extraire un tableau de structures `Data` pour un jour donné en paramètre (voir le prototype de la fonction dans le code ci-dessous).

Le nombre de mesures à lire est défini par `#define NBR_READ_MEASURES`.

Cette fonction doit extraire le tableau de structures depuis le fichier précédemment créé.

Si on extrait les valeurs sauvegardées dans le fichier avec un jour de départ `20`, on devrait obtenir quelque chose comme ceci :
```console
day = 20
measure[0] : x=0, value = ...
measure[1] : x=1, value = ...
measure[2] : x=2, value = ...
measure[3] : x=3, value = ...
...
day = 21
measure[0] : x=0, value = ...
measure[1] : x=1, value = ...
measure[2] : x=2, value = ...
measure[3] : x=3, value = ...
...
day = 22
measure[0] : x=0, value = ...
measure[1] : x=1, value = ...
measure[2] : x=2, value = ...
measure[3] : x=3, value = ...
...
```

```c
#define START_DAY 20
#define NBR_MEASURE 10
#define NBR_DAY 20
#define NBR_READ_MEASURES 5

typedef struct
{
    int x;
    double value;
} Measure;

typedef struct
{
    int day;
    Measure measure[NBR_MEASURE];
} Data;

Data readMeasure(int day, char* filename)
{}

void readMeasures(int day, char* filename, size_t nbrMeasure, Data tab[])
{}

void main()
{
    // On simule une mesure par jour
    for (int i = 0; i < NBR_DAY; i++)
    {
        // init de la structure
        // init du numéro du jour
        
        // Boucle pour remplir le tableau de mesure
        for (int m = 0; m < NBR_MEASURE; m++)
        {}
    }

    // Partie lecture

    // Affiche la taille

    // Le numéro du jour que l'on veut lire
    const int NumDayToRead = 30;    

    // Lecture d'une mesure
    Data res;

    // Lecture de plusieurs mesures
    Data res_tab[NBR_READ_MEASURES];
    
    
    // Test si le programme fonctionne

    printf("\nTest de la lecture\n");

    if( NumDayToRead == res.day ){
        printf("\033[1;32mLecture d'un résultat ok\n\033[0m");
    }
    else
    {
        printf("\032[1;32mLecture d'un résultat pas bon\n\033[0m");
    }

    if( res.measure[0].x == 0 ){
        printf("\033[1;32mLecture mesure 1 ok\n\033[0m");
    }
    else
    {
        printf("\032[1;32mLecture mesure 1 pas bon\n\033[0m");
    }

    // Test de la lecture en tableau
    if( (NumDayToRead + 1) == res_tab[1].day ){
        printf("\033[1;32mLecture d'un résultat ok\n\033[0m");
    }
    else
    {
        printf("\032[1;32mLecture d'un résultat pas bon\n\033[0m");
    }

    if( res_tab[1].measure[0].x == 0 ){
        printf("\033[1;32mLecture mesure tab 1 ok\n\033[0m");
    }
    else
    {
        printf("\032[1;32mLecture mesure tab 1 pas bon\n\033[0m");
    }
}
```
