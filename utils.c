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
#include <stdio.h>
#include <stdlib.h>
#include "includes/libft/ft_isdigit.c"
#include "includes/libft/ft_split.c"
#include "includes/libft/ft_atoi.c"


int is_integer(char *str)
{
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

void free_stack(t_stack *stacka) {
    t_node *current = stacka->top;
    t_node *next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    free(stacka);
}

int check_duplicat(t_stack *stacka)
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
    int i = 0;

    if (!nums)
        return;

    while (nums[i])
    {
        free(nums[i]);
        i++;
    }
    free(nums); 
}