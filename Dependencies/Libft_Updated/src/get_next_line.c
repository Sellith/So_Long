/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:27:44 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/24 16:51:16 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_n_stash(int fd, t_gnl **stash)
{
	char	*buffer;
	int		red_ptr;

	red_ptr = 1;
	while (!found_new_line(*stash))
	{
		buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
		if (buffer == NULL)
			return ;
		red_ptr = (int)read(fd, buffer, BUFFER_SIZE);
		if (red_ptr <= 0)
		{
			if ((*stash) && red_ptr < 0)
			{
				free_stash((*stash));
				(*stash) = NULL;
			}
			return (free(buffer));
		}
		buffer[red_ptr] = '\0';
		add_to_stash(stash, buffer, red_ptr);
		free(buffer);
	}
}

void	add_to_stash(t_gnl **stash, char *buffer, int red)
{
	int		i;
	t_gnl	*current;
	t_gnl	*new;

	new = malloc(sizeof(t_gnl));
	if (new == NULL)
		return ;
	new->next = NULL;
	new->content = malloc((red + 1) * sizeof(char));
	if (new->content == NULL)
		return (free(new));
	i = -1;
	while (buffer[++i] != '\0' && i < red)
		new->content[i] = buffer[i];
	new->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new;
		return ;
	}
	current = gnl_lstlast(*stash);
	current->next = new;
}

void	extract_line(t_gnl *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	ft_count_n_malloc(stash, line);
	if (*line == NULL)
		return (free_stash(stash));
	j = 0;
	while (stash != NULL)
	{
		i = 0;
		while (stash->content[i] != '\0')
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_gnl **stash)
{
	t_gnl	*last;
	t_gnl	*stash_nl;
	int		i;
	int		j;

	stash_nl = malloc(sizeof(t_gnl));
	if (stash_nl == NULL || stash == NULL)
		return ;
	stash_nl->next = NULL;
	last = gnl_lstlast(*stash);
	i = 0;
	while (last->content[i] != '\0' && last->content[i] != '\n')
		i++;
	if (last->content[i] != '\0' && last->content[i] == '\n')
		i++;
	stash_nl->content = malloc(sizeof(char) * ft_strlen(last->content) - i + 1);
	if (stash_nl->content == NULL)
		return ;
	j = 0;
	while (last->content[i] != '\0')
		stash_nl->content[j++] = last->content[i++];
	stash_nl->content[j] = '\0';
	free_stash(*stash);
	*stash = stash_nl;
}

char	*get_next_line(int fd)
{
	static t_gnl	*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_stash(stash), NULL);
	read_n_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		return (free(line), NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line = NULL;

// 	fd = open("read_error.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (line == NULL)
// 			break ;
// 		free(line);
// 	}
// 	return (0);
// }
