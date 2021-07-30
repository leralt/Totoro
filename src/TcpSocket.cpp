#include <wrap.h>
#include "TcpSocket.h"

TcpSocket::TcpSocket(int sock_fd) {
    conn_fd = sock_fd;
}

TcpSocket::~TcpSocket() {
    if (conn_fd > 0) {
        Close(conn_fd);
    }
}

int TcpSocket::sendmsg(string massage) {

}

string TcpSocket::recvmsg() {

}