#ifndef _TCPSOCKET_H_
#define _TCPSOCKET_H_

#include <cstring>
#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>
#include "wrap.h"

using namespace std;
class TcpSocket {
private:
    int conn_fd; /*通信描述符*/
public:
    TcpSocket(int sock_fd);
    ~TcpSocket();

    int sendmsg(string massage);
    string recvmsg();
};
#endif /*_TCPSOCKET_H_*/