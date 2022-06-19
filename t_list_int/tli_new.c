/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tli_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/19 11:19:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_tli	*tli_new(int content)
{
	t_tli	*ln;

	ln = malloc(sizeof(t_tli));
	if (!ln)
		return (NULL);
	ln->content = content;
	ln->next = NULL;
	ln->prev = NULL;
	return (ln);
}
