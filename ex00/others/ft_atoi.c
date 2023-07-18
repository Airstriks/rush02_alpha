/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:17:06 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/15 17:27:34 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	ft_atoi(char *str)
{
	int				i;
	int				isneg;
	int				res;

	i = 0;
	isneg = 1;
	res = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while ((str[i] == 43) || (str[i] == 45))
	{
		if (str[i] == 45)
			isneg *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * isneg);
}

/*#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int n = ft_atoi(argv[1]);
	printf("%d\n", n);
	return (0);
}*/
