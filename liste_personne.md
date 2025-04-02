# Exercice : Gestion de personnes avec fichier binaire et liste chaînée

## Partie 1 : Structure de la personne
Définir une structure `Person` avec :
* un tableau de `char` de taille 15 pour le nom
* un entier pour l'âge

## Partie 2 : Écriture dans un fichier binaire
Créer une fonction qui ajoute une personne dans un fichier binaire.
Les paramètres de la fonction sont :
- filename : le nom du fichier
- name : le nom de la personne
- age : l'âge de la personne

## Partie 3 : Ajout de 5 personnes
Dans la fonction `main`, appeler la fonction d'ajout 5 fois avec des noms et âges différents.
Exemples :

```c
add_person("personnes.dat", "Bob", 30);
add_person("personnes.dat", "David", 28);
add_person("personnes.dat", "Eva", 26);
add_person("personnes.dat", "Claire", 22);
add_person("personnes.dat", "Alice", 25);
```

## Partie 4 : Structure pour la liste chaînée
Définir deux structures :
* `Node` représentant un maillon de la liste (contenant une `Person` et un pointeur vers le suivant)
* `List` contenant uniquement un pointeur vers le début de la liste

## Partie 5 : Création d’une personne
Créer une fonction qui permet de créer une `Person` à partir d'un nom et d'un âge.

La fonction retourne un pointeur vers une `Person` nouvellement créée et NULL en cas d'erreur.

## Partie 6 : Insertion dans la liste par ordre alphabétique
Créer une fonction pour insérer une `Person` dans la liste chaînée.

Lors de l'insertion, il faut respecter l'ordre alphabétique des noms.

* Astuce : comparer les noms avec `strcmp`


## Partie 7 : Affichage de la liste
Créer une fonction pour afficher la liste chaînée.

## Partie 8 : Libération de la mémoire
Créer une fonction pour libérer la mémoire de la liste chaînée.

## Partie 9 : Chargement du fichier dans la liste
Dans la fonction `main` :
1. Créer une liste vide
2. Ouvrir le fichier en lecture binaire
3. Tant que lecture réussie :
   * Lire une `Person`
   * L’insérer dans la liste
4. Fermer le fichier
5. Afficher la liste
6. Libérer la mémoire de la liste
7. Quitter le programme