# Les fichiers

#### Rappel format `scanf`

Le format pour récupérer une chaîne de caractères
avec des espaces `"%[^\n]s"`

## Ex 1
Créer un programme qui réalise les opérations suivantes :
- Crée un fichier texte et écrit `Bonjour` dedans.
- Ajoute ` tout le monde à la suite`.
- Lit le fichier et affiche le contenu sur la console avec `fgets`.

Le fichier est fermé entre chaque opération.

## Ex 2
Créer un programme qui réalise les opérations suivantes :
- Crée un fichier texte et écrit `Bonjour` dedans.
- Ajoute `Tout le monde.` sur la `deuxième ligne`.
- Lit le fichier et affiche le contenu sur la console avec `fgetc` et `fgets`.

Le fichier est fermé entre chaque opération.

## Ex 3
Créer un programme qui remplit un fichier avec les multiples de `7` jusqu’à `100`.

Ensuite, lire le fichier et l’afficher sur la console.

Le fichier est fermé entre l'écriture et la lecture.

```console
7
14
21
28
...
```

## Ex 4
Créer un programme qui regarde si le fichier
`name.txt` existe.
- Si oui, afficher le nom qui est sauvé dedans
- Sinon, demander à l'utilisateur d'entrer son nom 
et ensuite il faut le sauver dans le fichier.

Il n'y a pas besoin de faire de validation de saisie.

```console
$ ./app
Veuillez entrer votre nom : > Tony

$ ./app
Bonjour : Tony
```

## Ex 5
Faire un programme qui écrit dans un fichier le carré et la racine
d'un nombre.

Les valeurs sont séparées par `,`

Une ligne :
nombre, carré, racine

```console
1,1,1
2,,4,1.41
3,9,1.73
...
```

Le nombre de valeur est donné par une `constante`

Ajouter une `fonction` pour lire le fichier et l'afficher à la `console`
