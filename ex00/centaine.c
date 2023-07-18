/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printeur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:28:48 by bfaisy            #+#    #+#             */
/*   Updated: 2023/07/15 13:28:50 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

long len(long nbr)
{
    int i;

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
    int i;
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
int just_centaine(int nb)
{
    int count;

    count = 0;
    while (nb > 100)
    {
        nb -= 100;
        count++;
    }
    return (count);
}

int just_dizaine(int nb)
{
    int count;

    count = 0;
    while (nb > 10)
    {
        nb -= 10;
        count++;
    }
    count *= 10;
    return (count);
}

long *centaine(int nb, long base, int bol)
{
    int count;
    long *tab;

    count = 0;
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
/* int main()
{
    int i = 0;
    long *nb;
    nb = malloc(sizeof(int) * 4);
    nb =centaine(109, 109000);
    while ( i != 5)
    {
        printf("%ld", nb[i]);
        printf("\n");
        i++;
    }
} */