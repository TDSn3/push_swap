/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_dt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:11:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/21 12:11:40 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int    *rra_dt(int *tab, int size)
{
    int	*copy;
	int tmp;
	int tmp_two;
	int i;
	
	if (!tab || size < 2)
		return (NULL);
	i = 0;
	copy = dup_tab(tab, size);
	if (!copy)
		return (NULL);
	while (i < size)
	{
		if (i == 0)
		{
			tmp_two = copy[i];
			copy[i] = copy[size - 1];
		}
        else
        {
            tmp = copy[i];
            copy[i] = tmp_two;
            tmp_two = tmp;
        }
		i++;
	}
	return (copy);
}