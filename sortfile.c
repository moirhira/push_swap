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
#include "push_swap.h"
#include "operations.h"

int is_sorted(t_stack *stack)
{
    if(!stack || !stack->top)
        return(0);
    int flag = 1;
    t_node *curent = stack->top;
    while (curent->next)
    {
        if (curent->value < curent->next->value)
            curent = curent->next;
        else
        {
            flag = 0;
            return (flag);
        }
    }
    return (flag);
}

void simple_sort(t_stack *stacka, t_stack *stackb)
{
    if (stacka->size == 2)
    {
        ra(stacka);
        printf("ra\n");
    }
    else if (stacka->size == 3)
        sort_three(stacka);
    else if (stacka->size >= 4 )
        sortonfour(stacka,stackb);
}

void sort_complicated(t_stack *stacka, t_stack *stackb)
{
    while (stacka->size > 3)
        pb(stacka,stackb);
    sort_three(stacka);

    while (stackb->size > 0)
        push_cheapest(stacka,stackb);
    final_rotation(stacka);
}


void sort_algo(t_stack *satcka, t_stack *satckb)
{
    if (is_sorted(satcka))
        printf("sorted ALREADY !\n");
    else
    {
        if (satcka->size < 6)
        {
            simple_sort(satcka,satckb);
        }
        else if (satcka->size >= 6)
        {
            sort_complicated(satcka, satckb);
        }
        if (is_sorted(satcka))
            printf("sorted!\n");
    }
}
























