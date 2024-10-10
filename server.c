#include<stdio.h>
#include<stlib.h>
#include<string.h>
#include<errno.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>

#define MAX_SIZE 16

int main(int argc, char **argv){
        int l_sfd, c_sfd;
        char buffer[MAX_SIZE];
        socklen_t addr_len, peer_addr;
        struct sockaddr_in addr, peer_addr;

        if(argc != 2){
                fprintf(stderr, "Usage: %s port\n", argv[0]);
                exit(EXIT_FAILURE);
        }
        
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr = INADDR_ANY;
        addr.sin_port = htons(argv[1]);

        l_sfd = socket(AF_INET, SOCK_STREAM, 0);
        if(l_sfd == -1){
               perror("socket");
               exit(EXIT_FAILURE);
        }
        
        if(bind(l_sfd, (struct sockaddr *) &addr, sizeof(addr)) == -1){
                perror("bind");
                exit(EXIT_FAILURE);
        }

        if(listen(l_sfd, 0) == -1){
                perror("listen");
                exit(EXIT_FAILURE);
        }

        for(;;){
                peer_addrlen = sizeof(peer_addr);
                c_sfd = accept(l_sfd, (struct sockaddr *) &peer_addr,
                                &peer_addrlen);

                if(c_sfd == -1){
                        perror("accept");
                        exit(EXIT_FAILURE);
                }


        }
        


