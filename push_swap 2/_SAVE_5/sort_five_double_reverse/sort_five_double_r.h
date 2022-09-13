/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_double_r.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 07:03:44 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/09 14:12:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_FIVE_DOUBLE_R_H
# define SORT_FIVE_DOUBLE_R_H

int		sfd_if_sorted_a_r(t_data *d, t_sub_lst *copy_sl, t_sub_lst **lst_oper);
void	sfd_make_all_oper_a_r(t_double_lst *dl, t_data *d, t_sub_lst **lst_oper);
void	sfd_sort_first_five_a_r(t_data *d, t_sub_lst **lst_oper);
int		sfd_if_sorted_b_r(t_data *d, t_sub_lst *copy_sl, t_sub_lst **lst_oper);
void	sfd_make_all_oper_b_r(t_double_lst *dl, t_data *d, t_sub_lst **lst_oper);
void	sfd_sort_first_five_b_r(t_data *d, t_sub_lst **lst_oper);
void	sort_five_double_r(t_data *d);
void	while_for_sfd_r(t_data *d, t_sub_lst **cpy_lo_a, t_sub_lst **cpy_lo_b);
int 	if_sorted_a_r(t_data *d, t_sub_lst *copy_sl);
int 	if_sorted_b_r(t_data *d, t_sub_lst *copy_sl);

#endif
