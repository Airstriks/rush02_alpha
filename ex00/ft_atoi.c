/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 07:41:34 by bfaisy            #+#    #+#             */
/*   Updated: 2023/07/09 10:36:59 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include <unistd.h>

int	ft_strlen(char *str);

long long	boucle(int i, char *str)
{
	long long	nbr;

	nbr = 0;
	while (i != ft_strlen(str))
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = (str[i] - '0') + nbr * 10;
		else
			break ;
		i++;
	}
	return (nbr);
}

int	ft_strlen(char *str)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	return (j);
}

long long ft_atoi(char *str)
{
	int		i;
	long long	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] == '-')
			write(1, "Error\n", 6);
		if (str[i] >= '0' && str[i] <= '9')
			break ;
		else
			return (0);
	}
	nbr = boucle(i, str);
	return (nbr);
}

/* int main (int argc, char **argv)
{
	long long nbr;
	argc++;
	nbr = ft_atoi(argv[1]);
	printf("%lld", nbr);
} */