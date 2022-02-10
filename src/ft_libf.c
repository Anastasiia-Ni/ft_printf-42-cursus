/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:48:51 by anifanto          #+#    #+#             */
/*   Updated: 2021/10/27 18:47:39 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s != '\0')
	{
		n++;
		s++;
	}
	return (n);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;
	int		l;

	i = 0;
	l = ft_strlen(s1);
	dest = (char *)malloc((l + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	sym;

	ptr = (unsigned char *)b;
	sym = (unsigned char)c;
	while (len--)
		*ptr++ = sym;
	return (b);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ftf_calloc(size_t count, size_t size)
{
	void	*str;

	if (!size || !count)
	{
		size = 1;
		count = 1;
	}
	str = malloc(size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
