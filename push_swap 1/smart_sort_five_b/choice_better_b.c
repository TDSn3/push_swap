/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_better_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:18:29 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/22 07:54:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_tli	*choice_better_b(t_data *d, t_tli *tli)
{
	int		nb_pos;
	t_tli	*tli_cpy;
	t_tli	*tli_stock;

	if (!tli)
		return (NULL);
	nb_pos = choice_better_give_nb_b(d, tli->content);
	tli_cpy = tli->next;
	tli_stock = tli;
	while (tli_cpy)
	{
		if (choice_better_give_nb_b(d, tli_cpy->content) < nb_pos)
		{
			nb_pos = choice_better_give_nb_b(d, tli_cpy->content);
			tli_stock = tli_cpy;
		}
		tli_cpy = tli_cpy->next;
	}
	return (tli_stock);
}
