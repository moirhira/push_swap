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

#include <stdio.h>
#include <stdlib.h>
#include "includes/libft/libft.h"

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

t_node *push(char *str, t_stack *stacka);
void  show_nbrs(t_stack *stack, int f);
int is_integer(char *str);
void free_stack(t_stack *stacka);
int check_duplicat(t_stack *stacka);
void free_spl(char **nums);
// sortfile && his utils =========================
void sort_algo(t_stack *satcka, t_stack *satckb);
int calculate_cost(t_stack *stacka, t_stack *stackb,int nbr);
int find_place_in_a(t_stack *stacka, int element);
int find_index(t_stack *stack, int nbr);
int find_cheapest(t_stack *stack_a, t_stack *stack_b);
void push_cheapest(t_stack *stack_a, t_stack *stack_b);
int is_sorted(t_stack *stack);
void final_rotation(t_stack *stack_a);
void sort_three(t_stack *stacka);
int get_min(t_stack *stack , int *f);
int find_max(t_stack *stack);
int find_min(t_stack *stack);
void sortonfour(t_stack *stacka, t_stack *stackb);
//================================================

#endif