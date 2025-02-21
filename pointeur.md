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

## Ex 8
Ajouter une ligne de code pour que le programme ci-dessous
affiche la plus grande chaîne de caractère.

```C
char txt1[] = "Bonjour";
char txt2[] = "Hello";

char* c1 = NULL;
// votre code ici

printf("%s\n", c1);
```

## Ex 9
Quel est l'affichage du programme suivant ?

```C
char txt[] = "Hello";

char* c1 = txt;

c1[1] = 'A';
txt[2] = 'b';

printf("Txt = %s\n", txt);
```

## Ex 10

Quel est l'affichage du programme ?

```C
//sizeof(int) = 4

int tab[] = {10,20,30,40,50,60,70,80,90};
int* p1 = tab;
int* p2 = &tab[4];
printf("Val1 = %d\n", (p2 - p1));
printf("Val2 = %d\n", *(++p2));
printf("Val3 = %d\n", *(p2-2));
printf("Val4 = %d\n", *(p2));
```

## Ex 11
Quel est l'affichage du programme suivant :
```C
    int ar[] = {2, 4, 6, 8, 10};
    int* p1 = ar;
    int** pp1 = &p1;
    int* p2 = ar + 2;
    int* pAr[] = {ar+1, ar+2, ar};
    int** pp2 = pAr+1;
    const char* tabText[] = {"Bonjour","comment"};

    int num = 1;
    puts("\nExemple de pointeurs\n");
    printf("Val %d : %d\n", num++, ar[1]);
    printf("Val %d : %d\n", num++, **pp1);
    printf("Val %d : %d\n", num++, *(p1+1));
    printf("Val %d : %ld\n", num++, pAr[1] - pAr[2]);
    printf("Val %d : %d\n", num++, pp2[1][2]);
    printf("Val %d : %d\n", num++, (*pp1)[1]);
    printf("Val %d : %c\n", num++, tabText[0][3]);
    printf("Val %d : %d\n", num++, *(*pp2-1));
    printf("Val %d : %d\n", num++, **(pp2-1));
    printf("Val %d : %c\n", num++, **(tabText+1));
    printf("Val %d : %d\n", num++, *(pAr[1]+1));
    printf("Val %d : %d\n", num++, *(pAr[1]+1));
    printf("Val %d : %s\n", num++, *(tabText+1)+2);   
```

## Ex 12

Remplacer les `...` pour que le programme affiche le nom du fichier

```C
char* argv[] = {"./app", "-ofile.txt", "-n5"};
char* c = ...;
printf("Le nom du fichier est : %s\n", c);
```

```console
Le nom du fichier est : file.txt
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

## Ex 7
```C
void func_ex7(char* p){
    size_t i = 0;
    do{
        p[i] = toupper(p[i]);
    }while(p[i++] != '\0');
}
```

## Ex 8
```C
c1 = strlen(txt1) > strlen(txt2) ? txt1 : txt2;
```

## Ex 9
```console
Txt = HAblo
```

## Ex 10
```console
Val1 = 4
Val2 = 60
Val3 = 40
Val3 = 60
```

## Ex 11
Executer le code...

