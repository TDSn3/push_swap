/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_dt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/01 14:40:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int    *sa_dt(int *tab, int size)
{
	int	*copy;
	int tmp;

	if (!tab || size < 2)
		return (NULL);
	else
	{
		copy = dup_tab(tab, size);
		if (!copy)
			return (NULL);
		tmp = copy[0];
		copy[0] = copy[1];
		copy[1] = tmp;
	}
	return (copy);
}