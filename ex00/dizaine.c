/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dizaine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:43:43 by bfaisy            #+#    #+#             */
/*   Updated: 2023/07/15 16:43:45 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int just_dizaine(int nb);
int just_centaine(int nb);
int boucle(int base);
int len(int nbr);

long *dizaine(int nb, int base, int bol)
{
    int count;
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