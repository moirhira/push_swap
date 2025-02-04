/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <moirhira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:42:13 by moirhira          #+#    #+#             */
/*   Updated: 2025/02/01 12:18:01 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_split(char **res, size_t indx)
{
	while (indx > 0)
	{
		free(res[--indx]);
	}
	free(res);
	return (NULL);
}

void	free_handel(t_stack *stacka, t_stack *stackb, char **nums)
{
	write(2, "Error\n", 6);
	free_stack(&stacka);
	free_stack(&stackb);
	free_spl(nums);
	exit(1);
}

int	is_only_whitespace(char *str)
{
	if (str[0] == '\0')
		return (0);
	while (*str)
	{
		if (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		else
			return (1);
	}
	if (ft_isdigit(*str))
		return (1);
	return (0);
}

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
			if (!is_inteeger(nums[i]) || num > 2147483647 || num < -2147483648)
				free_handel(stacka, stackb, nums);
			push(nums[i], stacka);
			i++;
		}
		k++;
		free_split(nums, i);
	}
	check_duplicat(stacka, stackb);
}

int	main(int ac, char *av[])
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = (t_stack *)malloc(sizeof(t_stack));
	stackb = (t_stack *)malloc(sizeof(t_stack));
	if (!stacka || !stackb)
		return (0);
	stacka->top = NULL;
	stacka->size = 0;
	stackb->top = NULL;
	stackb->size = 0;
	if (ac >= 2)
	{
		handel_args(ac, av, stacka, stackb);
		sort_algo(stacka, stackb);
	}
	free_stack(&stacka);
	free_stack(&stackb);
}
