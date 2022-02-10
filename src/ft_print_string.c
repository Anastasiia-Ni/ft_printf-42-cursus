/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:48:16 by anifanto          #+#    #+#             */
/*   Updated: 2021/10/27 17:26:39 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putstr(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_s(char *str)
{
	int	res;

	res = 0;
	if (!str)
		str = "(null)";
	res += ft_putstr(str, ft_strlen(str));
	return (res);
}
