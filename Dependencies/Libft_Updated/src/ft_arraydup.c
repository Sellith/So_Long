/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 00:42:36 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/31 16:56:07 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraydup(char **array)
{
	int		i;
	int		len;
	char	**buffer;

	if (array == NULL)
		return (NULL);
	len = darraylen(array);
	buffer = ft_calloc(len + 1, sizeof(char *));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (array[i] != NULL)
	{
		buffer[i] = ft_strdup(array[i]);
		i++;
	}
	buffer[len] = NULL;
	return (buffer);
}

// int	main(int argc, char **argv)
// {
// 	char	**buffer;
// 	int		i;

// 	i = 0;
// 	buffer = ft_arraydup(argv, argc + 1);
// 	if (buffer == NULL)
// 	{
// 		ft_putstr_fd("(NULL)", 1);
// 		return (0);
// 	}
// 	while (argc != i)
// 		printf("%s\n", buffer[i++]);
// 	while (i + 1 > 0)
// 	{
// 		free(buffer[i]);
// 		i--;
// 	}
// 	free(buffer);
// 	return (0);
// }
