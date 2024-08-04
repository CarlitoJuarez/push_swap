/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:09:52 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/03 11:13:15 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	valid_input(char **argv)
{
	int		i;
	int		j;
	char	*s;

	i = 1;
	while (argv[i])
	{
		j = 0;
		s = argv[i];
		while (*(s + j))
		{
			if (j == 0 && (*s == '-' || *s == '+'))
				j++;
			if (!(*(s + j) >= '0' && *(s + j) <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	duplicates(t_node *root)
{
	t_node	*cur;
	t_node	*buf;

	cur = root;
	while (cur)
	{
		buf = cur->next;
		while (buf)
		{
			if (buf->val == cur->val)
				return (1);
			buf = buf->next;
		}
		cur = cur->next;
	}
	return (0);
}

int	in_range(char **str)
{
	unsigned int	i;
	unsigned int	j;
	int				sign;
	long			check;

	j = -1;
	while ((str[++j]))
	{
		sign = 1;
		i = 0;
		if (*(str[j] + i) == '-' || *(str[j] + i) == '+')
		{
			if (*(str[j] + i) == '-')
				sign = -1;
			i++;
		}
		check = 0;
		while (*(str[j] + i))
			check = check * 10 + (*(str[j] + i++) - '0');
		check *= sign;
		if (check < INT_MIN || check > INT_MAX)
			return (0);
	}
	return (1);
}

int	comp_str(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_node *root)
{
	t_node	*cur;
	t_node	*buf;

	cur = root;
	while (cur)
	{
		buf = cur->next;
		while (buf)
		{
			if (cur->val > buf->val)
				return (0);
			buf = buf->next;
		}
		cur = cur->next;
	}
	return (1);
}
