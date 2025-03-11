# Ex 1 :
Ecrire une fonction qui retourne la taille d'un fichier en octets.
Si il y a une erreur, la fonction retourne -1.

# Ex 2 :
Ecrire une fonction qui retourne le nombre de lignes d'un fichier texte.
En cas d'erreur, la fonction retourne -1.

# Ex 3 :
Créer une fonction qui remplis un fichier csv avec une génération de sinus, cosinus.

La fonction prend en paramètre :
- le nom du fichier
- le temps total
- le pas de temps
- la fréquence

Exemple d'appel :
```c
generate_csv("sinus.csv", 10, 0.1, 1);
```

Le calcul du sinus et du cosinus se fait avec la formule suivante :

$sinus = sin(2 * PI * f * t)$

Le fichier généré doit ressembler à :
```
temps,sinus,cosinus
0.0,0.0,1.0
0.1,0.1,0.995
...
```

# Ex 4 :
Une structure est définie comme suit :
```c
typedef struct {
    int x;
    int y;
    int z;
} Point;
```

## Ex 4.1
Ecrire une fonction qui permet de sauvegarder un tableau de points dans un fichier binaire.

```c
Point points[] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

save_points("points.bin", points, 3);
```

La fonction prend en paramètre :
- le nom du fichier
- le tableau de points
- le nombre de points

## Ex 4.2
Ecrire une fonction qui permet d'ajouter un point à la fin d'un fichier binaire.

La fonction prend en paramètre :
- le nom du fichier
- le point à ajouter

Si le fichier n'existe pas, il est créé.

## Ex 4.3
Ecrire une fonction qui permet de lire un fichier binaire contenant un tableau de points.

Cette fonction affiche les points lus sur la sortie standard.

La fonction prend en paramètre :
- le nom du fichier
- un pointeur sur un tableau de points
- le nombre de points à lire

# Ex 5 :
Ecrire une fonction qui écrit sur la console toute les lignes d'un fichier texte qui contiennent plus de 30 caractères.

# Ex 6 :
Ecrire une fonction qui prend un tableau de double en paramètre et qui écrit ces valeurs dans un fichier texte avec 1 digit après la virgule.

Avec le tableau suivant :
```c
double tab[] = {1.23456, 3.4456};
```

La fonction écrit dans le fichier :
```
1.2
3.4
```

# Ex 7 :
Ecrire une fonction qui écrit sur la console le mot le plus long d'un fichier texte.

La fonction prend en paramètre le nom du fichier.

Le fichier contient un mot par ligne.

Exemple de fichier :
```
bonjour
salut
hello
```

La fonction affiche :
```
bonjour
```