/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unite.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:47:41 by bfaisy            #+#    #+#             */
/*   Updated: 2023/07/15 16:47:44 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


long boucle(int base);
long len(int nbr);

long *unite(int nb, long base, int bol)
{
    int count;
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