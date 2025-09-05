/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:47:12 by marvin            #+#    #+#             */
/*   Updated: 2025/09/02 21:47:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	
	str_len = len_to_newline(list); //conta até achar o primeiro \n da lista + 1
	next_str = malloc(str_len + 1);
	if (next_str == NULL);
		return (NULL);
	
	copy_str(list, next_str); //fazer a copia até encontrar o primeiro \n
	return (next_str);
}

void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	
		new_node->str_buf = buf;
		new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		
		char_read = read(fd, buf, BUFFER_SIZE);

		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append(list, buf);
	}

}


char	*get_next_line(int fd)
{
	static t_list *list;
	char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);

	create_list(&list, fd);

	if (list == NULL)
		return (NULL);

	next_line = get_line(list);

	polish_list(&list);
	return (next_line);
}