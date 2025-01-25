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

int find_index(t_stack *stack, int nbr) {
    int index = 0;
    t_node *tmp = stack->top;
    while (tmp) {
        if (tmp->value == nbr)
            return index;
        index++;
        tmp = tmp->next;
    }
    return -1;
}

int find_place_b(t_stack *stack_b, int nbr) {
    if (!stack_b) {
        return 0;
    }
    int place = 0;
    t_node *tmp = stack_b->top;

    int max = find_max(stack_b);
    int min = find_min(stack_b);

    if (nbr < min) {
        while (tmp->value != min) {
            place++;
            tmp = tmp->next;
        }
        return place;
    }

    if (nbr > max) {
        while (tmp->value != max) {
            place++;
            tmp = tmp->next;
        }
        return place + 1;
    }

    while (tmp->next)
    {
        if (nbr > tmp->value && nbr < tmp->next->value)
            return place + 1;
        place++;
        tmp = tmp->next;
    }

    return place;
}

int calculate_cost(t_stack *stack_a, t_stack *stack_b, int nbr)
{
    int cost_a = find_index(stack_a, nbr);
    int cost_b = find_place_b(stack_b, nbr);

    if (cost_a <= (stack_a->size / 2) && cost_b <= stack_b->size / 2)
    {
        return (cost_a > cost_b) ? cost_a : cost_b; 
    } 
    else if (cost_a > stack_a->size  / 2 && cost_b > stack_b->size / 2)
    {
        int reverse_a = stack_a->size - cost_a;
        int reverse_b = stack_b->size - cost_b;
        return (reverse_a > reverse_b) ? reverse_a : reverse_b;
    } 
    else 
    {
        return cost_a + cost_b; 
    }
}

int find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
    // if (!stack_a || !stack_a->top) return -1;
    t_node *tmp = stack_a->top;
    int cheapest_nbr = tmp->value;
    int cheapest_cost = calculate_cost(stack_a, stack_b, tmp->value);

    while (tmp) {
        int current_cost = calculate_cost(stack_a, stack_b, tmp->value);
        if (current_cost < cheapest_cost) {
            cheapest_cost = current_cost;
            cheapest_nbr = tmp->value;
        }
        
        tmp = tmp->next;
    }
    return(cheapest_nbr);
}

void push_cheapest(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b || stack_a->size == 0) return;
    int cheapest = find_cheapest(stack_a,stack_b);
    int cost_a = find_index(stack_a, cheapest);
    int cost_b = find_place_b(stack_b, cheapest);
    
    while (cost_a > 0 && cost_b > 0) {
        rr(stack_a, stack_b);
        cost_a--;
        cost_b--;
    }
    while (cost_a > 0) {
        ra(stack_a);
        cost_a--;
    }
    while (cost_b > 0) {
        rb(stack_b);
        cost_b--;
    }
    pb(stack_a, stack_b);
}


void final_rotation(t_stack *stack_a) {
    if (!stack_a || !stack_a->top) {
        printf("Error: stack_a is empty or NULL.\n");
        return;
    }

    int min_index = find_index(stack_a, find_min(stack_a));
    if (min_index <= stack_a->size / 2) {
        while (min_index-- > 0)
            ra(stack_a);
    } else {
        while (min_index++ < stack_a->size)
            rra(stack_a);
    }
}