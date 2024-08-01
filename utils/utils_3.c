#include "../push_swap.h"

int len_of(node *root)
{
    int i;
    node *cur;

    i = 0;
    cur = root;
    while (cur)
    {
        i++;
        cur = cur->next;
    }
    return (i);
}

node *find_max(node *root)
{
    node *cur;
    node *max;

    cur = root;
    max = cur;
    cur = cur->next;
    while (cur)
    {
        if (cur->val > max->val)
            max = cur;
        cur = cur->next;
    }
    return (max);
}

node *find_min(node *root)
{
    node *cur;
    node *min;

    cur = root;
    min = cur;
    cur = cur->next;
    while (cur)
    {
        if (cur->val < min->val)
            min = cur;
        cur = cur->next;
    }
    return (min);
}

node *find_cheapest(node *root)
{
    node *cur;
    node *min;

    cur = root;
    min = cur;
    cur = cur->next;
    while (cur)
    {
        if (cur->price < min->price)
            min = cur;
        cur = cur->next;
    }
    return (min);
}

void bring_to_start(int pos, int len, node **root)
{
    if (pos < (len / 2 + 1))
        while (pos)
        {
            exec_rotate(root);
            pos--;
        }
    else
        while ((len - pos))
        {
            exec_rrotate(root);
            pos++;
        }
}