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

void    sig_handler(int sig)
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

void error_handling(int ac ,char **av)
{
    if (ac != 3)
        printerror("arguments", 1);
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printerror("signal", 1);
    if (chdir(av[2]) != 0)
        printerror("chdir", 1);
}

void init_socket()
{
    struct protoent *pe;
    int opt;

    if ((pe = getprotobyname("TCP")) == NULL)
        exit(84);
    if ((server = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1) {
        printf("sockets sucked here");
        exit(84);
    }
    opt = 1;
    if (setsockopt(server, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) == -1) {
        printf("setsockopt fucked here");
        exit(84);
    }
}

void init_port(int port)
{
    struct sockaddr_in s_in;

    s_in.sin_family = AF_INET;
    s_in.sin_port = htons(port);
    s_in.sin_addr.s_addr = INADDR_ANY;
    if (bind(server, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
        if (close(server) == -1) {
            printf("server close fucked here");
            exit(84);
        }
        printf("the connection fucked here");
        exit(84);
    }
}

void init_listen()
{
    if (listen(server, 42) == -1)
    {
        if (close(server) == -1) {
            printf("close fuckds here 2");
            exit(84);
        }
        printf("listen fuekd here");
        exit(84);
    }
}

void init_connection(void)
{
    socklen_t s_in_size;
    struct sockaddr_in s_in_client;
    s_in_size = sizeof(s_in_client);

    while (1) {
        if ((client = accept(server, (struct sockaddr *)&s_in_client, &s_in_size)) == -1)
        {
            if (close(server) == -1)
                exit(84);
            printf("accept fucked here");
            exit(84);
        } else {
            if (fork() == 0)
                myftp();
            else
                if (close(client) == -1)
                    exit(84);
        }
    }
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
