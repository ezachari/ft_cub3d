/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:32:23 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/03 14:31:23 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	const char *s;

	s = str;
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char*)s);
		s++;
	}
	if (*s == ch)
		return ((char*)s);
	return (NULL);
}
