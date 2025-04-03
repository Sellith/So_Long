/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:30:31 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/24 13:42:50 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*gnl_lstlast(t_gnl *lst)
{
	while (lst != NULL)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

int	found_new_line(t_gnl *stash)
{
	int		i;
	t_gnl	*current;

	if (stash == NULL)
		return (0);
	current = gnl_lstlast(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_count_n_malloc(t_gnl *stash, char **line)
{
	int	len;
	int	i;

	len = 0;
	while (stash != NULL)
	{
		i = 0;
		while (stash->content[i] != '\0')
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			i++;
			len++;
		}
		stash = stash->next;
	}
	*line = malloc(len + 1 * sizeof(char));
}

void	free_stash(t_gnl *stash)
{
	t_gnl	*next;
	t_gnl	*current;

	current = stash;
	while (current != NULL)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
