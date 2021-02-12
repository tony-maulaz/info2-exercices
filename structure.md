## Les structures

### Ex 1

Déclarer une structure qui permet de représenter un `point` sans utiliser de `typedef`.

Un `point` a une coordonnée `x` et une `y` qui sont de type `double`

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

Quel est le problème du code ci-dessous ?

```C
struct Data {
    int v1;
    char c;
} d1;

int main(){
    d1.c = 'a';
}
```

### Ex 4

Quel est l'affichage du programme

```C
typedef struct {
    int v1 = 1;
    int v2;
} Data;

int main(){
    Data d1 = {
        v1 = 34;
        v2 = 8;
    };
    
    printf("Val = %d", d1.v1);
}
```


### Ex 5

Quel est l'affichage du programme

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

Complèter le code pour affecter "Bonjour" au champ `name` de `val`;

```C
typedef struct{
    int id;
    char name[100];
} Data;

void main(){
    Data d;
    
    // Complèter le code pour affecter "Bonjour" à la variable name de val;
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