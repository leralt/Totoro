#include <fstream>
#include "TcpSocket.h"

TcpSocket::TcpSocket(int sock_fd) {
    conn_fd = sock_fd;
}

TcpSocket::~TcpSocket() {
    if (conn_fd > 0) {
        Close(conn_fd);
    }
}

int TcpSocket::sendPage() {
    return send(conn_fd, pages.c_str(), sizeof(pages), MSG_WAITALL);
}

int TcpSocket::getRequest() {
    char *buff = new char[1024];
    recv(conn_fd, buff, 1024, MSG_WAITALL);
    char *path = strtok(buff, reinterpret_cast<const char *>(' '));
    return readFile(path);
}

int TcpSocket::readFile(string path) {
    string base_path = "home/lyc/vscode_ws/www";
    ifstream getfile;
    char buf[1024];

    if (path == "/") {
        path = "/index.html";
    }

    getfile.open(base_path + path, std::ios::in);
    getfile.read(buf, 1024);
    pages.append("HTTP/1.1 200 OK\nContent-Type: text/html\n\n");
    pages.append(buf);

    getfile.close();
    return 0;
}
