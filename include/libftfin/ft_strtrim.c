/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:56:51 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 09:56:51 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	issep(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1);
	while (issep(s1[i], set) == 1 && s1[i])
		i++;
	while (issep(s1[j - 1], set) == 1 && j > 0)
		j--;
	return (ft_substr(s1, i, j - i));
}
/*
int		main()
{
		char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
		printf("%s",ft_strtrim(s1, " "));
		char s2[] = "lorem ipsum dolor sit amet";
		printf("%s",ft_strtrim(s2, "t"));
		char s3[] = " lorem ipsum dolor sit amet";
		printf("%s",ft_strtrim(s3, "1 "));
	return (0);
}
*/