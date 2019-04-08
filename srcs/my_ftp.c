/*
** EPITECH PROJECT, 2019
** my ftp algorithm
** File description:
** made by Martin Vantalon
*/

#include "myftp.h"

int myftp()
{
    char *buf;
    FILE *tmp;
    size_t n;
    dprintf(client, "220 Welcome\r\n");
    tmp = fdopen(dup(client), "r");
    buf = NULL;
    while (1) {
        if (getline(&buf, &n, tmp) == -1) {
            fclose(tmp);
            free(buf);
            printf("getline have a problem here");
            exit(84);
        }
        fprintf(stderr, "! -> %s", buf);
//      parseCMD(buf);
        if (strcmp(buf, "QUIT") == 0)
            break;
    }
    free(buf);
    fclose(tmp);
    if (fcntl(client, F_GETFD) != -1)
        close(client);
     exit(0);
}