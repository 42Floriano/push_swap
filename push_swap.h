/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:28:09 by falberti          #+#    #+#             */
/*   Updated: 2023/11/29 17:08:57 by falberti         ###   ########.fr       */
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
	int					final_index;
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
void				stack_init(t_stack_node **a, char **list);

// stack_utils
t_stack_node		*find_last_node(t_stack_node *stack);
void				append_node(t_stack_node **stack, int nbr);

// error_checkers
void				error_free(t_stack_node **a, char **list);
int					int_repeat(t_stack_node *stack, int nbr);

#endif