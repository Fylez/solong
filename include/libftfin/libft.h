/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liam <liam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:20:53 by lzaengel          #+#    #+#             */
/*   Updated: 2023/09/22 18:21:52 by liam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_tolower(int character);
int		ft_toupper(int character);
int		ft_isprint(int character);
int		ft_isascii(int character);
int		ft_isdigit(int character);
int		ft_isalnum(int character);
int		ft_isalpha(int character);
void	*ft_memset( void *pointer, int value, size_t count );
char	*ft_strdup( const char *source );
int		ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *tofind, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *string, int searchedChar);
void	*ft_memcpy( void *destination, const void *source, size_t size );
void	*ft_memmove( void *destination, const void *source, size_t size );
int		ft_memcmp( const void *pointer1, const void *pointer2, size_t size );
void	*ft_calloc( size_t elementCount, size_t elementSize );
void	*ft_memchr( const void *memoryBlock, int searchedChar, size_t size );
int		ft_atoi( const char *theString );
char	*ft_strrchr( const char *string, int searchedChar);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_itoa(int n);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif