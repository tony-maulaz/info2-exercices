# TDA
## Ex 1

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

capacity
: La capacité du tableau

nbrElement
: Le nombre d'élément dans le tableau

element
: Le tableau dynamique d'élément


Créer les fonctions suivantes afin de pouvoir utiliser ce type de donnée.

```C
void init(Data* d);
```

```C
bool allocate(Data* d, int capacity)
```

```C
void freeData(Data* d)
```

```C
bool addElement(Data* d, Element* e)
```

```C
void printElement(Data* d)
```

Voici un exemple d'utilisation de ce type de donnée

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
