/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:24:23 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/05 16:03:43 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	return_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}