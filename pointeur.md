# Pointeur

## Ex 1

Donner 2 façons de récupérer la valeur du deuxième élément du tableau (le `20`).

```C
int tab[] = {10,20,30};
int* pi = tab;
```



## Ex 2
Quel est l'affichage du programme suivant :

```C
    int tab[] = {1,2,3,4};
    int* pi = tab;

    printf("Val 1 : %d\n", *pi);
    printf("Val 2 : %ld\n", sizeof(tab) / sizeof(int));
    printf("Val 3 : %d\n", pi[0]);
```

## Ex 3
Quel est l'affichage du programme suivant :

```C
    char* txt = "Bonjour";
    char* pc = txt;

    printf("Val 1 : %ld\n", sizeof(txt));
    printf("Val 2 : %c\n", txt[0]);
    printf("Val 3 : %c\n", *(pc++));
    printf("Val 4 : %c\n", *(pc++));
    printf("Val 5 : %c\n", pc[3]);
    printf("Val 6 : %ld\n", strlen(pc));
```

## Ex 4
Quel est l'affichage du programme suivant :

```C
int point_func(int* p){
    int val = 0;
    for(int i=0; i<4; i++){
        val += *p++;
    }
    return val;
}

void main(){
    int tab[] = {1,2,3,4,5};
    printf("Res : %d\n", point_func(tab));
}
```

## Ex 5
Quel est l'affichage du programme

```C
int tab[] = {1,2,3};
int *p;
p = tab + 2;
printf("Val : %d", *p);
```

## Ex 6
Quel est l'affichage du programme
```C
    char txt[] = "Bonjour";
    char* c = txt;
    printf("Val 1 : %c\n", *c);
    c = &txt[3];
    printf("Val 2 : %c\n", *c);
    c++;
    printf("Val 3 : %c\n", *c);  
```

## Ex 7

Complèter la fonction `func_ex7` avec une boucle `while`, afin de transformer la chaîne de caractère
en majuscule.

```C
void func_ex7(char* p){
}

char txt[] = "Bonjour";
func_ex7(txt);
printf("%s\n", txt);
```

```console
BONJOUR
```

# Solutions

## Ex 1
```C
tab[1];
pi[1];
```

## Ex 2
```console
Val 1 : 1
Val 2 : 4
Val 3 : 1
```

## Ex 3
```console
Val 1 : 8
Val 2 : B
Val 3 : B
Val 4 : o
Val 5 : u
Val 6 : 5
```

## Ex 4
```console
Res : 10
```

## Ex 5
```console
Res ex 5 : 3
```

## Ex 6
```console
Val 1 : B
Val 2 : j
Val 3 : o
```
