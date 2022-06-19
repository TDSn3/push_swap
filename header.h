/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/19 13:38:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./struct.h"
# include "./libft/libft.h"
# include "./sort_five/sort_five.h"
# include "./t_list_int/t_list_int.h"
# include "./smart_sort_five_b/smart_sort_five_b.h"
# include "./smart_sort_five_a/smart_sort_five_a.h"
# include "./operation/operation.h"
# include "./sort_five_double/sort_five_double.h"

int		setup_struct(t_data *d, int argc, char **argv);
t_tli	*tli_cpy(t_tli *tli, t_tli *stock_tli_a_ten);
void	setup_tli_ten(t_data *d);
void	setup_tli_five(t_data *d);

#endif
