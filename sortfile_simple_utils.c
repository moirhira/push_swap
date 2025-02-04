/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfile_simple_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:42:58 by moirhira          #+#    #+#             */
/*   Updated: 2025/02/01 18:47:27 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"
#include "push_swap.h"

void	sort_three(t_stack *stacka)
{
	if (stacka->size != 3)
		return ;
	if (stacka->top->value > stacka->top->next->value)
		sa(stacka);
	if (stacka->top->next->value > stacka->top->next->next->value)
		rra(stacka);
	if (stacka->top->value > stacka->top->next->value)
		sa(stacka);
}

int	get_min(t_stack *stack, int *f)
{
	t_node	*current;

	int (i), (min_index), (min);
	i = 0;
	min_index = 0;
	min = stack->top->value;
	current = stack->top;
	while (current)
	{
		if (min > current->value)
		{
			min = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	if (min_index <= stack->size / 2)
		*f = 1;
	else
		*f = 0;
	return (min);
}

void	sortonfour(t_stack *stacka, t_stack *stackb)
{
	int (f), (i), (rep);
	i = 0;
	rep = 2;
	if (stacka->size == 4)
		rep = 1;
	while (i < rep)
	{
		while (stacka->top->value != get_min(stacka, &f))
		{
			if (f == 1)
			{
				rotate(stacka);
				ft_printf("ra\n");
			}
			else
				rra(stacka);
		}
		if (stacka->top->value == get_min(stacka, &f))
			pb(stacka, stackb);
		i++;
	}
	sort_three(stacka);
	while (rep--)
		pa(stacka, stackb);
}

int	find_max(t_stack *stack)
{
	t_node	*current;

	int (i), (max);
	i = 0;
	max = stack->top->value;
	current = stack->top;
	while (current)
	{
		if (max < current->value)
		{
			max = current->value;
		}
		current = current->next;
		i++;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	t_node	*current;

	int (i), (min);
	i = 0;
	min = stack->top->value;
	current = stack->top;
	while (current)
	{
		if (min > current->value)
		{
			min = current->value;
		}
		current = current->next;
		i++;
	}
	return (min);
}
