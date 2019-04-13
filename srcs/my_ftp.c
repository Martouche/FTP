/*
** EPITECH PROJECT, 2019
** my ftp algorithm
** File description:
** made by Martin Vantalon
*/

#include "myftp.h"

char *cutCMD(char *buf)
{
    if (strlen(buf) > 0 && buf[strlen(buf) - 1] == '\n')
        buf[strlen(buf) - 1] = '\0';
    if (strlen(buf) > 0 && buf[strlen(buf) - 1] == '\r')
        buf[strlen(buf) - 1] = '\0';
    return (buf);
}

void my_parser(char *buf)
{
    char *str;
    int i;
    bool exist;
    char *cmd;

    i = 0;
    exist = false;
    buf = cutCMD(buf);
    cmd = strdup(buf);
    str = strtok(buf, " ");
    while (ptr_list[i].ptr) {
        if (str != NULL && strcmp(str, ptr_list[i].name) == 0) {
	       if (ptr_list[i].logged == 1 && user != 2)
            dprintf(client, "530 Not logged in.\r\n");
          else
               ptr_list[i].ptr(cmd);
               exist = true;
           }
           i++;
       }
       if (exist == false)
       dprintf(client, "500 Unknow command\r\n");
       free(cmd);
}

int myftp(void)
{
    char *buf;
    FILE *tmp;
    size_t n;
    tmp = fdopen(dup(client), "r");
    buf = NULL;

    dprintf(client, "220 Welcome\r\n");
    while (1) {
        if (getline(&buf, &n, tmp) == -1) {
            fclose(tmp);
            free(buf);
            printf("getline have a problem here");
            exit(84);
        }
        fprintf(stderr, "! -> %s", buf);
        my_parser(buf);
        if (strcmp(buf, "QUIT\r\n") == 0)
            break;
    }
    free(buf);
    fclose(tmp);
    if (fcntl(client, F_GETFD) != -1)
        close(client);
    exit(0);
}
