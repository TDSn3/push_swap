/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:36:43 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/27 22:41:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	setup_struct_two(t_data *d);
static int	check_argv(int argc, char **argv);
static int	return_error(void);
static int	check_int_max(char **argv, int i, int j);
static int	check_int_min(char **argv, int i, int j);

int	setup_struct(t_data *d, int argc, char **argv)
{
	int	i;

	i = 1;
	if (check_argv(argc, argv))
		return (return_error());
	d->stack_a = malloc(sizeof(int) * argc - 1);
	if (!d->stack_a)
		return (return_error());
	d->stack_b = malloc(sizeof(int) * argc - 1);
	if (!d->stack_b)
		return (return_error());
	d->size_a = argc - 1;
	d->size_b = 0;
	while (i < argc)
	{
		d->stack_a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	setup_struct_two(d);
	return (0);
}

static void	setup_struct_two(t_data *d)
{
	d->stock_tli_a_ten = NULL;
	d->firstpart_stock_a_ten = NULL;
	d->stock_tli_b_ten = NULL;
	d->firstpart_stock_b_ten = NULL;
	d->stock_tli_a_five = NULL;
	d->firstpart_stock_a_five = NULL;
	d->stock_tli_b_five = NULL;
	d->firstpart_stock_b_five = NULL;
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
		{
			if (j == 9 && check_int_max(argv, i, j))
				return (1);
			if (j == 10 && check_int_min(argv, i, j))		
				return (1);
			if (argv[i][j] != ' ')
				if (argv[i][j] != '-')
					if (argv[i][j] < '0' || argv[i][j] > '9')
						return (1);
			if (argv[i][j] == '-')
			{
				j++;
				if (argv[i][j])
					if (argv[i][j] < '0' || argv[i][j] > '9')
						return (1);
				if (!argv[i][j])
					return (1);
				j--;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static int	return_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

static int	check_int_max(char **argv, int i, int j)
{
	if (j != 9 && !argv[i][9])
		return (0);
	if (argv[i][0] >= '2')
		if (argv[i][1] >= '1')
			if (argv[i][2] >= '4')
				if (argv[i][3] >= '7')
					if (argv[i][4] >= '4')
						if (argv[i][5] >= '8')
							if (argv[i][6] >= '3')
								if (argv[i][7] >= '6')
									if (argv[i][8] >= '4')
										if (argv[i][9] > '7')
											return (1);
	return (0);
}

static int	check_int_min(char **argv, int i, int j)
{
	if (j != 10 && !argv[i][10])
		return (0);
	if (argv[i][0] == '-')
		if (argv[i][1] >= '2')
			if (argv[i][2] >= '1')
				if (argv[i][3] >= '4')
					if (argv[i][4] >= '7')
						if (argv[i][5] >= '4')
							if (argv[i][6] >= '8')
								if (argv[i][7] >= '3')
									if (argv[i][8] >= '6')
										if (argv[i][9] >= '4')
											if (argv[i][10] > '8')
												return (1);
	return (0);
}
