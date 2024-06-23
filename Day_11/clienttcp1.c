#include <arpa/inet.h> //inet_addr()
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h> //bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Function designed for chat between client and server
void func(int sockfd){
    char buff[MAX];
    int n;
    //infinite loop for chat
    for (;;){
        bzero(buff, sizeof(buff));
        printf("Enter a string: ");
        n=0;

        //copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n');

        //and send that buffer to client
        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server: %s", buff);
        //if msg contains "Exit" then server exit and chat ended.
        if (strncmp(buff, "exit", 4) == 0){
            printf("Server Exit...\n");
            break;
        }
    }
}
// Driver function

int main(){
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    //socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1){
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket succesfully creatd..\n");
    bzero(&servaddr, sizeof(servaddr));

    //assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    //connect the client socket to server socket
    if((connect(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0){
        printf("Not Connected to server...\n");
        exit(0);
    }
    else
        printf("Connected to server..\n");

    
    //func for chat
    func(sockfd);

    // close the socket
    close(sockfd);
}