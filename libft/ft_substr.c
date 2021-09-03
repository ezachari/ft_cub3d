/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:29:02 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/03 14:31:09 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(d = (char *)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	if (NULL == s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			d[j] = s[i];
			j++;
		}
		i++;
	}
	d[j] = '\0';
	return (d);
}
