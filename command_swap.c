/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:25:13 by albertini         #+#    #+#             */
/*   Updated: 2023/12/01 19:20:07 by albertini        ###   ########.fr       */
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
}