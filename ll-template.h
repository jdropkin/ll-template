/**
 * @file NAME.h
 * @brief
 */

#ifndef UPPERNAME_H
#define UPPERNAME_H

typedef struct NAME_node {
    int data;
    struct NAME_node *next;
} NAME_node_t;

typedef struct NAME {
    NAME_node_t *head;
} NAME_t;

NAME_t *NAME_new(void);

void NAME_destroy(NAME_t *FIRSTCHAR);

int NAME_insert(NAME_t *FIRSTCHAR, int data);

int NAME_search(NAME_t *FIRSTCHAR, int data);

int NAME_remove(NAME_t *FIRSTCHAR, int data);

#endif /* UPPERNAME_H */
