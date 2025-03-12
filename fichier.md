# Les fichiers

#### Rappel format `scanf`

Le format pour récupérer une chaîne de caractères
avec des espaces `"%[^\n]s"`

## Questions

Pour les questions, le contenu du fichier `question.txt` est :
```console
ABCD
EFGH
1234
```

### Q1
Quel est le problème du code ci-dessous ?
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

Le fichier est fermé entre chaque opérations.

## Ex 2
Créer un programme qui réalise les opérations suivantes :
- Crée un fichier texte et écrit `Bonjour` dedans.
- Ajoute `Tout le monde.` sur la `deuxième ligne`.
- Contrôler que le fichier est bien sur `2` lignes.
- Lit le fichier et affiche le contenu sur la console une fois avec `fgetc` et une fois avec `fgets`.

Le fichier est fermé entre chaque opérations.

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
- Si oui, afficher le nom qui est sauvé dedans
- Sinon, demander à l'utilisateur d'entrer son nom 
et ensuite il faut le sauver dans le fichier.

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

Le nombre de valeur est donné par une `constante`

Ajouter une `fonction` pour lire le fichier et l'afficher à la `console`

La fonction doit décoder le fichier ligne par ligne.

Le code de la fonction de lecture doit être avec un `printf` :

```C
for(...){
    int nombre;
    int square;
    double root;

    printf("Num : %d  /  Square : %d  /  Root : %.2lf\n", nombre, square, root);
}
```

## Ex 6

Dans un programme, nous avons la structure suivante :
```C
typedef struct{
    int id;
    double value;
    char txt[10];
} Meas;
```

Elle est déclarée ainsi :
```C
  Meas m1 = {.id=1, .value=2.34, .txt="Bonjour"};
```

Créer un programme qui exécute les opérations suivantes:
- sauver cette structure dans un fichier.
- fermer le fichier
- ouvrir le fichier en lecture
- lire le fichier pour placer les valeurs dans une structure `m2`
- exécuter le code ci-dessous pour l'affichage

```C
  Meas m2;
  // placer votre code de lecture ici

  printf("\nExercice 6 : structure\n");
  printf("Meas id : %d\n", m2.id);
  printf("Meas value : %.2lf\n", m2.value);
  printf("Meas txt : %s\n", m2.txt);
```

Votre programme doit afficher ceci :

```console
Exercice 6 : structure
Meas id : 1
Meas value : 2.34
Meas txt : Bonjour
```

## Ex 7
Un fichier de mesure contient les valeurs suivantes (valeurs séparées par `\t`):
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
int year, month day;
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

## Ex 8

**8.1 :** Quelle est la différence entre ces deux programmes :

**8.2 :** Dans quel cas ces programmes auront-ils un comportement différent ?

**8.3 :** Quelle version semble préférable, et pourquoi ?

<table>
<th>Programme 1</th>
<th>Programme 2</th>
<tr>
<td>
  <pre lang="C">
    
    #include <stdio.h>

    int main()
    {
        char texte[80];
        printf("Saisir un texte:");
        gets(texte);
        printf("Texte: %s\n", texte);
    }
  </pre>
</td>
<td>
  <pre lang="C">

    int main()
    {
        char texte[80];
        int longueur;

        printf("Saisir un texte:");
        fgets(texte, 80, stdin);
        // Suppression du \n terminal
        longueur = strlen(texte);
        if (texte[longueur - 1] == '\n')
            texte[longueur - 1] = '\0';
        printf("Texte: %s\n", texte);
    }

  </pre>
</td>
</tr>
</table>

## Ex 9

Il faut compléter le code suivant afin de sauvegarder le tableau `tab` dans un fichier.

Ensuite le code doit ouvrir le fichier et afficher les valeurs qui ont été écrites dedans.

