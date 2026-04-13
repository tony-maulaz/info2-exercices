# Introduction aux listes chaînées en C

> **Format "recette de cuisine"** : suivez les étapes dans l'ordre. Chaque étape s'appuie sur la précédente. Ne passez pas à la suivante tant que votre code ne compile pas et ne produit pas le résultat attendu.

---

## Ingrédients (structures de base)

Avant de commencer, définissez les deux structures suivantes :

```c
typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;
```

> **Pourquoi deux structures ?** `Node` représente un maillon de la chaîne. `List` est le "gestionnaire" de la liste — il suffit pour l'instant de connaître l'adresse du premier maillon.

---

## Partie 1 : Liste avec uniquement `head`

### Étape 1 — Initialiser la liste

Créez une fonction qui initialise une liste vide.

```c
void list_init(List* l);
```

Dans `main`, déclarez une liste et initialisez-la :

```c
List l;
list_init(&l);
```

> **Astuce :** Une liste vide, c'est une liste dont `head` vaut `NULL`.

---

### Étape 2 — Créer un nœud

Créez une fonction qui alloue un nouveau nœud en mémoire et l'initialise avec une valeur.

```c
Node* node_create(int value);
```

- La fonction retourne un pointeur vers le nœud créé.
- Elle retourne `NULL` en cas d'échec d'allocation.
- Le champ `next` du nouveau nœud doit être initialisé à `NULL`.

> **Rappel :** Utilisez `malloc`. N'oubliez pas de vérifier le retour de `malloc` avant d'utiliser le pointeur.

---

### Étape 3 — Insérer un nœud en tête

Créez une fonction qui insère un nœud **en tête** de liste.

```c
bool list_push_front(List* l, int value);
```

- La fonction retourne `true` si l'insertion a réussi, `false` sinon.
- Après l'appel, `l->head` doit pointer vers le nouveau nœud.

Dans `main`, insérez un premier élément :

```c
list_push_front(&l, 10);
```

> **Visualisation après cette étape :**
> ```
> head → [10|NULL]
> ```

---

### Étape 4 — Insérer un deuxième nœud en tête

Insérez un deuxième élément en tête :

```c
list_push_front(&l, 20);
```

> **Visualisation après cette étape :**
> ```
> head → [20|•] → [10|NULL]
> ```
>
> **Question :** Dans quel ordre faut-il effectuer les assignations pour ne pas perdre l'accès au reste de la liste ?

---

### Étape 5 — Afficher la liste

Créez une fonction qui affiche tous les éléments de la liste.

```c
void list_print(const List* l);
```

Résultat attendu après les étapes 3 et 4 :

```text
20 -> 10 -> NULL
```

> **Astuce :** Utilisez un pointeur temporaire `current` pour parcourir la liste sans modifier `head`.

---

### Étape 6 — Compter les éléments

Créez une fonction qui retourne le nombre d'éléments dans la liste.

```c
int list_count(const List* l);
```

Testez dans `main` :

```c
printf("Nombre d'elements : %d\n", list_count(&l));
```

Résultat attendu : `Nombre d'elements : 2`

---

### Étape 7 — Rechercher un élément

Créez une fonction qui indique si une valeur est présente dans la liste.

```c
bool list_contains(const List* l, int value);
```

- Retourne `true` si la valeur est trouvée, `false` sinon.

Testez :

```c
printf("Contient 10 : %s\n", list_contains(&l, 10) ? "oui" : "non");
printf("Contient 99 : %s\n", list_contains(&l, 99) ? "oui" : "non");
```

Résultat attendu :
```text
Contient 10 : oui
Contient 99 : non
```

---

### Étape 8 — Supprimer le nœud en tête

Créez une fonction qui supprime le premier élément de la liste.

```c
bool list_pop_front(List* l, int* out_value);
```

- Si la liste est vide, retourne `false`.
- Sinon, copie la valeur du nœud supprimé dans `*out_value`, libère le nœud et retourne `true`.

Testez :

```c
int val;
if (list_pop_front(&l, &val)) {
    printf("Supprime : %d\n", val);
}
list_print(&l);
```

Résultat attendu :
```text
Supprime : 20
10 -> NULL
```

> **Danger :** Sauvegardez le pointeur vers le prochain nœud **avant** de libérer le nœud courant.

---

### Étape 9 — Libérer toute la liste

Créez une fonction qui libère tous les nœuds de la liste.

```c
void list_free(List* l);
```

- Après l'appel, `l->head` doit valoir `NULL`.
- Appelez cette fonction **à la fin de `main`** — c'est une bonne habitude systématique.

> **Pourquoi ?** En C, la mémoire allouée avec `malloc` n'est pas libérée automatiquement. Chaque `malloc` doit avoir son `free` correspondant.

---

## Partie 2 : Ajout du pointeur `tail`

Jusqu'ici, insérer en **fin** de liste nécessite de parcourir tous les éléments : c'est O(n). En ajoutant un pointeur `tail`, on obtient une insertion en fin en O(1).

### Étape 10 — Modifier la structure `List`

Ajoutez un pointeur `tail` à la structure `List` :

```c
typedef struct {
    Node* head;
    Node* tail;
} List;
```

> **Question :** Quelles fonctions écrites précédemment doivent être mises à jour pour maintenir `tail` correctement ? Listez-les avant de commencer.

---

### Étape 11 — Mettre à jour `list_push_front`

Modifiez `list_push_front` pour maintenir `tail` à jour.

> **Cas particulier :** Que doit valoir `tail` quand on insère dans une liste **vide** ?

---

### Étape 12 — Insérer un nœud en fin

Créez une fonction qui insère un élément **en fin** de liste.

```c
bool list_push_back(List* l, int value);
```

Testez :

```c
list_push_front(&l, 1);
list_push_front(&l, 2);
list_push_back(&l, 3);
list_push_back(&l, 4);
list_print(&l);
```

Résultat attendu :
```text
2 -> 1 -> 3 -> 4 -> NULL
```

> **Visualisation :**
> ```
> head → [2|•] → [1|•] → [3|•] → [4|NULL] ← tail
> ```

---

### Étape 13 — Supprimer le nœud en fin

Créez une fonction qui supprime le dernier élément de la liste.

```c
bool list_pop_back(List* l, int* out_value);
```

- Si la liste est vide, retourne `false`.
- Sinon, supprime le dernier nœud, met `tail` à jour et retourne `true`.

> **Cas particuliers à gérer :**
> - Liste vide
> - Liste avec un seul élément (que doit valoir `head` et `tail` après suppression ?)
> - Liste avec plusieurs éléments (comment trouver l'avant-dernier nœud ?)

Testez :

```c
int val;
list_pop_back(&l, &val);
printf("Supprime en fin : %d\n", val);
list_print(&l);
printf("Tail pointe sur : %d\n", l.tail->value);
```

---

## Récapitulatif des fonctions

| Fonction | Description |
|---|---|
| `list_init` | Initialise une liste vide |
| `node_create` | Alloue et initialise un nœud |
| `list_push_front` | Insère en tête |
| `list_push_back` | Insère en fin *(après étape 12)* |
| `list_pop_front` | Supprime en tête |
| `list_pop_back` | Supprime en fin *(après étape 13)* |
| `list_print` | Affiche la liste |
| `list_count` | Retourne le nombre d'éléments |
| `list_contains` | Recherche une valeur |
| `list_free` | Libère toute la liste |
