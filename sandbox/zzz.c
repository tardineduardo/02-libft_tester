/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zzz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:02:27 by eduribei          #+#    #+#             */
/*   Updated: 2024/05/20 17:53:24 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s++)
	{
		count++;
	}
	return (count);
}

static char	*ft_find_string(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	s;
	size_t	len_avail;
	char	*match;

	b = 0;
	s = 0;
	len_avail = ft_strlen((char *)big) - ft_strlen((char *)little);
	while (big[b] != '\0' && b <= len_avail && b < len)
	{
		if (big[b] == little[s])
		{
			match = (char *)&big[b];
			while (little[s] != '\0')
			{
				b++;
				s++;
				if (little[s] == '\0')
					return (match);
			}
			s = 0;
		}
		b++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_s;
	size_t	len_b;

	len_b = ft_strlen((char *)big);
	len_s = ft_strlen((char *)little);
	if (len_s > len_b)
		return (NULL);
	if (len_s > len)
		return (NULL);
		
	if (ft_strlen((char *)little) == 0)
		return ((char *)(big));
	else
		return (ft_find_string(big, little, len));
}


int main(void)
{
char *a = "123456";
char *b = "234";
char *test1a = strnstr(a, b, 3);
printf("strnstr() = %s", test1a);
char *test1b = ft_strnstr(b, a, 3);
printf("\n");
printf("ft_strnstr = %s", test1b);
printf("\n");
}