#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    if(strstr(argv[1], "add"))
        printf("\n The addition of %s and %s is %d", argv[2], argv[3], atoi(argv[2])+ atoi(argv[3])); //ASCII to integer
    
    else if(strstr(argv[1], "sub"))
            printf("\n The subtraction of %s and %s is %d", argv[2], argv[3], atoi(argv[2]) - atoi(argv[3]));

    else if(strstr(argv[1], "sub"))
            printf("\n The multiplicagion of %s and %s is %d", argv[2], argv[3], atoi(argv[2]) * atoi(argv[3]));

    return 0;
        
}
