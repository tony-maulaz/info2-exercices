# Exercice : Gestion d'un tableau dynamique de `double` en C

## Objectif :
Écrire un programme en C qui gère un tableau dynamique de `double` en utilisant une structure et des fonctions dédiées.

## Contraintes :
- Le tableau doit être géré via une structure.
- Il doit être possible d'ajouter des éléments dynamiquement.
- Si le tableau est plein, sa capacité doit être augmentée grâce à un `#define` pour le facteur d'agrandissement.
- Lorsque la capacité est augmentée, un message doit être affiché sur la sortie standard.
- Les fonctions doivent être sûre.
- En cas de problème, le programme retourne un code d'erreur `1`.

## Tests :
- Créer un programme qui permet de tester les différentes fonctions.
- Il faut penser à tester les cas limites :
  - tableau vide,
  - tableau plein,
  - récupération d'un élément inexistant,
  - suppression d'un élément inexistant,
  - ajout d'un élément dans un tableau inexistant,
  - suppression d'un élément dans un tableau inexistant,
  - ...


## Spécifications :

1. **Définir une structure `DynamicArray`** qui contient :
   - ???

2. **Créer des fonctions** :
   - `bool createArray(int capacity, DynamicArray* array)`: Alloue et initialise un tableau dynamique. Si l'allocation échoue, retourne `NULL`.
   - `void destroyArray(DynamicArray* arr)`: Libère la mémoire allouée.
   - `int availableSpace(DynamicArray* arr)`: Retourne le nombre de places disponibles, `-1` si erreur.
   - `void addElement(DynamicArray* arr, double value)`: Ajoute un élément, agrandit si nécessaire.
   - `void displayArray(DynamicArray* arr)`: Affiche le contenu du tableau.
   - `bool popElement(DynamicArray* arr, double* val)`: Supprime le dernier élément et place la valeur dans `val`, en cas d'erreur, retourne `false`.
   - `bool isInitialized(DynamicArray* arr)`: Vérifie si le tableau est initialisé.
   - `bool getElement(DynamicArray* arr, int index, double* val)`: Copy la valeur de l'élément à l'index donné dans val et retourne `true`. La fonction retourne `false` en cas d'erreur.

3. **Utiliser un `#define`** pour définir le facteur d'agrandissement (`GROWTH_FACTOR`).
 
4. **Écrire un programme** qui teste les différentes fonctions.

Ceci est un exemple de programme de test pour vous aider à démarrer :

```c
int main() {
    // Création du tableau dynamique avec une capacité initiale de 3
    DynamicArray* arr = createArray(3);
    
    if (!isInitialized(arr)) {
        printf("Échec de l'initialisation du tableau.\n");
        return 1;
    }

    // Affichage de l'espace disponible
    printf("Espace disponible 1 : %d\n", availableSpace(arr));

    // Ajout d'éléments
    addElement(arr, 10.5);
    addElement(arr, 20.3);
    addElement(arr, 30.8);
    addElement(arr, 40.2); // Devrait déclencher un agrandissement

    // Affichage du tableau
    printf("Contenu du tableau :\n");
    displayArray(arr);

    // Affichage de l'espace disponible
    printf("Espace disponible 2 : %d\n", availableSpace(arr));

    // Récupération d'un élément par index
    int index = 2;
    double val;
    if (!getElement(arr, index, &val)) {
        printf("Échec de la récupération de l'élément.\n");
    }
    else {
        printf("Élément à l'index %d : %.2f\n", index, val);
    }

    // Suppression du dernier élément
    double pop;
    if (!popElement(arr, &pop)) {
        printf("Échec de la suppression de l'élément.\n");
    }
    else {
        printf("Élément supprimé : %.2f\n", pop);
    }

    // Affichage après suppression
    printf("Tableau après suppression :\n");
    displayArray(arr);

    // Libération de la mémoire
    destroyArray(arr);

    // Récupération d'un élément par index qui devrait échouer
    int index = 1;
    if (!getElement(arr, index, &val)) {
        printf("Échec de la récupération de l'élément.\n");
    }
    else {
        printf("Élément à l'index %d : %.2f\n", index, val);
    }

    return 0;
}
```
