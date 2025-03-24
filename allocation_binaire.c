#include <stdio.h>
#include <stdlib.h>

int main(){
    const char* filename = "alloc_bin";

    double arr[] = {1.2, -4.4e-4, -1.23, 24, 2.3e4};
    const size_t nb = sizeof(arr) / sizeof(arr[0]);
    printf("Il y a %ld éléments dans le tableau\n", nb);

    FILE* f = fopen(filename, "w");
    if( f == NULL )
        exit(1);
    fwrite(arr, sizeof(double), nb, f);
    fclose(f);

    // allocation du tableau
    f = fopen(filename, "r");
    fseek(f, 0, SEEK_END);
    size_t pos_end = ftell(f); // place le curseur à la fin du fichier
    size_t nb_in_file = pos_end / sizeof(double); // nombre de double dans fichier
    double* dynamic_array = malloc(sizeof(double) * nb_in_file);
    // au début du fichier
    fseek(f, 0, SEEK_SET);
    const int nb_read = fread(dynamic_array, sizeof(double), nb_in_file, f);
    fclose(f);
    
    // Affichage des données
    if( nb_read == nb_in_file ){
        for(int i=0; i<nb_in_file; i++){
            printf("Val pos %d : %.2lf\n", i, dynamic_array[i]);
        }
    }
    else
        printf("Erreur de lecture");
    
    free(dynamic_array);
}