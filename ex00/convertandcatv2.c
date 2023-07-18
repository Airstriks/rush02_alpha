/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertandcat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpetit <kpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:54:21 by kpetit            #+#    #+#             */
/*   Updated: 2023/07/16 18:28:45 by kpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

long len(long nbr)
{
    long i;

    i = 0;
    while (nbr > 0)
    {
        nbr = nbr /10;
        i++;
    }
    return(i);
}

long boucle(long base)
{
    long i;
    long nb;

    i = 0;
    nb = 1;
    while (len(base) % 3 != 1)
        base = base / 10;
    while (nb *10 < base)
    {
        nb = nb *10;
        i++;
    }
    return (nb);
}
long just_centaine(long nb)
{
    long count;

    count = 0;
    while (nb > 100)
    {
        nb -= 100;
        count++;
    }
    return (count);
}

long just_dizaine(long nb)
{
    long count;

    count = 0;
    while (nb > 10)
    {
        nb -= 10;
        count++;
    }
    count *= 10;
    return (count);
}

long *centaine(long nb, long base, long bol)
{
    long count;
    long *tab;

    count = 0;
	tab = malloc(sizeof(long) * 5);
    if (tab == NULL)
        return (NULL);
    tab[0] = just_centaine(nb);
    nb = nb % 100;
    tab[1] = 100;
    tab[2] = just_dizaine(nb);
    nb = nb % 10;
    count = 0;
    while (nb != 0)
    {
        nb -= 1;
        count++;
    }
    tab[3] = count;
    if (bol == 0)
        tab[4]= boucle(base);
    if (bol == 1)
        tab[4] = -1;
    return (tab);
}



long	powerr(long nb, long power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	else
	{
		return (nb * powerr(nb, power - 1));
	}	
}

void	*ft_strintcat(long *dest, long *src, long size, long new_size)
{
	long	count;
	long	i;
	long j;

	i = 0;
	while (i != new_size)
	{
		dest[i + size] = src[i];
		i++;
	}
}

long	intlen(long long nb)
{
	long long	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

long *unite(long nb, long base, long bol)
{
    long count;
    long *tab;

    count = 0;
    tab = malloc(sizeof(long) * 2);
    if (tab == NULL)
        return (NULL);
    while (nb != 0)
    {
        nb -= 1;
        count++;
    }
    tab[0] = count;
    if (bol == 0)
        tab[1]= boucle(base);
    if (bol == 1)
        tab[1] = -1;
    return (tab);
}

long *dizaine(long nb, long base, long bol)
{
    long count;
    long *tab;

    count = 0;
    tab = malloc(sizeof(long) * 3);
    if (tab == NULL)
        return (NULL);
    tab[0] = just_dizaine(nb);
    nb = nb % 10;
    count = 0;
    while (nb != 0)
    {
        nb -= 1;
        count++;
    }
    tab[1] = count;
    if (bol == 0)
    	tab[2]= boucle(base);
    if (bol == 1)
        tab[2] = -1;
    return (tab);
}

int	taille_final(long nb)
{
	int	size_mod;
	int	count;

	count = 0;
	size_mod = intlen(nb);
	if (intlen(nb) % 3 == 0)
		count += 5;
	if (intlen(nb) % 3 == 1)
		count += 2;
	if (intlen(nb) % 3 == 2)
		count += 3;
	count = count + (( intlen(nb) / 3) * 5);
	return (count);
}

void	opticentaine(long	*size, long	*temp, long	*len, long	*flag)
{
	*size +=5;
	*temp = *temp - ( (*temp / powerr(10, (*len - 3))) * powerr(10, (*len - 3)));
	*flag = 1;
	*len -= 3;
}

void	optidizaine(long	*size, long	*temp, long	*len, long	*flag)
{
	*size +=3;
	*temp = *temp - ( (*temp / powerr(10, (*len - 2))) * powerr(10, (*len - 2)));
	*flag = 1;
	*len -= 2;
}

void	optiunite(long	*size, long	*temp, long	*len, long	*flag)
{
	*size +=2;
	*temp = *temp - ( (*temp / powerr(10, (*len - 1))) * powerr(10, (*len - 1)));
	*flag = 1;
	*len -= 1;
}


long	*convertandcat(long temp)
{
	long	size;
	long	len;
	long	*premier;
	long	flag;
	long	*deuxieme;
	premier = malloc(sizeof(long) * taille_final(temp)); // faire une fonction qui calcul la taille a allouer
	if (premier == NULL)
		return (NULL);
	size = 0;
	len = intlen(temp);
	flag = 0;
	while (len > 0)
	{
			if (flag == 0)
			{
				if (len % 3 == 0)
				{
					premier = centaine((temp / powerr(10, (len - 3))), temp, !(len >3));
					if (premier == NULL)
						return (NULL);
					opticentaine(&size, &temp, &len, &flag);
				}
				else if (len % 3 == 2)
				{
					premier = dizaine((temp / powerr(10, (len - 2))), temp, !(len >3));
					if (premier == NULL)
						return (NULL);
					optidizaine(&size, &temp, &len, &flag);
				}
				else if (len % 3 == 1)
				{
					premier = unite((temp / powerr(10, (len - 1))), temp, !(len >3));
					if (premier == NULL)
						return (NULL);
					optiunite(&size, &temp, &len, &flag);
				}
			}
			else
			{
				deuxieme = malloc(sizeof(long) * 5);
				if (deuxieme == NULL)
					return (NULL);
				deuxieme =  (centaine((temp / powerr(10, (len - 3))), temp, !(len >3)));
				temp = temp - ( (temp / powerr(10, (len - 3))) * powerr(10, (len - 3)));
				ft_strintcat(premier, deuxieme, size, 5);
				free(deuxieme);
				size += 5;
				len -= 3;
			}
	}
	return (premier);
}

long main(void)
{
	long	 nb = 6637587;
	
	long *test = malloc(15*sizeof(long));
	long i =0;
	
	test = convertandcat(nb);

 	while ( i<15)
	{
		printf("%ld \n", test[i]);
		i++;
	}
	
	printf("\n");
	return 0;
}