/* ************************************************************************** */
/*														                    */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:50:23 by khaimer           #+#    #+#             */
/*   Updated: 2023/01/09 19:34:21 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	ft_atoi(char *string)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while ((string[i] >= '0' && string[i] <= '9') && string[i] != '\0')
	{
		result = result * 10;
		result = result + string[i] - '0';
		i++;
	}
	return (result);
}

void	sendchar(char c, int pid)
{
	int	counter;

	counter = 7;
	while (counter >= 0)
	{
		if (c & (1 << counter))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		counter--;
		usleep(70);
	}
}

void	message(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Your message was received", 25);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
	{
		write(1, "Please enter PID & String", 25);
		return (0);
	}
	signal(SIGUSR1, message);
	pid = ft_atoi(argv[1]);
	i = 0;
	if (pid == 0)
		return (0);
	while (argv[2][i] != '\0')
	{
		sendchar(argv[2][i], pid);
		i++;
	}
	sendchar('\0', pid);
	while (1)
		pause();
	return (0);
}
