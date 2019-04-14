/*
** EPITECH PROJECT, 2019
** my loading data functions
** File description:
** made by Martin Vantalon
*/

#include "myftp.h"

static int get_same_ip(int fd)
{
    struct sockaddr_in addr;
    socklen_t addr_len;

    if (fd == -1)
        return (htons(INADDR_ANY));
    addr_len = sizeof(addr);
    getsockname(fd, (struct sockaddr *)&addr, &addr_len);
    return (addr.sin_addr.s_addr);
}

void init_socketd(void)
{
    struct protoent *pe;
    int opt;

    if ((pe = getprotobyname("TCP")) == NULL)
        printerror("getprotobyname", 1);
    if ((data = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
        printerror("socket", 1);
    opt = 1;
    if (setsockopt(data, SOL_SOCKET, SO_REUSEADDR,
        (char *)&opt, sizeof(opt)) == -1)
        printerror("setsockopt", 1);
}

void init_bindd(int port)
{
    struct sockaddr_in s_in;

    s_in.sin_family = AF_INET;
    s_in.sin_port = htons(port);
    s_in.sin_addr.s_addr = get_same_ip(client);
    if (bind(data, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
        if (close(server) == -1)
            printerror("close", 1);
        if (close(client) == -1)
            printerror("close", 1);
        if (close(data) == -1)
            printerror("close", 1);
        printerror("bind", 1);
    }
}

void init_listend(void)
{
    if (listen(data, 42) == -1) {
        if (close(server) == -1)
            printerror("close", 1);
        if (close(client) == -1)
            printerror("close", 1);
        if (close(data) == -1)
            printerror("close", 1);
        printerror("listen", 1);
    }
}

void init_data(int port)
{
    init_socketd();
    init_bindd(port);
    init_listend();
}
