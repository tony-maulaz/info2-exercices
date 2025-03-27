# Exercices sur l'allocation dynamique en C

1. Représenter graphiquement les zones mémoires du code suivant (zone programme, zone fonction, zone allocation...): 
```c
typedef struct {
    int id;
    double value;
} Measure;

int main(void){
    Measure* data = malloc(10 * sizeof(Measure));
}
```

2. Représenter en graphiquement les zones mémoires du code suivant : 
```c
typedef struct {
    int id;
    double value;
} Measure;

typedef struct {
    Measure* datas;
    int capacity;
} Array;

int main(void){
    Array ar;
    ar.datas = malloc(10 * sizeof(Measure));
}
```

3. Représenter en graphiquement les zones mémoires du code suivant : 
```c
typedef struct {
    int id;
    double value;
} Measure;

typedef struct {
    Measure* datas;
    int capacity;
    char* name;
} Container;

Container* create(int capacity, const char* name){
    Container* ar = malloc(sizeof(Container));
    ar->datas = malloc(capacity * sizeof(Measure));
    ar->name = name;
    return ar;
}

int main(void){
    Container* tab = create(10, "Meas1");
}
```

4.
- Qu'est ce qui est stocké dans la variable `ar->name` dans la structure `Container` de l'exercice 3 ?
- Que fais l'instruction `ar->name = name;` de l'exercice 3 ?
- Ecrire une instruction dans le main de l'exercice 3 qui permet de récupèrer la valeur de la 3ème mesures.
- Est-ce que la taille de la structure `Container` de l'exercice 3 dépend du nombre de mesure ?

5. Écrivez une fonction `int* creer_tableau(int taille)` qui alloue dynamiquement un tableau de valeurs entières, l'initialise à 0, et retourne un pointeur vers ce tableau.

6. Écrivez une fonction `char* copier_majuscule(const char* chaine)` qui retourne une copie de la chaîne passée en paramètre, convertie en majuscules. Utilisez l'allocation dynamique.

7. Implémentez une fonction `void liberer_memoire(int* tableau)` qui libère un tableau d'entiers alloué dynamiquement.

8. Écrivez une fonction `char* decouper_mot(const char* phrase)` qui retourne le premier mot d'une phrase (mots séparés par des espaces) ou NULL si pas de mot.

9. Implémentez une fonction `void insert_element(int* tableau, int* count, int element)` qui ajoute dynamiquement un élément au début d’un tableau d’entiers (`count`: le nombre d'éléments). On sait qu'il reste de la place dans le tableau.

10. Implémentez une fonction `char* concatener(const char* s1, const char* s2)` qui retourne une nouvelle chaîne, résultat de la concaténation de deux chaînes données, allouée dynamiquement.

11. Créez une structure `Point` contenant deux coordonnées entières `x` et `y`, puis écrivez une fonction `Point* creer_point(int x, inty)` qui retourne un pointeur vers nouveau point.

12. Créez une structure `Etudiant` contenant un nom (chaîne dynamique) et une note (float), puis écrivez une fonction `Etudiant* creer_etudiant(const char* nom, float note)` qui retourne un pointeur vers un nouvel étudiant.

13. Le programme `main` suivant est créé en fonction de l'exerice précédant.
```c
int main(){
    Etudiant* class[] = {NULL, NULL, NULL, NULL, NULL};

    class[0] = creer_edutiant("Alice", 5.8);
    class[1] = creer_edutiant("John", 2.3);
    class[2] = creer_edutiant("Bob", 4.5);
}
```

- Est-ce que le code parraît correct ?
- Est-ce qu'il est correct de stocker des pointeurs ou il faudrait un tableau d'étuidant à la place ?
- Représenter graphiquement la mémoire de ce programme.
- Que se passe-t-il avec l'instruction `class[3]->nom
