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

int find_place_in_a(t_stack *stack_a, int nbr) {
    
    int place = 0;
    t_node *tmp = stack_a->top;
    t_node *tmp1 = stack_a->top;
    int max = find_max(stack_a);
    int min = find_min(stack_a);

    if (nbr < min)
        return(find_index(stack_a,min));
    else if (nbr > max)
        return (find_index(stack_a,min));
    while (tmp1->next)
    {
        tmp1 = tmp1->next;
    }
     if (nbr < tmp->value && nbr > tmp1->value)
         	return 0;
        while (tmp->next)
        {
            if (nbr > tmp->value && nbr < tmp->next->value)
                {
                    place++;
                    break;
                }
            place++;
            tmp = tmp->next;
        }

    return place;
}

// int calculate_cost(t_stack *stack_a, t_stack *stack_b, int nbr)
// {
//     int cost_b = find_index(stack_b, nbr);
//     int cost_a = find_place_in_a(stack_a, nbr);
//     int stack_b_size = stack_b->size;
//     int stack_a_size = stack_a->size;

//     // Calculate most efficient rotation strategy
//     int rotate_both = (cost_b <= stack_b_size/2 && cost_a <= stack_a_size/2) ? 
//         (cost_b > cost_a ? cost_b : cost_a) :
//         (cost_b > stack_b_size - cost_b ? stack_b_size - cost_b : cost_b) +
//         (cost_a > stack_a_size - cost_a ? stack_a_size - cost_a : cost_a);

//     return rotate_both;
// }

// int find_cheapest(t_stack *stack_a, t_stack *stack_b)
// {
//     t_node *tmp = stack_b->top;
//     int cheapest_nbr = tmp->value;
//     int cheapest_cost = calculate_cost(stack_a, stack_b, tmp->value);

//     while (tmp) {
//         int current_cost = calculate_cost(stack_a, stack_b, tmp->value);
//         // printf("number %d cose %d\n",tmp->value, current_cost);
//         if (current_cost < cheapest_cost) {
//             cheapest_cost = current_cost;
//             cheapest_nbr = tmp->value;
//         }
        
//         tmp = tmp->next;
//     }
//     return(cheapest_nbr);
// }

void push_cheapest(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b || stack_b->size == 0) return;

    // int cheapest = find_cheapest(stack_a, stack_b);
    int nbr = stack_b->top->value;
    int cost_b = find_index(stack_b, nbr);
    int cost_a = find_place_in_a(stack_a, nbr);
    int stack_b_size = stack_b->size;
    int stack_a_size = stack_a->size;
    // printf("nbr %d cost a : %d\n",nbr,cost_a);

    // while (cost_b > 0 && cost_a > 0 && 
    //        cost_b <= stack_b_size/2 && 
    //        cost_a <= stack_a_size/2) {
    //     rr(stack_a, stack_b);
    //     cost_b--;
    //     cost_a--;
    // }

    // Rotate B if needed
    while (cost_b > 0) {
        // if (cost_b > stack_b_size/2)
        //     rrb(stack_b);
        // else
        rb(stack_b);
        cost_b--;
    }

    // Rotate A if needed
    while (cost_a > 0) {
        // if (cost_a > stack_a_size/2)
        //     rra(stack_a);
        // else
        ra(stack_a);
        cost_a--;
    }

    pa(stack_a, stack_b);
}

void final_rotation(t_stack *stack_a) {
    if (!stack_a || !stack_a->top) {
        printf("Error: stack_a is empty or NULL.\n");
        return;
    }

    int max_index = find_index(stack_a, find_min(stack_a));
    if (max_index <= stack_a->size / 2) {
        while (max_index-- > 0)
            ra(stack_a);
    } else {
        while (max_index++ < stack_a->size)
            rra(stack_a);
    }
}