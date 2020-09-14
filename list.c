// list/list.c
// 
// Implementation for linked list.
//
// Raymond Gyabeng

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc() { 
  list_t * head = malloc(sizeof(list_t));
  return head; 
}

void list_free(list_t *l) {
  free(l);
}

void list_print(list_t *l) {
    node_t * current = l->head;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

int list_length(list_t *l) { 
    node_t * current = l->head;
    int length = 0;
    while (current != NULL) {
      length++;
      current = current->next;
    }
  return length; 
}

void list_add_to_back(list_t *l, elem value) {
    node_t * new_node =  malloc(sizeof(node_t));
    new_node -> value = value;
    new_node -> next = NULL;
    node_t* current = l->head;
    if(current == NULL){
      l->head = new_node;
    }
   else{
    while (current->next != NULL) {
        current = current->next;
      }
      current->next = new_node;
      //new_node = current->next;
  }
   
}

void list_add_to_front(list_t *l, elem value) {
    node_t * new_node =  malloc(sizeof(node_t));
    new_node -> value = value;
    new_node -> next = l->head;
    l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index) {
  if(index == 0){
    list_add_to_front(l, value);
    return;
   }
    node_t * new_node =  malloc(sizeof(node_t));
    new_node -> value = value;
    new_node -> next = NULL;
    node_t* current = l->head;
    if(current == NULL){
      return;
    }
    while (index != 0) {
        if(index == 1){
          node_t *tempNode = current->next;
          current->next = new_node;
          new_node->next = tempNode;
          return;
        }
        if(current->next == NULL){
           return;
        }  
        current = current->next;
        index--;
      }
}

elem list_remove_from_back(list_t *l) { 
    node_t* current = l->head;
    if(current == NULL){
      return -1;
    }
    if(current->next == NULL){
      elem retvalue = l->head->value;
      free(l->head);
      return retvalue;
   }
   else{
    while (current->next->next != NULL) {
        current = current->next;
      }
     elem retvalue = current->next->value;
     free(current->next);
     current->next = NULL;
     return retvalue;
  }
}

elem list_remove_from_front(list_t *l) { 
  elem retvalue = -1;
  if(l->head == NULL){
    return retvalue;
  }
  
  node_t* tempHead = l->head;
  retvalue =  l->head->value;
  l->head = l->head->next;
  free(tempHead);
  return retvalue;
}

elem list_remove_at_index(list_t *l, int index) { 
    if(index == 0){
    return list_remove_from_front(l);
   }
    node_t* current = l->head;
    if(current == NULL){
      return -1;
    }
  
    int count = 0;
     for (count = 0; count < index-1; count++) {
        if(current->next == NULL){
           return -1;
        }  
        current = current->next;
      }
  
       node_t* temp = current->next;
       elem retvalue =  temp->value;
       current->next = temp->next;
       free(temp);
       return retvalue;
    
}

bool list_is_in(list_t *l, elem value) { 
  
   node_t* current = l->head;
   if(current == NULL){
      return false;
   }
    while (current != NULL) {
        if(current->value == value){
          return true;
        }
        current = current->next;
      }
     return false; 
                                       
}

elem list_get_elem_at(list_t *l, int index) { 
  
    node_t* current = l->head;
    if(current == NULL){
      return;
    }
  
    int count = 0;
     while(current != NULL) {
        if(count == index){
           return current->value;
        }  
        current = current->next;
        count++;
      }
  
       return;
}


int list_get_index_of(list_t *l, elem value) { 
   node_t* current = l->head;
   if(current == NULL){
      return -1;
   }
    int index = 0;
    while (current != NULL) {
        if(current->value == value){
          return index;
        }
        current = current->next;
        index++;
      }
  
     return -1; 
}