#include <stdio.h>
#include <stdlib.h>
# define N 30


// Implementation d'une structure de tas et des méthodes associées

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
    if (k%2==0) {
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

void push(Heap* hp, node n) {
  int d = n.weight ; 
  int current = hp->next ;
  
  if (current < N) {
    hp->next = current+1; 

    // On ajoute le noeud n à la fin du tas 
    hp->array[current] = n ; 
    int pos_father = father(current) ;
    node f = hp->array[pos_father] ;
    int father_dist = f.weight;

    // Et on le fait remonter

    while (d < father_dist) {
      swap(&hp->array[current], &hp->array[pos_father]) ;
      current = pos_father ; 
      if (current==0) {
	break ;
      }
      pos_father = father(current) ;
      f = hp->array[pos_father] ;
      father_dist = f.weight ;
    }
  }
  return ;
}


node pop(Heap* hp) {
  node root = hp->array[0] ;
  int next = hp->next ; 
  hp->next = next-1 ; 

  node last = hp.array[next-1] ;
  node left, right ;

  // On échange root et last et on fait descendre last

  return root ; 
  }  

int main() {
 
  Heap hp = {.next = 0};
  
  node n1 = {.weight = 2} ;

  push(&hp, n1) ;
  
  node n2 = {.weight = 1} ;
  hp.array[1] = n2 ;
  
  push(&hp, n2) ;

  //increment(hp) ; 

  printf("%d \n", hp.next);
  
  return 0; 
}
