/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_dt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:11:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/20 10:09:41 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	rra_dt_two(int *tmp, int *copy, int *tmp_two, int i);

int	*rra_dt(int *tab, int size)
{
	int	*copy;
	int	tmp;
	int	tmp_two;
	int	i;

	tmp = 0;
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
			rra_dt_two(&tmp, copy, &tmp_two, i);
		i++;
	}
	return (copy);
}

static void	rra_dt_two(int *tmp, int *copy, int *tmp_two, int i)
{
	*tmp = copy[i];
	copy[i] = *tmp_two;
	*tmp_two = *tmp;
}
