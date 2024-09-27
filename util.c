#include<sys/types.h>
#include<sys/socket.h>

int create_socket(int domain, int type, int protocol)
{
        return socket(domain, type, protocol);
}

int bind_socket(int sockfd, const struct sockaddr *addr, 
                socklen_t addrlen)
{
        return bind(sockfd, addr, addrlen);
}

int listen_on_socket(int sockfd, int backlog)
{
        return listen(sockfd, backlog);
}

int accept_request(int so
