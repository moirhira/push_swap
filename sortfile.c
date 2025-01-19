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

void sort_one(t_stack *stacka, t_stack *stackb)
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
    
    if (stacka->size < 3)
        return stacka->top->value;

    int first = stacka->top->value;

    t_node *middle_node = stacka->top;
    for (int i = 0; i < stacka->size / 2; i++) {
        middle_node = middle_node->next;
    }
    int middle = middle_node->value;

    t_node *last_node = stacka->top;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    int last = last_node->value;

    if ((first >= middle && first <= last) || (first <= middle && first >= last))
        return first;
    if ((middle >= first && middle <= last) || (middle <= first && middle >= last))
        return middle;
    return last;
}

// void partition(t_stack *stacka, t_stack *stackb, int pivot)
// {
//     int size = stacka->size;
//     int i = 0;
//     while (i < size)
//     {
//         if (stacka->top->value <= pivot)
//             pb(stacka, stackb);
//         // else if (stacka->top->next->next->value > pivot)
//         //     rra(stacka);
//         else
//             ra(stacka); 
//         i++;
//     }
// }
void partition(t_stack *stacka, t_stack *stackb, int pivot) {
    int rotations = 0;
    int i = 0;
    int size = stacka->size;
    while (i < size) {
        if (stacka->top->value <= pivot) {
            pb(stacka, stackb); 
        } else {
            ra(stacka); 
            rotations++;
        }
        i++;
    }

    while (rotations--) {
        rra(stacka);
    }
}

void quick_sort(t_stack *stacka, t_stack *stackb)
{
    if (stacka->size <= 8)
    {
        printf("here\n");
        sort_then(stacka, stackb); 
        return;
    }

    int pivot = stacka->top->value;
    partition(stacka, stackb, pivot);

    quick_sort(stacka, stackb);

    while (stackb->top)
        pa(stacka, stackb);

}


void sort_algo(t_stack *satcka, t_stack *satckb)
{
    if (is_sorted(satcka))
        printf("sorted ALREADY !\n");
    else
    {
        if (satcka->size < 6)
            sort_one(satcka,satckb);
        else if (satcka->size >= 6)
        {
            quick_sort(satcka, satckb);
        }
        if (is_sorted(satcka))
            printf("sorted\n");
    }
}
























