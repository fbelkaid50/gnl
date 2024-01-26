/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:02:09 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/01/17 23:56:18 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_free(char *buf, char **p)
{
	free(*p);
	*p = NULL;
	free(buf);
	return (NULL);
}
size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    if (!s)
		return (0);
    while (s[i])
        i++;
    return i;
}
size_t ft_check (char *str)
{
    size_t i;
    i=0;
    if (!str)
		return (-1);
    while (*str)
    {
        if (str[i] == '\n')
            return i;
        i++;
    }
    return (-1);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void ft_strjoin(char *s1, char *s2, size_t len)
{
    size_t i;
    size_t j;
    size_t existing_len = ft_strlen(*s1);
    if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}

    if (existing_len + len + 1 > BUFFER_SIZE)
    {
        free(*s1);
        free(s2);
        return;
    }
    i = 0;
    j = existing_len;

    while (i < len)
    {
        (*s1)[j++] = s2[i++];
    }

    (*s1)[j] = '\0';

    free(s2);
}

// void ft_strjoin(char **s1, char *s2,size_t len)
// {
//     size_t i ;
//     size_t j;

//     i=0 ;
//     j= ft_strlen(*s1);
//     while (i<len)
//         (*s1)[j++] = s2[i++];
//     (*s1)[j] = '\0';
//     free(s2);
// }