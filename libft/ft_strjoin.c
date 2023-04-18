/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:52:56 by cllovio           #+#    #+#             */
/*   Updated: 2023/04/10 15:40:02 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*new_s;

	i = -1;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(new_s))
		return (NULL);
	while (s1[++i])
	{
		new_s[k] = s1[i];
		k++;
	}
	i = -1;
	while (s2[++i])
	{
		new_s[k] = s2[i];
		k++;
	}
	new_s[k] = '\0';
	return (new_s);
}
