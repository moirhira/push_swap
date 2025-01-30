/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:32:42 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/09 20:32:46 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int is_integer(char *str)
{
    if (*str == '\0' || str == NULL)
        return (0);
    if (*str == '+' || *str == '-')
        str++;
    if (*str == '\0')
        return (0);
    while (*str)
    {
        if (ft_isdigit(*str))
            str++;
        else
            return(0);
    }
    return (1);
}

void free_stack(t_stack **stacka)
{
    t_node *current;
    t_node *next;

    if (!stacka || !*stacka)
        return;
    current = (*stacka)->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(*stacka);
    *stacka = NULL;
}

int check_duplicat(t_stack *stacka, t_stack *stackb)
{
    t_node  *in_number;
    t_node  *next_number;

    in_number = stacka->top;
    while (in_number)
    {
        next_number = in_number->next;
        while (next_number)
        {
            if (in_number->value == next_number->value)
            {
                write(2,"Error\n",6);;
                free_stack(&stacka);
                free_stack(&stackb);
                exit(1);
                return (0);
            }
            next_number = next_number->next;
        }
        in_number = in_number->next;   
    }
    return (1);
}

void free_spl(char **nums)
{
    int i;

    i  = 0;
    if (!nums)
        return;
    while (nums[i])
    {
        free(nums[i]);
        i++;
    }
    free(nums); 
}

t_node *push(char *str, t_stack *stacka)
{
    t_node *new_number;
    t_node *ptr;

    new_number = (t_node *)malloc(sizeof(t_node));
    if (!new_number)
        return(NULL);
    new_number->value = ft_atoi(str);
    new_number->next = NULL;
    if (stacka->top == NULL)
    {
        stacka->top = new_number;
        stacka->size++;
    }
    else
    {
        ptr = stacka->top;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = new_number;
        stacka->size++;
    }
    return (stacka->top);
}
