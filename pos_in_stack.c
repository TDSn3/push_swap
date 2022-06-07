/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_in_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 07:55:30 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/04 07:55:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	pos_in_stack(int *tab, int size, int nb)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (nb == tab[i])
			return (i);
		i++;
	}
	return (-1);
}