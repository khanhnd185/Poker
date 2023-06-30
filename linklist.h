#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdint.h>

struct Node {
    int data; 
    struct Node *next; 
};

int ll_length(struct Node* list);
void ll_delete(struct Node** list);
void ll_push(struct Node** head_ref, int new_data);
void ll_insertAfter(struct Node* prev_node, int new_data);
void ll_append(struct Node** head_ref, int new_data);
void ll_merge(struct Node* head, struct Node* tail);
struct Node* ll_split(struct Node* head, int pos);
struct Node* ll_access(struct Node* head, int pos);

#endif /* LINKLIST_H */
