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
