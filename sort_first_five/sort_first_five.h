/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_first_five.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/14 10:49:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_FIRST_FIVE_H
# define SORT_FIRST_FIVE_H

t_double_lst	*dl_new(void);
t_sub_lst		*sl_new(int oper_used, int *stack_after_oper, int nb_rra);
t_double_lst	*dl_last(t_double_lst *dl);
t_sub_lst		*sl_last(t_sub_lst *sl);
void			dl_add_back(t_double_lst **dl, t_double_lst *new_dl);
void			sl_add_back(t_sub_lst **sl, t_sub_lst *new_sl);
void			sl_link(t_sub_lst *sl, t_sub_lst *sl_prev);
void			dl_clear(t_double_lst **dl);
void			sl_int_clear(t_sub_lst **sl);
int				*sa_dt(int *tab, int size);
int				*ra_dt(int *tab, int size);
int				*rra_dt(int *tab, int size);
int				if_sorted_a(t_data *d, t_sub_lst *copy_sl);
void			make_all_oper_a(t_double_lst *dl, t_data *d);
void			sort_first_five_a(t_data *d);
int				check_duplicate_a(t_double_lst *dl, t_data *d, int *tab);

#endif