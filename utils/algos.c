/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:07:15 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/03 11:08:20 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	exec_algo_1(t_node **root_a, t_node **root_b)
// {
// 	t_node	*cheapest;
// 	t_node	*cur;
// 	int		len;
// 	int		pos;

// 	len = len_of(*root_b);
// 	// if (len == 3)
// 	// // 	rev_three_nodes(root_b);
// 	// if (len == 2 && (*root_b)->val < (*root_b)->next->val)
// 	// {
// 	// 	ft_printf("sb");
// 	// 	exec_swap(root_b);
// 	// }
// 	cheapest = find_cheapest(*root_b);
// 	pos = cheapest->position;
// 	bring_to_start(pos, len, root_b);
// 	cur = cheapest->target;
// 	pos = cur->position;
// 	len = len_of(*root_a);
// 	bring_to_start(pos, len, root_a);
// 	ft_printf("pa\n");
// 	exec_push(root_a, root_b);
// }

int next_higher(int val_b, int val_next, t_node **root_a)
{
	t_node *cur_a;

	cur_a = *root_a;
	while (cur_a)
	{
		if (cur_a->val < val_next && cur_a->val > val_b)
			return (0);
		cur_a = cur_a->next;
	}
	return (1);
}

// void exec_algo_2(t_node **root_a, t_node **root_b)
// {
// 	t_node *cur_a;
// 	t_node *cur_b;
// 	t_node *last;

// 	/// 1 2 4 10
// 	/// 3 6 9 14 25

// 	/// 35 37 32
// 	/// 6

// 	// 3 4 1
// 	// 2

// 	// 4 3 1 --> 1 4 3 --> 2 1 4 3 
// 	// 2

// 	while (len_of(*root_b))
// 	{
// 		cur_a = *root_a;
// 		cur_b = *root_b;
// 		last = cur_a;
// 		print_it(*root_a);
// 		while (last->next)
// 			last = last->next;
// 		if (cur_a->val < cur_b->val && next_higher(cur_b->val, last->val, root_a))
// 		{
// 			ft_printf("pa\n");
// 			exec_push(root_a, root_b);
// 		}
// 		else if (cur_a->val < cur_b->val && !next_higher(cur_b->val, last->val, root_a))
// 		{
// 			ft_printf("ra\n");
// 			exec_rotate(root_a);
// 		}
// 		else if (last->val < cur_b->val && next_higher(cur_b->val, cur_a->val, root_a))
// 		{
// 			ft_printf("pa\n");
// 			exec_push(root_a, root_b);
// 		}
// 		else if (last->val < cur_b->val && !next_higher(cur_b->val, cur_a->val, root_a))
// 		{
// 			ft_printf("rra\n");
// 			exec_rrotate(root_a);
// 		}
// 	}
// }

void exec_algo(t_node **root_a, t_node **root_b)
{
	// printf("A: \n");
	// print_it(*root_a);
	// printf("B: \n");
	// print_it(*root_b);
	// printf("\n");
	bring_to_start(root_a, root_b);
	ft_printf("pb\n");
	exec_push(root_b, root_a);
}

void exec_algo_2(t_node **root_a, t_node **root_b)
{
	// printf("A2: \n");
	// print_it(*root_a);
	// printf("B2: \n");
	// print_it(*root_b);
	// printf("\n");
	bring_to_start_2(root_b, root_a);
	ft_printf("pa\n");
	exec_push(root_a, root_b);
}

void	three_nodes(t_node **root)
{
	t_node	*max;

	max = find_max(*root);
	if (*root == max)
		exec_rotate(root);
	else if ((*root)->next == max)
		exec_rrotate(root);
	if ((*root)->val > (*root)->next->val)
		exec_swap(root);
}

void	rev_three_nodes(t_node **root)
{
	t_node	*min;

	min = find_min(*root);
	if (*root == min)
		exec_rotate(root);
	else if ((*root)->next == min)
		exec_rrotate(root);
	if ((*root)->val < (*root)->next->val)
		exec_swap(root);
}
