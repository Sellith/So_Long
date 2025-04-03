/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstring.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:12:05 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/01/10 03:07:27 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_printf_putstr(char *str)
{
	int	ret;

	if (str == NULL)
		return (write(1, "(null)", 6));
	ret = write(1, str, ft_printf_strlen(str));
	return (ret);
}

// int main(void)
// {
// 	ft_printf_putstr("nei");
// 	return (0);
// }
