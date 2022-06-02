/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_ot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:11:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/21 12:11:40 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int    *rra_ot(int *tab, int size)
{
    int tmp;
	int tmp_two;
	int i;
	
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
        {
            tmp = tab[i];
            tab[i] = tmp_two;
            tmp_two = tmp;
        }
		i++;
	}
	return (tab);
}