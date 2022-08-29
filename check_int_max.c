/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:46:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/08/29 11:26:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	part_two(char **argv, int i);
static int	part_three(char **argv, int i);
static int	part_for(char **argv, int i);

int	check_int_max(char **argv, int i, int j)
{
	if (j != 9 && !argv[i][9])
		return (0);
	if (argv[i][0] > '2' || argv[i][10])
		return (1);
	else if (argv[i][0] == '2')
		if (part_two(argv, i))
			return (1);
	return (0);
}

static int	part_two(char **argv, int i)
{
	if (argv[i][1] > '1')
		return (1);
	else if (argv[i][1] == '1')
	{
		if (argv[i][2] > '4')
			return (1);
		else if (argv[i][2] == '4')
			if (part_three(argv, i))
				return (1);
	}
	return (0);
}

static int	part_three(char **argv, int i)
{
	if (argv[i][3] > '7')
		return (1);
	else if (argv[i][3] == '7')
	{
		if (argv[i][4] > '4')
			return (1);
		else if (argv[i][4] == '4')
		{	
			if (argv[i][5] > '8')
				return (1);
			else if (argv[i][5] == '8')
				if (part_for(argv, i))
					return (1);
		}
	}
	return (0);
}

static int	part_for(char **argv, int i)
{
	if (argv[i][6] > '3')
		return (1);
	else if (argv[i][6] == '3')
	{
		if (argv[i][7] > '6')
			return (1);
		else if (argv[i][7] == '6')
		{
			if (argv[i][8] > '4')
				return (1);
			else if (argv[i][8] == '4')
			{
				if (argv[i][9] > '7')
					return (1);
			}
		}
	}
	return (0);
}
