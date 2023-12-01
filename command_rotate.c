/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:25:31 by albertini         #+#    #+#             */
/*   Updated: 2023/12/02 00:20:24 by albertini        ###   ########.fr       */
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
    return ;
}

// ra (rotate a): Shift up all elements of stack a by 1.
void    ra(t_stack_node **stacka)
{
    rotate(stacka);
    write(1, "ra\n", 3);
    return ;
}

// rb (rotate b): Shift up all elements of stack b by 1.
void    rb(t_stack_node **stackb)
{
    rotate(stackb);
    write(1, "rb\n", 3);
    return ;
}

// rr : ra and rb at the same time.
void    rr(t_stack_node **stacka, t_stack_node **stackb)
{
    rotate(stacka);
    rotate(stackb);
    write(1, "rr\n", 3);
    return ;
}