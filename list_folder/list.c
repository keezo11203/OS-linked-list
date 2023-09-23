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
  list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 
  mylist->head = NULL;
  return mylist;
}

void list_free(list_t *l) {
  // Free all nodes in the list
  node_t* current = l->head;
  while (current != NULL) {
    node_t* next = current->next;
    free(current);
    current = next;
  }
  // Free the list structure itself
  free(l);
}

void list_print(list_t *l) {
  node_t* current = l->head;
  while (current != NULL) {
    printf("%d->", current->value);
    current = current->next;
  }
  printf("NULL\n");
}

char *listToString(list_t *l) {
  char* buf = (char *)malloc(sizeof(char) * 1024);
  char tbuf[20];

  strcpy(buf, ""); // Initialize buf as an empty string

  node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d -> ", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) { 
  int length = 0;
  node_t* current = l->head;
  while (current != NULL) {
    length++;
    current = current->next;
  }
  return length;
}

void list_add_to_back(list_t *l, elem value) {
  node_t* cur_node = (node_t *) malloc(sizeof(node_t));
  cur_node->value = value;
  cur_node->next = NULL;

  if (l->head == NULL) {
    // If the list is empty, set the new node as the head
    l->head = cur_node;
  } else {
    // Find the last node and add the new node to its next
    node_t* current = l->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = cur_node;
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t* cur_node = (node_t *) malloc(sizeof(node_t));
  cur_node->value = value;
  cur_node->next = l->head;  // Update l->head to point to the new node
  l->head = cur_node;  // Update the head of the list
}

void list_add_at_index(list_t *l, elem value, int index) {
  node_t* cur_node = (node_t *) malloc(sizeof(node_t));
  cur_node->value = value;
  cur_node->next = NULL;

  if (index <= 0) {
    // Handle invalid index by adding to the front
    cur_node->next = l->head;
    l->head = cur_node;
  } else {
    // Insert at index
    node_t* current = l->head;
    int i = 0;
    while (i < index - 1 && current != NULL) {
      current = current->next;
      i++;
    }
    if (current != NULL) {
      cur_node->next = current->next;
      current->next = cur_node;
    } else {
      // Index is beyond the end of the list, add to the back
      if (l->head == NULL) {
        // If the list is empty, set the new node as the head
        l->head = cur_node;
      } else {
        // Find the last node and add the new node to its next
        node_t* last = l->head;
        while (last->next != NULL) {
          last = last->next;
        }
        last->next = cur_node;
      }
    }
  }
}

elem list_remove_from_back(list_t *l) { 
  if (l->head == NULL) {
    // Handle empty list
    return -1;  // Or any other suitable value
  }

  if (l->head->next == NULL) {
    // Handle a list with only one element
    elem value = l->head->value;
    free(l->head);
    l->head = NULL;
    return value;
  }

  node_t* current = l->head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  elem value = current->next->value;
  free(current->next);
  current->next = NULL;
  return value;
}

elem list_remove_from_front(list_t *l) { 
  if (l->head == NULL) {
    // Handle empty list
    return -1;  // Or any other suitable value
  }

  elem value = l->head->value;
  node_t* current = l->head;
  l->head = current->next;
  free(current);
  return value;
}

elem list_remove_at_index(list_t *l, int index) { 
  if (l->head == NULL || index <= 0) {
    // Handle empty list or invalid index
    return -1;  // Or any other suitable value
  }

  if (index == 1) {
    // Handle removal of the first element
    elem value = l->head->value;
    node_t* current = l->head;
    l->head = current->next;
    free(current);
    return value;
  }

  node_t* current = l->head;
  int i = 0;
  while (i < index - 1 && current != NULL) {
    current = current->next;
    i++;
  }
  if (current != NULL && current->next != NULL) {
    elem value = current->next->value;
    node_t* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return value;
  } else {
    // Index is beyond the end of the list, return an error value
    return -1;  // Or any other suitable value
  }
}

bool list_is_in(list_t *l, elem value) { 
  node_t* current = l->head;
  while (current != NULL) {
    if (current->value == value) {
      return true;
    }
    current = current->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) {
  if (l->head == NULL || index <= 0) {
    // Handle empty list or invalid index
    return -1;  // Or any other suitable value
  }

  node_t* current = l->head;
  int i = 0;
  while (i < index) {
    if (current == NULL) {
      // Index is beyond the end of the list, return an error value
      return -1;  // Or any other suitable value
    }
    current = current->next;
    i++;
  }
  return current->value;
}
 
int list_get_index_of(list_t *l, elem value) { 
  node_t* current = l->head;
  int i = 0;
  while (current != NULL) {
    if (current->value == value) {
      return i;
    }
    current = current->next;
    i++;
  }
  return -1;  // Element not found
}