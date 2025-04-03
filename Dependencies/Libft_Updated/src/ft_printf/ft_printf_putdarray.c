/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putdarray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:35:45 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/31 17:15:06 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putdarray(char **darray)
{
	int	i;

	i = 0;
	while (darray[i])
	{
		ft_printf_putstr(darray[i++]);
		write(1, "\n", 1);
	}
	return (i);
}
