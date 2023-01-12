/* ************************************************************************** */
/*		                                                                    */
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

int	g_counter = 7;

void	ft_putnbr(int n)
{
	int	j;

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

void	print(int pid, char *c)
{
	if (*c == '\0')
		kill(pid, SIGUSR1);
	write(1, c, 1);
	g_counter = 7;
	*c = 0;
}

void	signal_hundler(int sig, siginfo_t *info, void *content)
{
	static char	c;
	static int	client_pid;
	static int	current_process;

	(void)content;
	client_pid = info->si_pid;
	if (current_process != client_pid)
	{
		g_counter = 7;
		c = 0;
		current_process = client_pid;
	}
	if (SIGUSR2 == sig)
	{
		c = c | (1 << g_counter);
		g_counter--;
	}
	else if (SIGUSR1 == sig)
		g_counter--;
	if (g_counter == -1)
		print(client_pid, &c);
}

int	main(void)
{
	struct sigaction	st;
	int					pid;

	pid = getpid();
	ft_putnbr(pid);
	st.sa_sigaction = signal_hundler;
	st.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &st, NULL);
	sigaction(SIGUSR2, &st, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
