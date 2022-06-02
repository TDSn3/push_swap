/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_ot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:15:50 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/21 11:15:52 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int    *ra_ot(int *tab, int size)
{
	int	stock_first;
	int i;
	
	if (!tab || size < 2)
		return (NULL);
	stock_first = tab[0];
	i = 0;
	while (i < size)
	{
		if (i == size - 1)
			tab[i] = stock_first;
		else
			tab[i] = tab[i + 1];
		i++;
	}
	return (tab);
}