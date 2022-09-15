/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:13:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/15 19:51:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	check_argv(int argc, char **argv);

int	check_error(int argc, char **argv)
{
	if (check_argv(argc, argv))
		return (return_error());
	return (0);
}

static int	check_argv(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc < 2 || !argv[1] || !argv[1][0])
		return (1);
	while (argv[i])
	{
		while (argv[i][j])
			if (ss_cargv_part_two(argv, &i, &j))
				return (1);
		j = 0;
		i++;
	}
	return (0);
}
