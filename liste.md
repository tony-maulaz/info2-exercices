# Liste

## Ex 1

1. Qu'est-ce qu'une file ?
1. Qu'est-ce qu'une pile ?

## Ex 2

1. Afin de pouvoir gérer une file avec une liste chaînée, quelles informations sont nécessaire dans la structure ?
1. Idem pour une pile ?

## Ex 3

Considérons une liste avec la structure suivante. Cette liste fonctionne comme une pile.

```C
#define TEXT_LENGTH 20

typedef struct{
    int id;
    char name[TEXT_LENGTH];
    double measure;
} Value;

typedef struct Element{
    Value val;
    struct Element* next;
} Element;

typedef struct{
    Element* tete;
} List;
```

Développer une fonction qui permet d'ajouter un élément dans la liste.

```C
bool add_element(List* l, Value* value);
```

Développer une fonction qui permet de trouver un élément dans la liste en fonction de la valeur `id`.

La valeur `id` est donc passée par paramètre à la fonction.

Si une valeur est trouvée, la fonction retourne `true` sinon `false`

La fonction retournera aussi par référence une copie de la structure si il y a une correspondance pour `id`.

#### Execution
Voici la fonction qui devrait pouvoir être exécutée

```C
    List l = {0};
    Value v;
    v.id = 1;
    v.measure = 1.3;
    strcpy(v.name, "Foo");
    add_element(&l, &v);

    v.id = 2;
    v.measure = 0.3;
    strcpy(v.name, "Bar");
    add_element(&l, &v);

    v.id = 6;
    v.measure = 56.3;
    strcpy(v.name, "Bob");
    add_element(&l, &v);

    if (find_list(&l, 2, &v))
    {
        printf("Id : %d / name : %s\n", v.id, v.name);
    }

    if (find_list(&l, 6, &v))
    {
        printf("Id : %d / name : %s\n", v.id, v.name);
    }

    if (find_list(&l, 9, &v))
    {
        printf("Id : %d / name : %s\n", v.id, v.name);
    }
    else
    {
        printf("Id not found\n");
    }
```

## Ex 4

Il y a une collection de données qui peut être représentée ainsi :

```C
typedef struct {
    int num;
    double value;
} Data;
```

Il faut représenter cette collection au moyen d'une liste chaînée afin de
pouvoir insérer facilement un élément au milieu de la liste.

Il faut insérer les éléments pour que la liste soit triée de façon à ce que la valeur de `num` reste croissante.
Ce qui veut dire que le premier élément sera celui qui possède la structure `Data` ayant la valeur `num` la plus petite.

Développer les fonctions afin de pouvoir :
- Insérer un nouvel élément (pour insérer un élément, il faut donner la valeur `num` et `value`)
- Afficher la liste 
- Libérer la mémoire

Le programme principal devrait ressembler à quelque chose comme ceci 

```C
int main(void){
    List l = {0};
    list_insert(&l, 4, 125.34);
    list_insert(&l, 2, -9872.4584);
    list_insert(&l, 8, -45.123);
    list_insert(&l, 78, -1.6);
    list_insert(&l, 34, 0.6);
    list_insert(&l, 1, 12.6);
    list_afficher(&l);
    list_liberer(&l);
}
```

```text
$./app

Les valeurs sont :
1   :     12.6
2   :  -9872.4584
4   :    125.34
8   :    -45.123
34  :      0.6
78  :     -1.6
```

## Ex 5

Avec la liste suivante

```C
typedef struct Element{
    int val;
    struct Element* next;
} Element;

typedef struct{
    Element* next;
    Element* previous;
} List;
```

Développer une fonction qui permet d'ajouter une valeur à une position dans la liste.

Le prototype de la fonction est

```C
bool add(List* l, int pos, int value);
```

Si la fonction est appelée avec 
- `pos == 0` : ajout au début de la liste
- `pos == 1` : ajout de la valeur après le premier élément
- `pos == 2` : ajout de la valeur après le deuxième élément

Si la position n'est pas possible ou qu'il y a une erreur, la fonction retourne `false`


## Ex 6

Un fichier texte contient les données suivantes

```text
date,val1,val2
2021-05-1,20,5.7

2021-06-3,6,-78.00
2021-06-3,7,AABB
2021-06-12,2,36.2
2021-07,1,45.67
2021-07-3,34,-0.02
2021-09-28,23,4587.3
```

Le format pour une ligne valide doit être : `date,val1,val2`. 

Les valeurs sont séparées par des `,`.

Si les informations d'une ligne ne correspond pas au format, la ligne sera simplement ignorée.

### But

Créer une fonction qui lit ce fichier texte et sauve chaque lignes dans une structure.

La structure doit donc contenir au moins les trois valeurs de la ligne.

Les structure seront placée par ordre croissant en utilisant `val1` comme donnée de tri.

Développer une fonction qui affiche les données de la liste

```text
Date         Val1   Val2
2021-06-12     2     36.2
2021-06-3      6    -78.00
2021-05-1     20      5.7
2021-09-28    23   4587.3
2021-07-3     34     -0.02
```


## Solutions

### Ex 1

1. C'est une liste ou le premier élément inséré sera le premier à sortir. Cela est comparable à une file d'attente.
1. C'est une liste ou le premier élément inséré sera le dernier à sortir. Cela est comparable à une pile d'assiette

### Ex 2

1. Il faut connaître l'adresse du premier et du dernier élément.
1. Il faut connaître l'adresse du premier élément.

## Ex 3

```C
bool add_element(List* l, Value* value)
{
    Element* e = malloc(sizeof(Element));
    if (e == NULL) return false;
    e->val = *value;
    e->next = l->head;
    l->head = e;
    return true;
}

bool find_list(List* l, int id, Value* val)
{
    if( l->head == NULL ){
        return false;
    }

    Element* current = l->head;
    do
    {
        if (current->val.id == id)
        {
            *val = current->val;
            // possible aussi de copier les champs
            return true;
        }
        current = current->next;
    } while (current != NULL);

    return false;
}
```