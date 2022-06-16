/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:01:58 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/01 14:42:08 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	*dup_tab(int *tab, int size)
{
	int	i;
	int	*tab_copy;

	i = 0;
	if (size > 0 && tab)
	{
		tab_copy = malloc(sizeof(int) * size);
		if (!tab)
		{
			write(2, "Error\n", 6);
			return (NULL);
		}
		while (i < size)
		{
			tab_copy[i] = tab[i];
			i++;
		}
		return (tab_copy);
	}
	return (NULL);
}