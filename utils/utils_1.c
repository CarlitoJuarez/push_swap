/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:08:36 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/03 11:09:42 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

long	nr_of_str(char *argv)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (argv[i])
	{
		if ((i == 0 && !is_(argv[i]))
			|| (is_(argv[i - 1]) && !is_(argv[i])))
			size++;
		i++;
	}
	return (size);
}

void	free_list(t_node *root)
{
	t_node	*curr;
	t_node	*buf;

	curr = root;
	while (curr)
	{
		buf = curr;
		curr = curr->next;
		free(buf);
	}
	buf = NULL;
	root = NULL;
}

void	free_set(char **set)
{
	int	i;

	i = 0;
	while (*(set + i))
	{
		free(*(set + i));
		*(set + i) = NULL;
		i++;
	}
	free(set);
}
