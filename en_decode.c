#include "en_decode.h"

void encode(char *msg, int key)
{
    int i;
    for (i = 0; msg[i]; i++)
    {
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            msg[i] = (msg[i] + key > 'z') ? (msg[i] + key - ('z' - 'a' + 1)) : (msg[i] + key);
        }
        else if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            msg[i] = (msg[i] + key > 'Z') ? (msg[i] + key - ('z' - 'a' + 1)) : (msg[i] + key);
        }
        else
        {
            continue;
        }
    }
}
void decode(char *msg, int key)
{
    int i;
    for (i = 0; msg[i]; i++)
    {
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            msg[i] = (msg[i] - key < 'a') ? (msg[i] - key + ('z' - 'a' + 1)) : (msg[i] - key);
        }
        else if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            msg[i] = (msg[i] - key < 'A') ? (msg[i] - key + ('Z' - 'A' + 1)) : (msg[i] - key);
        }
        else
        {
            continue;
        }
    }
}