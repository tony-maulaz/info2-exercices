## Les structures

### Ex 1

Déclarer une structure qui permet de représenter un `point` sans utiliser de `typedef`.

Un `point` a une coordonnée `x` et une coordonnée `y` qui sont de type `int`.

### Ex 2

Quel est le problème du code ci-dessous ?

```C
struct Data {
    int v1;
    char c;
};

int main(){
    Data d1;
}
```

### Ex 3

Déclarer deux variables de type `Data` avec des valeurs identiques. Peut-on comparer `s1` et `s2` ?

```C
struct Data {
    int v1;
    char c;
};

int main(){
    struct Data s1 = { .v1 = 1, .c = 'a' };
    struct Data s2 = { .v1 = 1, .c = 'a' };

    if (s1 == s2) {
        printf("identiques\n");
    }
}
```

### Ex 4

Quel est l'affichage du programme ?

```C
typedef struct {
    int v1;
    int v2;
} Data;

int main(){
    Data d1 = {
        .v1 = 34,
        .v2 = 8
    };
    
    printf("Val = %d", d1.v1);
}
```


### Ex 5

Est-ce que l'on peut récupèrer le nombre de champs de cette façon ?

```C
typedef struct {
    int v1;
    int v2;
} Data;

int main(){
    printf("Val = %d", sizeof(Data) / sizeof(int) );
}
```

### Ex 6

Compléter le code pour affecter "Bonjour" au champ `name` de `d`.

```C
typedef struct{
    int id;
    char name[100];
} Data;

void main(){
    Data d;
    
    // Compléter le code pour affecter "Bonjour" à la variable name de d.
}
```
### Ex 7

Quel est l'affichage du programme suivant:

```C
typedef struct
{
    int v1;
} S2;

typedef struct
{
    int a;
    int b;
    S2* s;
} S1;

void test1(S1 s){
    printf("Val1 : %d\n", s.a);
    printf("Val2 : %d\n", s.s->v1);
    s.b = 3;
    s.s->v1 = 4;
}

void test2(S1* s){
    s->b = 5;
    s->s->v1 = 6;
}

void ex7() { 
    printf("Ex7\n"); 
    
    S2 s2 = {10};

    S1 s1;
    s1.a = 20;
    s1.b = 30;
    s1.s = &s2;

    test1(s1);    
    printf("Val3 : %d\n", s1.b);
    printf("Val4 : %d\n", s1.s->v1);
    printf("Val5 : %d\n", s2.v1);

    test2(&s1);    
    printf("Val6 : %d\n", s1.b);
    printf("Val7 : %d\n", s1.s->v1);
    printf("Val8 : %d\n", s2.v1);
}
```

### Ex 8

On donne la structure suivante :

```C
typedef struct {
    char name[20];
    int id;
} Data2;
```

Écrire une fonction qui compare si les champs de deux structures sont identiques. Elle retourne `true`.
Est-ce que l'on peut utiliser `memcmp` ?

### Ex 9

Créer une structure `Vector` qui contient `x` et `y` en `int`.
Créer une fonction qui permet de sommer deux vecteurs et cette fonction retourne une nouvelle structure.
Les structures sont passées en référence.

## Solutions

### Ex 1

Important : le nom du type est après le `struct`.

```C
struct Point
{
    int x;
    int y;
};
```

### Ex 2 

On ne peut pas utiliser directement le type 
`Data`, on doit faire :

```C
struct Data d1;
```

### Ex 3

On ne peut pas comparer directement deux structures avec `==`. Il faut comparer champ par champ (ou utiliser `memcmp` si c'est pertinent).

### Ex 4
```console
Val = 34
```

### Ex 5
```console
Val = 2
```

### Ex 6
```C
strcpy(d.name, "Bonjour");
```

### Ex 7
À vous de le compiler et de l'exécuter.

### Ex 8
```C
#include <stdbool.h>
#include <string.h>

bool data2_equal(const Data2* a, const Data2* b) {
    return (a->id == b->id) && (strcmp(a->name, b->name) == 0);
}
```

Concernant `memcmp` : ce n'est pas adapté ici, car `name` est un tableau de caractères et une partie du tableau peut ne pas être utilisée. `memcmp` comparerait aussi ces octets inutilisés. Il faut comparer champ par champ.

### Ex 9
```C
typedef struct {
    int x;
    int y;
} Vector;

Vector vector_add(const Vector* a, const Vector* b) {
    Vector r;
    r.x = a->x + b->x;
    r.y = a->y + b->y;
    return r;
}
```
