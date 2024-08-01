#include "push_swap.h"

void print_it(node *root)
{
    node *cur;

    cur = root;
    while (cur)
    {
        printf("VAL: %d\n", cur->val);
        // printf("STACK %c\n", cur->stack);
        cur = cur->next;
    }
}

void init_nodes(node *root_a, node *root_b)
{
    set_pos(root_a);
    set_pos(root_b);
    set_target(root_a, root_b);
    set_price(root_a, root_b);
}

void    push_to_b(node **root_a, node **root_b)
{
    long len;

    len = len_of(*root_a) + 1;
    while (--len > 3)
    {
        ft_printf("pb\n");
        exec_push(root_b, root_a);
    }
}

void push_swap(node **root)
{
    long len;
    node *root_a;
    node *root_b;
    node *min;

    root_a = *root;
    root_b = NULL;
    push_to_b(&root_a, &root_b);
    three_nodes(&root_a);
    // printf("A: \n");
    // print_it(root_a);
    // printf("B: \n");
    // print_it(root_b);
    while (root_b)
    {
        init_nodes(root_a, root_b);
        exec_algo(&root_a, &root_b);
        // printf("A: \n");
        // print_it(root_a);
        // printf("B: \n");
        // print_it(root_b);
    }
    set_pos(root_a);
    min = find_min(root_a);
    len = len_of(root_a);
    if (min->position < len / 2)
        while (root_a != min)
            exec_rotate(&root_a);
    else
        while (root_a != min)
            exec_rrotate(&root_a);
    // print_it(root_a);
}

node *create_list(char **argv)
{
    int     i;
    node    *new_node;
    node    *curr;
    node    *root;

    i = -1;
    curr = NULL;
    root = NULL;
    while (argv[++i])
    {
        new_node = malloc(sizeof(node) * 1);
        if (!new_node)
            return (NULL);
        new_node->val = atoi(argv[i]);
        new_node->stack = 'a';
        new_node->next = NULL;
        if (curr)
            curr->next = new_node;
        new_node->prev = curr;
        curr = new_node;
        if (i == 0)
            root = curr;
    }
    return (root);
}

long nr_of_str(char *argv)
{
    unsigned int i;
    unsigned int size;
    
    i = 0;
    size = 0;
    while (argv[i])
    {
        if ((i == 0 && !is_space(argv[i])) || (is_space(argv[i - 1]) && !is_space(argv[i])))
            size++;
        i++;
    }
    return (size);
}

// void alloc_str(char *argv, char **arr)
// {
//     unsigned int i;
//     unsigned int j;
//     unsigned int k;

//     i = 0;
//     while (argv[i])
//     {
//         if ((i == 0 && !is_space(argv[i])) || (is_space(argv[i - 1]) && !is_space(argv[i])))
//         {
//             j = i;
//             while (argv[j] && !is_space(argv[j]))
//                 j++;
//             arr[k++] = malloc(sizeof(char) * j + 1);
//             arr[k - 1][j] = 0;
//             j = 0;
//             while (argv[i] && !is_space(argv[i]))
//                 arr[k - 1][j++] = argv[i++];
//         }
//     }

// }

char **create_list_test(char *argv)
{
    char    **arr;
    unsigned int     i;
    int     j;
    int     k;

    i = nr_of_str(argv);
    arr = malloc(sizeof(char *) * (i + 1));
    arr[i] = 0;
    k = 0;
    i = -1;
    while (argv[++i])
    {
        if ((i == 0 && !is_space(argv[i])) || (is_space(argv[i - 1]) && !is_space(argv[i])))
        {
            j = i;
            while (argv[j] && !is_space(argv[j]))
                j++;
            arr[k++] = malloc(sizeof(char) * j + 1);
            arr[k - 1][j] = 0;
            j = 0;
            while (argv[i] && !is_space(argv[i]))
                arr[k - 1][j++] = argv[i++];
        }
    }
    return (arr);
}

int main(int argc, char **argv)
{
    node *root_a;
    char **arr;

    root_a = NULL;
    if (1 == argc || (2 == argc && !argv[1][0]))
        return (0);
    if (!argv[2])
        arr = create_list_test(*(argv + 1));
    else
        arr = argv;
    if (!valid_input(arr) || !in_range(arr))
        return (write(1, "Error\n", 6), 0);
    else
    {

        root_a = create_list(arr);
        // print_it(root_a);
        if (duplicates(root_a))
            return (write(1, "Error\n", 6), 0);
        if (is_sorted(root_a))
            return (0);
        else
        {
            push_swap(&root_a);
            // if (is_sorted(root_a))
            //     printf("Sorted!!!\n");
            // else
            //     printf("KO\n");
        }
    }
}
