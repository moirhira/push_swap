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


t_node *push(char *str, t_stack *stacka)
{
    t_node *new_number;

    new_number = (t_node *)malloc(sizeof(t_node));
    if (!new_number)
        return(NULL);
    new_number->value = ft_atoi(str);
    new_number->next = stacka->top;
    stacka->top = new_number;
    stacka->size++;
    return (stacka->top);
}

t_node  *show_nbrs(t_stack *stack, int f)
{
    t_node *temp;
    temp = stack->top;
    while (stack->top)
    {
        printf("%d\n", stack->top->value);
        stack->top = stack->top->next;
    }
    stack->top = temp;
    printf("=\n");
    if (f == 0)
        printf("b\n");
    else
        printf("a\n");
}

void handel_args(int ac, char *av[], t_stack *stacka)
{
    int k = 1;
    char **nums;
    while (k < ac)
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
        k++;
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
        // sort_algo(stacka, stackb);

        // printf("==========after=======\n");
        
        
        printf("---------------------\n");
        sort_algo(stacka,stackb);
        // show_nbrs(stackb, 0);
        // show_nbrs(stacka, 1);

    }
    else
    {
        printf("Error from number args\n");
        free_stack(stacka);
        exit(0);
    }
}

