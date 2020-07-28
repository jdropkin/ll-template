/**
 * @file NAME.c
 * @brief
 */

#include "NAME.h"

#include <stdio.h>
#include <stdlib.h>

NAME_t *NAME_new() {
    NAME_t *FIRSTCHAR = malloc(sizeof(NAME_t));
    if (FIRSTCHAR == NULL) {
        return NULL;
    }

    FIRSTCHAR->head = NULL;

    return FIRSTCHAR;
}

void NAME_destroy(NAME_t *FIRSTCHAR) {
    NAME_node_t *curr;

    if (FIRSTCHAR == NULL) {
        return;
    }

    while (FIRSTCHAR->head != NULL) {
        curr = FIRSTCHAR->head;
        FIRSTCHAR->head = FIRSTCHAR->head->next;
        free(curr);
    }

    free(FIRSTCHAR);
}

int NAME_insert(NAME_t *FIRSTCHAR, int data) {
    NAME_node_t *new;

    if (FIRSTCHAR == NULL) {
        return -1;
    }

    new = malloc(sizeof(NAME_node_t));
    if (new == NULL) {
        return -1;
    }

    new->data = data;

    new->next = FIRSTCHAR->head;
    FIRSTCHAR->head = new;

    return 0;
}

int NAME_search(NAME_t *FIRSTCHAR, int data) {
    if (FIRSTCHAR == NULL) {
        return -1;
    }

    for (NAME_node_t *curr = FIRSTCHAR->head; curr != NULL; curr = curr->next) {
        if (curr->data == data) {
            return 1;
        }
    }

    return 0;
}

int NAME_remove(NAME_t *FIRSTCHAR, int data) {
    NAME_node_t *curr, *prev;

    if (FIRSTCHAR == NULL) {
        return -1;
    }

    curr = FIRSTCHAR->head;
    prev = NULL;

    while (curr != NULL) {
        if (curr->data == data) {
            if (prev == NULL) {
                FIRSTCHAR->head = curr->next;
                free(curr);
                return 0;
            } else {
                prev->next = curr->next;
                free(curr);
                return 0;
            }
        }

        prev = curr;
        curr = curr->next;
    }

    return -1;
}

