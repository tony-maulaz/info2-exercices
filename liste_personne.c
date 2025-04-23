#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE_NAME 15

typedef struct{
    char name[SIZE_NAME];
    int age;
} Person;

typedef struct Node{
    Person p;
    struct Node* next;
}Node;

typedef struct{
    Node* head;
}List;

Node* create_node_person(char* name, int age){
    Node* n = malloc(sizeof(Node));
    if( n == NULL ) return NULL;
    strcpy(n->p.name, name);
    n->p.age = age;
    return n;
}

bool insert_person(List* list, char* name, int age){
    Node* new_node = create_node_person(name, age);
    if( new_node == NULL || list == NULL ) return false;

    // La liste est vide ou on doit inserer entre le premier noeud et la tête
    if(list->head == NULL || strcmp(list->head->p.name, new_node->p.name) > 0){
        list->head = new_node;
        return;
    }

    // On cherche la position où inserer la personne
    Node* current = list->head;
    while(current != NULL){
        if(current->next == NULL || // fin de la liste
            strcmp(current->next->p.name, new_node->p.name) > 0) // suivant plus grand
        {
            break;
        } 
        current = current->next; // on passe au noeud suivant
        // current->next++; // ATTENTION IMPOSSIBLE
    }

    // on insert le nouveau noeud
    new_node->next = current->next;
    current->next = new_node;
    return true;
}

bool add_person(char* filename, char*name, int age){
    FILE* f = fopen(filename, "a");
    if(f == NULL)
        return false;

    Person p = {.age = age};
    strcpy(p.name, name);
    fwrite(&p, sizeof(Person), 1, f);
    fclose(f);
}

void print_list(List* l){
    Node* current = l->head;
    int cpt = 0;
    while(current != NULL){
        printf("Personne %d : %10s  age : %d\n", cpt++, current->p.name, current->p.age);
        current = current->next;
    }
}

void count_list(List* l){
    Node* current = l->head;
    int cpt = 0;
    while(current != NULL){
        current = current->next;
        cpt++;
    }
    return cpt;
}

void delete_list(List* l){
    Node* current = l->head;
    while(current != NULL){
        Node* tmp = current;
        current = current->next;
        free(tmp);
    }
}

bool remove_first(List* l, Person* p){
    if(l->head == NULL)
        return false;

    memcpy(p, l->head, sizeof(Person)); // copie toute la mémoire pour une personne
    Node* to_delete = l->head;
    l->head = l->head->next;
    free(to_delete);
    return true;
}

int main(){

    add_person("personnes.dat", "Bob", 30);
    add_person("personnes.dat", "David", 28);
    add_person("personnes.dat", "Eva", 26);
    add_person("personnes.dat", "Claire", 22);
    add_person("personnes.dat", "Alice", 25);
}