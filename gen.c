/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 23:45:19 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/14 15:42:54 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

static int	ft_isdigit(int c)
{
	if (c >= 0x30 && c <= 0x39)
		return (1);
	return (0);
}

static char	*atoi_shift(char *s)
{
	while ((*s > 8 && *s < 14) || *s == 32)
		s++;
	return (s);
}

static int	ft_atoi(const char *str)
{
	char	*shift;
	size_t	i;
	int		mul;
	int		rtn;
	int		neg;

	shift = atoi_shift((char*) str);
	i = 0;
	mul = 1;
	rtn = 0;
	neg = 1 - ((shift[i] == '-') * 2);
	if (shift[i] == '-' || shift[i] == '+')
		i++;
	while (ft_isdigit(shift[i]))
		i++;
	while (i > (shift[0] == '-' || shift[0] == '+'))
	{
		rtn += (shift[i-- - 1] - 0x30) * mul;
		mul *= 10;
	}
	return (rtn * neg);
}

int			main(int argc, char **argv)
{
	int	node;
	int	i;
	int	ran;

	srand(time(NULL));
	if (argc != 3 || !ft_atoi(argv[1]) || ft_atoi(argv[2]) < 2)
	{
		printf("Usage: gen [many of ants] [many of nodes]\n");
		return (1);
	}
	printf("%s\n", argv[1]);
	printf("##start\n");
	printf("start 0 1\n");
	printf("##end\n");
	printf("end 1 0\n");
	node = ft_atoi(argv[2]);
	i = 0;
	while (i < node)
		printf("%1$d %1$d %1$d\n", i++);
	i = 0;
	while (i < node)
	{
		while (rand() % 2)
		{
			ran = rand() % node;
			while (ran == i)
				ran = rand() % node;
			printf("%d-%d\n", i, ran);
		}
		ran = rand() % node;
		while (ran == i)
			ran = rand() % node;
		printf("%d-%d\n", i++, ran);
	}
	i = 0;
	printf("start-");
	printf("%d\n", rand() % node);
	while (rand() % 2)
	{
		printf("start-");
		printf("%d\n", rand() % node);
	}
	printf("end-");
	printf("%d\n", rand() % node);
	while (rand() % 2)
	{
		printf("end-");
		printf("%d\n", rand() % node);
	}
	return (0);
}
