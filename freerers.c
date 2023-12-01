/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:18:30 by albertini         #+#    #+#             */
/*   Updated: 2023/12/01 19:22:24 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(char **list)
{
	int i;

	i = 0;
	while(list[i])
		free(list[i++]);
	free(list);
	return ;
}
