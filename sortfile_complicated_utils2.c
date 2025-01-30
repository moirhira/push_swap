/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complicated_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:42:09 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/24 13:42:11 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"
#include "push_swap.h"

void	final_rotation(t_stack *stack_a)
{
	int max_index;
    
    max_index = find_index(stack_a, find_min(stack_a));
	if (max_index <= stack_a->size / 2)
	{
		while (max_index-- > 0)
		{
			ra(stack_a);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (max_index++ < stack_a->size)
			rra(stack_a);
	}
}

int is_sorted(t_stack *stack)
{
    int flag;
    t_node *curent;

    if(!stack || !stack->top)
        return(0);
    flag = 1;
    curent = stack->top;
    while (curent->next)
    {
        if (curent->value < curent->next->value)
            curent = curent->next;
        else
        {
            flag = 0;
            return (flag);
        }
    }
    return (flag);
}

int	find_index(t_stack *stack, int nbr)
{
	int		index;
	t_node	*tmp;

	index = 0;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->value == nbr)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (-1);
}