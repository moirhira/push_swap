/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:33:23 by moirhira          #+#    #+#             */
/*   Updated: 2025/02/01 12:19:54 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

void	ra(t_stack *stacka)
{
	t_node	*tempa;
	t_node	*ptr;

	if (stacka->size < 2)
	{
		exit(1);
	}
	tempa = stacka->top;
	stacka->top = stacka->top->next;
	ptr = stacka->top;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tempa;
	ptr->next->next = NULL;
}

void	rb(t_stack *stackb)
{
	t_node	*tempb;
	t_node	*ptr;

	if (stackb->size < 2)
	{
		exit(1);
	}
	tempb = stackb->top;
	stackb->top = stackb->top->next;
	ptr = stackb->top;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = tempb;
	ptr->next->next = NULL;
}

void	rr(t_stack *stacka, t_stack *stackb)
{
	if (!stacka || !stackb)
		return ;
	ra(stacka);
	rb(stackb);
}

void	rra(t_stack *stacka)
{
	t_node	*last_elm;
	t_node	*ptr;

	if (stacka->size < 2)
	{
		exit(1);
	}
	ptr = stacka->top;
	while (ptr->next->next)
		ptr = ptr->next;
	last_elm = ptr->next;
	ptr->next = NULL;
	last_elm->next = stacka->top;
	stacka->top = last_elm;
}

void	rrb(t_stack *stackb)
{
	t_node	*last_elm;
	t_node	*ptr;

	if (stackb->size < 2)
	{
		exit(1);
	}
	ptr = stackb->top;
	while (ptr->next->next)
		ptr = ptr->next;
	last_elm = ptr->next;
	ptr->next = NULL;
	last_elm->next = stackb->top;
	stackb->top = last_elm;
}
