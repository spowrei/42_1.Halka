/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukaplan <mukaplan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:43:02 by mukaplan          #+#    #+#             */
/*   Updated: 2025/01/21 20:48:36 by mukaplan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

int	ft_format(va_list arg_list, char type);
int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putint(int n, int *fail);
int	ft_putstr(char *s);
int	ft_puthex(unsigned int a, char c);
int	ft_putptr(void *ptr);
int	ft_putunsigned(unsigned int n, int *fail);

#endif 
