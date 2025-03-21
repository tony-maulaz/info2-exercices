# Exercice C : Manipulation de fichiers binaires et tableaux dynamiques

## Objectif
Dans cet exercice, vous allez apprendre à :
- Écrire des données dans un fichier binaire à partir d’un tableau statique.
- Lire les données depuis un fichier binaire dans un tableau dynamique.
- Gérer la mémoire dynamiquement en C.

## Étapes à suivre

### Partie 1 : Création et écriture du fichier binaire

1. Créez un tableau statique de `double` contenant les valeurs suivantes :
   ```c
   double tab[] = {1.1, -3.4, 4.55};
   ```

2. Ouvrez un fichier binaire.
3. Écrivez le contenu du tableau dans le fichier.
4. Fermez le fichier.

### Partie 2 : Lecture et manipulation dynamique

1. Ouvrez le fichier binaire.
2. Calculez le nombre d’éléments de type `double` contenus dans le fichier.
3. Allouez dynamiquement un tableau de `double` pour contenir les données.
4. Copiez les données du fichier dans le tableau dynamique.
5. Fermez le fichier.
6. Écrivez une fonction qui affiche les valeurs du tableau.
7. Appelez cette fonction pour afficher les valeurs du tableau.
8. Libérez la mémoire allouée dynamiquement.
9. Terminez proprement le programme.

Une fois que le programme fonnctionne, vous devez pouvoir ajouter des valeurs dans le tableau sans
perturber le fonctionnement du programme.

### Partie 3

Copiez le code des parties #1 et #2 et modifiez les pour avoir un tableau de structure plutôt que des `double`.

Utilisez par exemple une structure : 
```c
typedef struct{
    int x;
    int y;
}Point;
```
