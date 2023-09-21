/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <liamzaengel@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:07:43 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/17 21:20:47 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_printhexa(unsigned int n, unsigned int *bwr);
void	ft_printhexacaps(unsigned int n, unsigned int *bwr);
void	ft_ptr(unsigned long long n, unsigned int *bwr);
void	ft_printptr(unsigned long long n, unsigned int *bwr);
void	ft_putstr(char *s, unsigned int *bwr);
void	ft_putnbr(int n, unsigned int *bwr);
void	ft_putunbr(unsigned int n, unsigned int *bwr);
void	ft_putchar(char c, unsigned int *bwr);

#endif