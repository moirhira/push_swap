/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:51:37 by moirhira          #+#    #+#             */
/*   Updated: 2025/02/01 12:20:35 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	is_sorted(t_stack *stack)
{
	int		flag;
	t_node	*curent;

	if (!stack || !stack->top)
		return (0);
	flag = 1;
	curent = stack->top;
	while (curent->next)
	{
		if (curent->value < curent->next->value)
			curent = curent->next;
		else
		{
			flag = 0;
			return (flag);
		}
	}
	return (flag);
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
