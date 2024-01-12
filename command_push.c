/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:24:52 by albertini         #+#    #+#             */
/*   Updated: 2024/01/10 16:46:08 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*tmp;

	if (src == NULL)
		return ;
	tmp = src[0];
	src[0] = src[0]->next;
	if (src[0])
		src[0]->prev = NULL;
	tmp->prev = NULL;
	if (dest[0] == NULL)
	{
		dest[0] = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = dest[0];
		dest[0]->prev = tmp;
		dest[0] = tmp;
	}
	return ;
}

//pa (push a): Take the first element at the top of b and put it at the top of a.
void	pa(t_stack_node **stackdesta, t_stack_node **stacksrcb)
{
	push(stackdesta, stacksrcb);
	write(1, "pa\n", 3);
	return ;
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
void	pb(t_stack_node **stackdestb, t_stack_node **stacksrca)
{
	push(stackdestb, stacksrca);
	write(1, "pb\n", 3);
	return ;
}