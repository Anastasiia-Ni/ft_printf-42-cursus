/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:24:51 by anifanto          #+#    #+#             */
/*   Updated: 2021/10/27 20:00:02 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*ft_strtoupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int	ft_print_x(unsigned int xnb, t_flag tab, int size)
{
	int		res;
	char	*hex;

	res = 0;
	xnb = (unsigned int)(xnb + 4294967295 + 1);
	if (tab.hash == 1 && xnb != 0)
	{
		if (size == 1)
			res += ft_putstr("0X", 2);
		else
			res += ft_putstr("0x", 2);
	}
	hex = ft_ulltoa_base((unsigned long long)xnb, 16);
	if (size == 1)
		hex = ft_strtoupper(hex);
	res += ft_putstr(hex, ft_strlen(hex));
	free (hex);
	return (res);
}
