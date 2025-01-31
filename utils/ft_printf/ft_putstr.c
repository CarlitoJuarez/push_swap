/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:32:25 by cjuarez           #+#    #+#             */
/*   Updated: 2024/07/22 16:32:26 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!(s))
	{
		s = "(null)";
		ft_putstr(s);
		return (6);
	}
	while (*(char *)(s + i))
	{
		write(1, s + i, 1);
		i++;
	}
	return (i);
}
