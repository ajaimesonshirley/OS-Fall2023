// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t *mylist = (list_t *) malloc(sizeof(list_t)); 
  if (mylist){
    mylist->head = NULL;
  }
  return mylist;  
}

void list_free(list_t *l) {
  if (l == NULL){
    return;
  }

  node_t *current = l->head;
  while (current != NULL){
    node_t *temp = current;
    current = current->next;
    free(temp);
  }
  free(l);
}

void list_print(list_t *l) {
  if (l == NULL || l->head == NULL){
    printf("The list is empty.\n");
    return;
  }

  node_t *current = l -> head;

  while (current != NULL){
    printf("%d ", current->value);
    current = current->next;
  }

  printf("\n");  
}

char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) { 
  int length = 0;
  node_t *current = l->head;
  while(current != NULL){
    length++;
    current = current -> next;
  }

  return length;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *newNode = (node_t *)malloc(sizeof(node_t));
  newNode->value = value;
  newNode->next = NULL;
  
  if (l->head == NULL) {
      l->head = newNode;
  } else {
      node_t *current = l->head;
      while (current->next != NULL) {
          current = current->next;
      }
      current->next = newNode;
  }
}

void list_add_to_front(list_t *l, elem value) {
     node_t *cur_node = (node_t *) malloc(sizeof(node_t));
     cur_node->value = value;
     cur_node->next = l->head;
     l->head = cur_node;

     /* Insert to front */

    //  node_t *head = l->head;  // get head of list

    //  cur_node->next = head;
    //  head = cur_node;
}

void list_add_at_index(list_t *l, elem value, int index) {
  if (index < 1){
    return;
  }

  node_t *newNode = (node_t *) malloc(sizeof(node_t));
  newNode->value = value;

  if (index == 1 || l->head == NULL){
    // this means we're adding the value to the front
    newNode->next = l->head;
    l->head = newNode;
  }
  else{
    int curr_index = 1;
    node_t *current = l->head;
    while (curr_index < index-1 && current->next != NULL){
      current = current->next;
      curr_index++;
    }
    newNode->next = current->next;
    current->next = newNode; 
  }
}

elem list_remove_from_back(list_t *l) { 
  if (l->head == NULL) {
    // printf("The list is empty.\n");
    return -1;
  }
    
  if (l->head->next == NULL) {
    // only one element in the list
    elem value = l->head->value;
    free(l->head);
    l->head = NULL;
    return value;
  }
  
  node_t *current = l->head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  
  elem value = current->next->value; //moving to the last value
  free(current->next);
  current->next = NULL;
  return value;
}

elem list_remove_from_front(list_t *l) { 
  if (l->head == NULL){
    // printf("The list is empty.\n")
    return -1;
  }

  node_t *temp = l->head;
  elem value = temp->value;
  l->head = l->head->next; //set head to the be the next index
  free(temp);
  return value;
}

elem list_remove_at_index(list_t *l, int index) {
  if (index < 1 || l->head == NULL){
    return -1;
  }

  if (index == 1){
    //remove the first element
    return list_remove_from_front(l);
  }

  int curr_index = 1;
  node_t *current = l->head;
  while (curr_index < index - 1 && current->next != NULL){
    current = current->next;
    curr_index++;
  }
  
  if (current->next == NULL) {
    // index is out of bounds
    return -1; 
  }
  
  node_t *temp = current->next;
  elem value = temp->value;
  current->next = temp->next;
  free(temp);
  return value;
}  

bool list_is_in(list_t *l, elem value) { 
  node_t *current = l->head;
  while (current != NULL){
    if (current->value == value){
      return true;
    }
    current = current->next;
  }
  return false; 
}

elem list_get_elem_at(list_t *l, int index) { 
  if (index < 1 || l->head == NULL){
    return -1;
  }

  int curr_index = 1;
  node_t *current = l->head;
  while(curr_index < index){
    if (current->next == NULL){
      return -1;
    }
    current = current->next;
    curr_index++;
  }
  return current->value;
}

int list_get_index_of(list_t *l, elem value) { 
  if (l == NULL || l->head == NULL){
    return -1;
  }

  int index = 1;
  node_t *current = l->head;
  while(current != NULL){
    if (current->value == value){
      return index;
    }
    current = current->next;
    index++;
  }

  //if element is not found
  return -1; 
}

