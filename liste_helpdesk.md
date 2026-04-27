# File de priorité — Helpdesk

> **Format "recette de cuisine"** : suivez les étapes dans l'ordre. Chaque étape s'appuie sur la précédente. Ne passez pas à la suivante tant que votre code ne compile pas et ne produit pas le résultat attendu.

---

## Pourquoi une liste chaînée ici ?

Dans un vrai système de ticketing (Jira, Zendesk…), des tickets arrivent et partent en permanence. Si on stockait les tickets dans un tableau trié, insérer un nouveau ticket au milieu obligerait à **décaler tous les éléments suivants** — coûteux quand la file est longue. Avec une liste chaînée, on se contente de modifier quelques pointeurs, quelle que soit la taille de la liste.

Votre objectif : maintenir une file triée par priorité, où `head` pointe toujours sur le ticket le plus urgent et `tail` sur le moins urgent.

```
head → [T3|•] → [T1|•] → [T7|NULL]
                                ↑
                               tail
 priorité  1         2         5
```

---

## Structures de base

Définissez ces trois structures **avant** de commencer :

```c
#define DESC_LEN 64

typedef struct {
    int  id;
    char description[DESC_LEN];
    int  priority;   /* 1 = très urgent, 5 = faible priorité */
} Ticket;

typedef struct Node {
    Ticket       data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;   /* ticket le plus urgent  (priority la plus basse)  */
    Node* tail;   /* ticket le moins urgent (priority la plus haute)  */
} List;
```

---

## Étape 1 — Initialiser la liste

Créez une fonction qui initialise une liste vide.

```c
void list_init(List* l);
```

Dans `main`, déclarez une liste et initialisez-la :

```c
List l;
list_init(&l);
```

> **Astuce :** Une liste vide a `head` et `tail` à `NULL`.

---

## Étape 2 — Créer un nœud

Créez une fonction qui alloue un nouveau nœud et l'initialise avec les données d'un ticket.

```c
Node* node_create(int id, const char* description, int priority);
```

- Retourne un pointeur vers le nœud créé, ou `NULL` en cas d'échec d'allocation.
- Le champ `next` doit être initialisé à `NULL`.
- Utilisez `strncpy` pour copier la description.

> **Rappel :** Vérifiez toujours le retour de `malloc` avant d'utiliser le pointeur.

---

## Étape 3 — Afficher la liste

Créez une fonction qui affiche tous les tickets de la liste.

```c
void list_print(const List* l);
```

Format attendu pour chaque ticket :

```text
[id=3 | prio=1 | Serveur de production hors ligne] -> [id=1 | prio=2 | VPN lent] -> NULL
```

> **Astuce :** Utilisez un pointeur temporaire `current` pour parcourir la liste sans modifier `head`.

Testez avec quelques nœuds créés manuellement (sans insertion triée pour l'instant) pour valider l'affichage avant de continuer.

---

## Étape 4 — Insérer un ticket en ordre croissant de priorité

Créez la fonction d'insertion triée :

```c
bool list_insert_sorted(List* l, int id, const char* description, int priority);
```

- Retourne `true` si l'insertion a réussi, `false` en cas d'échec d'allocation.
- La liste doit rester triée par `priority` croissante après chaque insertion.
- `head` et `tail` doivent toujours être corrects.


Testez avec ces insertions dans cet ordre :

```c
list_insert_sorted(&l, 1, "VPN lent",                   2);
list_insert_sorted(&l, 2, "Imprimante hors service",    4);
list_insert_sorted(&l, 3, "Serveur de prod hors ligne", 1);
list_insert_sorted(&l, 4, "Mise a jour Windows",        5);
list_insert_sorted(&l, 5, "Email non recu",             3);
```

Résultat attendu :

```text
[id=3 | prio=1 | Serveur de prod hors ligne] ->
[id=1 | prio=2 | VPN lent] ->
[id=5 | prio=3 | Email non recu] ->
[id=2 | prio=4 | Imprimante hors service] ->
[id=4 | prio=5 | Mise a jour Windows] ->
NULL
```

Vérifiez aussi que `head` pointe sur le ticket de priorité 1 et `tail` sur le ticket de priorité 5.

---

## Étape 5 — Traiter le ticket le plus urgent (`pop_front`)

Un agent prend en charge le ticket en tête de file. Créez :

```c
bool list_pop_front(List* l, Ticket* out);
```

- Si la liste est vide, retourne `false`.
- Copie les données du ticket supprimé dans `*out`, libère le nœud et retourne `true`.
- Met `head` à jour. **Cas particulier :** que devient `tail` si la liste ne contenait qu'un seul ticket ?

Testez :

```c
Ticket t;
if (list_pop_front(&l, &t)) {
    printf("Ticket traite : [id=%d | prio=%d | %s]\n", t.id, t.priority, t.description);
}
list_print(&l);
```

Résultat attendu :

```text
Ticket traite : [id=3 | prio=1 | Serveur de prod hors ligne]
[id=1 | prio=2 | VPN lent] -> ... -> NULL
```

---

## Étape 6 — Supprimer le ticket le moins urgent (`pop_back`)

Après un délai sans réponse du client, le système ferme automatiquement le ticket le moins urgent. Créez :

```c
bool list_pop_back(List* l, Ticket* out);
```

- Si la liste est vide, retourne `false`.
- Copie les données du dernier ticket dans `*out`, libère le nœud et retourne `true`.
- Met `tail` à jour.

Testez :

```c
Ticket t;
if (list_pop_back(&l, &t)) {
    printf("Ticket expire : [id=%d | prio=%d | %s]\n", t.id, t.priority, t.description);
}
list_print(&l);
printf("Nouveau tail : id=%d\n", l.tail->data.id);
```

---

## Étape 7 — Libérer toute la liste

Créez une fonction qui libère tous les nœuds de la liste.

```c
void list_free(List* l);
```

- Après l'appel, `head` et `tail` doivent valoir `NULL`.
- Appelez cette fonction à la fin de `main`.

> **Pourquoi ?** Chaque `malloc` doit avoir son `free` correspondant. Un outil comme Valgrind signalera toute fuite mémoire.

---

## Récapitulatif des fonctions

| Fonction | Description |
|---|---|
| `list_init` | Initialise une liste vide |
| `node_create` | Alloue et initialise un nœud |
| `list_insert_sorted` | Insère un ticket en maintenant l'ordre croissant de priorité |
| `list_pop_front` | Retire et retourne le ticket le plus urgent (tête) |
| `list_pop_back` | Retire et retourne le ticket le moins urgent (queue) — traversal requis |
| `list_print` | Affiche tous les tickets |
| `list_free` | Libère toute la liste |
