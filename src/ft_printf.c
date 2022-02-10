/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:30:30 by anifanto          #+#    #+#             */
/*   Updated: 2021/10/27 19:56:58 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_isconv(int c)
{
	if (c == 'c' || c == 'd' || c == 's' || c == 'p' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	ft_define_format(t_flag *tab, char *str, va_list arg, int *poz)
{
	int	res;

	if (str[*poz] == 'c')
		res = ft_print_c(va_arg(arg, int));
	if (str[*poz] == 'd' || str[*poz] == 'i')
		res = ft_print_d(va_arg(arg, int), *tab);
	if (str[*poz] == 's')
		res = ft_print_s(va_arg(arg, char *));
	if (str[*poz] == 'p')
		res = ft_print_p(va_arg(arg, unsigned long long));
	if (str[*poz] == 'u')
		res = ft_print_u(va_arg(arg, unsigned int));
	if (str[*poz] == 'x')
		res = ft_print_x(va_arg(arg, unsigned int), *tab, 0);
	if (str[*poz] == 'X')
		res = ft_print_x(va_arg(arg, unsigned int), *tab, 1);
	if (str[*poz] == '%')
		res = ft_print_c('%');
	return (res);
}

static int	ft_def_input(char *str, va_list arg, t_flag *tab)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (str[++i])
	{
		if (!str[i])
			break ;
		else if (str[i] != '%')
			res += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			i++;
			ft_init_tab(tab);
			i = ft_defiflag(str, i, tab);
			if (ft_isconv(str[i]))
				res += ft_define_format(tab, str, arg, &i);
		}
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	t_flag	*tab;
	char	*str;
	int		res;

	res = 0;
	str = ft_strdup(format);
	if (!str)
		return (0);
	va_start(arg, format);
	tab = (t_flag *)malloc(sizeof(t_flag));
	if (!tab)
		return (-1);
	ft_init_tab(tab);
	res += ft_def_input(str, arg, tab);
	va_end(arg);
	free (str);
	free (tab);
	return (res);
}
