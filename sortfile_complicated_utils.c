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


int	find_place_in_a(t_stack *stack_a, int nbr)
{
	int(max), (min), (place);
	t_node(*tmp), (*tmp1);

	place = 0;
	tmp = stack_a->top;
	tmp1 = stack_a->top;
	max = find_max(stack_a);
	min = find_min(stack_a);
	if (nbr < min || nbr > max)
		return (find_index(stack_a, min));
	while (tmp1->next)
		tmp1 = tmp1->next;
	if (nbr < tmp->value && nbr > tmp1->value)
		return (0);
	while (tmp->next)
	{
		if (nbr > tmp->value && nbr < tmp->next->value)
			return (place + 1);
		place++;
		tmp = tmp->next;
	}
	return (place);
}

int	calculate_cost(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int(cost_b), (cost_a), (rotate_both);

	cost_b = find_index(stack_b, nbr);
	cost_a = find_place_in_a(stack_a, nbr);
	if (cost_b <= stack_b->size / 2 && cost_a <= stack_a->size / 2)
	{
		if (cost_b > cost_a)
			rotate_both = cost_b;
		else
			rotate_both = cost_a;
	}
	else
	{
		if (cost_b > stack_b->size - cost_b)
			rotate_both = stack_b->size - cost_b;
		else
			rotate_both = cost_b;
		if (cost_a > stack_a->size - cost_a)
			rotate_both += stack_a->size - cost_a;
		else
			rotate_both += cost_a;
	}
	return (rotate_both);
}

int	find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	int(cheapest_nbr), (cheapest_cost), (current_cost);
	
	tmp = stack_b->top;
	cheapest_nbr = tmp->value;
	cheapest_cost = calculate_cost(stack_a, stack_b, tmp->value);
	while (tmp)
	{
		current_cost = calculate_cost(stack_a, stack_b, tmp->value);
		if (current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cheapest_nbr = tmp->value;
		}
		tmp = tmp->next;
	}
	return (cheapest_nbr);
}

void push_cheapset_helper(int cost_a, t_stack *stack_a)
{
    if (cost_a <= stack_a->size / 2)
        while (cost_a-- > 0)
        {
            ra(stack_a);
            ft_printf("ra\n");
        }
    else
        while (cost_a++ < stack_a->size)
            rra(stack_a);
}

void	push_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	int (cost_b), (cost_a);
	if (!stack_a || !stack_b || stack_b->size == 0)
		return ;
	cost_b = find_index(stack_b, find_cheapest(stack_a, stack_b));
	cost_a = find_place_in_a(stack_a, find_cheapest(stack_a, stack_b));
	while (cost_b > 0 && cost_a > 0 && cost_b <= stack_b->size / 2
		&& cost_a <= stack_a->size / 2)
	{
		rr(stack_a, stack_b);
		cost_b--;
		cost_a--;
	}
	 if (cost_b <= stack_b->size / 2)
        while (cost_b-- > 0)
        {
            rb(stack_b);
            ft_printf("rb\n");
        }
    else
        while (cost_b++ < stack_b->size)
            rrb(stack_b);
    push_cheapset_helper(cost_a,stack_a);
	pa(stack_a, stack_b);
}

