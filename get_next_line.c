/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:26:21 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/01/18 00:03:08 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *str;
    char *buff;

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX || read(fd, buff, 0) < 0)
    {
        free(buff); 
        return (NULL);
    }
    if (read(fd, buff, BUFFER_SIZE) < 0)
        return (ft_free(buff, str));
 if (ft_check(buff)!= 0)
{
    ft_strjoin(&str,ft_substr(buff,0,ft_check(buff)),ft_check(buff));
    ft_strjoin(&str,ft_substr(buff,ft_check(buff)+1, ft_strlen(buff) - ft_check(buff) - 1),ft_strlen(buff)-ft_check(buff)-1);
}
    ft_strjoin(&str, buff,ft_strlen(buff));
    free( buff);
    return (str);
}



int main ()
{

    int fd;
    char *line;
    fd = open("test.txt",O_RDONLY);
    line = get_next_line(fd);
        printf("%s\n",line);
    close(fd);
    return 0;
}

// char *get_next_line(int fd)
// {
//     static char *str;
//     char *buff;

// buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// if (!buff)
//     return (NULL);
// if (fd <0 || BUFFER_SIZE <1 || BUFFER_SIZE > INT_MAX || read(fd,buff, 0) < 0)
//     return (NULL);
//     read (fd ,buff,BUFFER_SIZE);
// if (ft_check(buff)!= 0)
// {
//     ft_strjoin(&str,ft_substr(buff,0,ft_check(buff)),ft_check(buff));
//     ft_strjoin(&str,ft_substr(buff,ft_check(buff)+1,ft_strlen(buff)),ft_strlen(buff)-ft_check(buff));
// }
//     ft_strjoin(&str,buff,ft_strlen(buff));
//     ft_free(&str,buff);

//     return (str);
// }







// #include <stdlib.h>
// #include <limits.h> // Include for INT_MAX
// #include <unistd.h> // Include for read function

// #define BUFFER_SIZE 1024 // Adjust the buffer size as needed

// char *ft_substr(const char *s, unsigned int start, size_t len);
// void ft_strjoin(char **s1, const char *s2, size_t len);
// void ft_free(char **ptr1, char *ptr2);