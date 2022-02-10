/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:24:09 by anifanto          #+#    #+#             */
/*   Updated: 2021/10/27 18:48:45 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_flag	*ft_init_tab(t_flag *tab)
{
	tab->hash = 0;
	tab->plus = 0;
	tab->space = 0;
	return (tab);
}

int	ft_isflag(int c)
{
	return (c == ' ' || c == '#' || c == '+');
}

int	ft_defiflag(char *str, int poz, t_flag *tab)
{
	while (str[poz])
	{
		if (!ft_isflag(str[poz]))
			break ;
		if (str[poz] == ' ')
			tab->space = 1;
		if (str[poz] == '#')
			tab->hash = 1;
		if (str[poz] == '+')
			tab->plus = 1;
		poz++;
	}
	return (poz);
}
