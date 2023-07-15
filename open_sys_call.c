#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main() {
    int fileDescriptor;

    // write-only mode (O_WRONLY) and creates it if it doesn't exist (O_CREAT). 
    fileDescriptor = open("./example.txt",O_WRONLY | O_CREAT, 0666);

    if (fileDescriptor == -1) {
        perror("Error opening file.");
        return 1;
    }

    printf("File opened successfully. File Descriptor %d\n", fileDescriptor);

    if(close(fileDescriptor) == -1) {
        perror("Error closing file.");
        return 1;
    }

    return 0;   
}