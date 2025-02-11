#include "list.h"

#include <stdlib.h>

struct node* init(struct door* door) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node) {
        new_node->door = *door;
        new_node->next = NULL;
    }
    return new_node;
}
struct node* add_door(struct node* elem, struct door* door) {
    if (!elem || !door) return NULL;

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node) {
        new_node->door = *door;
        new_node->next = elem->next;
        elem->next = new_node;
    }
    return new_node;
}
struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while (current) {
        if (current->door.id == door_id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
struct node* remove_door(struct node* elem, struct node* root) {
    if (!elem || !root) return root;

    if (elem == root) {
        struct node* new_root = root->next;
        free(root);
        return new_root;
    }
    struct node* current = root;
    while (current->next != elem) {
        current = current->next;
        if (!current) return root;
    }
    current->next = elem->next;
    free(elem);
    return root;
}
void destroy(struct node* root) {
    while (root) {
        struct node* temp = root;
        root = root->next;
        free(temp);
    }
}