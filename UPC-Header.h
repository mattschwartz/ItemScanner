#ifndef UPC_HEADER
#define UPC_HEADER

#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <time.h>

//struct size = 36
#define FILE_PATH "/Users/mattschwartz/Desktop/CS Projects/1 - Xcode Projects/Item-Scanner-Simulator/Product-List.txt"
#define MAX_NAME_LENGTH 20
#define MAX_CODE_LENGTH 11
#define TRUE  1
#define FALSE 0

void gets_w(int filedes, char *string, int size);
float getf(int filedes, int size);
void usage(int argc);

typedef struct {
    char productName[MAX_NAME_LENGTH];
    char productCode[MAX_CODE_LENGTH];
    int alcoholFlag;
    int tobaccoFlag;
    float productCost;
} item_t;


// ###############################################
void gets_w(int filedes, char *string, int size) {
    int i;
    int status;
    
    memset(string, '\0', size);
    
    for (i= 0; i < size; i++) {
        status = (int)read(filedes, &string[i], 1);
        if (status < 0) 
            perror("Read error");
        
        if (string[i] == '\n') {
            string[i] = '\0';
            break;
        } // End if
    } // End for
    
    /* 
     Not implemented 
     if (string[i] != '\0') { 
     for ( i= 0; ;i++ ) {
     status = (int)read(filedes, &nullBuffer[i], 1);
     if (status < 0)
     perror("Read error");
     
     if (nullBuffer[i] == '\n')
     break;
     } // End for
     } // End if */
} // End gets_w



// ###############################################
float getf(int filedes, int size) {
    int i;
    char buffer[size+1];
    int status;
    
    memset(buffer, 0, size);
    
    for (i= 0; i <= size+1; i++) {
        status = (int)read(filedes, &buffer[i], 1);
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        } // End if
    } // End for
    
    return atof(buffer);
} // End getf

#endif
