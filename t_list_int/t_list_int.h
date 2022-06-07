/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/07 07:22:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LIST_INT_H
# define T_LIST_INT_H

# include "../header.h"

typedef struct s_tli
{
	int				content;
	struct s_tli	*next;
}	t_tli;

t_tli	*tli_new(int content);
void	tli_add_back(t_tli **lst, t_tli *new);
int		tli_size(t_tli *lst);
t_tli	*tli_last(t_tli *lst);
void	tli_clear(t_tli **lst);
t_tli	*find_pos_max_tli(t_tli *tli);


#endif