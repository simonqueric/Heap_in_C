## Implémentation d'une structure de tas et du tri par tas 

### Execution du code 

1. ```sh
   gcc heap.c -o heap
   ```

2. ```sh
   ./heap
   ```

### Complexité temporelle du tri par tas

On note $N$ le nombre d'éléments de la liste que l'on souhaite trier

1. Pour créer le tas on a $N$ opérations qui nous coûte chacune $\log{N}$ opérations.
2. Pour avoir la liste triée il suffit d'appeler la méthode pop $N$ fois qui coûte $\log{N}$ opérations.

La complexité est donc en $O(N\log{N})$
