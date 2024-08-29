#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ArrayCount(arr) (sizeof arr / sizeof arr[0])
static char Alphabets[] =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
static int unsigned AlphabetsSize = ArrayCount(Alphabets);

static char *
Encode(const char *Input, int unsigned InputSize, int unsigned Shift)
{
    char *Result = malloc(sizeof(char) * (InputSize * AlphabetsSize + 1));
    char *At = Result;

    for(int unsigned i = 0; i < InputSize; ++i)
    {
        if(Input[i] == ' ')
        {
            *At = ' ';
            At++;
            continue;
        }

        for(int unsigned j = 0; j < AlphabetsSize; ++j)
        {
            if(Alphabets[j] == Input[i])
            {
                int unsigned Index = (j + Shift) % AlphabetsSize;
                *At = Alphabets[Index];
                At++;
                break;
            }
        }
    }
    *At = '\0';

    return Result;
}

static char *
Decode(const char *Input, int unsigned InputSize)
{
    char *Result = malloc(sizeof(char) * (InputSize * AlphabetsSize + 1));
    char *At = Result;

    int unsigned shift;
    for(shift = 1; shift < AlphabetsSize; ++shift)
    {
        for(int unsigned i = 0; i < InputSize; ++i)
        {
            if(Input[i] == ' ' )
            {
                *At = ' ';
                At++;
                continue;
            }

            for(int unsigned j = 0; j < AlphabetsSize; ++j)
            {
                if(Alphabets[j] == Input[i])
                {
                    int unsigned Index = (j - shift + AlphabetsSize) % AlphabetsSize;
                    *At = Alphabets[Index];
                    At++;
                    break;
                }
            }
        }
        *At = '\n';
        At++;
    }

    *At = '\0';

    return Result;
}

static char *
DecodeWithShift(const char *Input, int unsigned InputSize, int unsigned Shift)
{
    char *Result = malloc(sizeof(char) * (InputSize * AlphabetsSize + 1));
    char *At = Result;

    for(int unsigned i = 0; i < InputSize; ++i)
    {
        if(Input[i] == ' ' )
        {
            *At = ' ';
            At++;
            continue;
        }

        for(int unsigned j = 0; j < AlphabetsSize; ++j)
        {
            if(Alphabets[j] == Input[i])
            {
                int unsigned Index = (j - Shift + AlphabetsSize) % AlphabetsSize;
                *At = Alphabets[Index];
                At++;
                break;
            }
        }
    }
    *At = '\n';
    At++;

    *At = '\0';

    return Result;
}

int main(int argc, char *argv[])
{
    char Input[] = "zh duh zd lwlqj";
    int unsigned InputSize = ArrayCount(Input);
    char *Decoded = Decode(Input, InputSize);
    printf("%s\n", Decoded);

    char Output[] = "we are wa iting";
    int unsigned OutputSize = ArrayCount(Output);
    int unsigned Shift = 3;
    char *Encoded = Encode(Output, OutputSize, Shift);
    printf("%s\n", Encoded);

    // char *Decoded = DecodeWithShift(Encoded, OutputSize, Shift);
    // printf("%s\n", Decoded);

    if(Decoded)
        free(Decoded);
    if(Encoded)
        free(Encoded);

    return 0;
}
