/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:52:25 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/06 16:05:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USEFUL_FUNCTION_H
# define USEFUL_FUNCTION_H

int	ascending_order_tab(int *tab, int size);
int	descending_order_tab(int *tab, int size);
int	*dup_tab(int *tab, int size);
int	setup_struct(t_data *d, int argc, char **argv);
int	return_error(void);
int	ss_cargv_part_two(char **argv, int *i, int *j);
int	check_int_max(char **argv, int i, int j);
int	check_int_min(char **argv, int i, int j);
int check_error(int argc, char **argv);
int	check_repeat(t_data *d);
int	pos_in_stack(int *tab, int size, int nb);

#endif