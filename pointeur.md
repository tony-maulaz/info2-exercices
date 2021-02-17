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