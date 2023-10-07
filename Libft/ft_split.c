/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:30:16 by darotche          #+#    #+#             */
/*   Updated: 2023/07/04 19:49:51 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_count(char const *s, char c)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (*s)
	{
		if (*s != c && b == 0)
		{
			i++;
			b = 1;
		}
		else if (*s == c && b == 1)
			b = 0;
		s++;
	}
	return (i);
}

char	**ft_split(char const	*s, char c)
{
	char	**arrstr;
	int		len;
	int		i;

	arrstr = (char **)malloc((str_count(s, c) + 1) * sizeof(char *));
	if (!s || !arrstr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			arrstr[i++] = ft_substr(s, 0, len);
			s = s + len;
		}
	}
	arrstr[i] = NULL;
	return (arrstr);
}

#include <stdio.h>
int main()
{
    char *s = "hello, world, whats up, and other questions.";
    char **as = ft_split(s, ' ');
    int wordCount = str_count(s,  ' ');

    printf("\033[1;35mThe number of strings is: %d\033[0m\n", wordCount);

    int i;
    i = 0; 
    while (as[i])
    {
        printf("\033[3;34mString: \033[0m%s\n", as[i]);
        i++;
    }
    return 0;
}
