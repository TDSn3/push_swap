/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/04 10:10:35 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

int	OPER_;

typedef struct s_data
{
	int		*stack_a;
	int		size_a;
	int		*stack_b;
	int		size_b;
}	t_data;

# include "./operation/operation.h"
# include "./sort_five/sort_five.h"

int		setup_struct(t_data *d, int argc, char **argv);
void	show_stack(t_data d, int argc);
int		pos_in_stack(int *tab, int size, int nb);
int		find_pos_max(int *tab, int size);

#endif
