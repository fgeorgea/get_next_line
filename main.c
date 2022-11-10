/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:54:05 by fgeorgea          #+#    #+#             */
/*   Updated: 2022/11/10 15:39:02 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char *str;
	int	i;

	i = 1;
	fd = open("text.txt", O_RDONLY);
	while (i < 10)
	{
		str = get_next_line(fd);
		printf("%s", str);
		i++;
		free(str);
	}
	system("leaks a.out");
	close(fd);
}
