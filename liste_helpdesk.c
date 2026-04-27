#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DESC_LEN 64

typedef struct {
    int  id;
    char description[DESC_LEN];
    int  priority;
} Ticket;

typedef struct Node {
    Ticket       data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} List;

void list_init(List* l) {
    l->head = NULL;
    l->tail = NULL;
}

Node* node_create(int id, const char* description, int priority) {
    Node* n = malloc(sizeof(Node));
    if (n == NULL) return NULL;
    n->data.id = id;
    strncpy(n->data.description, description, DESC_LEN - 1);
    n->data.description[DESC_LEN - 1] = '\0';
    n->data.priority = priority;
    n->next = NULL;
    return n;
}

void list_print(const List* l) {
    Node* current = l->head;
    while (current != NULL) {
        printf("[id=%d | prio=%d | %s] -> ", current->data.id, current->data.priority, current->data.description);
        current = current->next;
    }
    printf("NULL\n");
}

bool list_insert_sorted(List* l, int id, const char* description, int priority) {
    Node* n = node_create(id, description, priority);
    if (n == NULL) return false;

    /* Liste vide */
    if (l->head == NULL) {
        l->head = n;
        l->tail = n;
        return true;
    }

    /* Insertion en tête */
    if (priority <= l->head->data.priority) {
        n->next = l->head;
        l->head = n;
        return true;
    }

    /* Insertion en milieu ou en queue */
    Node* current = l->head;
    while (current->next != NULL && current->next->data.priority <= priority) {
        current = current->next;
    }

    n->next = current->next;
    current->next = n;

    /* Mise à jour de tail si insertion en queue */
    if (n->next == NULL) {
        l->tail = n;
    }

    return true;
}

bool list_pop_front(List* l, Ticket* out) {
    if (l->head == NULL) return false;

    Node* to_free = l->head;
    *out = to_free->data;
    l->head = l->head->next;

    /* Liste devenue vide */
    if (l->head == NULL) {
        l->tail = NULL;
    }

    free(to_free);
    return true;
}

bool list_pop_back(List* l, Ticket* out) {
    if (l->head == NULL) return false;

    *out = l->tail->data;

    /* Un seul élément */
    if (l->head == l->tail) {
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
        return true;
    }

    /* Trouver l'avant-dernier nœud */
    Node* current = l->head;
    while (current->next != l->tail) {
        current = current->next;
    }

    free(l->tail);
    current->next = NULL;
    l->tail = current;
    return true;
}

void list_free(List* l) {
    Node* current = l->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    l->head = NULL;
    l->tail = NULL;
}

int main(void) {
    List l;
    list_init(&l);

    list_insert_sorted(&l, 1, "VPN lent",                   2);
    list_insert_sorted(&l, 2, "Imprimante hors service",    4);
    list_insert_sorted(&l, 3, "Serveur de prod hors ligne", 1);
    list_insert_sorted(&l, 4, "Mise a jour Windows",        5);
    list_insert_sorted(&l, 5, "Email non recu",             3);

    printf("Liste initiale :\n");
    list_print(&l);
    printf("head : id=%d | tail : id=%d\n\n", l.head->data.id, l.tail->data.id);

    Ticket t;
    if (list_pop_front(&l, &t)) {
        printf("Ticket traite : [id=%d | prio=%d | %s]\n", t.id, t.priority, t.description);
    }
    list_print(&l);
    printf("head : id=%d | tail : id=%d\n\n", l.head->data.id, l.tail->data.id);

    if (list_pop_back(&l, &t)) {
        printf("Ticket expire : [id=%d | prio=%d | %s]\n", t.id, t.priority, t.description);
    }
    list_print(&l);
    printf("head : id=%d | tail : id=%d\n\n", l.head->data.id, l.tail->data.id);

    list_free(&l);
    printf("Apres list_free :\n");
    list_print(&l);

    return 0;
}
