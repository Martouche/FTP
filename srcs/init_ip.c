/*
** EPITECH PROJECT, 2019
** my init IP functions
** File description:
** made by Martin Vantalon
*/

#include "myftp.h"

char *makeIp(char *cmd)
{
    char	*ip[4];
    char	*buf;
    char	*ipaddr;

    buf = strtok(cmd, " ");
    buf = strtok(NULL, " ");
    ip[0] = strtok(buf, ",");
    ip[1] = strtok(NULL, ",");
    ip[2] = strtok(NULL, ",");
    ip[3] = strtok(NULL, ",");
    if ((ipaddr = malloc(sizeof(char *) * (strlen(ip[0]) + strlen(ip[1])
	 + strlen(ip[2]) + strlen(ip[3]) + 4))) == NULL)
        printerror("malloc", 1);
    ipaddr = strcpy(ipaddr, ip[0]);
    ipaddr = strcat(ipaddr, ".");
    ipaddr = strcat(ipaddr, ip[1]);
    ipaddr = strcat(ipaddr, ".");
    ipaddr = strcat(ipaddr, ip[2]);
    ipaddr = strcat(ipaddr, ".");
    ipaddr = strcat(ipaddr, ip[3]);
    free(cmd);
    return (ipaddr);
}

void printIp(char *ip)
{
    int	i;

    i = 0;
    while (ip[i] != '\0') {
        ip[i] == '.' ? dprintf(client, ",")
	    : dprintf(client, "%c", ip[i]);
        i++;
    }
}

int	makePort(char *cmd)
{
    char *buf;
    int port1;
    int port2;

    buf = strtok(cmd, " ");
    buf = strtok(NULL, " ");
    buf = strtok(buf, ",");
    buf = strtok(NULL, ",");
    buf = strtok(NULL, ",");
    buf = strtok(NULL, ",");
    port1 = atoi(strtok(NULL, ","));
    port2 = atoi(strtok(NULL, ","));
    free(cmd);
    return ((port1 * 256) + port2);
}
