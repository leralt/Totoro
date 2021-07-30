#ifndef TOTORO_WRAP_H
#define TOTORO_WRAP_H

#include <cstdlib>
#include <cerrno>
#include <unistd.h>
#include <cstdio>
#include <sys/socket.h>

void perr_exit(const char *s);

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);

void Bind(int fd, const struct sockaddr *sa, socklen_t salen);

//void Connect(int fd, const struct sockaddr *sa, socklen_t salen);

void Listen(int fd, int backlog);

int Socket(int family, int type, int protocol);

ssize_t Read(int fd, void *ptr, size_t nbytes);

ssize_t Write(int fd, const void *ptr, size_t nbytes);

void Close(int fd);

#endif //TOTORO_WRAP_H
