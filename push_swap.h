/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:02:23 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/03 11:06:05 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

typedef struct node
{
	char			stack;
	int				val;

	int				position;
	int				up;
	int				price;

	struct node		*next;
	struct node		*prev;

	struct node		*target;
}	t_node;

void	print_it(t_node *root);

// utils_1

int		is_(char c);

long	nr_of_str(char *argv);

void	free_list(t_node *root);
void	free_set(char **set);

// utils_2

int		valid_input(char **argv);
int		duplicates(t_node *root);
int		in_range(char **str);
int		comp_str(char *s1, char *s2);
int		is_sorted(t_node *root);

// utils_3

void	bring_to_start(t_node **root_a, t_node **root_b);
void	bring_to_start_2(t_node **root_a, t_node **root_b);

int		len_of(t_node *root);

t_node	*find_max(t_node *root);
t_node	*find_min(t_node *root);
t_node	*find_cheapest(t_node *root);

// push_util

void	push_normal(t_node **cur_a, t_node **cur_b, t_node **buf);
void	push_b_one(t_node **cur_a, t_node **cur_b);
void	push_a_empty(t_node **cur_a, t_node **cur_b);

// Init Nodes

void	set_pos(t_node *root);
void	set_target(t_node *root_a, t_node *root_b);
void	set_price_a(t_node *root_a, t_node *root_b);
void	init_nodes(t_node *root_a, t_node *root_b);

// Algos

void	exec_algo(t_node **root_a, t_node **root_b);
void	exec_algo_2(t_node **root_a, t_node **root_b);
void	three_nodes(t_node **root);
void	rev_three_nodes(t_node **root);

// Instructions

void	exec_swap(t_node **root);
void	exec_push(t_node **root_a, t_node **root_b);
void	exec_rotate(t_node **root);
void	exec_rrotate(t_node **root);

// Push Swap

void	push_swap(t_node **root);

// FT_PRINTF

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putaddress(void *p);
int		ft_puthexa(unsigned int n, const char c);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned long n);

char	*ft_strchr(const char *s, int c);

#endif
