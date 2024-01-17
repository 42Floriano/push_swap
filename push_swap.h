/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:28:09 by falberti          #+#    #+#             */
/*   Updated: 2024/01/17 16:12:35 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}					t_stack_node;

// split function
char				**split(char *str, char sep);

// stack_init
void				node_init(t_stack_node **a, char **list);

// stack_utils
t_stack_node		*find_last_node(t_stack_node *stack);
void				append_node(t_stack_node **stack, int nbr);
t_stack_node		*find_smallest(t_stack_node *stack);
int					stack_len(t_stack_node *list);

// error_checkers
void				error_free(t_stack_node **a, char **list);
int					error_syntax(char *to_check);
int					int_repeat(t_stack_node *stack, int nbr);

// freerers
void				free_list(char **list);
void				free_stack(t_stack_node **stack);

// commands
void				pa(t_stack_node **stackdesta, t_stack_node **stacksrcb);
void				pb(t_stack_node **stackdestb, t_stack_node **stacksrca);
void				sa(t_stack_node **stack);
void				sb(t_stack_node **stack);
void				ra(t_stack_node **stacka);
void				rb(t_stack_node **stackb);
void				rr(t_stack_node **stacka, t_stack_node **stackb);
void				rra(t_stack_node **stacka);
void				rrb(t_stack_node **stackb);
void				rrr(t_stack_node **stacka, t_stack_node **stackb);

// tiny sort
void				tiny_sort(t_stack_node **a);
int					stack_sorted(t_stack_node *stack);
void				handle_five(t_stack_node **a, t_stack_node **b);

// push swap init
void				set_price(t_stack_node *a, t_stack_node *b);
void				set_current_position(t_stack_node *stack);
void				set_cheapest(t_stack_node *b);
void				init_nodes(t_stack_node *a, t_stack_node *b);

// push swap command
void				push_swap(t_stack_node **a, t_stack_node **b);
void				finish_rotation(t_stack_node **s, t_stack_node *n, char c);

#endif
