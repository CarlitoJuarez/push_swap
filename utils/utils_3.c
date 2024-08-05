/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:13:28 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/03 11:15:06 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	send_a_up(t_node **root_a, t_node **root_b, t_node *target, int pos)
{
	if (target->position < (len_of(*root_b) / 2))
	{
		while (pos && target->position)
		{
			exec_rotate(root_a);
			exec_rotate(root_b);
			ft_printf("rr\n");
			pos--;
			target->position--;
		}
		while (target->position)
		{
			exec_rotate(root_b);
			ft_printf("rb\n");
			target->position--;
		}
	}
	else
	{
		while (target->position != len_of(*root_b))
		{
			exec_rrotate(root_b);
			ft_printf("rrb\n");
			target->position++;
		}
	}
	while (pos)
	{
		exec_rotate(root_a);
		ft_printf("ra\n");
		pos--;
	}
}

void	send_a_down(t_node **root_a, t_node **root_b, t_node *target, int pos)
{
	if (target->position > (len_of(*root_b) / 2))
	{
		while (pos != len_of(*root_a) && target->position != len_of(*root_b))
		{
			exec_rrotate(root_a);
			exec_rrotate(root_b);
			ft_printf("rrr\n");
			pos++;
			target->position++;
		}
		while (target->position != len_of(*root_b))
		{
			exec_rrotate(root_b);
			ft_printf("rrb\n");
			target->position++;
		}
	}
	else 
	{
		while (target->position)
		{
			exec_rotate(root_b);
			ft_printf("rb\n");
			target->position--;
		}
	}
	while (pos != len_of(*root_a))
	{
		exec_rrotate(root_a);
		ft_printf("rra\n");
		pos++;
	}
}

void	bring_to_start(t_node **root_a, t_node **root_b)
{
	int len;
	int pos;
	t_node *cheapest;
	t_node *target;

	cheapest = find_cheapest(*root_a);
	target = cheapest->target;
	len = len_of(*root_a);
	pos = cheapest->position;
	// 3 5 22 24
	// 6 9 21
	if (pos < (len / 2))
		send_a_up(root_a, root_b, target, pos);
	else
		send_a_down(root_a, root_b, target, pos);
}

int	len_of(t_node *root)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = root;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

t_node	*find_max(t_node *root)
{
	t_node	*cur;
	t_node	*max;

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

t_node	*find_min(t_node *root)
{
	t_node	*cur;
	t_node	*min;

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

t_node	*find_cheapest(t_node *root)
{
	t_node	*cur;
	t_node	*min;

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
