#include "UPC-Header.h"

#define NUM_OF_ITEMS 1000

void readUPC(void);
void scanItems(void);

char upcList[NUM_OF_ITEMS][MAX_CODE_LENGTH];


// ###############################################
int main(void) {
    readUPC();   
    
    srand((int)time(NULL));
    
    scanItems();
    
    return 0;
} // End main


// ###############################################
void readUPC(void) {
    int i;
    int filedes;
    char buffer[MAX_NAME_LENGTH];
    
    
    filedes = open(FILE_PATH, O_RDONLY);
    if (filedes < 0) {
        perror("Open error");
        exit(1);
    } // End if
    
    for (i = 0; i < NUM_OF_ITEMS; i++) {
        gets_w(filedes, buffer, MAX_NAME_LENGTH);
        gets_w(filedes, upcList[i], MAX_CODE_LENGTH);
        getf(filedes, sizeof(int));
        getf(filedes, sizeof(int));
        getf(filedes, sizeof(float));
    } // End for
} // End readUPC


// ###############################################
void scanItems(void) {
    int i;
    int productNumber;
    int sleepTime;
    int numItems;
    
    //    for ( ; ; ) {
    numItems = rand() % 10 + 1;
    for (i = 0; i < numItems; i++) {
        productNumber = rand() % 1000;
        printf("%s\n", upcList[i]);
        if (i== numItems-1) break;
        sleepTime = rand() % 4;
        sleep(sleepTime);
    } // End for
    //    } // End for
} // End scanItems