/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:52:25 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/14 14:36:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USEFUL_FUNCTION_H
# define USEFUL_FUNCTION_H

int		ascending_order_tab(int *tab, int size);
int		descending_order_tab(int *tab, int size);
int		*dup_tab(int *tab, int size);
int		setup_struct(t_data *d, int argc, char **argv);
int		return_error(void);
int		ss_cargv_part_two(char **argv, int *i, int *j);
int		check_int_max(char **argv, int i, int j);
int		check_int_min(char **argv, int i, int j);
int		check_error(int argc, char **argv);
int		check_repeat(t_data *d);
int		pos_in_stack(int *tab, int size, int nb);
void    pb_sort(t_data *d, int min_index, int max_index, t_index *index_lst);
void	clear_all(t_data *d);
void	exe_rr_rrr(t_data *d);
void	smart_a(t_data *d, int next_index);
void	smart_b(t_data *d, int x);
int	    find_nb(int index, t_index *index_lst);
int	    smart_insertion(t_data *d, int nb);
int     find_pos_a(int nb, t_data *d);
int     find_nex_index(int min_id, int max_id, t_index *id_lst, t_data *d);
int	    find_pos_max_b(t_data *d);
void	ex_pa_end(t_data *d, int min_id, int sz_divd);
void	up_biggest_b(t_data *d);

#endif