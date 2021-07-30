#include "../include/TcpServer.h"

TcpServer::TcpServer()
{
    sock_fd = Socket(AF_INET, SOCK_STREAM, 0);
}

TcpServer::~TcpServer()
{
    Close(sock_fd);
}

int TcpServer::listen(unsigned short port)
{
    struct sockaddr_in sockaddrIn
    {
    };
    bzero(&sockaddrIn, sizeof(sockaddrIn));
    sockaddrIn.sin_family = AF_INET;
    sockaddrIn.sin_addr.s_addr = htonl(INADDR_ANY);
    sockaddrIn.sin_port = htons(port);

    Bind(sock_fd, (struct sockaddr *)&sockaddrIn, sizeof(sockaddrIn));

    std::cout << "套接字绑定成功, ip: "
              << inet_ntoa(sockaddrIn.sin_addr)
              << ", port: " << port << std::endl;

    Listen(sock_fd, 128);
    cout << "设置监听成功..." << endl;
    return 0;
}

TcpSocket *TcpServer::accept(sockaddr_in *addr)
{
    if (addr == nullptr)
    {
        return nullptr;
    }

    /*
    * Accept的第三个参数为什么非要是大小的地址
    */
    socklen_t size = sizeof(addr);
    int conn_fd = Accept(sock_fd, (struct sockaddr *)addr, &size);

    printf("成功和客户端建立连接...\n");
    return new TcpSocket(conn_fd);
}
