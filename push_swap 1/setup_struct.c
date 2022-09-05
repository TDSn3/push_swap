/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:36:43 by tda-silv          #+#    #+#             */
/*   Updated: 2022/08/29 15:43:02 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	setup_struct_two(t_data *d);
static int	check_argv(int argc, char **argv);
static void	part_two(t_data *d, int argc);

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
	part_two(d, argc);
	while (i < argc)
	{
		d->stack_a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (check_repeat(d))
	{
		free(d->stack_a);
		free(d->stack_b);
		return (return_error());
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
			if (ss_cargv_part_two(argv, &i, &j))
				return (1);
		j = 0;
		i++;
	}
	return (0);
}

static void	part_two(t_data *d, int argc)
{
	d->size_a = argc - 1;
	d->size_b = 0;
}
