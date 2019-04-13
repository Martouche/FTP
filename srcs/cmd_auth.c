
#include "myftp.h"

void	cmd_user(char *cmd)
{
    char	*buf;

    buf = strtok(cmd, " ");
    buf = strtok(NULL, " ");
    user = 1;
    if (strcmp(buf, "Anonymous") == 0)
        user = 0;
    dprintf(client, "331 Need password.\r\n");
}

void cmd_pass(char *cmd)
{
    (void)cmd;
    if (user == 0) {
        user = 2;
        dprintf(client, "230 User logged in, proceed.\r\n");
    }
    else
        dprintf(client, "530 Login incorrect.\r\n");
}

void cmd_quit(char *cmd)
{
    (void)cmd;
    printf("--> QUIT: 221\n");
    dprintf(client, "221 End of conection\r\n");
}
