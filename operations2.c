/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:33:23 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/09 20:33:25 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"
#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*tempa;
	t_node	*ptr;

	if (stack->size < 2)
	{
		exit(1);
	}
	tempa = stack->top;
	stack->top = stack->top->next;
	ptr = stack->top;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tempa;
	ptr->next->next = NULL;
}

void	rr(t_stack *stacka, t_stack *stackb)
{
	if (!stacka || !stackb)
		return ;
	rotate(stacka);
	rotate(stackb);
	ft_printf("rr\n");
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
	ft_printf("rra\n");
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
	ft_printf("rrb\n");
}

void	rrr(t_stack *stacka, t_stack *stackb)
{
	if (!stacka || !stackb)
		return ;
	rra(stacka);
	rrb(stackb);
}
