#include <stdio.h>
#include <process.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *create_node(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->val = n;
    temp->next = NULL;
    return temp;
}

int count_node(struct node *h)
{
    int count = 0;
    struct node *first = h;
    while (first != NULL)
    {
        count++;
        first = first->next;
    }
    return count;
}

struct node *insert_at_beg(struct node *h, int n)
{
    struct node *t;
    t = create_node(n);
    if (h == NULL)
        return t;
    else
    {
        t->next = h;
        h = t;
        return h;
    }
}

struct node *insert_at_end(struct node *h, int n)
{
    struct node *t, *first = h;
    t = create_node(n);
    if (h == NULL)
        return t;
    else
    {
        while (first->next != NULL)
            first = first->next;
        first->next = t;
        return h;
    }
}

struct node *insert_at_pos(struct node *h, int n, int pos)
{
    struct node *t;
    t = create_node(n);
    if (h == NULL)
        return t;
    else if (pos == 1)
    {
        h = insert_at_beg(h, n);
        return h;
    }
    else
    {
        int count = count_node(h);
        if (pos > count + 1)
        {
            printf("Entered position doesn't exist\n");
            return h;
        }
        else
        {
            struct node *prev = h, *cur = h;
            int i = 1;
            while (i < pos)
            {
                prev = cur;
                cur = cur->next;
                i++;
            }
            prev->next = t;
            t->next = cur;
            return h;
        }
        //***OR***
        // struct node *prev = h, *cur = h;
        // int i = 1;
        // while (cur != NULL && i < pos)
        // {
        //     prev = cur;
        //     cur = cur->next;
        //     i++;
        // }
        // if (cur == NULL)
        //     printf("No such pos exists\n");
        // else
        // {
        //     prev->next = t;
        //     t->next = cur;
        // }
        // return h;
    }
}

struct node *insert_sort(struct node *h, int n)
{
    struct node *t;
    t = create_node(n);
    if (h == NULL)
        return t;
    else if (n < h->val)
    {
        h = insert_at_beg(h, n);
        return h;
    }
    else
    {
        struct node *prev = h, *cur = h;
        while (cur != NULL && n > cur->val)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = t;
        t->next = cur;
        return h;
    }
}

struct node *delete_first(struct node *h)
{
    if (h == NULL)
        printf("List is empty, nothing to delete\n");
    else
    {
        struct node *t = h;
        h = h->next;
        free(t);
    }
    return h;
}

struct node *delete_last(struct node *h)
{
    if (h == NULL)
        printf("List is empty, nothing to delete\n");
    else if (h->next == NULL)
        delete_first(h);
    else
    {
        struct node *prev = h, *first = h;
        while (first->next != NULL)
        {
            prev = first;
            first = first->next;
        }
        prev->next = NULL;
    }
    return h;
}

struct node *delete_by_pos(struct node *h, int pos)
{

    if (h == NULL)
    {
        printf("List is empty, nothing to delete\n");
        return h;
    }
    else if (pos == 1)
    {
        h = delete_first(h);
        return h;
    }
    else
    {
        struct node *prev = h, *cur = h;
        int i = 1;
        while (cur != NULL && i < pos)
        {
            prev = cur;
            cur = cur->next;
            i++;
        }
        if (cur == NULL)
        {
            printf("Given position doesn't exist\n");
            return h;
        }
        else
        {
            prev->next = cur->next;
            free(cur);
            return h;
        }
    }
}

struct node *delete_by_value(struct node *h, int v)
{

    if (h == NULL)
    {
        printf("Nothing to delete, linked list is empty\n");
        return h;
    }
    else if (v == h->val)
    {
        h = delete_first(h);
        return h;
    }
    else
    {
        struct node *prev = h, *cur = h;
        while (cur != NULL && v != cur->val)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur == NULL)
        {
            printf("Given value doesn't exist\n");
            return h;
        }
        else
        {
            prev->next = cur->next;
            free(cur);
            return h;
        }
    }
}

struct node *find_by_value(struct node *h, int v)
{

    if (h == NULL)
    {
        printf("linked list is empty\n");
        return h;
    }
    else
    {
        struct node *cur = h;
        int i = 1;
        while (cur != NULL && v != cur->val)
        {
            cur = cur->next;
            i++;
        }
        if (cur == NULL)
        {
            printf("%d doesn't exist in the list\n", v);
            return h;
        }
        else
        {
            printf("%d is present at position %d\n", v, i);
            return h;
        }
    }
}

struct node *find_by_pos(struct node *h, int pos)
{

    if (h == NULL)
    {
        printf("linked list is empty\n");
        return h;
    }
    else
    {
        struct node *cur = h;
        int i = 1;
        while (cur != NULL && i < pos)
        {
            cur = cur->next;
            i++;
        }
        if (cur == NULL)
        {
            printf("Given position doesn't exist\n");
            return h;
        }
        else
        {
            printf("Value at position %d is %d", pos, cur->val);
            return h;
        }
    }
}

void display(struct node *h)
{
    if (h == NULL)
        printf("List is empty, nothing to display\n");
    else
    {
        struct node *first = h;
        while (first != NULL)
        {
            printf("%d ", first->val);
            first = first->next;
        }
    }
}

void main()
{
    struct node *head = NULL;
    int pos, n, v;
    while (1)
    {
        printf("****MENU****\n");
        printf("1-Insert a node at desired position\n");
        printf("2-Insert a node sorted manner\n");
        printf("3-Display the linked list\n");
        printf("4-Delete a node by pos\n");
        printf("5-Delete a node by value\n");
        printf("6-Check no. of nodes present\n");
        printf("7-Value present at a position\n");
        printf("8-Position of a value\n");
        printf("9-Exit from the program\n");
        printf("Choose a number from among the above options\n");

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a value\n");
            scanf("%d", &n);
            if (head == NULL)
                head = insert_at_beg(head, n);
            else
            {
                printf("Enter a position\n");
                scanf("%d", &pos);
                head = insert_at_pos(head, n, pos);
            }
            printf("\n");
            break;

        case 2:
            printf("Enter a value\n");
            scanf("%d", &n);
            if (head == NULL)
                head = insert_at_beg(head, n);
            else
                head = insert_sort(head, n);
            printf("\n");
            break;

        case 3:
            display(head);
            printf("\n");
            break;

        case 4:
            printf("Enter the position to be deleted\n");
            scanf("%d", &pos);
            head = delete_by_pos(head, pos);
            printf("\n");
            break;

        case 5:
            printf("Enter the value to be deleted\n");
            scanf("%d", &v);
            head = delete_by_value(head, v);
            printf("\n");
            break;

        case 6:
            printf("%d", count_node(head));
            printf("\n");
            break;

        case 7:
            printf("Enter the position\n");
            scanf("%d", &pos);
            head = find_by_pos(head, pos);
            printf("\n");
            break;

        case 8:
            printf("Enter the value\n");
            scanf("%d", &v);
            head = find_by_value(head, v);
            printf("\n");
            break;

        case 9:
            exit(0);
            printf("\n");
            break;

        default:
            printf("Choose a correct option\n");
            printf("\n");
            break;
        }
    }
}