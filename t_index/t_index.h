/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_index.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:48:31 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/15 19:50:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_INDEX_H
# define T_INDEX_H

t_index	*find_pos_max_tindex(t_index *tli);
t_index	*find_pos_min_tindex(t_index *tli);
void	tindex_add_back(t_index **lst, t_index *new);
void	tindex_clear_one(t_index **tli, int content);
void	tindex_clear(t_index **lst);
t_index	*tindex_last(t_index *lst);
t_index	*tindex_new(int content_index, int content_stack);
int		tindex_size(t_index *lst);

#endif