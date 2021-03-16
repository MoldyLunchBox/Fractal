/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 05:05:10 by amya              #+#    #+#             */
/*   Updated: 2019/04/08 04:45:45 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*alloc(char *ptr, int max, int i)
{
	if (max < 0)
	{
		ptr = (char *)malloc(1);
		if (!ptr)
			return (NULL);
	}
	else
	{
		ptr = (char *)malloc(max - i + 2);
		if (ptr == NULL)
			return (0);
	}
	return (ptr);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*ptr;
	int		max;
	int		j;

	j = 0;
	i = 0;
	ptr = NULL;
	if (!s)
		return (NULL);
	max = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[max] == ' ' || s[max] == '\n' || s[max] == '\t')
		max--;
	if (!(ptr = alloc(ptr, max, i)))
		return (NULL);
	while (i <= max)
	{
		ptr[j] = s[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
