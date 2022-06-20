/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:12:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/20 09:17:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_duplicate_a(t_double_lst *dl, t_data *d, int *tab)
{
	t_double_lst	*copydl;
	t_sub_lst		*copysl;
	int				i;
	int				j;
	
	i = 0;
	j = 0;
	copydl = dl;
	if (!tab)
		return (0);
	while (copydl)
	{
		if (!dl || !dl->sub_lst || !dl->sub_lst->stack_after_oper)
		{
			free(tab);
			return (0);
		}
		copysl = copydl->sub_lst;
		while (copysl)
		{
			while (i < d->size_a)
			{
				if (copysl->stack_after_oper[i] == tab[i])
					j++;
				i++;
			}
			if (j == d->size_a)
			{
				free(tab);
				return (1);
			}
			i = 0;
			j = 0;
			copysl = copysl->next;
		}
		copydl = copydl->next;
	}
	free(tab);
	return (0);
}