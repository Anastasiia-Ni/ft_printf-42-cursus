/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:24:24 by anifanto          #+#    #+#             */
/*   Updated: 2021/10/27 17:25:06 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_c(char c)
{
	int	res;

	res = 0;
	res += ft_putchar(c);
	return (res);
}
