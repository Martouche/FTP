/*
** EPITECH PROJECT, 2019
** my initialize functions
** File description:
** made by Martin Vantalon
*/

#include "myftp.h"

void init_socket(void)
{
    struct protoent *pe;
    int opt;
    pe = getprotobyname("TCP");
    if (pe == NULL)
        exit(84);
    server = socket(AF_INET, SOCK_STREAM, pe->p_proto);
    if (server == -1) {
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

void init_listen(void)
{
    if (listen(server, 42) == -1)
    {
        if (close(server) == -1) {
            printf("close fuckds here 2");
            exit(84);
        }
        printf("listen fucked here");
        exit(84);
    }
}

void init_connection(void)
{
    socklen_t s_in_size;
    struct sockaddr_in s_in_client;
    s_in_size = sizeof(s_in_client);

    while (1) {
        client = accept(server, (struct sockaddr *)&s_in_client, &s_in_size);
        if (client == -1)
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
