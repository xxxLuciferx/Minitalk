/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:21:19 by khaimer           #+#    #+#             */
/*   Updated: 2022/12/25 16:19:13 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int	ft_atoi(const char *str)
{
	int	a;
	int	sign;
	int	res;

	res = 0;
	a = 0;
	sign = 1;
	while (str[a] == ' ' || (str[a] <= 13 && str[a] >= 9))
		a++;
	if (str[a] == '-')
	{
		sign = sign * -1;
		a++;
	}
	else if (str[a] == '+')
		a++;
	while (str[a] <= '9' && str[a] >= '0')
	{
		res = str[a] - '0' + (res * 10);
		a++;
	}
	return (res * sign);
}
void	signal_sender(char c, int PID)
{	
	int i;
	i = 7;

	while(i >= 0)
	{	
		if((c >> i) & 1)
		{
			kill(PID, SIGUSR2);
			// printf("1");
			usleep(70);
		}
		else
		{
			kill(PID, SIGUSR1);
			// printf("0");
			usleep(70);
		}
		i--;
	}
	// printf("\n");
}

int main(int argc, char *argv[])
{
	int i;
	int PID;
	// int opperation;
	i = 0;
    PID = ft_atoi(argv[1]);
	while(argv[2][i] != '\0')
	{
		signal_sender(argv[2][i], PID);
		i++;
	}
    // opperation = kill(PID,SIGUSR2);
	// if(opperation == 0)
    printf("\nsignal sent successfully");
}
