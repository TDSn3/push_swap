/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tli_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/06 15:50:05 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list_int.h"

t_tli	*tli_new(int content)
{
	t_tli	*ln;

	ln = malloc(sizeof(t_tli));
	if (!ln)
		return (NULL);
	ln->content = content;
	ln->next = NULL;
	return (ln);
}
