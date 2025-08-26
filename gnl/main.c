/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovais <jnovais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:50:14 by jnovais           #+#    #+#             */
/*   Updated: 2025/08/22 20:13:02 by jnovais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	buf[128];
	size_t	n;

	fd = open("arquivo.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}

	n = read(fd, buf, sizeof (buf) -1);
	printf("%zu\n", n);
	if (n == -1)
	{
		perror("read");
		return (1);
	}
	write(STDOUT_FILENO, buf, n);

	close(fd);
	return (0);

}
