/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:25:13 by albertini         #+#    #+#             */
/*   Updated: 2023/12/02 00:20:42 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void  swap(t_stack_node **stack)
{
    t_stack_node *tmp;
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
void    sa(t_stack_node **stack)
{
    swap(stack);
    write(1, "sa\n", 3);
    return ;
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
void    sb(t_stack_node **stack)
{
    swap(stack);
    write(1, "sb\n", 3);
    return ;
}