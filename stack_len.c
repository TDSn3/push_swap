/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:30:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/22 15:43:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	stack_len(int argc, char *argv[])
{
	int i;
	int	j;
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
			if (argv[i][j] != ' ' && argv[i][j] != '+' && argv[i][j] != '-' && (argv[i][j] < '0' || argv[i][j] > '9'))
				return (0);
			if (argv[i][j] == ' ')
			{
				while (argv[i][j] && argv[i][j] == ' ')
					j++;
				continue ;
			}
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				len++;
				while (argv[i][j] && argv[i][j] >= '0' && argv[i][j] <= '9')
					j++;
				continue ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (len);
}
