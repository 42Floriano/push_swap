/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:01:28 by falberti          #+#    #+#             */
/*   Updated: 2024/01/18 14:05:13 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* Pushes the first node from src to the top of dest
*/
static	void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (src[0] == NULL)
		return ;
	node_to_push = src[0];
	src[0] = src[0]->next;
	if (*src)
		src[0]->prev = NULL;
	if (dest[0] == NULL)
	{
	dest[0] = node_to_push;
	dest[0]->next = NULL;
	}
	else
	{
	node_to_push->next = dest[0];
	dest[0]->prev = node_to_push;
	dest[0] = node_to_push;
	}
	return ;
}

//pa (push a): Take the first element at the
//top of b and put it at the top of a.
void	pa(t_stack_node **stackdesta, t_stack_node **stacksrcb)
{
	push(stackdesta, stacksrcb);
	write(1, "pa\n", 3);
	return ;
}

// pb (push b): Take the first element 
// at the top of a and put it at the top of b.
void	pb(t_stack_node **stackdestb, t_stack_node **stacksrca)
{
	push(stackdestb, stacksrca);
	write(1, "pb\n", 3);
	return ;
}
