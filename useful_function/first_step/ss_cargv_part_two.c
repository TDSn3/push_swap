/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_cargv_part_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:50:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/18 18:49:35 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	check_plus(char **argv, int *i, int *j);
static int	check_minus(char **argv, int *i, int *j);

int	ss_cargv_part_two(char **argv, int *i, int *j)
{
	int	pos;
	int	stock;

	pos = argv[*i][*j];
	if (pos != '0' && check_int_max(argv, *i, *j) && argv[*i][0] != '-')
		return (1);
	stock = check_int_min(argv, *i, *j);
	if (pos != '0' && pos != '-' && stock && argv[*i][0] == '-')
		return (1);
	if (argv[*i][*j] != ' ')
		if (argv[*i][*j] != '-')
			if (argv[*i][*j] != '+')
				if (argv[*i][*j] < '0' || argv[*i][*j] > '9')
					return (1);
	if (check_minus(argv, i, j) || check_plus(argv, i, j))
		return (1);
	*j += 1;
	return (0);
}

static int	check_plus(char **argv, int *i, int *j)
{
	if (argv[*i][*j] == '+')
	{
		*j += 1;
		if (argv[*i][*j])
			if (argv[*i][*j] < '0' || argv[*i][*j] > '9')
				return (1);
		if (!argv[*i][*j])
			return (1);
		*j -= 2;
		if (argv[*i][*j])
			if (argv[*i][*j] != ' ')
				return (1);
		*j += 1;
	}
	return (0);
}

static int	check_minus(char **argv, int *i, int *j)
{
	if (argv[*i][*j] == '-')
	{
		*j += 1;
		if (argv[*i][*j])
			if (argv[*i][*j] < '0' || argv[*i][*j] > '9')
				return (1);
		if (!argv[*i][*j])
			return (1);
		*j -= 2;
		if (argv[*i][*j])
			if (argv[*i][*j] != ' ')
				return (1);
		*j += 1;
	}
	return (0);
}
