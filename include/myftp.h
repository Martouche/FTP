/*
** EPITECH PROJECT, 2019
** my FTP include file
** File description:
** made by Martin Vantalon
*/

#ifndef MYFTP_H_
#define MYFTP_H_

#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

void cmd_user(char *cmd);
void cmd_pass(char *cmd);
void cmd_quit(char *cmd);

void cmd_mkd(char *cmd);
void cmd_rmd(char *cmd);

void cmd_cwd(char *cmd);
void cmd_cdup(char *cmd);
void cmd_dele(char *cmd);
void cmd_pwd(char *cmd);
void cmd_list(char *cmd);

void cmd_nlst(char *cmd);

void cmd_syst(char *cmd);
void help2(void);
void cmd_help(char *cmd);
void cmd_noop(char *cmd);
void cmd_type(char *cmd);

void cmd_pasv(char *cmd);
void cmd_port(char *cmd);
void cmd_retr(char *cmd);
void cmd_stor(char *cmd);

int	client;
int	server;
int	data;
int	user;
int	mode;

typedef struct s_ptr
{
    char *name;
    void (*ptr)(char *cmd);
    int logged;
}t_ptr;

static t_ptr  ptr_list[] = {
    {"USER", &cmd_user, 0}, {"PASS", &cmd_pass, 0},
    {"CWD", &cmd_cwd, 1}, {"CDUP", &cmd_cdup, 1},
    {"QUIT", &cmd_quit, 0}, {"DELE", cmd_dele, 1},
    {"PWD", &cmd_pwd, 1}, {"PASV", &cmd_pasv, 1},
    {"PORT", &cmd_port, 1}, {"HELP", &cmd_help, 0},
    {"NOOP", &cmd_noop, 0}, {"RETR", &cmd_retr, 1},
    {"STOR", &cmd_stor, 1}, {"LIST", &cmd_list, 1},
    {"SYST", &cmd_syst, 0}, {"TYPE", &cmd_type, 1},
    {"MKD", &cmd_mkd, 1}, {"RMD", &cmd_rmd, 1},
    {"NLST", &cmd_nlst, 1}, {NULL, NULL, 0}
};

void init_socket(void);
void init_port(int);
void init_listen(void);
void init_connection(void);

void printerror(char *, int);
void sig_handler(int);
void error_handling(int, char **);
void loop_ftp(int);

void accept_data(void);
int isValid(char *);

char *makeIp(char *);
int	makePort(char *);
char *createCmd(char *, char *);

#endif
