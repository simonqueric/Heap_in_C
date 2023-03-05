#include <stdio.h>
#include <stdlib.h>
# define N 30


// Implementation d'une structure de tas et des méthodes associées, implémentation du tri par tas

typedef struct node {
  int weight; 
} node ; 

typedef struct Heap {
  struct node array[N] ;
  int next;
} Heap;

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
      return (k-2)/2;
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

int* heap_sort(int T[]) {
  // Tri une liste d'entier

  // creation du Tas par empilement
  int i = 0;
  node n ;
  Heap h = {.next=0} ; 
  while (T[i] != '\0') {
    n.weight = T[i] ;  
    push(&h, n) ;
    i++ ;
  }

  int lenght = i ;
  int* T_sorted = malloc(lenght * sizeof(int)); 
  
  // dépilement
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

  int T[10] = {1, 6, -7, 10, 205, 2, 5, 10, 6, 7} ;

 int* T_trie = malloc(10 * sizeof(int));

  T_trie = heap_sort(T) ; 

  for (int i=0; i<10; i++) {
    printf("%d ", T_trie[i]);
  }
  printf("\n") ; 

  /* Comparaison avec le tri par tas */

  
  return 0; 
}
