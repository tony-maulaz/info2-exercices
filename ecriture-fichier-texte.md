## Exercice : Génération de fichier CSV

Créer un programme qui génère un fichier `csv` avec les données suivantes :
```csv
number,root,square
1,1,1
2,1.414,4
3,1.732,9
```

Le fichier est rempli à partir de la valeur `1` jusqu'à la valeur `n` spécifiée en argument du programme.

Par défaut, lors de l'exécution du programme, il doit créer un fichier `data.csv`. L'option `-o` permet de choisir un nom de fichier de sortie personnalisé.

**Exemple d'exécution :**
```bash
./program -o output.csv 24
```

Le programme doit créer un fichier `output.csv` contenant les données de 1 à 24.
