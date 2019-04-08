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

int	client;
int	server;
int	data;
int	user;
int	mode;

typedef struct	s_ptr
{
    char *name;
    int logged;
}t_ptr;

#endif
