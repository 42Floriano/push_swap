/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:45:33 by albertini         #+#    #+#             */
/*   Updated: 2024/01/24 13:51:19 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	str_len(char **lst)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	z = 0;
	while (lst[x])
	{
		y = 0;
		while (lst[x][y])
			y++;
		x++;
		z += y;
	}
	return (x + z);
}

char	*str_join(char **lst)
{
	int		x;
	int		y;
	int		len;
	char	*str;

	x = 0;
	len = str_len(lst);
	str = malloc(sizeof(char) * len + 1);
	len = 0;
	while (lst[x])
	{
		if (!lst[x][0])
		{
			free(str);
			mini_error_free();
		}
		y = 0;
		while (lst[x][y])
			str[len++] = lst[x][y++];
		str[len++] = ' ';
		x++;
	}
	str[--len] = '\0';
	return (str);
}
