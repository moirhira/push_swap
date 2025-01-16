/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:33:23 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/09 20:33:25 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>




void sa(t_stack *stacka)
{
    if (stacka->top != NULL)
    {
        int temp;
        temp = stacka->top->value;
        stacka->top->value = stacka->top->next->value;
        stacka->top->next->value = temp;
    }
    else
        exit(1);
}


void sb(t_stack *stackb)
{
    if (stackb->top != NULL)
    {
        int temp;
        temp = stackb->top->value;
        stackb->top->value = stackb->top->next->value;
        stackb->top->next->value = temp;
    }
    else
        exit (0);
}

void ss(t_stack *stacka, t_stack *stackb)
{
    sa(stacka);
    sb(stackb);
}

void pa(t_stack *stacka, t_stack *stackb)
{
    if (stackb->top != NULL)
    {
        t_node *tempb;
        tempb = stackb->top;
        stackb->top = stackb->top->next;
        tempb->next = stacka->top;
        stacka->top = tempb;
    }
    else
        exit(1);
}

void pb(t_stack *stacka, t_stack *stackb)
{
    if (stacka->top != NULL)
    {
        t_node *tempa;
        tempa = stacka->top;
        stacka->top = stacka->top->next;
        tempa->next = stackb->top;
        stackb->top = tempa;
    }
    printf("pb\n");
}

int ra(t_stack *stacka)
{
    if (stacka->size < 2)
    {
        return (-1);
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
    printf("ra\n");
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
    ra(stacka);
    rb(stackb);
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
        printf("rra\n");
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
    }
    else
        exit (1);
}


void rrr(t_stack *stacka, t_stack *stackb)
{
    rra(stacka);
    rrb(stackb);
}