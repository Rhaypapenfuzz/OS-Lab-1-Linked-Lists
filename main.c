#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  
  printf("Tests for linked list implementation\n");
  
  //list should have elements 4,6,7 added and a length of 3
  list_t * list1 = list_alloc();
  list_add_to_back(list1, 4);
  list_add_to_back(list1, 6);
  list_add_to_back(list1, 7);
	list_print(list1); 
  printf("Length is: %d\n", list_length(list1));
  
  //list should have add elements 2 to front then 1 ie: 1, 2, 4, 6, 7
  list_add_to_front(list1, 2);
  list_add_to_front(list1, 1);
  list_print(list1);
  printf("Length is: %d\n", list_length(list1));

  //0 should be first, 2 should be 3rd element and 25 should be last elements.
  // ie: 0, 1, 2, 3, 4, 6, 7, 25. Length of list should be 8
  list_add_at_index(list1, 25, 5);
  list_add_at_index(list1, 3, 2);
  list_add_at_index(list1, 0, 0);
  list_print(list1);
  printf("Length is: %d\n", list_length(list1));
 
  //7 and 25 should be removed from back of list
  // ie: 0, 1, 2, 3, 4, 6. Length of list should be 6
  list_remove_from_back(list1);
  list_remove_from_back(list1);
  list_print(list1);
  printf("Length is: %d\n", list_length(list1));

  //0 and 1 should be removed from front of list
  // ie: 2, 3, 4, 6. Length of list should be 4
  list_remove_from_front(list1);
  list_remove_from_front(list1);
  list_print(list1);
  printf("Length is: %d\n", list_length(list1));
  
  //Item 6 at index 3 should be removed from list
  //No item should be removed for index 5 which is out of range
  // ie: 2, 3, 4. Length of list should be 3
  list_remove_at_index(list1, 3);
  list_remove_at_index(list1, 5);
  list_print(list1);
  printf("Length is: %d\n", list_length(list1));
  
  // elem 3 and 4 should be true 
  // elem 10 and 5 not in list should be false
  //ie: true, false, false, true
  bool result = list_is_in(list1, 3);
  printf("%s", result ? "true\n" : "false\n");
  result = list_is_in(list1, 10);
  printf("%s", result ? "true\n" : "false\n");
  result = list_is_in(list1, 5);
  printf("%s", result ? "true\n" : "false\n");
  result = list_is_in(list1, 4);
  printf("%s", result ? "true\n" : "false\n");
  
  
   //Index of 2,4,3 should be 0,2,1 respectively
  // Elements not in list should return -1 ie. 50 and 0
  int index = list_get_index_of(list1, 2);
  printf("Index of 2 is: %d\n", index);
  index = list_get_index_of(list1, 4);
  printf("Index of 4 is: %d\n", index);
 index = list_get_index_of(list1, 3);
  printf("Index of 3 is: %d\n", index);
  index = list_get_index_of(list1, 50);
  printf("Index of 50 is: %d\n", index); 
  index = list_get_index_of(list1, 0);
  printf("Index of 0 is: %d\n", index);

  //Element at index 0, 2 should be 2 and 4
  int elem = list_get_elem_at(list1, 0); 
  printf("Element at index 0 is: %d\n", elem);
  elem =list_get_elem_at(list1, 2);
  printf("Element at index 2 is: %d\n", elem);

  return 0;
}