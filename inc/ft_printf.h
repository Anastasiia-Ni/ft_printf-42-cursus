/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:38:54 by anifanto          #+#    #+#             */
/*   Updated: 2021/10/27 19:14:05 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <float.h>

typedef struct s_print
{
	int	hash;
	int	plus;
	int	space;
}	t_flag;

int		ft_printf(const char *format, ...);
int		ft_print_s(char *str);
int		ft_print_c(char c);
int		ft_print_d(int nb, t_flag tab);
int		ft_print_p(unsigned long long ull);
int		ft_print_x(unsigned int xnb, t_flag tab, int size);
int		ft_print_u(unsigned int unb);
char	*ft_ulltoa_base(unsigned long long ull, int base);
int		ft_putstr(char *str, int len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
void	*ftf_calloc(size_t count, size_t size);
int		ft_defiflag(char *str, int poz, t_flag *tab);
int		ft_isflag(int c);
t_flag	*ft_init_tab(t_flag *tab);

#endif