/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:21:22 by khaimer           #+#    #+#             */
/*   Updated: 2022/12/25 14:06:52 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int i = 7;

void sigusr1_handler(int sig) 
{
	static char c;
	// if(!c)
	// {
	// 	c = 0;
	// 	i = 7;
	// }
	if (sig == SIGUSR2)
	{
		// printf("this is value of i in sig2: %d \n", i);
		c |= (1 << i);
		// write(1, "1", 1);
		i--;
	}
	if (sig == SIGUSR1)
	{
		// printf("this is value of i in sig1 : %d \n", i);
		// write(1, "0", 1);
		i--;
	}
	// printf("this is value of i -------- : %c \n", c);
	if(i == -1)
	{
		// printf("we are here\n");
		// string[8]= '\0';
		// unsigned char d = strtol(string,NULL, 2);
		write(1, &c, 1);
		// write(1, "\n", 1);
		// printf("this is c \n");

		i = 7;
		c = 0;
	}
}

int main()
{
	printf("PID: %d\n",getpid());
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr1_handler);
	while(1)
	{
		pause();
	}
}
