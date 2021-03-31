# Programme de mesure

## Mesure
Il faut développer un programme pour sauver des mesures dans un fichier binaire.

Si il est utilisé plusieurs fois, le nom du fichier doit être dans une variable.

Afin de simuler une mesure journalière, il faut utiliser une boucle `for`.

Chaque jour le fichier est ouvert pour l'écriture de la nouvelle mesure et ensuite fermé.

Donc chaque jour le process est :
- Créer une nouvelle structure `Data` pour le jour en cours
- Remplir la structure avec des mesures
- Sauver la structure dans le fichier de mesures.

Dans `measure` :
- `x` : l'indice de la mesure qui commence à `0` et s'incrémente de `1`
- `value` : une valeur aléatoire en `0` et `100`

Pour les nombres aléatoires, utiliser le générateur `srand`.

Il y a une mesure par jour et la variable `day` représente le numéro du jour entre `1` et `365`,

Les mesures ne commencent pas au jour `1`, le  jour de départ est choisit par un `#define` à `20`

Le nombre de jour de mesure est donné par un `#define NBR_DAY`

Faire une fonction `reset` qui permet de mettre tout les champs d'une structure `Data` à 0.


## Lecture
Une fois les mesures terminées, il faut afficher la taille du fichier en `byte`.

Développer une fonction pour pouvoir extraire une structure `Data` pour un jour donné en paramètre (voir le prototype de la fonction dans le code ci-dessous).
Cette fonction va extraire la structure depuis le fichier que vous avez créé avant.

Développer une fonction pour pouvoir extraire un tableau de structure `Data` pour un jour donné en paramètre (voir le prototype de la fonction dans le code ci-dessous).
Le nombre de mesure à lire est définit par `#define NBR_READ_MEASURES`
Cette fonction va extraire le tableau de structure depuis le fichier que vous avez créé avant.

Les données dans le fichier seront ainsi si le jour de départ vaut `20`:
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


```C
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

// Fonction pour faire le reset d'une structure
// ....

Data readMeasure(int day, char* filename)
{}

void readMeasures(int day, char* filename, size_t nbrMeasure, Data tab[])
{}

void main()
{
    // On simule une mesure par jour
    for (int i = 0; i < NBR_DAY; i++)
    {
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

    printf("\nTest de la lecutre\n");

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
