/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:35:23 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/03 11:37:55 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_normal(t_node **cur_a, t_node **cur_b, t_node **buf)
{
	if ((*cur_b)->stack == 'a')
		(*cur_b)->stack = 'b';
	else
		(*cur_b)->stack = 'a';
	*buf = (*cur_b)->next;
	(*cur_b)->next = *cur_a;
	(*cur_a)->prev = *cur_b;
	(*buf)->prev = NULL;
}

void	push_b_one(t_node **cur_a, t_node **cur_b)
{
	if ((*cur_b)->stack == 'a')
		(*cur_b)->stack = 'b';
	else
		(*cur_b)->stack = 'a';
	(*cur_b)->next = *cur_a;
	(*cur_a)->prev = *cur_b;
}

void	push_a_empty(t_node **cur_a, t_node **cur_b)
{
	if ((*cur_b)->stack == 'a')
		(*cur_b)->stack = 'b';
	else
		(*cur_b)->stack = 'a';
	*cur_a = *cur_b;
	if ((*cur_b)->next)
		(*cur_b)->next->prev = NULL;
	*cur_b = (*cur_b)->next;
	(*cur_a)->next = NULL;
}
