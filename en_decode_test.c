#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "en_decode.h"

int main(int argc, char const *argv[])
{
    char test_str[]="AaBbCcDdXxYyZz123890-=,./";

    printf("加密前:%s\n",test_str);
    encode(test_str,3);
    
    printf("加密后:%s\n",test_str);
    decode(test_str,3);

    return 0;
}
