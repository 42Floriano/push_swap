/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_r_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:25:56 by albertini         #+#    #+#             */
/*   Updated: 2023/12/01 19:22:38 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void  r_rotate(t_stack_node **stack)
{
    t_stack_node *last_node;
    if (stack == NULL || *stack == NULL || stack_len(*stack) == 1)
        return ;
    last_node = find_last_node(*stack);
    last_node->prev->next = NULL;
    last_node->prev = NULL;
    stack[0]->prev = last_node;
    last_node->next = stack[0];
    stack[0] = last_node;
}