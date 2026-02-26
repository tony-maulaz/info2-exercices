# Exercice — Structure + fichier texte (CSV)

## Contexte
On dispose d’un fichier texte au format CSV qui contient une liste de mesures. Chaque ligne est une mesure composée de trois champs :

```
id,pos,force
```

## Fichier d’exemple
Un fichier d’exemple `meas.csv` est fourni dans le même dossier. Il contient l’en‑tête et des mesures avec les identifiants **1 à 6**.

## Travail demandé
Écrire un programme en C qui permet de récupérer une mesure à partir de son identifiant.

### Spécifications
- Définir une structure `Mesure` contenant les champs :
  - `int id`
  - `double pos`
  - `double force`
- Écrire une fonction qui recherche une ligne de mesure dans le fichier CSV à partir d’un `id` donné.
- La fonction reçoit :
  - le nom du fichier,
  - l’`id` recherché,
  - un pointeur vers une `Mesure` (structure retournée **par référence**).
- La fonction retourne `true` si la mesure a été trouvée et remplie, sinon `false`.

### Signature possible
```c
bool lire_mesure_par_id(const char* nom_fichier, int id, Mesure* m);
```

### Contraintes
- Le fichier est un CSV simple (séparateur virgule).
- La première ligne est l’en‑tête et doit être ignorée.
- La recherche se fait en parcourant les lignes jusqu’à trouver le bon `id`.

### Exemple d’utilisation
- Appeler `lire_mesure_par_id("meas.csv", 4, &m)`. La fonction doit retourner `true` et remplir `m` avec les valeurs de la ligne `id=4`.
- Si l’`id` n’existe pas, la fonction retourne `false`.
