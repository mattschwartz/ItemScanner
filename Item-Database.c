// ###############################################
/* **************************************************
 
 * File name:               Item-Database.c
 * Project name:            Item-Scanner-Simulator
 * Author:                  Matt Schwartz
 * Date created:            June 26, 2011
 * Additional information:  Reads in list of products
    and associated product information and allows 
    incoming network communication from terminal
 
 ************************************************** */

#include "UPC-Header.h"
#include "Network-Header.h"

#define MAX_NUM_ITEMS 1000

item_t itemList[MAX_NUM_ITEMS];

void readProductList(void);
void readStruct(int productfd, item_t *product);
void gets_w(int filedes, char *string, int size);
float getf(int filedes, int size);


// ###############################################
int main(void) {
    int status;
    int clientfd;
    int listenfd;
    
    printf("\n Reading in product information from file\n");
    readProductList();
    printf("\n Finished reading product information\n");
    
    printf("\n Opening network connection\n");
    listenfd = openSocket();
    
    printf("\n Listening for clients\n");
    for ( ; ; ) {
		clientfd = accept(listenfd, (struct sockaddr *) NULL, NULL);
        printf("\n Accepted client on TCP connection\n");
        
        status = close(clientfd);
        if (status < 0)
            perror("\n Close error");
        
    } // End for
    
    return 0;
} // End main


// ###############################################
int openSocket(void) {
    int status;
    int sockfd;
    struct sockaddr_in serverAddress;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("\n Unable to create socket");
        exit(1);
    } // End if
    
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(DATABASE_PORT);
    
    status = bind(sockfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    if (status < 0) {
        perror("\n Unable to bind to listen file descriptor");
        exit(1);
    } // End if
    
    status = listen(sockfd, LISTENQ);
    if (status < 0) {
        perror("\n Unable to listen to file descriptor");
        exit(1);
    } // End if
    
    return sockfd;
} // End openSocket



// ###############################################
void readProductList(void) {
    int i;
    int productList_fd;
    
    productList_fd = open(FILE_PATH, O_RDONLY);
    if (productList_fd < 0) {
        perror("Open error");
        exit(1);
    } // End if
    
    for (i= 0; i < MAX_NUM_ITEMS; i++) {
        readStruct(productList_fd, &itemList[i]);
    } // End for
} // End readProductList


// ###############################################
void readStruct(int productList_fd, item_t *product) {
    // read product name
    gets_w(productList_fd, product->productName, MAX_NAME_LENGTH);
    
    // read product code
    gets_w(productList_fd, product->productCode, MAX_CODE_LENGTH);
    
    // read alcohol flag
    product->alcoholFlag = getf(productList_fd, sizeof(int));
    
    // read tobacco flag
    product->tobaccoFlag = getf(productList_fd, sizeof(int));
    
    // read product cost
    product->productCost = getf(productList_fd, sizeof(float));
} // End readItemList