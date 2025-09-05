/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:44:26 by marvin            #+#    #+#             */
/*   Updated: 2025/09/01 23:44:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int fd;
	char buf[256];
	int chars_read;

	fd = open("arquivo.txt", O_RDONLY);

	while ((chars_read = read(fd, buf, 5)))
	{
		buf[chars_read] = '\0';
		printf("buf-> %s\n", buf);
	}
}