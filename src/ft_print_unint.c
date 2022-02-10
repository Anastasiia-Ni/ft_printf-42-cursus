/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:48:28 by anifanto          #+#    #+#             */
/*   Updated: 2021/10/27 19:57:37 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_lsize(long nb)
{
	int		size;

	size = 0;
	if (!nb)
		size++;
	while (nb)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static char	*ft_utoa(long nu)
{
	char	*str;
	int		len;

	len = ft_lsize(nu);
	str = (char *)ftf_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	if (nu == 0)
		str[0] = '0';
	while (nu != 0)
	{
		str[--len] = (nu % 10) + '0';
		nu /= 10;
	}
	return (str);
}

int	ft_print_u(unsigned int unb)
{
	int		res;
	char	*un_int;

	res = 0;
	unb = (unsigned int)(unb + 4294967295 + 1);
	un_int = ft_utoa(unb);
	res += ft_putstr(un_int, ft_strlen(un_int));
	free (un_int);
	return (res);
}
