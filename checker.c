/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:10:49 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/29 23:10:51 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_exit(t_stack *stacka,t_stack *stackb)
{
    write(2,"Error\n",6);
    free_stack(&stacka);
    free_stack(&stackb);
    exit (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
	}
	return (0);
}
void exec_instruction(char *instruction, t_stack *stacka, t_stack *stackb)
{
    if (ft_strcmp(instruction, "sa") == 0)
        sa(stacka);
    else if (ft_strcmp(instruction, "sb") == 0) 
        sb(stackb);
    else if (ft_strcmp(instruction, "ss") == 0)
        ss(stacka, stackb);
    else if (ft_strcmp(instruction, "pa") == 0)
        pa(stacka, stackb);
    else if (ft_strcmp(instruction, "pb") == 0)
        pb(stackb, stacka);
    else if (ft_strcmp(instruction, "ra") == 0)
        ra(stacka);
    else if (ft_strcmp(instruction, "rb") == 0)
        rb(stackb);
    else if (ft_strcmp(instruction, "rr") == 0)
        rr(stacka, stackb);
    else if (ft_strcmp(instruction, "rra") == 0)
        rra(stacka);
    else if (ft_strcmp(instruction, "rrb") == 0)
        rrb(stackb);
    else if (ft_strcmp(instruction, "rrr") == 0)
        rrr(stacka, stackb);
    else
        error_exit(stacka,stackb);
}


int main(int ac, char *av[])
{
    if (ac < 2)
        return (0);
    char instruction[4];
    int read_chars;
    t_stack *stacka, *stackb;
    stacka = (t_stack*)malloc(sizeof(t_stack));
    stackb = (t_stack*)malloc(sizeof(t_stack));
    if (!stacka || !stackb)
        return (0);
    stacka->top = NULL;
    stacka->size = 0;
    stackb->top = NULL;
    stackb->size = 0;
    handel_args(ac ,av, stacka, stackb);   
    while ((read_chars = read(0, instruction, 4)) > 0)
    {
        instruction[read_chars - 1] = '\0';
        exec_instruction(instruction, &stacka,&stackb);
    }
    

    if (is_sorted(stacka) && stacka->size == 0)
        write(1, "OK\n",3);
    else
        write(1, "KO\n",3);
    free_stack(&stacka);
    free_stack(&stackb);
    return (0);
}