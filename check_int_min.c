/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:48:59 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/29 09:01:19 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_int_min(char **argv, int i, int j)
{
	if (j != 10 && !argv[i][10])
		return (0);
	if (argv[i][0] == '-')
		if (argv[i][1] >= '2')
			if (argv[i][2] >= '1')
				if (argv[i][3] >= '4')
					if (argv[i][4] >= '7')
						if (argv[i][5] >= '4')
							if (argv[i][6] >= '8')
								if (argv[i][7] >= '3')
									if (argv[i][8] >= '6')
										if (argv[i][9] >= '4')
											if (argv[i][10] > '8')
												return (1);
	return (0);
}
