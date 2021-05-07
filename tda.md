# TDA

## Ex 1

Créer un type de donnée abstrait nomé `Vector`.

Ce type de donnée va permette de gérer le calcul vectoriel.

Un vecteur contient une composante `x` et `y` en valeur entière.

Le `TDA` va permettre les opérations suivantes
- `void vector_create(Vector* v, int x, int y)`
- `vector vector_add(Vector* v1, Vector* v2)`
- `vector vector_sub(Vector* v1, Vector* v2)`
- `int vector_x(Vector* v)`
- `int vector_y(Vector* v)`
- `double vector_norme(Vector* v)`


## Ex 2

Créer un type de donnée nomé `Data`. Ce type va permettre de gérer un tableau dynamique.

Il doit y avoir `3` fichiers pour ce programme

- `main.c`
- `data.h`
- `data.c`

Ce sera un tableau d'`Element`

```C
typedef struct
{
    double value;
} Element;
```

Ce type de donnée contient ces champs

*capacity*
: La capacité du tableau

*nbrElement*
: Le nombre d'élément dans le tableau

*element*
: Le tableau dynamique d'élément


Créer les fonctions suivantes afin de pouvoir utiliser ce type de donnée.

### La fonction init
```C
void init(Data* d);
```
Initialise les variables à `0` et le pointeur.


### La fonction allocation
```C
bool allocate(Data* d, int capacity)
```
Permet de faire l'allocation de mémoire pour le tableau d'éléments.

Si l'allocation se passe mal, la fonction retourne `false` sinon `true`

### La fonction pour libérer
```C
void freeData(Data* d)
```
Libère la mémoire.

### La fonction pour ajouter
```C
bool addElement(Data* d, Element* e)
```
Ajoute un élément dans le tableau.

Si l'ajout se passe mal, la fonction retourne `false` sinon `true`

### La fonction pour afficher

```C
void printElement(Data* d)
```

Affiche la liste des éléments du genre :
```texte
Element : 0 -> value : 7.19
Element : 1 -> value : 7.50
Element : 2 -> value : 7.81
Element : 3 -> value : 8.12
```

### Programme principal

Voici la fonction `main` du programme, c'est un exemple d'utilisation de ce type de donnée.

Vous remarquerez que dans ce code, on accède jamais directement aux champs de la structure mais que l'on passe toujours par des fonctions.

```C
void main(){
    printf("\033[1;33mExercice 1\n\033[0m");    
    
    Data d;
    
    init(&d);
    allocate(&d, 10);

    for(int j=0; j<20; j++){
        Element e = {.value = (j+23)/3.2};
        if( !addElement(&d, &e) ){
            printf("\033[1;31mIl n'y a plus de place\n\033[0m");
            break;
        }
    }

    printElement(&d);

    freeData(&d);
}
```
