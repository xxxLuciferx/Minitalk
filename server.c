/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:50:21 by khaimer           #+#    #+#             */
/*   Updated: 2023/01/04 18:50:21 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

int counter = 7;

void	ft_putnbr(int n)
{
	int j;
	if (n >= 0 && n <= 9)
	{
		j = n + '0';
		write(1, &j, 1);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void    signal_hundler(int sig)
{
    static char c;
    if(SIGUSR2 == sig)
    {
        c = c | (1 << counter);
        counter--;
    }
    else if(SIGUSR1 == sig)
        counter--;
    if(counter == -1)
    {
        write(1, &c, 1);
        c = 0;
        counter = 7;
    }
}


int main()
{
    int PID;
    PID = getpid();
	ft_putnbr(PID);
	write(1,"\n", 1);
    signal(SIGUSR1,signal_hundler);
    signal(SIGUSR2,signal_hundler);
    while(1)
    {
        pause();
    }
}
