/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:30:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/29 09:18:16 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	part_two(char **argv, int i, int *j, size_t *len);

size_t	stack_len(int argc, char *argv[])
{
	int		i;
	int		j;
	int		stock;
	size_t	len;

	i = 1;
	j = 0;
	len = 0;
	if (argc < 2 || !argv[1] || !argv[1][0])
		return (0);
	while (argv[i])
	{
		while (argv[i][j])
		{
			stock = part_two(argv, i, &j, &len);
			if (stock == -1)
				return (0);
			else if (stock == 1)
				continue ;
		}
		j = 0;
		i++;
	}
	return (len);
}

static int	part_two(char **argv, int i, int *j, size_t *len)
{
	if (argv[i][*j] != ' ')
		if (argv[i][*j] != '+')
			if (argv[i][*j] != '-')
				if ((argv[i][*j] < '0' || argv[i][*j] > '9'))
					return (-1);
	if (argv[i][*j] == ' ')
	{
		while (argv[i][*j] && argv[i][*j] == ' ')
			*j += 1;
		return (1);
	}
	if (argv[i][*j] >= '0' && argv[i][*j] <= '9')
	{
		*len += 1;
		while (argv[i][*j] && argv[i][*j] >= '0' && argv[i][*j] <= '9')
			j++;
		return (1);
	}
	*j += 1;
	return (0);
}
