/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tindex_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/10 18:01:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_index	*tindex_new(int content_index, int content_stack)
{
	t_index	*ln;

	ln = malloc(sizeof(t_index));
	if (!ln)
		return (NULL);
	ln->content_index = content_index;
	ln->content_stack = content_stack;
	ln->next = NULL;
	ln->prev = NULL;
	return (ln);
}
