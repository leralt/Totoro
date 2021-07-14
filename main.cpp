#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <netinet/in.h>
#include "wrap.h"

#define SERVER_PORT 9527


void readFile(std::string filepath,char* buff){
    std::string base_path = "home/lyc/vscode_ws/www/";
    std::ifstream getfile;
    char buf[1024];
    getfile.open(base_path + filepath, std::ios::in);
    getfile.read(buf,1024);
    strcpy(buff,u8"HTTP/1.1 200 OK\nContent-Type: text/html\n\n");
    strcat(buff,buf);
    //printf("%s",buff);
    getfile.close();
}


int main() {
    //recv buff
    char buff[1024];
    //send buff
    char html[1024];
    //printf("%s",buff);
    
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
    while(true){
        if(-1 == recv(connfd,buff, strlen(buff),0)){
            perr_exit("recv error");
        };
        std::istringstream str(buff);
        std::string no,path;
        str >> no>>path;
        if(path == "close"){
            break;
        }
        readFile(path,html);
        //printf("%s",buff);
        if(-1 == send(connfd,html, strlen(html),0)){
            perr_exit("send error");
        }
    }
    
    Close(connfd);
    return 0;
}
