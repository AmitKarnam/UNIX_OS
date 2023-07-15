//The fcntl.h header file provides various constants and function prototypes related to file control operations.
#include <fcntl.h>

//The unistd.h header file provides access to various standard system services, including functions, constants, and types related to I/O operations, process handling, and system utilities.
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

int main() {
    int fileDescriptor;
    char buffer[BUFFER_SIZE];

    //The purpose of ssize_t is to provide a data type that can hold the size or count of bytes returned by I/O-related functions, such as read(), write(), recv(), send()
    ssize_t bytesRead;

    fileDescriptor = open("./example.txt", O_RDONLY);

    if (fileDescriptor == -1) {
        perror("Error opening file.");
        return 1;
    }

    bytesRead = read(fileDescriptor, buffer, BUFFER_SIZE);

    if (bytesRead == -1) {
        perror("Error reading file.");
        return 1;
    }

    printf("Read %zd bytes from the file : \n%s\n", bytesRead,buffer);

    if (close(fileDescriptor) == -1) {
        perror("Error closing file.");
        return 1;
    }

    return 0;



}