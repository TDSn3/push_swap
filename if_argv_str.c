/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_argv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:31:03 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/24 17:54:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int if_argv_str(int argc, char **argv)
{
	int		i;
	int		j;
	int		nb_str;

	i = 1;
	j = 0;
	nb_str = 0;
	if (argc < 2 || !argv[1] || !argv[1][0])
		return (0);
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] != ' ' && argv[i][j] != '+' && argv[i][j] != '-' && (argv[i][j] < '0' || argv[i][j] > '9'))
				return (0);
			if (argv[i][j] == ' ' || argv[i][j] == '+' || argv[i][j] == '-')
			{
					nb_str++;
					break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (nb_str);
}