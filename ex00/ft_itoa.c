/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:41:31 by bfaisy            #+#    #+#             */
/*   Updated: 2023/07/15 10:57:32 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/* #include <stdio.h>
 */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	ft_swap(char *tab)
{
	int	i;
	int	j;
	char	tmp;

	j = ft_strlen(tab) - 1;
	i = 0;
	while (i < ft_strlen(tab) / 2)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}
}

char	*ft_itoa(long nb)
{
	char	*tab;
	int		i;
	int		count;
	long long		nb1;

	i = 0;
	nb1 = nb;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	tab = malloc(sizeof(char) * (count +1));
	if (tab == NULL)
		return (NULL);
	while (nb1 > 0)
	{
		tab[i++] = nb1 % 10 + '0';
		nb1 = nb1 /10;
	}
	tab[i] = '\0';
	ft_swap(tab);
	return (tab);
}
/* int main()
{
	char *str;
	str = ft_itoa(50);
	printf("%s", str);
} */
