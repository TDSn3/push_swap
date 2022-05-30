/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:04:39 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/30 11:04:41 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_sub_lst	*sl_new(int oper_used, int *stack_after_oper)
{
	t_sub_lst	*sln;

	sln = malloc(sizeof(t_sub_lst));
	if (!sln)
		return (NULL);
	sln->oper_used = oper_used;
	sln->stack_after_oper = stack_after_oper;
    sln->prev = NULL;
	sln->next = NULL;
    sln->prev_oper = NULL;
    sln->next_oper = NULL;
	return (sln);
}
