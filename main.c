/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:25:05 by falberti          #+#    #+#             */
/*   Updated: 2024/01/24 13:27:58 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * My main 
 * 1. split what is recieve in the argv then init the node with the this list.
 * 2. Check if sorted, if not check the number of elements in the stack.
 * 3. Free the stack
*/
int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**splited_list;

	a = NULL;
	b = NULL;
	splited_list = NULL;
	if (ac == 1 || (ac == 2 && (!av[1][0] || av[1][0] == '\0')))
		mini_error_free();
	else if (ac == 2)
		splited_list = split(av[1], ' ', true);
	else if (ac > 2)
		splited_list = split(str_join((av + 1)), ' ', false);
	stack_init(&a, splited_list);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
