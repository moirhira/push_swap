/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <moirhira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:47:09 by moirhira          #+#    #+#             */
/*   Updated: 2025/02/01 13:37:17 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../includes/libft/libft.h"
# include "../includes/printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

// operations
void				swap(t_stack *stack);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_b, t_stack *stack_a);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);

// utility functions
void				handel_args(int ac, char *av[], t_stack *stacka,
						t_stack *stackb);
int					ft_strcmp(const char *s1, const char *s2);
t_node				*push(char *str, t_stack *stacka);
int					is_integer(char *str);
void				free_stack(t_stack **stacka);
int					check_duplicat(t_stack *stacka, t_stack *stackb);
void				free_spl(char **nums);
char				**free_split(char **res, size_t indx);
void				free_handel(t_stack *stacka, t_stack *stackb, char **nums);
int					is_sorted(t_stack *stack);
int					is_only_whitespace(char *str);

#endif
