#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>



typedef uint8_t BYTE;

int main (int argc, char *argv[])
{
    //check usage
    if (argc != 2)
    {
        return 1;
    }
    //open file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }

    //read first three bytes
    BYTE bytes[3];
    fread(bytes, sizeof(BYTE), 3, file);

    //check first three bytes
    if(bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("Maybe\n");
    }
    else
    {
        printf("No \n");
    }
}
