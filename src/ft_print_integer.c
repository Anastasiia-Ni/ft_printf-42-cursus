/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:34:59 by anifanto          #+#    #+#             */
/*   Updated: 2021/10/27 19:59:33 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_size(int nb)
{
	int		size;

	size = 0;
	if (!nb)
		size++;
	if (nb < 0)
		size++;
	while (nb)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_size(n);
	str = (char *)ftf_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--len] = (n % 10) + '0';
		if (n < 0)
			str[len] = ((n % 10) * -1) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_print_d(int nb, t_flag tab)
{
	char	*str;
	int		res;

	res = 0;
	if (tab.space == 1 && nb >= 0 && tab.plus == 0)
		res += ft_putchar(' ');
	if (tab.plus == 1 && nb >= 0)
		res += ft_putchar('+');
	str = ft_itoa(nb);
	res += ft_putstr(str, ft_strlen(str));
	free (str);
	return (res);
}
