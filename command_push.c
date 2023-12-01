/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:24:52 by albertini         #+#    #+#             */
/*   Updated: 2023/12/01 17:50:14 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void  push(t_stack_node **dest, t_stack_node **src)
{
  t_stack_node *tmp;
  if (src == NULL)
    return ;
  tmp = src[0];
  src[0] = src[0]->next;
  if(src[0])
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
    //tmp->next->prev = tmp;
    dest[0] = tmp;
  }
}