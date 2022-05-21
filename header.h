/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/31 17:35:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;
}	t_data;

void    sa(t_data *d);
void    sb(t_data *d);
void    ss(t_data **d);
void    pa(t_data *d);
void    pb(t_data *d);
void    ra(t_data *d);
void    rb(t_data *d);
void    rr(t_data **d);
void    rra(t_data *d);
void    rrb(t_data *d);
void    rrr(t_data **d);
int		setup_struct(t_data *d, int argc, char **argv);
int		ascending_order_a(t_data d);
int		find_max_a(t_data d);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);

#endif