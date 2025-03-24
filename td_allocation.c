#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GROWTH_FACTOR 2

typedef struct {
    double* data;
    int capacity;
    int number_element;
} DynamicArray;

bool createArray(int capacity, DynamicArray* arr){
    if( capacity <= 0 ) return false;

    arr->data = malloc(capacity * sizeof(double));
    if (arr->data == NULL) {
        return false;
    }
    arr->capacity = capacity;
    arr->number_element = 0;
    return true;
}

bool is_initialized(DynamicArray* arr){
    return !(arr == NULL || arr->data == NULL);
}

void add_element(DynamicArray* arr, double value){
    if( !is_initialized(arr) ) exit(1);

    if(arr->number_element >= arr->capacity){
        const int new_capacity = arr->capacity * GROWTH_FACTOR;
        double* tmp = realloc(arr->data, sizeof(double) * new_capacity);
        if( tmp == NULL ){
            // backup ancien tableau
            exit(1);
        }
        arr->data = tmp;
        arr->capacity = new_capacity;
    }
    // const int index = arr->number_element;
    // arr->data[index] = value;
    // arr->number_element++;

    arr->data[(arr->number_element)++] = value;
}

int get_available(DynamicArray* arr){
    return arr->capacity - arr->number_element;
}

void destroy(DynamicArray* arr){
    if( !is_initialized(arr) ) exit(1);

    free(arr->data);
    arr->data = NULL;
    arr->capacity = 0;
    arr->number_element = 0;
}

bool pop_element(DynamicArray* arr, double* val){
    if( !is_initialized(arr) || arr->number_element <= 1  )
        return false;

    *val = arr->data[--arr->number_element]; // version sur une ligne
    // *val = arr->data[arr->number_element - 1];
    // arr->number_element--;
    return true;
}

bool get_element(DynamicArray* arr, int index, double* val){
    if( !is_initialized(arr) || arr->number_element > index )
        return false;
    *val = arr->data[index];
    return true;
}

bool resizeIfNeeded(DynamicArray* arr) {
    if (!is_initialized(arr)) return false;

    if (arr->number_element >= arr->capacity) {
        int new_capacity = arr->capacity * GROWTH_FACTOR;
        double* tmp = realloc(arr->data, sizeof(double) * new_capacity);
        if (tmp == NULL) return false;

        arr->data = tmp;
        arr->capacity = new_capacity;
    }
    return true;
}

bool insertAt(DynamicArray* arr, int pos, double val) {
    if (!is_initialized(arr) || pos < 0 || pos > arr->number_element)
        return false;

    // réallocation

    // Décalage des éléments à droite
    for (int i = arr->number_element; i > pos; i--) {
        arr->data[i] = arr->data[i - 1];
    }

    // Insertion
    arr->data[pos] = val;
    arr->number_element++;

    return true;
}

int main(){
    printf("Gestion d'un tableau dynamique de double\n\n");

    DynamicArray arr = {0};
    bool res = createArray(3, &arr);


    is_initialized()
}