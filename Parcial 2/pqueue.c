#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "character/character.h"
#include "pqueue.h"

/* ============================================================================
STRUCTS!
============================================================================ */

struct s_pqueue {
  struct s_node *front;
  unsigned int size;
};

struct s_node {
    Character c;
    struct s_node *next;
    unsigned int prio;  
};

/* ============================================================================
INVREP
============================================================================ */

static bool invrep(pqueue q)
{
  bool flag=true;
  struct s_node *prev=NULL;
  struct s_node *curr=q->front;
  unsigned int len=0;
  while(curr!=NULL && flag){
    prev=curr;
    flag = flag && curr->prio <= prev->prio; // colas de prioridad [propiedad e1>=e2]
    curr=curr->next;
    prev=prev->next;
    len=len+1;
  }
  bool len_vs_size = q->size==len; // verificar que el size de retorno esta ok
  return len_vs_size && flag;
}


/* ============================================================================
NEW
============================================================================ */

pqueue pqueue_empty(void) {
  pqueue q = NULL;
  q = malloc(sizeof(struct s_pqueue));
  q->front=NULL;
  q->size=0;
  return q;
}

/* ============================================================================
ENQUEUE
============================================================================ */

static float calculate_priority(Character character) {
  unsigned int baseInitiative=character_agility(character);
  charttype_t modificador=character_ctype(character);
  bool isAlive = character_is_alive(character);
  float iniciative = 1;
  if(modificador==agile){
    iniciative = baseInitiative * 1.5 * isAlive;
  }
  if(modificador==tank){
    iniciative = baseInitiative * 0.8 * isAlive;
  }else{
    iniciative = baseInitiative * modificador * isAlive;
  }

  return iniciative;
}

static struct s_node *create_node(Character character) {
  struct s_node *new_node = NULL;
  float priority = calculate_priority(character);
  new_node = malloc(sizeof(struct s_node));
  assert(new_node != NULL);
  new_node->c=character;
  new_node->next=NULL;
  new_node->prio=priority;
  return new_node;
}

pqueue pqueue_enqueue(pqueue q, Character character) {
  assert(invrep(q));
  struct s_node *new_node = create_node(character);
  struct s_node *prev_node = NULL;
  struct s_node *curr_node =NULL;
  curr_node=q->front;

  while(curr_node != NULL && new_node->prio >= curr_node->prio) {
      prev_node=curr_node;
      curr_node=curr_node->next;
  }
  if(prev_node==NULL) {
    new_node->next=curr_node;
    q->front=new_node;
  }else{
    prev_node->next=new_node;
    new_node->next=curr_node;
  }

  q->size +=1;

  return q;
}

/* ============================================================================
IS EMPTY?
============================================================================ */

bool pqueue_is_empty(pqueue q) {
  
  return q->size==0;
}

/* ============================================================================
PEEKS
============================================================================ */

Character pqueue_peek(pqueue q) {
  assert(invrep(q));
  return q->front->c;
}

float pqueue_peek_priority(pqueue q) {
  assert(invrep(q));
  return q->front->prio;
}

/* ============================================================================
SIZE
============================================================================ */

unsigned int pqueue_size(pqueue q) {
  assert(invrep(q));
  return q->size;
}

/* ============================================================================
COPY
============================================================================ */
pqueue pqueue_copy(pqueue q) {
    pqueue cpy = pqueue_empty(); 
    struct s_node *tmp = q->front;

    while (tmp != NULL) {
        Character clone = character_copy(tmp->c); // usar! character_copy + enqueue
        pqueue_enqueue(cpy, clone);
        tmp = tmp->next;

    }

    assert(pqueue_size(cpy) == pqueue_size(q));
    return cpy;
}


/* ============================================================================
DESTROY!
============================================================================ */
static struct s_node *destroy_node(struct s_node *node) {
  assert(node != NULL);
  character_destroy(node->c); // faltaba deletear el character
  free(node);
  node=NULL;
  assert(node == NULL);
  return node;
}

pqueue pqueue_dequeue(pqueue q) {
  assert(invrep(q));
  struct s_node *killme = q->front;
  q->front=q->front->next;
  destroy_node(killme);
  --q->size;
  return q;
}

pqueue pqueue_destroy(pqueue q) {
  struct s_node *killme=q->front;
  while(q->front !=NULL){
    killme=q->front;
    q->front=killme->next;
    destroy_node(killme);
  }
  free(q);
  q=NULL;
  assert(q == NULL);
  return q;
}
