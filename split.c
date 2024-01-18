/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:15:49 by falberti          #+#    #+#             */
/*   Updated: 2024/01/18 13:43:39 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char *str, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str[i] && str[i] != sep)
		count++;
	while (str[i])
	{
		while (str[i] && str[i] != sep)
			i++;
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] && str[i] != sep)
			count++;
	}
	return (count);
}

static char	*get_next_word(char *str, char sep)
{
	static int	i = 0;
	char		*next_word;
	int			y;
	int			len;

	y = 0;
	len = 0;
	while (str[i] && str[i] == sep)
		i++;
	while (str[i + len] && str[i + len] != sep)
		len++;
	next_word = malloc(sizeof(char) * (len + 1));
	if (next_word == NULL)
		return (next_word);
	while (str[i] && str[i] != sep)
		next_word[y++] = str[i++];
	next_word[y] = '\0';
	return (next_word);
}

/*
 * Recieve a string and a char seperator
 * Split the string using the seperator recieved into a list of string.
 * Returns the **list
*/
char	**split(char *str, char sep)
{
	int		i;
	int		len;
	char	**list;
	char	*new;

	len = count_word(str, sep);
	list = malloc(sizeof(list) * len + 1);
	if (list == NULL)
		return (list);
	i = 0;
	while (len-- > 0)
		list[i++] = get_next_word(str, sep);
	list[i] = NULL;
	return (list);
}
