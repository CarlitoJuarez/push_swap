/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:33:16 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/03 11:34:41 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_pos(t_node *root)
{
	t_node	*cur;
	int		i;

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

void	set_target(t_node *root_a, t_node *root_b)
{
	t_node	*cur;
	t_node	*tar;
	long	best;

	while (root_b)
	{
		best = LONG_MAX;
		cur = root_a;
		while (cur)
		{
			if (cur->val > root_b->val && cur->val < best)
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

void	set_price_b(t_node *root_b)
{
	int len;
	t_node *cur;

	cur = root_b;
	len = len_of(root_b);
	while (cur)
	{
		if (cur->position < len / 2)
		{
			if (cur->target->up == 1)
			{
				if (cur->position > cur->target->price)
					cur->price = cur->position;
				else
					cur->price = cur->target->price;
			}
			else
				cur->price = cur->position + cur->target->price;
		}
		else 
		{
			if (cur->target->up == 0)
			{
				if (cur->position > cur->target->price)
					cur->price = len - cur->position;
				else
					cur->price = cur->target->price;
			}
			else
				cur->price = (len - cur->position) + cur->target->price;
		}
		cur = cur->next;
	}
}

void	set_price_a(t_node *root_a, t_node *root_b)
{
	int		len;
	t_node	*cur;

	len = len_of(root_a);
	cur = root_a;
	while (cur)
	{
		if (cur->position < len / 2)
		{
			cur->price = cur->position;
			cur->up = 1;
		}
		else
		{
			cur->price = len - cur->position;
			cur->up = 0;
		}
		cur = cur->next;
	}
	set_price_b(root_b);
}

void	init_nodes(t_node *root_a, t_node *root_b)
{
	set_pos(root_a);
	set_pos(root_b);
	set_target(root_a, root_b);
	set_price_a(root_a, root_b);
}
