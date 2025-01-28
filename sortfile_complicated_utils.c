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
#include "push_swap.h"
#include "operations.h"

int find_index(t_stack *stack, int nbr)
{
    int index;
    t_node *tmp;

    index = 0;
    tmp= stack->top;
    while (tmp)
    {
        if (tmp->value == nbr)
            return index;
        index++;
        tmp = tmp->next;
    }
    return (-1);
}

int find_place_in_a(t_stack *stack_a, int nbr){
    
    int (max),(min),(place);
    t_node (*tmp),(*tmp1);
    
    place = 0;
    tmp = stack_a->top;
    tmp1 = stack_a->top;
    max = find_max(stack_a);
    min = find_min(stack_a);
    if (nbr < min || nbr > max)
        return(find_index(stack_a,min));
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
    return place;
}

int calculate_cost(t_stack *stack_a, t_stack *stack_b, int nbr)
{
    int (cost_b),(cost_a),(b_size),(a_size),(rotate_both);

    cost_b = find_index(stack_b, nbr);
    cost_a = find_place_in_a(stack_a, nbr);
    b_size = stack_b->size;
    a_size = stack_a->size;
    if (cost_b <= b_size / 2 && cost_a <= a_size / 2)
    {
        if (cost_b > cost_a)
            rotate_both = cost_b;
        else
            rotate_both = cost_a;
    }
    else
    {
        if (cost_b > b_size - cost_b)
            rotate_both = b_size - cost_b;
        else
            rotate_both = cost_b;
        if (cost_a > a_size - cost_a)
            rotate_both += a_size - cost_a;
        else
            rotate_both += cost_a;
    }
    return (rotate_both);
}

int find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
    
    int (cheapest_nbr),(cheapest_cost),(current_cost);
    t_node *tmp;
    
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

void push_cheapest(t_stack *stack_a, t_stack *stack_b)
{
    int (cheapest),(cost_b),(cost_a);

    if (!stack_a || !stack_b || stack_b->size == 0)
        return;
    cheapest = find_cheapest(stack_a, stack_b);
    cost_b = find_index(stack_b, cheapest);
    cost_a = find_place_in_a(stack_a, cheapest);
    while (cost_b > 0 && cost_a > 0 && cost_b <= stack_b->size / 2 && cost_a <= stack_a->size / 2)
    {
        rr(stack_a, stack_b);
        cost_b--;
        cost_a--;
    }
    if (cost_b <= stack_b->size / 2)
        while (cost_b-- > 0)
        {
            rb(stack_b);
            printf("rb\n");
        }
    else
        while (cost_b++ < stack_b->size)
            rrb(stack_b);
    if (cost_a <= stack_a->size / 2)
        while (cost_a-- > 0)
        {
            ra(stack_a);
            printf("ra\n");
        }
    else
        while (cost_a++ < stack_a->size)
            rra(stack_a);
    pa(stack_a, stack_b);
}

void final_rotation(t_stack *stack_a)
{
    if (!stack_a || !stack_a->top) {
        printf("Error: stack_a is empty or NULL.\n");
        return;
    }

    int max_index = find_index(stack_a, find_min(stack_a));
    if (max_index <= stack_a->size / 2) {
        while (max_index-- > 0)
        {
            ra(stack_a);
            printf("ra\n");
        }
    } else {
        while (max_index++ < stack_a->size)
            rra(stack_a);
    }
}