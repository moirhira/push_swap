/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:33:23 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/09 20:33:25 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"
#include "push_swap.h"

void	sa(t_stack *stacka)
{
	int		temp;

	if (stacka->top != NULL)
	{
		temp = stacka->top->value;
		stacka->top->value = stacka->top->next->value;
		stacka->top->next->value = temp;
		ft_printf("sa\n");
	}
	else
		exit(1);
}

void	sb(t_stack *stackb)
{
	int		temp;

	if (stackb->top != NULL)
	{
		temp = stackb->top->value;
		stackb->top->value = stackb->top->next->value;
		stackb->top->next->value = temp;
		ft_printf("sb\n");
	}
	else
		exit(0);
}

void	ss(t_stack *stacka, t_stack *stackb)
{
	sa(stacka);
	sb(stackb);
	ft_printf("ss\n");
}

void	pa(t_stack *stacka, t_stack *stackb)
{
	t_node		*tempb;

	if (stackb->top != NULL)
	{
		tempb = stackb->top;
		stackb->top = stackb->top->next;
		tempb->next = stacka->top;
		stacka->top = tempb;
		stacka->size++;
		stackb->size--;
		ft_printf("pa\n");
	}
	else
		exit(1);
}

void	pb(t_stack *stacka, t_stack *stackb)
{
	t_node		*tempa;

	if (stacka->top != NULL)
	{
		tempa = stacka->top;
		stacka->top = stacka->top->next;
		tempa->next = stackb->top;
		stackb->top = tempa;
		stacka->size--;
		stackb->size++;
	}
	ft_printf("pb\n");
}
