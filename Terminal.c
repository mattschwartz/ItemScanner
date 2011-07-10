#include "UPC-Header.h"
#include "Network-Header.h"


 // ###############################################
int main(int argc, char **argv) {
    int clientfd;
    
    usage(argc);
    
    printf("\n Attempting to establish connection with database server\n");
    clientfd = serverConnect(argv[1]);
    printf("\n Connection established\n");
    
} // End main


 // ###############################################
int serverConnect(char *ip_address) {
    int status;
    int sockfd;
    struct sockaddr_in serverAddress;
     
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socker");
        exit(1);
    } // End if
     
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(DATABASE_PORT);
     
    status = inet_pton(AF_INET, ip_address, &serverAddress.sin_addr);
    if (status < 0) {
        perror("\n Invalid IP Address");
        exit(1);
    } // End if
     
    status = connect(sockfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    if (status < 0) {
        perror("\n Database appears to be offline");
        exit(1);
    } // End if
    
    return sockfd;
} // End serverConnect

 // ###############################################
void usage(int argc) {
    if (argc != 2) {
        printf("\n usage: a.out <database ip>\n");
        exit(1);
    } // End if
} // End usage