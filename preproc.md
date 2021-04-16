# Exercices pré-processeur

## Ex 1

Quel est l'affichage du programme suivant

```C
#define EX1_ADD(a,b) a + b 
#define EX1_MAX(x, y) (x > y ? x : y)
#define EX1_DIV(x,y) (x/y)

void ex1(){

    int res1 = EX1_ADD(3,4) * 2;
    printf("Ex 1 - val 1: %d\n", res1);

    int x = 2;
    int y = 3;
    int res2 = EX1_MAX(++x, y);
    printf("Ex 1 - val 2: x=%d,  res=%d\n", x, res2);

    double res3 = EX1_DIV(5,2);
    printf("Ex 1 - val 3: %.2lf\n", res3);
}
```

## Ex 2

Modifier le code ci-dessous.

Définir un `define` `PRODUCTION` afin que si sa valeur vaut `0` la variable `x` prend la valeur de `5` sinon `9`

Utiliser un `if` avec le préprocesseur pour faire la sélection.

```C
static void ex2(){
    int x;

    //Simulation
    x = 5;

    //Production
    x = 9;

    printf("La valeur de x est : %d\n", x);
}
```

## Ex 3

Créer une `macro` `REPEAT` qui permet d'afficher plusieurs fois le même caractère sur la console.

Cette `macro` prend 2 paramètres en entrée

x
: le nombre de fois qu'il faut répéter le caractère

c
: le caractère à répéter

Exemple d'utilisation

Dans le code
```C
REPEAT(3,'Q');
```

Affichage
```console
QQQ
```

## Solutions

### Ex 1
```console
Ex 1 - val 1: 11
Ex 1 - val 2: x=3,  res=3
Ex 1 - val 3: 2.00
```

### Ex 2
```C
#define PRODUCTION 1
static void ex2(){
    int x;

    #if PRODUCTION == 0
    //Simulation
    x = 5;
    #else
    //Production
    x = 9;
    #endif

    printf("La valeur de x est : %d\n", x);
}
```

### Ex 3
```C
#define REPEAT_1(x,c) for(int i=0; i<x; i++){printf("%c",c);}
static void ex3(){
    REPEAT_1(3,'a');
    puts("");
}
```