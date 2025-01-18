/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:42:58 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/17 11:42:59 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "operations.h"

int is_sorted(t_stack *stack)
{
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
    }    //////  

// 3
// 2
// 1


    return (flag);
}

void sort_three(t_stack *stacka)
{
    if (stacka->top->value > stacka->top->next->value)
        sa(stacka);
    if (stacka->top->next->value > stacka->top->next->next->value)
        rra(stacka);
    if (stacka->top->value > stacka->top->next->value)
        sa(stacka);
}

int get_min(t_stack *stack , int *f)
{
    int i = 0;
    int min_index = 0;
    int min = stack->top->value;
    t_node *current = stack->top;
    while(current)
    {
        if (min > current->value)
        {
            min = current->value;
            min_index = i;
        }
        current = current->next;
        i++;
    }
    if (min_index <= stack->size / 2)
        *f = 1;
    else
        *f = 0;
    return (min);
}

void sortonfour(t_stack *stacka, t_stack *stackb)
{
    int f;
    int i = 0;
    int rep = 2;
    if (stacka->size == 4)
        rep = 1;
    while (i < rep)
    {
        int min = get_min(stacka, &f);
        while(stacka->top->value != min)
        {
            if (f == 1)
                ra(stacka);
            else
                rra(stacka);
        }
        if (stacka->top->value == min)
            pb(stacka,stackb);
        i++;
    }
    sort_three(stacka);
    while (rep--)
        pa(stacka,stackb);
}