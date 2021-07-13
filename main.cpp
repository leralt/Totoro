#include <iostream>
#include <netinet/in.h>
#include "wrap.h"


#define SERVER_PORT 9527

int main() {
    //socket
    //bind
    //listen
    //accept
    char buff[1024] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>hello</h1>\n";
    const char html[] = "HTTP/1.1 200 OK\r\n"
                        "Content-type: text/html\r\n"
                        "\r\n"
                        "<html>\r\n"
                        "<head>\r\n"
                        "<title>Hello, world!</title>\r\n"
                        "</head>\r\n"
                        "<body>\r\n"
                        "<h1>Hello, world!</h1>\r\n"
                        "</body>\r\n"
                        "</html>\r\n\r\n";
    printf("%s",buff);

    sockaddr_in socket_addr;
    bzero(&socket_addr, sizeof(socket_addr));
    int sock_fd = Socket(AF_INET,SOCK_STREAM,0);
    socket_addr.sin_family = AF_INET;
    socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    socket_addr.sin_port = htons(SERVER_PORT);

    Bind(sock_fd,(sockaddr*)&socket_addr, sizeof(socket_addr));
    Listen(sock_fd,6);

    sockaddr_in client;
    socklen_t clientlen = sizeof(client);

    //Read(connfd,buff,1024);
    //printf("%s",buff);
    //printf("%u", ntohl(client.sin_addr.s_addr));
    //Write(connfd,buff,1024);
    int connfd = Accept(sock_fd,(sockaddr*)&client, &clientlen);
    //recv(connfd,buff, strlen(buff),0);
    //printf("%s",buff);

    send(connfd,buff, strlen(buff)-1,0);
    Close(connfd);
    return 0;
}
