
// gcc -Wall -o app revision_solutions.c -lm && ./app

// # Ex 1 :
// Ecrire une fonction qui retourne la taille d'un fichier en octets.
// Si il y a une erreur, la fonction retourne -1.
#include <stdio.h>
#include <string.h>

long size_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return -1;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);
    return size;
}

// # Ex 2 :
// Ecrire une fonction qui retourne le nombre de lignes d'un fichier texte.
// En cas d'erreur, la fonction retourne -1.

size_t count_lines(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return -1;
    }
    size_t count = 0;
    char buffer[1024];
    while (fgets(buffer, 1024, file) != NULL)
    {
        count++;
    }
    fclose(file);
    return count;
}

// # Ex 3 :
// Créer une fonction qui remplis un fichier csv avec une génération de sinus, cosinus.

#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void generate_csv(const char *filename, double total_time, double time_step, double frequency)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        return;
    }
    fprintf(file, "temps,sinus,cosinus\n");
    for (double t = 0; t <= total_time; t += time_step)
    {
        double sinus = sin(2 * M_PI * frequency * t);
        double cosinus = cos(2 * M_PI * frequency * t);
        fprintf(file, "%f,%f,%f\n", t, sinus, cosinus);
    }
    fclose(file);
}


// # Ex 4 :
// Une structure est définie comme suit :
typedef struct {
    int x;
    int y;
    int z;
} Point;

// ## Ex 4.1
// Ecrire une fonction qui permet de sauvegarder un tableau de points dans un fichier binaire.

void save_points(const char* filename, Point* points, size_t count)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        return;
    }
    fwrite(points, sizeof(Point), count, file);
    fclose(file);
}

// ## Ex 4.2
// Ecrire une fonction qui permet d'ajouter un point à la fin d'un fichier binaire.
void add_point(const char* filename, Point* point)
{
    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        return;
    }
    fwrite(point, sizeof(Point), 1, file);
    fclose(file);
}

// ## Ex 4.3
// Ecrire une fonction qui permet de lire un fichier binaire contenant un tableau de points.
void read_points(const char* filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return;
    }
    Point points[1024];
    size_t count = fread(points, sizeof(Point), 1024, file);

    if (count == 0)
    {
        return;
    }

    for (size_t i = 0; i < count; i++)
    {
        printf("Point %zu : %d %d %d\n", i, points[i].x, points[i].y, points[i].z);
    }
    fclose(file);
}

// # Ex 5 :
// Ecrire une fonction qui écrit sur la console toute les lignes d'un fichier texte qui contiennent plus de 30 caractères.
void print_long_lines(const char* filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return;
    }
    char buffer[1024];
    while (fgets(buffer, 1024, file) != NULL)
    {
        if (strlen(buffer) > 100)
        {
            printf("%s", buffer);
        }
    }
    fclose(file);
}


// # Ex 6 :
// Ecrire une fonction qui prend un tableau de double en paramètre et qui écrit ces valeurs dans un fichier texte avec 1 digit après la virgule.
void save_double(const char* filename, double* tab, size_t count)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        return;
    }
    for (size_t i = 0; i < count; i++)
    {
        fprintf(file, "%.1f\n", tab[i]);
    }
    fclose(file);
}


// # Ex 7 :
// Ecrire une fonction qui écrit sur la console le mot le plus long d'un fichier texte.

void print_longest_word(const char* filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return;
    }
    char buffer[1024];
    char longest[1024] = "";
    while (fgets(buffer, 1024, file) != NULL)
    {
        if (strlen(buffer) > strlen(longest))
        {
            strcpy(longest, buffer);
        }
    }
    printf("%s", longest);
    fclose(file);
}


int main(){
    // ex 1
    printf("Ex 1 : %ld\n", size_file("fichier_revision.md"));

    // ex 2
    printf("Ex 2 : %ld\n", count_lines("fichier_revision.md"));

    // ex 3
    generate_csv("sinus.csv", 10, 0.1, 1);

    // ex 4
    Point points[] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    save_points("points.bin", points, sizeof(points) / sizeof(Point));
    Point point = {10, 11, 12};
    add_point("points.bin", &point);
    read_points("points.bin");

    // ex 5
    printf("Ex 5 :\n");
    print_long_lines("fichier_revision.md");

    // ex 6
    printf("Ex 6 :\n");
    double tab[] = {1.23456, 3.4456};
    save_double("double.txt", tab, sizeof(tab) / sizeof(double));

    // ex 7
    printf("Ex 7 :\n");
    print_longest_word("words.md");

    return 0;
}