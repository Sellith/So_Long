/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:35:17 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/01/15 23:32:49 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_puthexa(unsigned long nmb, char format)
{
	char	*def;
	int		res;

	if (format == 'x')
		def = "0123456789abcdef";
	else
		def = "0123456789ABCDEF";
	res = 0;
	if (nmb / 16)
		res += ft_printf_puthexa(nmb / 16, format);
	res += ft_printf_putchar(def[nmb % 16]);
	return (res);
}
