#include "../push_swap.h"

void	send_b_up(t_node **root_a, t_node **root_b, t_node *target, int pos)
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
			ft_printf("ra\n");
			target->position--;
		}
	}
	else
	{
		while (target->position != len_of(*root_b))
		{
			exec_rrotate(root_b);
			ft_printf("rra\n");
			target->position++;
		}
	}
	while (pos)
	{
		exec_rotate(root_a);
		ft_printf("rb\n");
		pos--;
	}
}

void	send_b_down(t_node **root_a, t_node **root_b, t_node *target, int pos)
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
			ft_printf("rra\n");
			target->position++;
		}
	}
	else
	{
		while (target->position)
		{
			exec_rotate(root_b);
			ft_printf("ra\n");
			target->position--;
		}
	}
	while (pos != len_of(*root_a))
	{
		exec_rrotate(root_a);
		ft_printf("rrb\n");
		pos++;
	}
}


void	bring_to_start_2(t_node **root_a, t_node **root_b)
{
	int len;
	int pos;
	t_node *cheapest;
	t_node *target;

	cheapest = find_cheapest(*root_a);
	target = cheapest->target;
	len = len_of(*root_b);
	pos = cheapest->position;
	if (pos < (len / 2))
		send_b_up(root_a, root_b, target, pos);
	else
		send_b_down(root_a, root_b, target, pos);    
}