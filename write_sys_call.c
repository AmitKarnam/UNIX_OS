#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fileDescriptor;
    char buffer[] = "This text was written using write system call.";
    ssize_t bytesWritten;

    fileDescriptor = open("./example.txt", O_WRONLY | O_APPEND );

    if (fileDescriptor == -1) {
        perror("Error opening file.");
        return 1;
    }

    bytesWritten = write(fileDescriptor,buffer,sizeof(buffer)-1);

    if (bytesWritten == -1) {
        perror("Error writing to file.");
        return 1;
    }

    printf("Wrote %zd bytes to file.\n", bytesWritten);

    if (close(fileDescriptor) == -1) {
        perror("Error closing file.");
        return 1;
    }

    return 0;
}