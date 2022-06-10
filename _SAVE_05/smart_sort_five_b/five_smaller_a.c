/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_smaller_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:18:27 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/07 13:28:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header.h"

t_tli	*five_smaller_a(t_data *d, t_tli *tli)
{
	int	i;
	t_tli	*tli_cpy;
	
	i = tli_size(tli);
	tli_cpy = tli;
	if (d->size_a == 0)
		return (NULL);

	while (i < d->size_a)
	{
		while (tli_cpy)
		{
			if (tli_cpy->content > d->stack_a[i])
			{
				find_pos_min_tli(tli)->content = d->stack_a[i];
				break;
			}
			tli_cpy = tli_cpy->next;
		}
		tli_cpy = tli;
		i++;
	}
	return (tli);
}