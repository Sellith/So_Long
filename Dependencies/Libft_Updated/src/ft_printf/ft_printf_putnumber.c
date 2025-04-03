/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnumber.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 04:28:27 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/01/15 23:51:33 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putnumber(int nmb)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (nmb < 0)
	{
		res += ft_printf_putchar('-');
		sign = -1;
	}
	if (nmb / 10)
		res += ft_printf_putnumber((nmb / 10) * sign);
	res += ft_printf_putchar((nmb % 10) * sign + '0');
	return (res);
}

// int	main(void)
// {
// 	int	res;

// 	res = ft_printf_putnumber(214747);
// 	printf("\n%d", res);
// 	return (0);
// }
