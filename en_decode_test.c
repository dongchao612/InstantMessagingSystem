#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "en_decode.h"

int main(int argc, char const *argv[])
{
    char test_str[]="AaBbCcDdXxYyZz123890-=,./";
    encode(test_str,3);
    decode(test_str,3);
    printf("%s",test_str);
    return 0;
}
