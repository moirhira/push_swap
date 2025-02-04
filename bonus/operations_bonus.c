/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <moirhira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:33:23 by moirhira          #+#    #+#             */
/*   Updated: 2025/02/01 13:37:02 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->top != NULL)
	{
		temp = stack->top->value;
		stack->top->value = stack->top->next->value;
		stack->top->next->value = temp;
	}
	else
		exit(0);
}

void	ss(t_stack *stacka, t_stack *stackb)
{
	swap(stacka);
	swap(stackb);
}

void	pa(t_stack *stacka, t_stack *stackb)
{
	t_node	*tempb;

	if (stackb->top != NULL)
	{
		tempb = stackb->top;
		stackb->top = stackb->top->next;
		tempb->next = stacka->top;
		stacka->top = tempb;
		stacka->size++;
		stackb->size--;
	}
}

void	pb(t_stack *stacka, t_stack *stackb)
{
	t_node	*tempa;

	if (stacka->top != NULL)
	{
		tempa = stacka->top;
		stacka->top = stacka->top->next;
		tempa->next = stackb->top;
		stackb->top = tempa;
		stacka->size--;
		stackb->size++;
	}
}

void	rrr(t_stack *stacka, t_stack *stackb)
{
	if (!stacka || !stackb)
		return ;
	rra(stacka);
	rrb(stackb);
}
