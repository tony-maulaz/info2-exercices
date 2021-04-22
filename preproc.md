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

## Ex 1.1

Quel est l'affichage du programme suivant

```C
#define MAC_1_1(x,y) (x * y)

void main(){
    printf("Ex 1-1 : %d\n", MAC_1_1( 3+1 , 4+2 ));
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

## Ex 4

Avec les définitions suivantes

```C
#define VAL_1 12
#define VAL_2 7
#define SOMME VAL_1 + VAL_2
```

Quel code sera généré par l'opération suivante
```C
    int val = SOMME * 4;
```

## Ex 5 (facultatif, pas demandé au TE ou exa)

Avec la définition suivante

```C
#define DECL_STR(a) char* a = #a
```

Quel code sera généré par l'opération suivante
```C
    DECL_STR(txt);
```

## Ex 6

Quel est l'affichage du programme suivant

```C
#define AFF_EX6

void main(){
    #ifdef AFF_EX6
        printf("Ex 6 : Cas 1\n");
    #else
        printf("Ex 6 : Cas 2\n");
    #endif
}
```

## Ex 7 (facultatif, pas demandé au TE ou exa)

Quel est l'affichage du programme suivant

```C
#define AFFICHAGE(a) printf("Le texte : %s", #a)

#ifdef AFF_EX7
    #define TEXTE AFFICHAGE(Bonjour);
#else
    #define TEXTE AFFICHAGE(Hello);
#endif

void main(){
    TEXTE;
}
```

## Ex 8
Définir une macro qui donne le minimum entre 2 nombres

*Utiliser une instruction ternaire*

On doit pouvoir l'utiliser ainsi
```C
MIN_2(4,3)
```

## Ex 9
En utilisant la macro de l'exercice `8`, définir une macro qui donne le minimum entre 3 nombres


## Solutions

### Ex 1
```console
Ex 1 - val 1: 11
Ex 1 - val 2: x=3,  res=3
Ex 1 - val 3: 2.00
```

### Ex 1-1

```console
Ex 1-1 : 9
```

Le code créé sera 
```C
(3+1 * 4+2)
```

Voici l'importance de mettre des `()` aussi entre les paramètres

```C
#define MAC_1_1(x,y) ((x) * (y))
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

### Ex 4
```C
    int val = 12 + 7 * 4;
```

### Ex 5
```C
    char* txt = "txt";
```

### Ex 6
```console
Ex 6 : Cas 1
```

### Ex 7
```console
Le texte : Hello
```

### Ex 8
```C
#define MIN_2(a,b) (a < b ? a : b)
```

### Ex 9
```C
#define MIN_3(a,b,c)  ( (a < b) && (a < c) ? a : MIN_2(b,c))
```
