#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 200

// Implementation d'une structure de tas et des méthodes associées, implémentation du tri par tas

// Déclaration des fonctions et des structures 

typedef struct node {
  int weight; 
} node ; 

typedef struct Heap {
  struct node array[N] ;
  int next;
} Heap ;

int father(int pos) {
  int k = pos ;
  if (k==0) {
    return k ; // n est la racine
  }
  else { 
    if (k%2==1) {
      return k/2 ;
    }
    else {
      return (k-1)/2;
    }
  }
}

void swap(node* p1, node* p2) {
  node tmp = *p1 ;
  *p1 = *p2 ;
  *p2 = tmp ;
}

void push(Heap* hp, node new_node) {
  int w = new_node.weight ; 
  int current = hp->next ; 
  if (current < N) {
    hp->next = current+1; 
    
    // On ajoute le noeud n à la fin du tas 
    hp->array[current] = new_node ;
    int pos_father = father(current) ;
    node f = hp->array[pos_father] ;
    int father_w = f.weight;

    // Et on le fait remonter

    while (w < father_w) {
      //int brother_w = hp.array[current+1].weight ;
      swap(&hp->array[current], &hp->array[pos_father]) ;
      current = pos_father ; 
      if (current==0) {
	break ;
      }
      pos_father = father(current) ;
      f = hp->array[pos_father] ;
      father_w = f.weight ;
    }
  }
  return ;
}


node pop(Heap* hp) {
  node root = hp->array[0] ;
  //printf("%d \n", root.weight);
  
  int next = hp->next ; 
  hp->next = next-1 ; 
  swap(&hp->array[0], &hp->array[next-1]) ;
  node last = hp->array[next-1] ;
  int current = 0 ; 
  
  int left, right ;

  left = 2*current+1; right = 2*current+2;

  // On échange root et current et on fait descendre current

  while (left < next-1) {
    if (right < next - 1) {      
      if (hp->array[current].weight <= hp->array[left].weight) {
        if (hp->array[current].weight <= hp->array[right].weight) {
          return root ;
        }
        else {
            swap(&hp->array[current], &hp->array[right]) ;
            current = right ; 
            left = 2*current+1; right = 2*current+2;
        }
      }

      else {
        if (hp->array[left].weight <= hp->array[right].weight) {
          swap(&hp->array[current], &hp->array[left]) ;
          current = left ; 
          left = 2*current+1; right = 2*current+2;
        }

        else {
          swap(&hp->array[current], &hp->array[right]) ;
          current = right ; 
          left = 2*current+1; right = 2*current+2;
        }
      }
    }

    else {
       if (hp->array[current].weight <= hp->array[left].weight) { 
          return root ;
        }
      else {
          swap(&hp->array[current], &hp->array[left]) ;
          current = left ; 
          left = 2*current+1; right = 2*current+2;
          return root ; 
         
      }
    } 
     
 }
  return root ; 
  
}

int* heap_sort(int T[], int k) {
  // Tri une liste d'entier

  // creation du Tas 
  int i = 0;
  node n ;
  Heap h = {.next=0} ; 
  for(int i=0; i<k; i++) {
    n.weight = T[i] ;  
    push(&h, n) ;
  }

  int lenght = i ;
  int* T_sorted = malloc(lenght * sizeof(int)); 

  // Dépilement du tas
  node pp;
  i=0;
  while (h.next!=0) {
    pp = pop(&h) ;
    T_sorted[i] = pp.weight ; 
    i++;
  }
  return T_sorted ; 
}

