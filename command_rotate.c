/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:25:31 by albertini         #+#    #+#             */
/*   Updated: 2023/12/01 19:15:06 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void  rotate(t_stack_node **stack)
{
  t_stack_node *last_node;
  if (stack == NULL || *stack == NULL || stack_len(*stack) == 1)
    return ;
  last_node = find_last_node(*stack);
  last_node->next = stack[0];
  stack[0] = stack[0]->next;
  stack[0]->prev = NULL;
  last_node->next->prev = last_node;
  last_node->next->next = NULL;
}