#include <stdio.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
    // Windows
    #define OS_NAME "Windows"
#elif defined(__linux__)
    // Linux
    #define OS_NAME "Linux"
#elif defined(__APPLE__) && defined(__MACH__)
    // macOS
    #define OS_NAME "macOS"
#else
    // Other or unknown OS
    #define OS_NAME "Unknown"
#endif


int main() {
    return 0;
}


// this is the main code 
// when everything is ready this is where all the code is executed
// for now it just checks what os is running
// i will edit it so that it gets more informations