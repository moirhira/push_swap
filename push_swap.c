/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:42:13 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/17 11:42:15 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void handel_args(int ac, char *av[], t_stack *stacka)
{
    char **nums;
    int k = ac - 1;
    while (k >= 1)
    {
        nums = ft_split(av[k], ' ');
        int i = 0;

        while (nums[i])
        {
            long num = ft_atoi(nums[i]);
            if (!is_integer(nums[i]) || num > 2147483647 || num < -2147483648)
            {
                free_spl(nums);
                free_stack(stacka);
                printf("Error from integer validation\n");
                exit(1);
            }
            push(nums[i], stacka);
            i++;            
        }
        k--;
    }
    if (!check_duplicat(stacka))
    {
        printf("Error from duplication\n");
        free_spl(nums);
        free_stack(stacka);
        exit(1);
    }
}


int main(int ac, char *av[])
{
    t_stack *stacka, *stackb;
    stacka = (t_stack*)malloc(sizeof(t_stack));
    stackb = (t_stack*)malloc(sizeof(t_stack));
    if (!stacka || !stackb)
        return (0);
    stacka->top = NULL;
    stacka->size = 0;
    stackb->top = NULL;
    stackb->size = 0;

    if (ac >= 2)
    {
        handel_args(ac ,av, stacka);     
        printf("---------------------\n");

        sort_algo(stacka,stackb);
        // show_nbrs(stacka, 1);
        // show_nbrs(stackb, 0);

    }
    else
    {
        printf("Error from number args\n");
        free_stack(stacka);
        exit(0);
    }
}

