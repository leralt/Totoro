#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <netinet/in.h>
#include "wrap.h"
#include "TcpServer.h"

using namespace std;

#define SERVER_PORT 9527
#define SERVER_STRING "Server: Totoro 0.1.0\r\n"

void readFile(const std::string &filepath, char *buff);

void headers();

// void readFile(const std::string &filepath, char *buff) {
//     std::string base_path = "home/lyc/vscode_ws/www";
//     std::ifstream getfile;
//     char buf[1024];
//     std::cout << base_path + filepath << std::endl;
//     getfile.open(base_path + filepath, std::ios::in);
//     getfile.read(buf, 1024);
//     memcpy(buff, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n",
//            sizeof("HTTP/1.1 200 OK\nContent-Type: text/html\n\n"));
//     strcat(buff, buf);

//     getfile.close();
// }



int main() {
    sockaddr_in client{};
    auto *tcpServer = new TcpServer();
    tcpServer->listen(SERVER_PORT);
    auto sock_trans = tcpServer->accept(&client);

    sock_trans->getRequest();
    sock_trans->sendPage();

    return 0;
}
