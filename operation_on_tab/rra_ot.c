/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_ot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:11:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/04 14:33:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	rra_ot_two(int *tmp, int *tab, int *tmp_two, int i);

int	*rra_ot(int *tab, int size)
{
	int	tmp;
	int	tmp_two;
	int	i;

	tmp = 0;
	if (!tab || size < 2)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (i == 0)
		{
			tmp_two = tab[i];
			tab[i] = tab[size - 1];
		}
		else
			rra_ot_two(&tmp, tab, &tmp_two, i);
		i++;
	}
	return (tab);
}

static void	rra_ot_two(int *tmp, int *tab, int *tmp_two, int i)
{
	*tmp = tab[i];
	tab[i] = *tmp_two;
	*tmp_two = *tmp;
}
