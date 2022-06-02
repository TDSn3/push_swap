/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_dt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:15:50 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/01 14:40:16 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int    *ra_dt(int *tab, int size)
{
    int	*copy;
	int	stock_first;
	int i;
	
	if (!tab || size < 2)
		return (NULL);
	copy = dup_tab(tab, size);
	if (!copy)
		return (NULL);
	stock_first = copy[0];
	i = 0;
	while (i < size)
	{
		if (i == size - 1)
			copy[i] = stock_first;
		else
			copy[i] = copy[i + 1];
		i++;
	}
	return (copy);
}