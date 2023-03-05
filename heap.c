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

    printf("current: %d \n", current) ;
    printf("father: %d \n", pos_father) ;
    node f = hp->array[pos_father] ;
    int father_w = f.weight;

    // Et on le fait remonter

    while (w < father_w) {
      printf("%d VS %d \n", w, father_w);

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
  int next = hp->next ; 
  hp->next = next-1 ; 
  swap(&hp->array[0], &hp->array[next-1]) ;
  node last = hp->array[next-1] ;
  int current = 0 ; 
  
  int left, right ;

  left = 2*current+1; right = 2*current+2;

  // On échange root et last et on fait descendre last

  while (left < next-1) {
    int min;
    if (right < next-1) {
      if (hp->array[left].weight < hp->array[right].weight) {
	if (hp->array[left].weight < hp->array[current].weight) {
	  swap(&hp->array[left], &hp->array[current]);
	  current = left ;      
	}
	else {
	  return root; 
	}
      }
      else {
	if (hp->array[right].weight < hp->array[current].weight) {
	  swap(&hp->array[right], &hp->array[current]);
	  current = left ;      
	}
	else {
	  return root; 
	}
      }   

      left = 2*current+1; right = 2*current+2;
    }
  

  else {
    if (hp->array[left].weight < hp->array[current].weight) {
	swap(&hp->array[left], &hp->array[current]);       
      }
    return root; 
  }
 }
 }  

int main() {
 
  Heap hp = {.next = 0};
  
  node n1 = {.weight = 2} ;

  push(&hp, n1) ;
  
  node n2 = {.weight = 5} ;
  node n3 = {.weight = 34} ;
  node n4 = {.weight = 1} ;
  
  push(&hp, n2) ;

  push(&hp, n3) ;
  
  push(&hp, n4) ;

    for (int i=0; i<4; i++) {
    printf("%d \n", hp.array[i].weight) ;
  }

  /*
  //increment(hp) ; 

  node pp = pop(&hp);
  
  printf("%d \n", pp.weight); //1

  pp = pop(&hp); 
  
  printf("%d \n", pp.weight); //1
 
  pp = pop(&hp); 
  
  printf("%d \n", pp.weight); //2

  pp = pop(&hp); 
  
  printf("%d \n", pp.weight); //34 */

  int k = 3/2 ;
  printf("%d \n", k) ;
    
  return 0; 
}
