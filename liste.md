# Liste

## Ex 1

Il y a une collection de données qui peut être représentée ainsi :

```C
typedef struct {
    int num;
    double value;
} Data;
```

Il faut représenter cette collection au moyen d'une liste chaînée afin de
pouvoir insérer facilement un élément au milieu de la liste.

Il faut insérer les éléments pour que la liste soit triée de façon à ce que la valeur de `num` reste croissante.
Ce qui veut dire que le premier élément sera la structure `Data` avec la valeur `num` la plus petite.

Développer les fonctions afin de pouvoir :
- Insérer un nouvel élément (pour insérer un élément, il faut donner la valeur `num` et `value`)
- Afficher la liste 
- Libérer la mémoire

Le programme principal devrait ressembler à quelque chose comme ceci 

```C
int main(void){
    List l = {0};
    list_insert(&l, 4, 125.34);
    list_insert(&l, 2, -9872.4584);
    list_insert(&l, 8, -45.123);
    list_insert(&l, 78, -1.6);
    list_insert(&l, 34, 0.6);
    list_insert(&l, 1, 12.6);
    list_afficher(&l);
    list_liberer(&l);
}
```

```text
$./app

Les valeurs sont :
1   :     12.6
2   :  -9872.4584
4   :    125.34
8   :    -45.123
34  :      0.6
78  :     -1.6
```