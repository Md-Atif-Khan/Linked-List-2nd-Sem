#include <stdio.h>
#include <stdlib.h>
#include <process.h>

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
    struct node *first = h, *t;
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
        struct node *prev = h, *cur = h;
        int i = 1;
        while (cur != NULL && i < pos)
        {
            prev = cur;
            cur = cur->next;
            i++;
        }
        if (cur == NULL)
            printf("No such pos exists\n");
        else
        {
            prev->next = t;
            t->next = cur;
        }
        return h;
    }
}

struct node *insert_sort(struct node *h, int n)
{
    struct node *t;
    t = create_node(n);
    if (h == NULL)
        return t;
    else if (h->val > n)
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
        struct node *first = h;
        h = h->next;
        free(first);
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
        struct node *prev = h, *cur = h;
        while (cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
    }
    return h;
}

struct node *delete_by_val(struct node *h, int n)
{
    if (h == NULL)
        printf("List is empty, nothing to delete\n");
    else
    {
        struct node *prev = h, *cur = h;
        while (cur != NULL && n != cur->val)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur == NULL)
            printf("Given position doesn't exist\n");
        else
        {
            prev->next = cur->next;
            free(cur);
        }
    }
    return h;
}

struct node *delete_by_pos(struct node *h, int pos)
{
    if (h == NULL)
        printf("List is empty, nothing to delete\n");
    else if (pos == 1)
        delete_first(h);
    else
    {
        int i = 1;
        struct node *prev = h, *cur = h;
        while (cur != NULL && i < pos)
        {
            prev = cur;
            cur = cur->next;
            i++;
        }
        if (cur == NULL)
            printf("Given position doesn't exist\n");
        else
        {
            prev->next = cur->next;
            free(cur);
        }
    }
    return h;
}

void display(struct node *h)
{
    if (h == NULL)
        printf("Nothing to display, list is empty\n");
    else
    {
        struct node *first = h;
        while (first != NULL)
        {
            printf("%d ", first->val);
            first = first->next;
        }
        printf("\n");
    }
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int n, pos, head;
    while (1)
    {
        printf("insert value\n");
        scanf("%d", &n);
        printf("In which list [1/2]\n");
        scanf("%d", &head);
        if (head == 1)
        {
            if (n > 0)
            {
                if (head1 == NULL)
                {
                    head1 = insert_at_beg(head1, n);
                }
                else
                {
                    printf("Enter the position\n");
                    scanf("%d", &pos);
                    head1 = insert_at_pos(head1, n, pos);
                }
            }
            else
                exit(0);
        }
        else
        {
            if (n > 0)
            {
                if (head2 == NULL)
                {
                    head2 = insert_at_beg(head2, n);
                }
                else
                {
                    printf("Enter the position\n");
                    scanf("%d", &pos);
                    head2 = insert_at_pos(head2, n, pos);
                }
            }
            else
                exit(0);
        }
        display(head1);
        printf("\n");
        display(head2);
        printf("\n");
    }
}