```C
    double tab[] = {1.2, 4.5, 123.4, -12.893, 45.66, 56.5, 1, 2, 3};

    const int nbr_elem = // calcul du nombre d'éléments
    // Écriture dans le fichier
    fclose(fp);

    double tab_r[100];
    // Lecture du fichier et écriture des valeurs dans le tableau tab_r
    fclose(fp);

    // Affichage des valeurs du tableau
    printf("Val : ");
    for(int i=0; i<nbr_elem; i++)
        printf(" %.2lf ", tab_r[i]);
```

## Ex 10

A la fin du code suivant, quelle est la différence entre le contenu des deux fichiers ?

```C
    FILE* fp = fopen("ex10_file_1.dat", "w");
    char buffer_out[] = {'1','2','3'};
    fwrite(buffer_out, sizeof(char), 3, fp);
    fclose(fp);

    fp = fopen("ex10_file_2.dat", "w");
    fprintf(fp, "123");
    fclose(fp);
```

## Ex 11
Une structure de donnée est définie comme suit :
```C
typedef struct{
    int id;
    double value;
    char txt[10];
} Meas;
```

On sait que dans le fichier `ex11_file.dat` il y a des données de type `Meas`.

Créer une fonction qui prend en paramètre le nom du fichier et qui retourne le nombre de données de type `Meas` dans le fichier.

En cas d'erreur, la fonction doit retourner `-1`.

```C
int count_meas(const char* filename);
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
## Ex 6
```C
    Meas m1 = {.id = 1, .value = 2.34, .txt = "Bonjour"};

    FILE* fp = fopen("ex6_struct.dat", "w");
    if (fp == NULL) exit(EXIT_FAILURE);

    fwrite(&m1, sizeof(Meas), 1, fp);
    fclose(fp);

    fp = fopen("ex6_struct.dat", "r");
    if (fp == NULL) exit(EXIT_FAILURE);
    Meas m2;
    fread(&m2, sizeof(Meas), 1, fp);

    printf("\nExercice 6 : structure\n");
    printf("Meas id : %d\n", m2.id);
    printf("Meas value : %.2lf\n", m2.value);
    printf("Meas txt : %s\n", m2.txt);
    fclose(fp);
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

## Ex 8

#### 8.1 :
Le programme 2 utilise l’instruction fgets(texte, 80, stdin) au lieu de gets(texte) pour effectuer la saisie d’un texte.

#### 8.2 :
Si l’utilisateur saisit plus de 80 caractères, ces deux programmes auront un comportement différent. 

Le programme 1 écrira en mémoire au-delà de la limite du tableau texte, ce qui pourra causer des dysfonctionnements du programme survenant à un moment imprévisible.

Le programme 2 arrêtera la lecture du texte au 80ème caractère. Le reste du texte restera dans le tampon d’entrée.

#### 8.3 :
Le programme 2 a un fonctionnement plus sûr. Même si cela coûte un peu plus d’effort de programmation d’utiliser fgets à la place de gets, il est préférable d’utiliser dans des programmes industriels fgets pour éviter que les actions de l’utilisateur ne puissent déboucher sur des comportements erratiques.

## Ex 9
```C
    // Write
    FILE* fp = fopen("ex9_file.dat", "w");
    double tab[] = {1.2, 4.5, 123.4, -12.893, 45.66, 56.5, 1, 2, 3};

    const int nbr_elem = sizeof(tab) / sizeof(double);
    fwrite(&tab, sizeof(double), nbr_elem, fp);
    fclose(fp);

    // Read
    double tab_r[100];
    fp = fopen("ex9_file.dat", "r");
    fread(&tab_r, sizeof(double), nbr_elem, fp);
    fclose(fp);

    printf("Val : ");
    for(int i=0; i<nbr_elem; i++)
        printf(" %.2lf ", tab_r[i]);

    printf("\n");
```

## Ex 10
Aucune

## Ex 11
```C
int count_meas(const char* filename) {
    FILE *file = fopen(filename, "r"); // Ouvrir
    if (file == NULL) {
        return -1;
    }

    // Se déplacer à la fin du fichier pour obtenir la taille
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fclose(file); // Fermer le fichier

    return file_size / sizeof(Meas); // Retourne le nombre d'éléments
}
```
