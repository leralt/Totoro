#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <netinet/in.h>
#include "wrap.h"

#define SERVER_PORT 9527


void readFile(std::string filepath,char* buff){
    std::ifstream getfile;
    char buf[1024];
    getfile.open(filepath,std::ios::in);
    getfile.read(buf,1024);
    strcpy(buff,u8"HTTP/1.1 200 OK\nContent-Type: text/html\n\n");
    strcat(buff,buf);
    printf("%s",buff);
    getfile.close();
}


int main() {
    //socket
    //bind
    //listen
    //accept
    char buff[1024] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
    char html[1024];
    //printf("%s",buff);
    readFile("/home/lyc/vscode_ws/www/index.html",html);
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
    if(-1 == send(connfd,html, strlen(html),0)){
        perr_exit("send error");
    }
    Close(connfd);
    return 0;
}
