# Allocation dynamique

## Ex 1
Allouer un tableau de `int` dont la taille est donné par `nbr`

Faire une boucle `for` pour remplir le tableau avec une valeur de `5`

Ajouter tout le code nécessaire pour que le programme soit fait avec les bonnes pratiques

Compléter le code ci-dessous

```C
void main()
{
    const int nbr = 5;
}
```

## Ex 2
Le programme principal envoie une chaîne de caractère dans la fonction `printUpper`.

La fonction `printUpper` alloue une chaîne de caractère de la même taille que la chaîne passée en paramètre.

Dans le code ci-dessous, le nom du pointeur pour la chaîne est nommé `c`

La fonction rempli la chaîne allouée avec une copie du texte passée en paramètre, mais modifiée en majuscule.

```C
void printUpper(char* txt){
    // Allocation de la chaîne temporaire

    // Boucle pour remplir la nouvelle chaîne en majuscule

    // Affichage de la chaîne de caractères
    printf("%s", c);
}

void main() 
{
    char* text = "Bonjour";
    printUpper(text);
}
```

## Ex 3
Idem que l'exercice `2` mais ici la fonction `stringToUpper` retourne la nouvelle chaîne.

Vous devez développer la fonction `stringToUpper`

Le `printf` de la chaîne se fait dans la fonction `main`.

```C
void main() 
{
    char* text = "Bonjour";
    //... = stringToUpper(text);

    printf("%s\n", c);
}
```

## Ex 4
Compléter le code ci-dessous pour :
1. Allouer un tableau de 7 entiers avec le code de validation nécessaire
1. La boucle `for` simule un programme qui va ajouter des valeurs dans le tableau
1. Ajouter du code pour que si l'on dépasse la capacité du tableau, on **double** sa capacité.
1. Ajouter les tests pour que le code soit robuste.

```C
void ex4()
{
    printf("Ex 4 allocation\n");
    int size = 7;
    
    int* tab = //allouer un tableau de 7 entiers 

    for(int i = 0; i<20; i++){
        if( i < size )
            tab[i] = i;
        else{
            // ???
        }
    }

    free(tab);
}
```

# Solutions
## Ex 1
#### Points importants
- `(int*)` pour `caster` le `malloc`
- Ne pas oublier le `sizeof` dans le malloc
- Tester si le pointeur d'allocation est non nul
- Ne pas oublier de libérer la mémoire

```C
    const int nbr = 5;

    int* tab = (int*)malloc(sizeof(int) * nbr);
    if (tab != NULL)
    {
        for (int i = 0; i < nbr; i++)
        {
            tab[i] = 5;
        }
    }

    free(tab);
    tab = NULL; // Optionnel
```

## Ex 2
- Ne pas oublier de compter le `\0`
- Test du pointeur `NULL`
- Libération de la mémoire

```C
void printUpper(char* txt){
    size_t size = strlen(txt) + 1;
    char* c = (char*)malloc(size);

    if( c == NULL )
    {
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<size; i++)
    {
        c[i] = toupper( txt[i] );
    }

    printf("%s\n", c);

    free(c);
}

void main() 
{
    char* text = "Bonjour";
    printUpper(text);
}
```

## Ex 3
- Ne pas oublier de libérer la mémoire dans le `main` après le `printf`
- Ne pas oublier de tester si le retour de `stringToUpper` n'est pas `NULL` si la fonction peut retourner `NULL`

```C
char* stringToUpper(char* txt){
    size_t size = strlen(txt) + 1;
    char* c = (char*)malloc(size);

    if( c == NULL )
    {
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<size; i++){
        c[i] = toupper( txt[i] );
    }

    return c;
}

void ex3() 
{
    char* text = "Bonjour";
    char* c = stringToUpper(text);

    // si il n'y a pas d'exit() dans la fonction stringToUpper et
    // que la fonction peut retourner une valeur NULL, 
    // il faut tester si le retour de stringToUpper ici

    printf("%s\n", c);
    // a ne pas oublier
    free(c);
}
```

## Ex 4
```C
```
