
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:33:23 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/09 20:33:25 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "operations.h"


void ra(t_stack *stacka)
{
    if (stacka->size < 2)
    {
        exit(1);
    }
    t_node *tempa, *ptr;
    tempa = stacka->top;
    stacka->top = stacka->top->next;
    ptr = stacka->top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = tempa;
    ptr->next->next = NULL;
}

void rb(t_stack *stackb)
{
    if (stackb->size >= 2)
    {
        t_node *tempb,*ptr;
        tempb = stackb->top;
        stackb->top = stackb->top->next;
        ptr = stackb->top;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = tempb;
        ptr->next->next = NULL;
    }
    else
        exit (1);
}

void rr(t_stack *stacka, t_stack *stackb)
{
    if (!stacka || !stackb) return;
    ra(stacka);
    rb(stackb);
    ft_printf("rr\n");
}

void rra(t_stack *stacka)
{
    if (stacka->size >= 2)
    {
        t_node *last_elm, *ptr;
        ptr = stacka->top;
        while(ptr->next->next)
            ptr = ptr->next;
        last_elm = ptr->next;
        ptr->next = NULL;
        last_elm->next = stacka->top;
        stacka->top = last_elm;
        ft_printf("rra\n");
    }
    else
        exit(1);
}

void rrb(t_stack *stackb)
{
    if (stackb->size >= 2)
    {
        t_node *last_elm, *ptr;
        ptr = stackb->top;
        while (ptr->next->next)
            ptr = ptr->next;
        last_elm = ptr->next;
        ptr->next = NULL;
        last_elm->next = stackb->top;
        stackb->top = last_elm;
        ft_printf("rrb\n");
    }
    else
        exit (1);
}

// void rrr(t_stack *stacka, t_stack *stackb)
// {
//     if (!stacka || !stackb) return;
//     rra(stacka);
//     rrb(stackb);
// }