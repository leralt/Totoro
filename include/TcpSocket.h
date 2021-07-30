#ifndef _TCP_SOCKET_H_
#define _TCP_SOCKET_H_

#include <cstring>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <arpa/inet.h>
#include "wrap.h"

using namespace std;

class TcpSocket {
private:
    int conn_fd; /*通信描述符*/
    string pages; /*存储文件内容*/

    int readFile(string path);

public:
    TcpSocket(int sock_fd);

    ~TcpSocket();

    int sendPage();

    int getRequest();
};
#endif /*_TCPSOCKET_H_*/