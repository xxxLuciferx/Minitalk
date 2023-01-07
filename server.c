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
#include <signal.h>

static int counter = 7;

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

void    signal_hundler(int sig, siginfo_t *info, void *content)
{
    static char c;
	static int Client_PID;
	static int Current_process;
	(void)content;

	Client_PID = info->si_pid;
	if(Current_process != Client_PID)
	{
		c = 0;
		counter = 7;
		Current_process = Client_PID;
	}
    if(SIGUSR2 == sig)
    {
        c = c | (1 << counter);
        counter--;
    }
    else if(SIGUSR1 == sig)
        counter--;
    if(counter == -1)
    {
		if(c == '\0')
		{
			kill(Client_PID,SIGUSR1);
		}

		if(Current_process == Client_PID)
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
	struct sigaction st;
	st.sa_sigaction = signal_hundler;
	st.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1,&st,NULL);
	sigaction(SIGUSR2,&st,NULL);
    while(1)
    {
        pause();
    }
	return 0;
}
