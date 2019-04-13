#include "myftp.h"

void cmd_syst(char *cmd)
{
    (void)cmd;
    dprintf(client, "215 UNIX\r\n");
}

void help2(void)
{
    dprintf(client, "PASV <CRLF>\t\t\t: Enable \"passive\" mode for\
 data transfer\r\n");
    dprintf(client, "PORT <SP> <host-port> <CRLF>\t: Enable \"active\"\
 mode for data transfer\r\n");
    dprintf(client, "RETR <SP> <pathname> <CRLF>\t: Download file from\
 server to client\r\n");
    dprintf(client, "STOR <SP> <pathname> <CRLF>\t: Upload file from client\
 to server\r\n");
    dprintf(client, "MKD <SP> <pathname> <CRLF>\t: Create directory\r\n");
    dprintf(client, "RMD <SP> <pathname> <CRLF>\t: Delete directory\r\n");
}

void cmd_help(char *cmd)
{
    (void)cmd;
    dprintf(client, "214- This is list of available commande :\r\n");
    dprintf(client, "USER <SP> <username> <CRLF>\t: Specify user for\
 authentication\r\n");
    dprintf(client, "PASS <SP> <password> <CRLF>\t: Specify password\
for authentication\r\n");
    dprintf(client, "QUIT <CRLF>\t\t\t: Disconnection\r\n");
    dprintf(client, "SYST <CRLF>\t\t\t: Print information system\r\n");
    dprintf(client, "HELP <CRLF>\t\t\t: Print this help\r\n");
    dprintf(client, "NOOP <CRLF>\t\t\t: Do nothing\r\n");
    dprintf(client, "CWD  <SP> <pathname> <CRLF>\t: Change working\
 directory\r\n");
    dprintf(client, "CDUP <CRLF>\t\t\t: Change working directory\
 to parent directory\r\n");
    dprintf(client, "DELE <SP> <pathname> <CRLF>\t: Delete file\
 on the server\r\n");
    dprintf(client, "PWD  <CRLF>\t\t\t: Print working directory\r\n");
    dprintf(client, "LIST [<SP> <pathname>] <CRLF>\t: List files in\
 the current working directory\r\n");
    help2();
    dprintf(client, "214 End of help\r\n");
}

void cmd_noop(char *cmd)
{
    (void)cmd;
    printf("--> NOOP: 200\n");
    dprintf(client, "200 Ok\r\n");
}

void cmd_type(char *cmd)
{
    (void)cmd;
    if (user != 2)
        dprintf(client, "530 Not logged in.\r\n");
    else
        dprintf(client, "200 Ok\r\n");
}
