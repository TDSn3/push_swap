/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_rr_rrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:36:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/14 12:55:39 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	exe_one(t_data *d);

void	exe_rr_rrr(t_data *d)
{
	while (d->ra_i > 0 || d->rb_i > 0 || d->rra_i > 0 || d->rrb_i > 0)
	{
		if (d->rra_i && d->rrb_i)
		{
			rrr(&d);
			d->rra_i--;
			d->rrb_i--;
			continue ;
		}
		else if (d->ra_i && d->rb_i)
		{
			rr(&d);
			d->ra_i--;
			d->rb_i--;
			continue ;
		}
		exe_one(d);
	}
}

static void	exe_one(t_data *d)
{
		if (d->ra_i)
		{
			ra(d);
			d->ra_i--;
		}
		else if (d->rb_i)
		{
			rb(d);
			d->rb_i--;
		}
		else if (d->rra_i)
		{
			rra(d);
			d->rra_i--;
		}
		else if (d->rrb_i)
		{
			rrb(d);
			d->rrb_i--;
		}
}
