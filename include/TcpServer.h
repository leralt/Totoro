#ifndef _TCPSERVER_H
#define _TCPSERVER_H

#include <cstring>
#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>
#include "TcpSocket.h"


using namespace std;

class TcpServer {
public:
    TcpServer();
    ~TcpServer();

    int listen(unsigned short port);
    TcpSocket* accept(sockaddr_in* addr);
private:
    int sock_fd;   //监听套接字
};


#endif // _TCPSERVER_H