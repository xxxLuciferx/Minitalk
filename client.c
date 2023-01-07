/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:50:23 by khaimer           #+#    #+#             */
/*   Updated: 2023/01/07 18:45:10 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h> 

int	ft_atoi(char *string)
{
    int result;
    int i;
	
	result = 0;
	i = 0;
    while ((string[i] >= '0' && string[i] <= '9') && string[i] != '\0')
	{
		result = result * 10;
		result = result + string[i] - '0';
		i++;
	}
    return(result);
}

void    sendchar(char c, int PID)
{
	int counter;
	
    counter = 7;
    while(counter >= 0)
    {
        if(c & (1 << counter))
            kill(PID, SIGUSR2); // 1
        else
            kill(PID, SIGUSR1); // 0
        counter--;
		usleep(70); 
    }
}
void	message(int sig)
{
	if(sig == SIGUSR1)
		write(1,"every message receive", 21);
}

int main(int argc, char **argv)
{
	signal(SIGUSR1,message);
    if(argc == 3)
    {
        int i = 0;
        int PID = ft_atoi(argv[1]);
        if(PID == 0)
            return 0; 
        while(argv[2][i] != '\0')
        {
            sendchar(argv[2][i], PID);
            i++;
        }
	sendchar('\0',PID);	
    }
	while(1)
		pause();
    return 0;
}
