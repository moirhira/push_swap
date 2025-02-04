/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:43:12 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/17 11:43:13 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "push_swap.h"

void	sa(t_stack *stacka);
void	sb(t_stack *stackb);
void	ss(t_stack *stacka, t_stack *stackb);
void	pa(t_stack *stacka, t_stack *stackb);
void	pb(t_stack *stacka, t_stack *stackb);
void	rotate(t_stack *stack);
void	rr(t_stack *stacka, t_stack *stackb);
void	rra(t_stack *stacka);
void	rrb(t_stack *stackb);
void	rrr(t_stack *stacka, t_stack *stackb);

#endif