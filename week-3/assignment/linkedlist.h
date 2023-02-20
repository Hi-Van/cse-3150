#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

#include <iostream>
using namespace std;

struct node
{
    int number;
    struct node *next;
};

struct node *build_linked_list(int elements)
{
    struct node *travel = nullptr;
    struct node *anchor = travel;

    for (int idx = 0; idx < elements; idx++)
    {
        struct node *curr = new node;
        curr->number = idx;

        if (!travel)
        {
            travel = curr;
        }

        else
        {
            travel->next = curr;
            travel = travel->next;
        }
    }

    return anchor;
};

void connect(struct node *nodes[])
{
    for (int idx = 1; idx < (sizeof(nodes) / sizeof(struct node *)) - 1; idx++)
    {
        struct node *left = nodes[idx - 1];
        struct node *right = nodes[idx];

        left->next = right;
    };
};

void print_linked_list(struct node *list, int elements)
{
    struct node *sentinel = list;

    while (sentinel && sentinel->next)
    {
        cout << sentinel->number << " -> ";
        sentinel = sentinel->next;
    }

    cout << "NULL" << endl;
};

int delete_linked_list(struct node *list)
{
    while (list)
    {
        struct node *curr = list;
        list = list->next;

        curr->next = NULL;
        free(curr);
    }

    return 1;
}

int sum_values_in_linked_list(struct node *list)
{
    struct node *travel = list;
    int total = 0;

    while (travel) {
        total += travel->number;
        travel = travel->next;
    }

    return total;
}

#endif
