/*
** EPITECH PROJECT, 2019
** my data accept
** File description:
** made by Martin Vantalon
*/

#include "myftp.h"

void init_data2(void)
{
    struct protoent *pe;

    (pe = getprotobyname("TCP")) == NULL ? printerror("getprotobyname", 1) : 0;
    if ((data = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
        printerror("socket", 1);
}

void accept_data(void)
{
    socklen_t s_in_size;
    struct sockaddr_in s_in_client;
    int tmp;
    s_in_size = sizeof(s_in_client);
    tmp = data;
    if ((data = accept(tmp, (struct sockaddr *)&s_in_client,
                        &s_in_size)) == -1) {
        if (close(server) == -1)
            printerror("close", 1);
        printerror("accept", 1);
    }
    close(tmp);
}

int isValid(char *file)
{
    struct stat	st;

    if (!stat(file, &st) && S_ISREG(st.st_mode))
        return (0);
    else
        return (-1);
}
