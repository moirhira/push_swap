/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:33:05 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/09 20:33:06 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;


typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;



int is_integer(char *str);
void free_stack(t_stack *stacka);
int check_duplicat(t_stack *stacka);
void free_spl(char **nums);

#endif