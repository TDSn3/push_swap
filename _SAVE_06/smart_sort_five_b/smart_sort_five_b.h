/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort_five_b.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:18:15 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/10 12:26:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMART_SORT_FIVE_B_H
# define SMART_SORT_FIVE_B_H

int		choice_better_give_nb(t_data *d, int nb);
int		choice_better_give_nb_b(t_data *d, int nb);
t_tli	*choice_better(t_data *d, t_tli *tli);
t_tli	*choice_better_b(t_data *d, t_tli *tli);
t_tli	*five_smaller_a(t_data *d, t_tli *tli);
t_tli	*five_smaller_b(t_data *d, t_tli *tli, t_tli *stock_tli_b);
void    up_smaller_tli_b(t_data *d, t_tli *tli, t_tli *firstpart_stock);
int		pos_in_stack(int *tab, int size, int nb);
void	rotate_choice(t_data *d, t_tli *tli);

#endif