/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:13:47 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/31 17:02:39 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <aio.h>

int	ft_printf_putchar(char c);
int	ft_printf_puthexa(unsigned long nmb, char format);
int	ft_printf_putptr(void *ptr);
int	ft_printf_strlen(char *str);
int	ft_printf_putstr(char *str);
int	ft_printf_putnumber(int nmb);
int	selec(char format, va_list args);
int	ft_printf_putunsigned(unsigned int nmb);
int	ft_printf(const char *format, ...);
int	ft_printf_puterror(char *str);
int	ft_printf_putdarray(char **darray);

#endif
