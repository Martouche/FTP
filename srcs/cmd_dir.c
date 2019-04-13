
#include "myftp.h"

void cmd_mkd(char *cmd)
{
    char	*buf;
    struct stat st;

    buf = strtok(cmd, " ");
    buf = strtok(NULL, " ");
    if (stat(buf, &st) == -1) {
        if (mkdir(buf, 0755) == -1)
            dprintf(client, "550 Error can't create directory\r\n");
        else
            dprintf(client, "257 Directory sucessfuly created\r\n");
    }
    else
        dprintf(client, "550 Directory already exist\r\n");
}

void cmd_rmd(char *cmd)
{
  char	*buf;

  buf = strtok(cmd, " ");
  buf = strtok(NULL, " ");

  if (rmdir(buf) == -1)
    dprintf(client, "550 Invalid directory (or not empty)\r\n");
  dprintf(client, "250 Directory sucessfuly deleted\r\n");
}
