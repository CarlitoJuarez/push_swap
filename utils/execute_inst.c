/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_inst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:19:20 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/03 11:33:00 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exec_swap(t_node **root)
{
	t_node	*buf;
	t_node	*cur;

	if ((*root)->stack)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	cur = *root;
	buf = cur->next;
	cur->next = buf->next;
	if (buf->next != NULL)
		buf->next->prev = cur;
	buf->next = cur;
	buf->prev = NULL;
	cur->prev = buf;
	*root = buf;
}

void	exec_push(t_node **root_a, t_node **root_b)
{
	t_node	*buf;
	t_node	*cur_a;
	t_node	*cur_b;

	cur_a = *root_a;
	cur_b = *root_b;
	buf = NULL;
	if (cur_a && cur_b && cur_b->next)
	{
		push_normal(&cur_a, &cur_b, &buf);
		*root_a = cur_b;
		*root_b = buf;
	}
	else if (cur_a && cur_b && !cur_b->next)
	{
		push_b_one(&cur_a, &cur_b);
		*root_a = cur_b;
		*root_b = NULL;
	}
	else if (!cur_a && cur_b)
	{
		push_a_empty(&cur_a, &cur_b);
		*root_a = cur_a;
		*root_b = cur_b;
	}
}

void	exec_rrotate(t_node **root)
{
	t_node	*buf;
	t_node	*cur;

	cur = *root;
	buf = cur;
	if ((*root)->stack == 'a')
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
	while (buf)
	{
		if (buf->next)
			buf = buf->next;
		else
			break ;
	}
	buf->prev->next = NULL;
	buf->next = cur;
	cur->prev = buf;
	buf->prev = NULL;
	*root = buf;
}

void	exec_rotate(t_node **root)
{
	t_node	*buf;
	t_node	*cur;

	if ((*root)->stack == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	cur = *root;
	buf = cur;
	while (buf)
	{
		if (buf->next)
			buf = buf->next;
		else
			break ;
	}
	buf->next = cur;
	cur->prev = buf;
	cur->next->prev = NULL;
	*root = cur->next;
	cur->next = NULL;
}
