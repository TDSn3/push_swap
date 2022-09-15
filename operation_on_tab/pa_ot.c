/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_ot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/15 19:51:25 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	pa_two(int *tab_b, int size_a, int size_b);

void	pa_ot(int *tab_a, int *tab_b, int size_a, int size_b)
{
	int	tmp;
	int	tmp_two;
	int	i;

	i = 1;
	if (!tab_b || size_b < 1)
		return ;
	tmp = tab_a[0];
	tab_a[0] = tab_b[0];
	while (i < size_a + 1)
	{
		if (i == 1)
		{
			tmp_two = tab_a[i];
			tab_a[i] = tmp;
		}
		else
		{
			tmp = tab_a[i];
			tab_a[i] = tmp_two;
			tmp_two = tmp;
		}
		i++;
	}
	pa_two(tab_b, size_a, size_b);
}

static void	pa_two(int *tab_b, int size_a, int size_b)
{
	int	i;

	size_a++;
	i = 0;
	while (i < size_b)
	{
		if (i == size_b - 1)
			tab_b[i] = 0;
		else
			tab_b[i] = tab_b[i + 1];
		i++;
	}
	size_b--;
}
