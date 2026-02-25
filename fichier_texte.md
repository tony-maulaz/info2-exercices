# Les fichiers

#### Rappel du format `scanf`

Le format pour récupérer une chaîne de caractères
avec des espaces est `"%[^\n]s"`.

## Questions

Pour les questions, le contenu du fichier `question.txt` est :
```console
ABCD
EFGH
1234
```

### Q1
Quel est le danger du code ci-dessous ?
```C
    FILE* f = fopen("question.txt", "r");
    char c;
    while ((c = fgetc(f)) != EOF)
    {
        printf("%c", c);
    }
    fclose(f);
```

### Q2

Quel est l'affichage du programme ?

```C
    FILE* f2 = fopen("question.txt", "r");
    char c2  = fgetc(f2);
    c2  = fgetc(f2);
    c2  = fgetc(f2);
    printf("Val = %c\n", c2);
    fclose(f2);
```

### Q3

Quel problème a le code suivant ?

```C
FILE* f3 = fopen("question.txt", "r");
if( f3 != NULL)
{
    char c3;
    while ((c3 = fgetc(f3)) != EOF)
    {
        printf("%c", c3);
    }
}
f3 = fopen("question.txt", "r");
```

### Q4

Quel est l'affichage du programme suivant ?

```C
    FILE* f4 = fopen("question.txt", "r");
    char txt[10];
    char c4;
    fgets(txt,10,f4);
    c4  = fgetc(f4);
    printf("Val = %c\n", c4);
    fclose(f4);
```

### Q5

Quel est l'affichage du programme suivant ?

```C
    FILE* f5 = fopen("question.txt", "r");
    char txt5[10];
    char c5;
    fgets(txt5,10,f5);
    c5  = fgetc(f5);
    c5  = fgetc(f5);
    fgets(txt5,10,f5);
    c5  = fgetc(f5);
    printf("Val c5 = %c\n", c5);
    printf("Val txt5 = %s\n", txt5);
    fclose(f5);
```

## Ex 1
Créer un programme qui réalise les opérations suivantes :
- Crée un fichier texte et écrit `Bonjour` dedans.
- Ajoute ` tout le monde à la suite` (utiliser le mode `a`).
- Lit le fichier et affiche le contenu sur la console avec `fgets`.

Le fichier est fermé entre chaque opération.

## Ex 2
Créer un programme qui réalise les opérations suivantes :
- Crée un fichier texte et écrit `Bonjour` dedans.
- Ajoute `Tout le monde.` sur la `deuxième ligne`.
- Contrôler avec un éditeur que le fichier est bien sur `2` lignes.
- Lire le fichier et afficher le contenu sur la console une fois avec `fgetc` et une fois avec `fgets`.

Le fichier est fermé entre chaque opération.

## Ex 3
Créer un programme qui remplit un fichier avec les multiples de `7` jusqu’à `100`.

Ensuite, lire le fichier et l’afficher sur la console.

Le fichier est fermé entre l'écriture et la lecture.

```console
7
14
21
28
...
```

## Ex 4
Créer un programme qui regarde si le fichier
`name.txt` existe.
- Si oui, afficher le nom qui est sauvegardé dedans
- Sinon, demander à l'utilisateur d'entrer son nom
et ensuite il faut le sauvegarder dans le fichier.

Il n'y a pas besoin de faire de validation de saisie.

```console
$ ./app
Veuillez entrer votre nom : > Tony

$ ./app
Bonjour : Tony
```

## Ex 5
Faire un programme qui écrit dans un fichier le carré et la racine
d'un nombre.

Les valeurs sont séparées par `,`

Une ligne :
`nombre`, `carré`, `racine`

```console
1,1,1
2,4,1.41
3,9,1.73
...
```

Le nombre de valeurs est donné par une `constante`

Ajouter une `fonction` pour lire le fichier et l'afficher à la `console`.

La fonction doit lire le fichier ligne par ligne.

Le code de la fonction de lecture doit être avec un `printf` :

```C
for(...){
    int nombre;
    int square;
    double root;

    printf("Num : %d  /  Square : %d  /  Root : %.2lf\n", nombre, square, root);
}
```

## Ex 7
Un fichier de mesure contient les valeurs suivantes (valeurs séparées par `\t`) :
```csv
2021-3-9 12:3	1	34.560000
2021-3-9 13:42	2	-98.230000
2021-3-9 14:12	3	987.470000
2021-3-9 15:52	4	-123.900000
```

Copier ces valeurs à l'intérieur d'un fichier.

Ensuite, compléter le code suivant afin que l'on puisse choisir la ligne
du fichier que l'on veut afficher en fonction de la variable `line`.

```C
int year, month, day;
int hour, min;
int id;
double value;

int line = 3;

// placer votre code ici :

printf("\nExercice 7 : lecture\n");
printf("Dat : %d/%d/%d\n", day, month, year);
printf("Time : %dh%d\n", hour, min);
printf("Value : %.2lf\n", value);
```

Par exemple en choisissant `line=3`, on doit avoir :

```console
Exercice 7 : lecture
Dat : 9/3/2021
Time : 14h12
Value : 987.47
```


# Solutions
## Q1
On doit toujours tester si le fichier est bien ouvert
```C
if( f == NULL )
    ....
```

