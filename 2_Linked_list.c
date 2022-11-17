#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};

struct node *create_node(int v)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->val = v;
    temp->next = NULL;
    return temp;
}

struct node *insert_at_beg(struct node *h, int v)
{
    struct node *t;
    t = create_node(v);

    if (h == NULL)
        return t;
    else
    {
        t->next = h;
        h = t;
        return h;
    }
}

struct node *insert_at_end(struct node *h, int v)
{
    struct node *t, *first;
    t = create_node(v);

    if (h == NULL)
        return t;
    else
    {
        first = h;
        while (h->next != NULL)
            h = h->next;

        h->next = t;
    }
    return first;
}
int count_node(struct node *h)
{
    int count = 0;
    while (h != NULL)
    {
        count++;
        h = h->next;
    }
    return count;
}

struct node *insert_at_pos(struct node *h, int v, int pos)
{
    struct node *t, *prev, *cur;
    int count, i;
    t = create_node(v);
    if (pos == 1)
    {
        if (h == NULL)
            return t;
        else
            h = insert_at_beg(h, v);
    }
    else
    {
        prev = cur = h;
        while (i < pos)
        {
            prev = cur;
            cur = cur->next;
            i++;
        }
        prev->next = t;
        t->next = cur;
    }

    return h;
}
struct node *insert_sort(struct node *h, int v)
{
    struct node *t, *prev, *cur;
    int count, i;
    t = create_node(v);
    if (h == NULL)
        return t;
    else if (h->val > v)
        h = insert_at_beg(h, v);
    else
    {
        prev = cur = h;
        while (cur != NULL && v > cur->val)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = t;
        t->next = cur;
    }
    return h;
}
struct node *delete_first(struct node *h)
{
    struct node *t;
    if (h == NULL)
    {
        printf("\n List does not exist");
        return NULL;
    }
    else
    {
        t = h;
        h = h->next;
        free(t);
        return h;
    }
}
void display_list(struct node *h)
{
    while (h != NULL)
    {
        printf("%d->", h->val);
        h = h->next;
    }
}

struct node *link_two_list(struct node *h1, struct node *h2)
{
    struct node *first=h1;
    while(h1->next!=NULL)
        h1=h1->next;
    h1->next=h2;
    return first;
}

void main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int n, pos;

    while (1)
    {
        printf("\n Enter any positive integer:");
        scanf("%d", &n);
        if (n < 0)
            break;
        else
        {
            printf("\n Enter the choice of linked list [1 or 2]:");
            scanf("%d", &pos);
            if (pos == 1)
            {
                if (head1 == NULL)
                    head1 = create_node(n);
                else
                {
                    // printf("\n Enter the position:");
                    // scanf("%d", &pos);
                    head1 = insert_sort(head1, n);
                }
            }
            else
            {
                if (pos == 2)
                    if (head2 == NULL)
                        head2 = create_node(n);
                    else
                    {
                        head2 = insert_sort(head2, n);
                    }
                else
                {
                    printf("\n Your choice of linked list is invalid");
                    printf("\n Try again in 1 or 2");
                }
            }
            printf("Head1->");
            display_list(head1);
            printf("\n");
            printf("Head2->");
            display_list(head2);
        }
    }
    // *********Deleting one by one the elements of 1st linked list********
    //  while (head1 != NULL)
    //  {
    //      head1 = delete_first(head1);
    //      printf("\n");
    //      display_list(head1);
    //  }
    //  printf("NULL");

    //********Linking two different linked list********
    head1=link_two_list(head1,head2);
    display_list(head1);
    printf("\n");
    head2=NULL;
    display_list(head2);
}