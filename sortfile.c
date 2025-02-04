/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:42:29 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/17 11:42:30 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "operations.h"
#include "push_swap.h"

void	simple_sort(t_stack *stacka, t_stack *stackb)
{
	if (stacka->size == 2)
	{
		rotate(stacka);
		ft_printf("ra\n");
	}
	else if (stacka->size == 3)
		sort_three(stacka);
	else if (stacka->size >= 4)
		sortonfour(stacka, stackb);
}

void	sort_complicated(t_stack *stacka, t_stack *stackb)
{
	while (stacka->size > 3)
		pb(stacka, stackb);
	sort_three(stacka);
	while (stackb->size > 0)
		push_cheapest(stacka, stackb);
	final_rotation(stacka);
}

void	sort_algo(t_stack *satcka, t_stack *satckb)
{
	if (is_sorted(satcka))
	{
		free_stack(&satcka);
		free_stack(&satckb);
		exit(0);
	}
	else
	{
		if (satcka->size < 6)
		{
			simple_sort(satcka, satckb);
		}
		else if (satcka->size >= 6)
		{
			sort_complicated(satcka, satckb);
		}
	}
}
