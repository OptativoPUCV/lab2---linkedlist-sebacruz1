#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() 
{
  List *ListAux = (List *)malloc(sizeof(List));

  ListAux->head = NULL;
  ListAux->tail = NULL;
  ListAux->current = NULL;

  
  return ListAux;
}

void * firstList(List * list) 
{
  if (list -> head == NULL) return NULL;

  list->current = list->head;
  
  return list->head->data;;

}

void * nextList(List * list) 
{ 
  if (list->current == NULL) return NULL;

  if (list->current == list->tail) return NULL;

  list->current = list->current->next;
  
  return list->current->data;
}

void * lastList(List * list) 
{
  list->current = list->tail;

  return list->current->data;

}

void * prevList(List * list) 
{
  if (list->current == NULL) return NULL;

  if (list->current == list->head) return NULL;

  list->current = list->current->prev;
  
  return list->current->data;
}

void pushFront(List * list, void * data) 
{
  Node *n = createNode(data);
  if (list->head == NULL)
  {
    list->head = n;
    list->tail = n;
  }
  else
  {

    n->next = list->head;
    list->head->prev = n;
    list->head = n;
  }
}

void pushBack(List * list, void * data) 
{
  list->current = list->tail;
  pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
  Node *n = createNode(data);

  if (list->current == list->tail) list->tail = n;
    
  n->next = list->current->next;
  n->prev = list->current;
  
  list->current->next = n;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void *popCurrent(List * list) 
{
  Node *aux = list->current;

  if (aux->prev != NULL)
  {
    aux->prev->next = aux->next;
  }
  else list->head = aux->next;

  if (aux->next != NULL)
  {
    aux->next->prev = aux->prev;
  }
  else
  {
    list->tail = aux->prev;
  }
  
  return (aux->data);

}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}