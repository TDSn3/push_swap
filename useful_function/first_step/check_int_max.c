/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:46:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/18 18:00:43 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	part_two(char **argv, int i, int j);
static int	part_three(char **argv, int i, int j);
static int	part_for(char **argv, int i, int j);

int	check_int_max(char **argv, int i, int j)
{
	int	x;

	x = 0;
	while (x <= 9)
	{
		if (!argv[i][j + x])
			return (0);
		x++;
	}
	if (argv[i][j + 0] > '2' || argv[i][j + 10])
		return (1);
	else if (argv[i][j + 0] == '2')
		if (part_two(argv, i, j))
			return (1);
	return (0);
}

static int	part_two(char **argv, int i, int j)
{
	if (argv[i][j + 1] > '1')
		return (1);
	else if (argv[i][j + 1] == '1')
	{
		if (argv[i][j + 2] > '4')
			return (1);
		else if (argv[i][j + 2] == '4')
			if (part_three(argv, i, j))
				return (1);
	}
	return (0);
}

static int	part_three(char **argv, int i, int j)
{
	if (argv[i][j + 3] > '7')
		return (1);
	else if (argv[i][j + 3] == '7')
	{
		if (argv[i][j + 4] > '4')
			return (1);
		else if (argv[i][j + 4] == '4')
		{	
			if (argv[i][j + 5] > '8')
				return (1);
			else if (argv[i][j + 5] == '8')
				if (part_for(argv, i, j))
					return (1);
		}
	}
	return (0);
}

static int	part_for(char **argv, int i, int j)
{
	if (argv[i][j + 6] > '3')
		return (1);
	else if (argv[i][j + 6] == '3')
	{
		if (argv[i][j + 7] > '6')
			return (1);
		else if (argv[i][j + 7] == '6')
		{
			if (argv[i][j + 8] > '4')
				return (1);
			else if (argv[i][j + 8] == '4')
			{
				if (argv[i][j + 9] > '7')
					return (1);
			}
		}
	}
	return (0);
}
