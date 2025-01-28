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

static char	**free_split(char **res, size_t indx)
{
	while (indx > 0)
	{
		free(res[--indx]);
	}
	free(res);
	return (NULL);
}

void handel_args(int ac, char *av[], t_stack *stacka, t_stack *stackb)
{
    char **nums;
    int (k),(i);
    k = 1;
    while (k < ac)
    {
        nums = ft_split(av[k], ' ');
        i = 0;
        while (nums[i])
        {
            long num = ft_atoi(nums[i]);
            if (!is_integer(nums[i]) || num > 2147483647 || num < -2147483648)
            {
                printf("Error\n");
                free_stack(&stacka);
                free_stack(&stackb);
                free_spl(nums);
                exit(1);
            }
            push(nums[i], stacka);
            i++;            
        }
        k++;
        free_split(nums, i);
    }
    check_duplicat(stacka,stackb);
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
        handel_args(ac ,av, stacka, stackb);     
        sort_algo(stacka,stackb);
        // show_nbrs(stacka,1);
    }
    else
        printf("Error\n");
    free_stack(&stacka);
    free_stack(&stackb);
}

