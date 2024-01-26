/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:03:28 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/01/18 00:00:46 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include<fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <unistd.h>


   char *get_next_line(int fd);
   void ft_free(char **str,char *s);
   size_t ft_strlen(const char *s);
    size_t ft_check (char *str);
    char	*ft_substr(char const *s, unsigned int start, size_t len);
    void ft_strjoin(char **s1, char *s2, size_t len);   


#endif