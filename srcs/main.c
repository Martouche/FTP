/*
** EPITECH PROJECT, 2019
** my main functions of FTP server
** File description:
** made by Martin Vantalon
*/

#include "myftp.h"

void printerror(char *str, int ex)
{
    if (fcntl(client, F_GETFD) != -1)
        close(client);
    if (fcntl(server, F_GETFD) != -1)
        close(server);
    if (fcntl(data, F_GETFD) != -1)
        close(data);
    perror(str);
    fprintf(stderr, "Error with %s\n", str);
    exit(ex);
}

int	errorClient(char *str, int ret)
{
    dprintf(client, "%s\r\n", str);
    return (ret);
}

void sig_handler(int sig)
{
    if (sig == SIGINT) {
        if (fcntl(client, F_GETFD) != -1)
            close(client);
        if (fcntl(server, F_GETFD) != -1)
            close(server);
        if (fcntl(data, F_GETFD) != -1)
            close(data);
        exit(0);
    }
}

void error_handling(int ac, char **av)
{
    if (ac != 3)
        printerror("arguments", 1);
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printerror("signal", 1);
    if (chdir(av[2]) != 0)
        printerror("chdir", 1);
}

void loop_ftp(int port)
{
    init_socket();
    init_port(port);
    init_listen();
    init_connection();
}

int main(int ac, char **av)
{
    error_handling(ac, av);
    loop_ftp(atoi(av[1]));
    printf("ca compile");
    if (close(server) == -1)
        return 1;
    return 0;
}
