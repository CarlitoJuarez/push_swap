#include "../push_swap.h"

void set_pos(node *root)
{
    node    *cur;
    int     i;

    i = 0;
    cur = root;
    while (cur)
    {
        cur->position = i;
        cur = cur->next;
        i++;
    }
    cur = NULL;
}

void set_target(node *root_a, node *root_b)
{
    node    *cur;
    node    *tar;
    long    best;

    while (root_b)
    {
        best = LONG_MAX;
        cur = root_a;
        while (cur)
        {
            if ( cur->val > root_b->val && cur->val < best )
            {
                best = cur->val;
                tar = cur;
            }
            cur = cur->next;
        }
        if (best == LONG_MAX)
            root_b->target = find_min(root_a);
        else
            root_b->target = tar;
        root_b = root_b->next;
    }
}

void set_price(node *root_a, node *root_b)
{
    int len;
    node *cur;

    len = len_of(root_a);
    cur = root_a;
    while (cur)
    {
        if (cur->position < len / 2)
            cur->price = cur->position;
        else
            cur->price = len - cur->position;
        cur = cur->next;
    }
    cur = root_b;
    len = len_of(root_b);
    while (cur)
    {
        if (cur->position < len / 2)
            cur->price = cur->position + cur->target->price;
        else
            cur->price = ( len - cur->position ) + cur->target->price;
        cur = cur->next;
    }
}
