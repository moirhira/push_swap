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

void simple_sort(t_stack *stacka, t_stack *stackb)
{
    if (stacka->size == 2)
        ra(stacka);
    else if (stacka->size == 3)
        sort_three(stacka);
    else if (stacka->size >= 4 )
        sortonfour(stacka,stackb);
}

int sort_then(t_stack *stacka, t_stack *stackb)
{
    while (stacka->size > 0)
        pb(stacka,stackb);

    while (stackb->size > 0)
    {
        int max_value = stackb->top->value;
        int max_index = 0;
        int indx = 0;

        t_node *current = stackb->top;
        while(current)
        {
            if (max_value < current->value)
            {
                max_value = current->value;
                max_index = indx;
            }
            current = current->next;
            indx++;
        }
        int rotation;
        if (max_index <= stackb->size / 2)
        {
            while (max_index--)
                rb(stackb);
        }
        else
        {
            rotation = stackb->size - max_index;
            while (rotation--)
                rrb(stackb);
        }
        pa(stacka, stackb);
    }
    return (1);
}


int choose_pivot(t_stack *stacka)
{
    int k = 0 ;
    t_node *ptr = stacka->top;
    int array[stacka->size];  
    while (ptr != NULL)
    {
        array[k] = ptr->value;
        ptr = ptr->next;
        k++;
    }
    int i = 0;
    while (i < stacka->size - 1)
    {
        int j = 0;
        while (j < stacka->size - i - 1)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
    int pivot = array[stacka->size / 2];
    return pivot;
}

void partition(t_stack *stacka, t_stack *stackb, int pivot)
{
    int size = stacka->size;
    int i = 0;
    while (i < size)
    {
        if (stacka->top->value <= pivot)
            pb(stacka,stackb);
        else
            ra(stacka);
        i++;
    }
    
}
void quick_sort(t_stack *stacka, t_stack *stackb)
{
    if (stacka->size <= 8)
    {
        sort_then(stacka,stackb);
        return;
    }
    
    int pivot;
    pivot = choose_pivot(stacka);
    partition(stacka, stackb, pivot);
    
    quick_sort(stacka,stackb);
    // quick_sort(stackb,stacka);
    while (stackb->top)
        pa(stacka,stackb);
}


void sort_algo(t_stack *satcka, t_stack *satckb)
{
    if (is_sorted(satcka))
        printf("sorted ALREADY !\n");
    else
    {
        if (satcka->size < 6)
            simple_sort(satcka,satckb);
        else if (satcka->size >= 6)
        {
            quick_sort(satcka, satckb);
        }
        if (is_sorted(satcka))
            printf("sorted\n");
    }
}
























