/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:22:50 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 12:37:41 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] || (char)c == 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
#define SEARCH -2147483647

int	main(void)
{
	char	tab[] = "tripouille";
	printf("\n-- strchr :%s", strchr(tab, SEARCH));
	printf("\nft_strchr :%s ", ft_strchr(tab, SEARCH));
	strchr(tab, SEARCH) == ft_strchr(tab, SEARCH) ? 
printf("OK\n\n") : printf("NO\n\n");
	return (0);
}
*/
