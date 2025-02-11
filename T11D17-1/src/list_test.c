#include "list.h"

#include <stdio.h>

int test_add_door() {
    struct door door1 = {1, 0};
    struct door door2 = {2, 0};

    struct node* root = init(&door1);
    struct node* new_node = add_door(root, &door2);

    if (new_node && root->next == new_node && new_node->door.id == door2.id) {
        destroy(root);
        return SUCCESS;
    }
    destroy(root);
    return FAIL;
}

int test_remove_door() {
    struct door door1 = {1, 0};
    struct door door2 = {2, 0};

    struct node* root = init(&door1);
    struct node* node2 = add_door(root, &door2);

    root = remove_door(node2, root);

    if (root && !root->next) {
        destroy(root);
        return SUCCESS;
    }
    destroy(root);
    return FAIL;
}

int main() {
    printf("Test add_door: %s\n", test_add_door() ? "SUCCESS" : "FAIL");
    printf("Test remove_door: %s\n", test_remove_door() ? "SUCCESS" : "FAIL");
    return 0;
}