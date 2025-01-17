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

int sort_one(t_stack *stacka, t_stack *stackb)
{
    if (stacka->size == 2)
        ra(stacka);
    else if (stacka->size == 3)
        sort_three(stacka);
    else if (stacka->size >= 4 )
        sortonfour(stacka,stackb);
}

int sort_radix(t_stack *stacka, t_stack *stackb)
{
    printf("radix work !\n");
}

void sort_algo(t_stack *satcka, t_stack *satckb)
{
    if (is_sorted(satcka))
    {
        printf("sorted ALREADY !\n");
    }
    else
    {
        if (satcka->size < 6)
            sort_one(satcka,satckb);
        else if (satcka->size >= 6)
            sort_radix(satcka, satckb);
    }
}























// /int i = 0;
//     while (i < stacka->size)
//     {
//         int max_value = stacka->top->value;
//         int max_index = 0;
//         int indx = 0;

//         t_node *current = stacka->top;
//         while(current)
//         {
//             if (max_value < current->value)
//             {
//                 max_value = current->value;
//                 max_index = indx;
//             }
//             current = current->next;
//             indx++;
//         }
//         int rotation;
//         if (max_index <= stacka->size / 2)
//         {
//             while (max_index--)
//                 ra(stacka);
//         }
//         else
//         {
//             rotation = stacka->size - max_index;
//             while (rotation--)
//                 rra(stacka);
//         }
//         pb(stacka, stackb);
//         i++;
//     }
//     pb(stacka,stackb);
//     return (1);
