# Exercices sur les enum

## Ex 1

Déclarer une énumération `Jour` qui représente les jours de la semaine (`LUNDI`, `MARDI`, ..., `DIMANCHE`), sans utiliser `typedef`.

Déclarer ensuite une variable de type `Jour` initialisée à `MERCREDI`.

## Ex 2

Quel est le problème du code ci-dessous ?

```C
enum Couleur {
    ROUGE,
    VERT,
    BLEU
};

int main(){
    Couleur c = ROUGE;
    return 0;
}
```

## Ex 3

Quel est l'affichage du programme suivant ?

```C
typedef enum {
    LUNDI,
    MARDI,
    MERCREDI,
    JEUDI,
    VENDREDI,
    SAMEDI,
    DIMANCHE
} Jour;

int main(){
    Jour j = JEUDI;
    printf("j = %d\n", j);
    printf("DIMANCHE = %d\n", DIMANCHE);
}
```

## Ex 4

Quel est l'affichage du programme suivant ?

```C
typedef enum {
    A = 3,
    B,
    C = 10,
    D,
    E
} Lettre;

int main(){
    printf("A=%d B=%d C=%d D=%d E=%d\n", A, B, C, D, E);
}
```

## Ex 5

Donner deux différences entre une énumération et une série de `#define`.

Exemple à comparer :

```C
#define ROUGE 0
#define VERT  1
#define BLEU  2
```

et

```C
typedef enum {
    ROUGE,
    VERT,
    BLEU
} Couleur;
```

## Ex 6

Écrire une fonction `nom_jour` qui retourne une chaîne de caractères correspondant au nom du jour passé en paramètre.

```C
typedef enum {
    LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE
} Jour;

const char* nom_jour(Jour j);
```

Exemple d'utilisation :

```C
printf("%s\n", nom_jour(MERCREDI));
```

Affichage attendu :

```console
mercredi
```

## Ex 7

À l'aide de l'énumération `Jour` de l'exercice précédent, écrire une fonction `est_weekend` qui retourne `1` si le jour passé en paramètre est un samedi ou un dimanche, `0` sinon.

Utiliser une instruction `switch`.

## Ex 8

Implémenter une énumération `Etat` représentant les états d'un feu de circulation : `ROUGE`, `ORANGE`, `VERT`.

Écrire une fonction `etat_suivant` qui retourne l'état suivant du feu selon le cycle :

```
ROUGE -> VERT -> ORANGE -> ROUGE -> ...
```

Signature attendue :

```C
Etat etat_suivant(Etat e);
```

Exemple d'utilisation :

```C
Etat e = ROUGE;
for(int i = 0; i < 5; i++){
    printf("%d\n", e);
    e = etat_suivant(e);
}
```

## Ex 9 (facultatif)

Définir une énumération `Permission` utilisée comme drapeaux binaires (bit flags) avec les valeurs :
- `LECTURE` = 1
- `ECRITURE` = 2
- `EXECUTION` = 4

Combiner ensuite les permissions `LECTURE` et `ECRITURE` dans une variable et tester si la permission `EXECUTION` est active.


## Solutions

### Ex 1

```C
enum Jour {
    LUNDI,
    MARDI,
    MERCREDI,
    JEUDI,
    VENDREDI,
    SAMEDI,
    DIMANCHE
};

int main(){
    enum Jour j = MERCREDI;
}
```

Sans `typedef`, il faut écrire `enum Jour` à chaque déclaration de variable.

### Ex 2

Le type `Couleur` n'existe pas tel quel : il s'appelle `enum Couleur`. Sans `typedef`, il faut écrire :

```C
enum Couleur c = ROUGE;
```

ou utiliser un `typedef` :

```C
typedef enum {
    ROUGE,
    VERT,
    BLEU
} Couleur;

Couleur c = ROUGE;
```

### Ex 3

```console
j = 3
DIMANCHE = 6
```

Par défaut, le premier identifiant vaut `0` et chaque suivant est incrémenté de `1`.

### Ex 4

```console
A=3 B=4 C=10 D=11 E=12
```

Les valeurs explicites fixent le compteur ; les suivantes reprennent l'incrémentation à partir de cette valeur.

### Ex 5

- Une énumération crée un véritable type (vérifié par le compilateur), tandis qu'un `#define` est un simple remplacement textuel sans type.
- Une énumération attribue automatiquement des valeurs croissantes aux constantes, ce qui simplifie l'ajout/le retrait d'éléments.
- Les valeurs d'une énumération sont visibles par le débogueur (le nom symbolique est conservé), ce qui n'est pas le cas avec un `#define`.

### Ex 6

```C
const char* nom_jour(Jour j){
    switch(j){
        case LUNDI:    return "lundi";
        case MARDI:    return "mardi";
        case MERCREDI: return "mercredi";
        case JEUDI:    return "jeudi";
        case VENDREDI: return "vendredi";
        case SAMEDI:   return "samedi";
        case DIMANCHE: return "dimanche";
    }
    return "inconnu";
}
```

Variante avec un tableau (en exploitant le fait que les valeurs commencent à `0`) :

```C
const char* nom_jour(Jour j){
    static const char* noms[] = {
        "lundi", "mardi", "mercredi", "jeudi",
        "vendredi", "samedi", "dimanche"
    };
    return noms[j];
}
```

### Ex 7

```C
int est_weekend(Jour j){
    switch(j){
        case SAMEDI:
        case DIMANCHE:
            return 1;
        default:
            return 0;
    }
}
```

### Ex 8

```C
typedef enum {
    ROUGE,
    VERT,
    ORANGE
} Etat;

Etat etat_suivant(Etat e){
    switch(e){
        case ROUGE:  return VERT;
        case VERT:   return ORANGE;
        case ORANGE: return ROUGE;
    }
    return ROUGE;
}
```

Variante plus compacte en utilisant l'arithmétique modulaire (à condition que les valeurs de l'énumération restent contiguës et dans l'ordre du cycle) :

```C
Etat etat_suivant(Etat e){
    return (e + 1) % 3;
}
```

### Ex 9

```C
typedef enum {
    LECTURE   = 1,  // 0b001
    ECRITURE  = 2,  // 0b010
    EXECUTION = 4   // 0b100
} Permission;

int main(){
    int perm = LECTURE | ECRITURE;

    if (perm & EXECUTION) {
        printf("Execution activée\n");
    } else {
        printf("Execution désactivée\n");
    }
}
```

Affichage :

```console
Execution désactivée
```
