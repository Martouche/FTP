
#include "myftp.h"

void cmd_nlst(char *cmd)
{
    int   oldfd;
    char  *command;

    command = createCmd(cmd, "ls -1a");
    mode == 1 ? accept_data() : 0;
    oldfd = dup(1);
    if (dup2(data, 1) != -1) {
        dprintf(client, "150\r\n");
        if (system(command) != 0)
            dprintf(client, "550 Bad file for ls\r\n");
        else
            dprintf(client, "226 End of list\r\n");
        dup2(oldfd, 1);
        close(data);
    }
    else
        dprintf(client, "450\r\n");
  free(command);
}
