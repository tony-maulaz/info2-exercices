# Gestion d'une liste de points 3D

Créer un programme en C permettant de gérer une liste de points en trois dimensions (3D).

## Structures à définir
- Une structure `Point` représentant un point en 3D (avec les coordonnées `x`, `y`, `z`).
- Une structure représentant une **liste doublement chaînée** de points, contenant :
  - Un pointeur vers le **premier élément** de la liste.
  - Un pointeur vers le **dernier élément** de la liste.

## Fonctions à implémenter

### Création et comparaison
- `create_point` : crée un point à partir de ses coordonnées (`x`, `y`, `z`).
- `compare_points` : compare deux points. Retourne `true` s’ils sont identiques, `false` sinon.
  **Astuce : utilisez `memcmp` pour comparer directement les coordonnées.**
- `find_point` : recherche un point dans la liste. Retourne sa position en partant de `0` ou `-1` si le point n’existe pas.

### Insertion
- `insert_point_first` : insère un point au **début** de la liste.
- `insert_point_end` : insère un point à la **fin** de la liste.
- `insert_point_after` : insère un point **après** un point donné (passé par référence).
  Si le point n’existe pas, la fonction retourne `false`.
- `insert_point_before` : insère un point **avant** un point donné (passé par référence).
  Si le point n’existe pas, la fonction retourne `false`.

### Suppression
- `remove_first` : supprime le **premier** point de la liste.
- `remove_last` : supprime le **dernier** point de la liste.
- `remove_point` : supprime un point donné (passé par référence).  
  Si le point n’existe pas, la fonction retourne `false`.
- `remove_all` : supprime **tous** les points de la liste.

### Affichage
- `display_list` : affiche tous les points présents dans la liste.