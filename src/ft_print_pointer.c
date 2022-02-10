/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:35:36 by anifanto          #+#    #+#             */
/*   Updated: 2021/10/27 18:48:18 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	len_nbr_base(unsigned long long nb, int base)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		len += 1;
		nb /= base;
	}
	return (len);
}

char	*ft_ulltoa_base(unsigned long long ull, int base)
{
	int					len;
	unsigned long long	nb;
	char				*str;
	char				*base_str;

	len = len_nbr_base(ull, base);
	nb = ull;
	base_str = ft_strdup("0123456789abcdef");
	if (!base_str)
		return (NULL);
	str = (char *)ftf_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (ull == 0)
		str[0] = '0';
	while (nb)
	{
		str[--len] = base_str[nb % base];
		nb /= base;
	}
	free(base_str);
	return (str);
}

int	ft_print_p(unsigned long long ull)
{
	int		res;
	char	*pointer;

	res = 0;
	pointer = ft_ulltoa_base(ull, 16);
	res += ft_putstr("0x", 2);
	res += ft_putstr(pointer, ft_strlen(pointer));
	free (pointer);
	return (res);
}
