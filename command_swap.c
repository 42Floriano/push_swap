/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:25:48 by falberti          #+#    #+#             */
/*   Updated: 2024/01/24 14:48:28 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
* Swaps the two top nodes of the stack
*/
static	void	swap(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (stack == NULL || *stack == NULL || stack_len(*stack) == 1)
		return ;
	tmp = stack[0]->next;
	stack[0]->next = stack[0]->next->next;
	stack[0]->prev = tmp;
	tmp->prev = NULL;
	tmp->next = stack[0];
	stack[0] = tmp;
	return ;
}

// sa (swap a): Swap the first 2 elements at the top of stack a.
void	sa(t_stack_node **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
	return ;
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
void	sb(t_stack_node **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
	return ;
}
