/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <moirhira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:42:13 by moirhira          #+#    #+#             */
/*   Updated: 2025/02/01 13:38:19 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

void	handel_args(int ac, char *av[], t_stack *stacka, t_stack *stackb)
{
	char	**nums;
	long	num;

	int (k), (i);
	k = 1;
	while (k < ac)
	{
		if (!is_only_whitespace(av[k]))
			free_handel(stacka, stackb, NULL);
		nums = ft_split(av[k], ' ');
		i = 0;
		while (nums[i])
		{
			num = ft_atoi(nums[i]);
			if (!is_integer(nums[i]) || num > 2147483647 || num < -2147483648)
				free_handel(stacka, stackb, nums);
			push(nums[i], stacka);
			i++;
		}
		k++;
		free_split(nums, i);
	}
	check_duplicat(stacka, stackb);
}

void	execute_operations(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(operation, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(operation, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(operation, "ss") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(operation, "pa") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(operation, "pb") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(operation, "ra") == 0)
		ra(stack_a);
	else if (ft_strcmp(operation, "rb") == 0)
		rb(stack_b);
	else if (ft_strcmp(operation, "rr") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(operation, "rra") == 0)
		rra(stack_a);
	else if (ft_strcmp(operation, "rrb") == 0)
		rrb(stack_b);
	else if (ft_strcmp(operation, "rrr") == 0)
		rrr(stack_a, stack_b);
	else
		free_handel(stack_a, stack_b, NULL);
}

int	init_stacks(t_stack **stacka, t_stack **stackb)
{
	(*stacka) = (t_stack *)malloc(sizeof(t_stack));
	(*stackb) = (t_stack *)malloc(sizeof(t_stack));
	if (!stacka || !stackb)
	{
		return (0);
		exit(1);
	}
	(*stacka)->top = NULL;
	(*stacka)->size = 0;
	(*stackb)->top = NULL;
	(*stackb)->size = 0;
	return (1);
}

void	helper_main(t_stack *stacka, t_stack *stackb)
{
	char	operation[4];
	int		read_chars;

	while (1)
	{
		read_chars = read(0, operation, 4);
		if (read_chars <= 0)
			break ;
		operation[read_chars - 1] = '\0';
		execute_operations(operation, stacka, stackb);
	}
}

int	main(int ac, char *av[])
{
	t_stack	*stacka;
	t_stack	*stackb;

	init_stacks(&stacka, &stackb);
	if (ac >= 2)
	{
		handel_args(ac, av, stacka, stackb);
		helper_main(stacka, stackb);
		if (is_sorted(stacka))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_stack(&stacka);
	free_stack(&stackb);
}
