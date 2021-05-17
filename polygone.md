# Polygone

## Description

Il faut développer une application qui permet de créer des polygones.

Un polygone est composé de points et d'un nom.

Le nom d'un polygone ne peut pas dépasser `20` caractères.

Un point est composé de coordonnées cartésiennes avec une valeur `X` et `Y`.

L'application doit permette de sauver un polygone dans un fichier.

## TDA

Pour faciliter la réutilisation des modules, il faut developer un type abstrait pour les points
et un pour les polygones.

## Programme principale

Afin de faciliter le développement de l'application il n'y aura pas d'interaction avec
l'utilisateur mais simplement une simulation comme montré ci-dessous.

```C
int main(){
    printf("%s", "Création du carré\n");
    Poly carre = {0};
    poly_init(&carre, 4);
    poly_set_name(&carre, "Carre");
    poly_add_point_cartesian(&carre, 0, 0);
    poly_add_point_cartesian(&carre, 10, 0);
    poly_add_point_cartesian(&carre, 10, 10);
    poly_add_point_cartesian(&carre, 0, 10);
    poly_print(&carre);
    poly_save(&carre, "carre.bin");

    printf("%s", "\nLecture du carré\n");
    Poly c1 = {0};
    poly_read(&c1, "carre.bin");
    poly_print(&c1);
}
```
