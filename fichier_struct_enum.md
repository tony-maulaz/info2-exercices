# Liste de formes géométriques

## Description
Créer un programme en C permettant de gérer une liste de formes géométriques.

Une forme géométrique est définie par une structure `Shape` qui contient :
- Un nom `name` (chaîne de caractères max 20) pour identifier la forme.
- Un type de forme `type` (enum) qui peut être un cercle, un carré ou un triangle.
- Une couleur `color` (enum) qui peut être rouge, vert ou bleu.
- Des coordonnées `x`, `y` (flottants) pour la position de la forme.

## Une liste de formes est contenue dans un fihcier `csv` avec les champs suivants :
- `name` : nom de la forme.
- `type` : type de la forme (cercle, carré, triangle).
- `color` : couleur de la forme (rouge, vert, bleu).

Voici un exemple de contenu du fichier `shapes.csv` :
```
name,type,color,x,y
Circle1,0,0,10.5,20.5
Circle2,0,1,20.5,20.5
Circle3,0,2,30.5,20.5
Square,1,1,15.0,25.0
Triangle,2,2,30.0,35.0
```

## Tableau dynamique
Créer un tableau dynamique de formes géométriques qui permet d'initialiser, ajouter, et afficher des formes.

Lors de la création du tableau, il doit être initialisé avec une taille de 3. Si le tableau est plein, il doit être redimensionné pour doubler sa capacité.

## Cahier des charges
Le fichier à lire est passé en argument du programme. Le programme doit :
1. Lire le fichier et remplir le tableau dynamique de formes géométriques.
2. Afficher le contenu du tableau.
3. Sauver le tableau dans un fichier `shapes_output.bin` en binaire.