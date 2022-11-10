/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:08:53 by fgeorgea          #+#    #+#             */
/*   Updated: 2022/11/10 16:09:38 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	len;

	if (!src)
		return (0);
	len = ft_strlen(src);
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (len);
}

char	*ft_strdup(char *s1, int *check_nl)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	i = -1;
	while (s1[len])
	{
		if (s1[len] == '\n')
		{
			len++;
			break ;
		}
		len++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (++i < len)
		res[i] = s1[i];
	res[i] = '\0';
	if (len > 0 && res[i - 1] == '\n')
		*check_nl = i - 1;
	return (res);
}

char	*ft_strjoin(char *s1, char *s2, int *check_nl)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = -1;
	while (s1[++j])
		str[i++] = s1[j];
	free(s1);
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	if (len > 0 && str [i - 1] == '\n')
		*check_nl = 0;
	return (str);
}
