#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
  printf("Running linked list test cases\n");

  // Test Case 1: NULL list
  list_t *mylist = list_alloc();
  printf("Test Case 1: ");
  list_print(mylist);
  list_free(mylist);

  // Test Case 2: Add elements to the front
  mylist = list_alloc();
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  printf("Test Case 2: ");
  list_print(mylist);

  // Test Case 3: Add elements to the back
  list_add_to_back(mylist, 40);
  list_add_to_back(mylist, 50);
  list_add_to_back(mylist, 60);
  printf("Test Case 3: ");
  list_print(mylist);

  // Test Case 4: Remove an element at index
  list_remove_at_index(mylist, 2);
  printf("Test Case 4: ");
  list_print(mylist);

  // Test Case 5: Check if an element exists
  if (list_is_in(mylist, 30)) {
    printf("Test Case 5: Element 30 exists in the list.\n");
  }

  // Test Case 6: Get element at index
  int elem_at_index = list_get_elem_at(mylist, 3);
  printf("Test Case 6: Element at index 3 is %d\n", elem_at_index);

  // Test Case 7: Get index of element
  int index_of_elem = list_get_index_of(mylist, 50);
  printf("Test Case 7: Index of element 50 is %d\n", index_of_elem);

  // Test Case 8: Add elements at specific indexes
  list_add_at_index(mylist, 35, 1);
  list_add_at_index(mylist, 55, 4);
  printf("Test Case 8: ");
  list_print(mylist);

  // Test Case 9: Remove elements from the front
  list_remove_from_front(mylist);
  printf("Test Case 9: ");
  list_print(mylist);

  // Test Case 10: Remove elements from the back
  list_remove_from_back(mylist);
  printf("Test Case 10: ");
  list_print(mylist);

  // Free the list
  list_free(mylist);

  return 0;
}