int main() {
 
  Heap hp = {.next = 0};
  
  node n1 = {.weight = 10} ;
  node n2 = {.weight = 20} ;
  node n3 = {.weight = 50} ;
  node n4 = {.weight = 80} ;
  node n5 = {.weight = 30} ;
  node n6 = {.weight = 60} ;
  node n7 = {.weight = 70} ;
  
  push(&hp, n1) ;
  push(&hp, n2) ;
  push(&hp, n3) ;
  push(&hp, n4) ;
  push(&hp, n5) ;
  push(&hp, n6) ;
  push(&hp, n7) ; 

  for (int i=0; i<7; i++) {
    printf("%d, ", hp.array[i].weight) ;
  }
  printf("\n");


  node pp ;
  pp = pop(&hp) ;
  //printf("%d ", pp.weight) ; // 10
  for (int i=0; i<6; i++) {
    printf("%d ", hp.array[i].weight) ; 
  } 
  printf("\n");
  pp = pop(&hp) ;
  //printf("%d ", pp.weight) ; // 20
  //pp = pop(&hp) ;
  for (int i=0; i<5; i++) {
    printf("%d ", hp.array[i].weight) ; 
  } 

  printf("\n") ;
  //printf("%d ", pp.weight) ; // 30 
  pp = pop(&hp) ;
  for (int i=0; i<4; i++) {
    printf("%d ", hp.array[i].weight) ; 
  } 

  printf("\n") ;
  //printf("%d ", pp.weight) ; // 50
  pp = pop(&hp) ;
  for (int i=0; i<3; i++) {
    printf("%d ", hp.array[i].weight) ; 
  } 

  printf("\n") ;
  //printf("%d ", pp.weight) ; // 60 
  pp = pop(&hp) ;

  for (int i=0; i<2; i++) {
    printf("%d ", hp.array[i].weight) ; 
  }

  printf("\n") ;
  //printf("%d ", pp.weight) ; // 70
  pp = pop(&hp) ;
   for (int i=0; i<1; i++) {
    printf("%d ", hp.array[i].weight) ; 
  } 
  //printf("%d ", pp.weight) ; // 80

  printf("\n") ;

  /* ......................................... */

  // int* T = malloc(13 * sizeof(int));
  // int T[N] = {4, -6700, 34, 1, 6, -7, 10, 205, 2, 5, 10, 6, 7} ;
  int T[N] = {98, 38, 91, 24, 58, 68, 72, 73, 78, 7, 94, 57, 36, 68, 26, 42, 78,
        40, 60, 48, 59, 10, 30, 55,  2, 40, 74, 32, 81, 75, 44, 23, 85, 93,
       42, 14, 55, 70, 65,  9, 97, 50, 63,  1,  4,  1, 76,  3, 15, 22, 76,
       97, 24, 73,  0, 60, 37, 83, 90, 79, 20, 90, 71, 60, 66, 74,  3, 54,
       93, 13, 11, 82, 90, 73, 11, 67, 94, 53, 92, 16, 84, 60, 91, 49, 41,
        2, 87, 87, 49, 84, 99, 75, 25, 54, 97, 99, 22, 38, 37, 78, 49, 55,
       64, 42, 90, 81, 18, 58, 61, 34, 30, 55, 62,  9, 88, 51,  1, 68, 83,
       93, 62, 30, 36, 47, 67, 13, 90, 48, 94, 15,  3, 33, 85, 98, 97, 79,
       79, 58, 71, 85, 95, 98, 22, 34,  3, 46, 34, 81, 87, 19, 45, 82, 37,
       20, 28, 90, 70, 94, 54,  6, 33, 11, 75, 73, 28, 73,  5, 85, 12, 55,
       27, 81, 70, 94,  1, 42, 52, 56,  1, 80, 70, 32, 61, 72, 66, 66, 44,
      7, 57, 83, 87, 42, 76, 74, 98, 14,  4, 48, 14, 80 } ;
  int i = 0;
  printf("Liste non triée : \n") ;
  for (int i=0; i<N;i++) {
    printf("%d ", T[i]);
  }
  printf("\n") ; 
  
  /*....................................................................................*/

  int* T_trie; // = malloc(10 * sizeof(int));

  clock_t begin = clock();

  T_trie = heap_sort(T, N) ; 

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("Temps d'execution : %f seconds \n", time_spent) ; 
  printf("\n") ; 
  printf("Liste triée : \n") ;
  i=0; 
  for (int i=0; i<N; i++) {
    printf("%d ", T_trie[i]);
  }
  printf("\n") ; 
  printf("\n") ;
  free(T_trie) ;

  /* Comparaison avec le tri par tas */

  return 0; 

}