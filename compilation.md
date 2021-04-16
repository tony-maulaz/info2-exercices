# Compilation séparée

## Partie 1
cloner ce dépot sur votre ordinateur
[https://github.com/tony-maulaz/template-dev-container.git](https://github.com/tony-maulaz/template-dev-container.git)

Créer un fichier `lib.c` avec comme contenu
```C
#include <stdio.h>

void func(){
    printf("La fonction dans mon fichier\n");
}
```

Créer un fichier `lib.h` et le compléter. Ne pas oublier de le protéger contre les mutli inclusions.

Modifier le fichier `main.c` pour appeler votre fonction.

## Partie 2

Créer un fichier `meas.c` et `meas.h`

Dans le fichier `meas.c` ajouter le contenu
```C
#include <stdio.h>

void test()
{
    printf("On est dans le fichier meas\n");
}
```

Modifier le fichier `lib.c` pour que la fonction `func` appelle la fonction `test` qui est dans le fichier `meas.c`

```C
void func(){
    printf("La fonction dans mon fichier\n");
    test();
}
```

Compléter le fichier `meas.h`

# Solution

## Partie 1

### Le fichier `lib.h`
```C
#pragma once

void func();
```

ou 

```C
#ifndef LIB_H_
#define LIB_H_

void func();

#endif
```

### Le fichier `main.c`

Il faut faire l'inclusion du fichier dans le `main` pour que l'on puisse avoir accès à la fonction.

```C
#include "lib.h"

int main(){
    func();
}
```

## Partie 2

### fichier `meas.h`

Ne pas oublier de mettre la protection `pragma once`

```C
#pragma once

void test();
```

### fichier `meas.c`

```C
#include <stdio.h>

void test()
{
    printf("On est dans le fichier meas\n");
}
```

### fichier `lib.c`

Vous devez mettre le `#include "meas.h"`  pour pouvoir appeler la fonction.

**Attention, l'include de se fichier doit être uniquement ici et dans aucun autre fichier.**

```C
#include <stdio.h>
#include "meas.h"

void func(){
    printf("La fonction dans mon fichier\n");
    test();
}
```