## Q2
```console
Val = C
```

## Q3
Le fichier n'est pas fermé

## Q4
```console
Val = E
```

## Q5
```console
Val c5 = 1
Val txt5 = GH
```

## Ex 1 et 2
```C
    const char fname[] = "f_ex1.txt";

    FILE* fp = fopen(fname, "w");
    if (fp == NULL) exit(EXIT_FAILURE);

    fprintf(fp, "Bonjour");
    fclose(fp);

    fp = fopen(fname, "a");
    if (fp == NULL) exit(EXIT_FAILURE);

    fprintf(fp, " tout le monde");
    fclose(fp);

    // Ex 2 deuxième ligne
    fp = fopen(fname, "a");
    if (fp == NULL) exit(EXIT_FAILURE);

    fprintf(fp, "\nTout le monde");
    fclose(fp);

    // lecture fgets
    fp = fopen(fname, "r");
    if (fp == NULL) exit(EXIT_FAILURE);

    char txt[30];
    while (fgets(txt, 30, fp) != NULL)
    {
        printf("%s", txt);
    }
    fclose(fp);

    // lecture fgetc
    fp = fopen(fname, "r");
    if (fp == NULL) exit(EXIT_FAILURE);

    char c;
    printf("\nFichier fgetc: \n");
    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }
    fclose(fp);
```

## Ex 3
```C
    printf("Exercice 3 sur les fichiers \n");
    FILE* f = fopen("ex3.txt", "w");
    if (f == NULL) 
        exit(EXIT_FAILURE);
    
    int val = 7;
    do{
        fprintf(f,"%d\n", val);
        val += 7;
    }while(val < 100);
    fclose(f);

    printf("Lecture avec fscanf\n");
    f = fopen("ex3.txt", "r");
    while( fscanf(f,"%d",&val) != EOF ){
        printf("%d\n", val);
    }
    fclose(f);

    printf("Lecture avec fgets\n");
    f = fopen("ex3.txt", "r");
    char txt[100];
    while (fgets(txt, 100, f) != NULL)
    {
        printf(txt);
    }
    fclose(f);
```

## Ex 4
```C
    FILE* f = fopen("name.txt", "r");

    char name[20];
    if (f != NULL)
    {
        fgets(name, 20, f);
        fprintf(stdout, "Bonjour : %s\n", name);
    }
    else
    {
        printf("Veuillez entrer votre nom : > ");
        scanf("%[^\n]s", name);
        f = fopen("name.txt", "w+");
        fputs(name, f);
    }

    fclose(f);
```

## Ex 5
```C
    const char* filename = "ex5.txt";

    FILE* f = fopen(filename, "w");
    if (f == NULL) exit(EXIT_FAILURE);

    for (int i = 0; i < 10; i++)
    {
        fprintf(f, "%d,%d,%.2lf\n", i, (int)pow(i, 2), sqrt(i));
    }
    fclose(f);

    f = fopen(filename, "r");
    if (f == NULL) exit(EXIT_FAILURE);

    char buffer[MAX_LINE];

    while (fgets(buffer, MAX_LINE, f) != NULL) {
        int nombre, square;
        double root;

        if (sscanf(buffer, "%d,%d,%lf", &nombre, &square, &root) == 3) {
            printf("Num : %d  /  Square : %d  /  Root : %.2lf\n", nombre, square, root);
        } else {
            fprintf(stderr, "Erreur de lecture d'une ligne\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(f);
```

## Ex 7
```C
    FILE* fp = fopen("ex7_meteo.dat", "w");
    if (fp == NULL) 
        exit(EXIT_FAILURE);    

    // date                id    value
    // 2021-03-09 14:56    1      4.56
    int year = 2021;
    int month = 03;
    int day = 9;
    int hour = 12;
    int min = 3;
    int id = 1;
    double value = 34.56;
    fprintf(fp, "%d-%d-%d %d:%d\t%d\t%lf\n", year, month, day, hour, min, id, value);
    fprintf(fp, "%d-%d-%d %d:%d\t%d\t%lf\n", year, month, day, 13, 42, 2, -98.23);
    fprintf(fp, "%d-%d-%d %d:%d\t%d\t%lf\n", year, month, day, 14, 12, 3, 987.47);
    fprintf(fp, "%d-%d-%d %d:%d\t%d\t%lf\n", year, month, day, 15, 52, 4, -123.9);
    fclose(fp);

    fp = fopen("ex7_meteo.dat", "r");
    if (fp == NULL) 
        exit(EXIT_FAILURE);
        
    int line = 3;
    for (int i = 0; i < line; i++) {
        if (fgets(buffer, MAX_LINE, fp) == NULL) {
            fprintf(stderr, "Erreur de lecture ou fin de fichier atteinte prématurément\n");
            exit(EXIT_FAILURE);
        }
    }

    if (sscanf(buffer, "%d-%d-%d %d:%d\t%d\t%lf", &year, &month, &day, &hour, &min, &id, &value) == 7) {
        printf("\nExercice 7 : lecture\n");
        printf("Dat : %d/%d/%d\n", day, month, year);
        printf("Time : %dh%d\n", hour, min);
        printf("Value : %.2lf\n", value);
    }
    fclose(fp);
```
