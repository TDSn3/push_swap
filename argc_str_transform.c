/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_str_transform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:10:42 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/24 17:25:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	argc_str_transform(t_data *d, int argc, char **argv)
{
	int		i;
	int		j;
	int		save_j;
	int		size;
	int		nb_nega;
	char	*str;

	i = 1;
	j = 0;
	size = 0;
	nb_nega = 0;
	str = NULL;
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
				while (argv[i][j] && (argv[i][j] == ' ' || argv[i][j] == '+' || argv[i][j] == '-'))
				{
					if (argv[i][j] == '-')
						nb_nega++;
					else
						nb_nega = 0;
					j++;
				}
				continue ;
			}
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				while (argv[i][j] && argv[i][j] >= '0' && argv[i][j] <= '9')
				{
					size++;
					j++;
				}
				save_j = j - 1;
				if (nb_nega % 2 == 1)
					size++;
				str = malloc(size + 1);
				if (!str)
				{
					write(2, "Error\n", 6);
					return (1);
				}
				str[size] = 0;
				if (size == 0)
					break ;
				size--;
				while (size >= 0)
				{
					str[size] = argv[i][save_j];
					size--;
					save_j--;
					if (nb_nega % 2 == 1 && size == 0)
					{
						str[0] = '-';
						break;
					}
				}
				printf("\n-->%s\n", str);
				free(str);
				save_j = 0;
				size = 0;
				nb_nega = 0;
				continue ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	(void) d;
	return (0);
}