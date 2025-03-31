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
    if (arr == NULL || capacity <= 0) return false;

    arr->data = malloc(capacity * sizeof(double));
    if (arr->data == NULL) return false;

    arr->capacity = capacity;
    arr->number_element = 0;
    return true;
}

bool isInitialized(DynamicArray* arr){
    return arr != NULL && arr->data != NULL;
}

bool resizeIfNeeded(DynamicArray* arr){
    if (!isInitialized(arr)) return false;

    if (arr->number_element >= arr->capacity){
        int new_capacity = arr->capacity * GROWTH_FACTOR;
        double* tmp = realloc(arr->data, new_capacity * sizeof(double));
        if (tmp == NULL) return false;

        arr->data = tmp;
        arr->capacity = new_capacity;
        printf("Tableau agrandi à %d éléments.\n", new_capacity);
    }
    return true;
}

void addElement(DynamicArray* arr, double value){
    if (!resizeIfNeeded(arr)) exit(1);
    arr->data[arr->number_element++] = value;
}

int availableSpace(DynamicArray* arr){
    if (!isInitialized(arr)) return -1;
    return arr->capacity - arr->number_element;
}

void displayArray(DynamicArray* arr){
    if (!isInitialized(arr)) {
        printf("Tableau non initialisé\n");
        return;
    }
    printf("Tableau : [ ");
    for (int i = 0; i < arr->number_element; i++){
        printf("%.2f ", arr->data[i]);
    }
    printf("]\n");
}

void destroyArray(DynamicArray* arr){
    if (!isInitialized(arr)) exit(1);
    free(arr->data);
    arr->data = NULL;
    arr->capacity = 0;
    arr->number_element = 0;
}

bool popElement(DynamicArray* arr, double* val){
    if (!isInitialized(arr) || arr->number_element == 0 || val == NULL)
        return false;

    *val = arr->data[--arr->number_element];
    return true;
}

bool getElement(DynamicArray* arr, int index, double* val){
    if (!isInitialized(arr) || index < 0 || index >= arr->number_element || val == NULL)
        return false;
    *val = arr->data[index];
    return true;
}

bool insertElement(DynamicArray* arr, int index, double value){
    if (!isInitialized(arr) || index < 0 || index > arr->number_element)
        return false;

    if (!resizeIfNeeded(arr)) return false;

    for (int i = arr->number_element; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = value;
    arr->number_element++;
    return true;
}

bool removeAt(DynamicArray* arr, int index, double* value){
    if (!isInitialized(arr) || index < 0 || index >= arr->number_element)
        return false;

    if (value != NULL)
        *value = arr->data[index];

    for (int i = index; i < arr->number_element - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->number_element--;
    return true;
}