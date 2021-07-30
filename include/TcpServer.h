#ifndef _TCPSERVER_H
#define _TCPSERVER_H

#include <string>

using namespace std;


class TcpServer {
public:
    TcpServer();
    ~TcpServer();

    int send_msg(string message);
    string recv_msg();
private:
    int conn_fd;     //通信套接字
    int listen_fd;   //监听套接字
};


#endif // _TCPSERVER_H