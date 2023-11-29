/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:11:52 by falberti          #+#    #+#             */
/*   Updated: 2023/11/29 17:08:59 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char			**splited_list;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	splited_list = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		splited_list = split(av[1], ' ');
	node_init(a, splited_list);
	return (42);
}

// Test Split
/* int i = 0;
int y = 0;

while (splited_list[i])
	{
		y = 0;
		while (splited_list[i][y])
			write(1, &splited_list[i][y++], 1);
		write(1, " ", 1);
		i++;
	} */