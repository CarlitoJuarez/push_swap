/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:43:56 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/03 11:01:39 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_it(t_node *root)
{
	t_node	*cur;

	cur = root;
	while (cur)
	{
		printf("VAL: %d\n", cur->val);
		cur = cur->next;
	}
}

void	push_to_b(t_node **root_a, t_node **root_b)
{
	ft_printf("pb\n");
	exec_push(root_b, root_a);
	ft_printf("pb\n");
	exec_push(root_b, root_a);
	// long	len;

	// len = len_of(*root_a) + 1;
	// while (--len > 3)
	// {
	// 	ft_printf("pb\n");
	// 	exec_push(root_b, root_a);
	// }
}

void	push_swap(t_node **root)
{
	long	len;
	t_node	*root_a;
	t_node	*root_b;
	t_node	*min;

	root_a = *root;
	root_b = NULL;
	// if (len_of(root_a) >= 5)
	// {
	// 	push_to_b(&root_a, &root_b);
	// 	while (len_of(root_a) > 3)
	// 	{
	// 		init_nodes(root_b, root_a);
	// 		exec_algo(&root_a, &root_b);
	// 	}
	// }
	// else if (len_of(root_a) == 4)
	// {
	// 	ft_printf("pb\n");
	// 	exec_push(&root_b, &root_a);
	// }
	while (len_of(root_a) > 3)
	{
		ft_printf("pb\n");
		exec_push(&root_b, &root_a);
	}
	three_nodes(&root_a);
	while (len_of(root_b))
	{
		init_nodes(root_a, root_b);
		exec_algo_2(&root_a, &root_b);
	}
	// print_it(root_a);
	min = find_min(root_a);
	len = len_of(root_a);
	init_nodes(root_a, root_b);
	if (min->position < (len / 2))
	{
		while (root_a != min)
		{
			exec_rotate(&root_a);
			ft_printf("ra\n");
		}
		min->position--;
	}
	else
	{
		while (len != min->position)
		{
			exec_rrotate(&root_a);
			ft_printf("rra\n");
			min->position++;
		}
	}
	// print_it(root_a);
}

t_node	*arr_to_ll(char **argv)
{
	int		i;
	t_node	*new_node;
	t_node	*curr;
	t_node	*root;

	i = -1;
	curr = NULL;
	root = NULL;
	while (argv[++i])
	{
		new_node = malloc(sizeof(t_node) * 1);
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

char	**str_to_arr(char *argv)
{
	char			**arr;
	unsigned int	i;
	int				j;
	int				k;

	i = nr_of_str(argv);
	arr = malloc(sizeof(char *) * (i + 1));
	arr[i] = 0;
	k = 0;
	i = -1;
	while (argv[++i])
	{
		if ((i == 0 && !is_(argv[i])) || (is_(argv[i - 1]) && !is_(argv[i])))
		{
			j = i;
			while (argv[j] && !is_(argv[j]))
				j++;
			arr[k++] = malloc(sizeof(char) * j + 1);
			arr[k - 1][j] = 0;
			j = 0;
			while (argv[i] && !is_(argv[i]))
				arr[k - 1][j++] = argv[i++];
		}
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	t_node	*root_a;
	char	**arr;

	root_a = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (0);
	if (!argv[2])
		arr = str_to_arr(*(argv + 1));
	else
		arr = argv + 1;
	if (!valid_input(arr) || !in_range(arr))
		return (write(1, "Error\n", 6), 0);
	else
	{
		print_it(root_a);
		root_a = arr_to_ll(arr);
		if (duplicates(root_a))
			return (write(1, "Error\n", 6), 0);
		if (is_sorted(root_a))
			return (0);
		else
			push_swap(&root_a);
	}
}
