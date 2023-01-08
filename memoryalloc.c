#include "memoryalloc.h"
int check_spaces_endl(char tempChar)
{
    if (tempChar == ' ')
    {
        printf("Please enter each segment seprated with ONLY ONE SPACE!\n");
        return TRUE;
    }
    if (tempChar == '\n')
    {
        printf("Too few entry! please ensure that your command is correct \n");
        return TRUE;
    }
}

char *dynamic_memory_alloc(char *chararray, char tempChar, int mode)
{
    size_t count_read = 0;
    size_t increase, allocated, upper;
    if (mode == REGISTER_MODE)
    {
        increase = LOWER_REGISTER;
        upper = UPPER_REGISTER;
    }
    else
    {
        increase = LOWER_TEXT;
        upper = UPPER_TEXT;
    }
    allocated = increase;
    chararray = calloc(allocated, CLEAR_MEM);
    while (((mode == REGISTER_MODE) && tempChar != ' ' && tempChar != '\n') || (mode == TEXT_MODE) && tempChar != '\n') // Dynamic memory alloc for the char array
    {
        chararray[count_read] = tempChar;
        tempChar = getchar();
        count_read++;
        if (count_read >= allocated) // Expand memory  by dobuling the value each time untill upper limit reach and stop increasing from there
        {
            if (increase >= upper)
                increase = upper;
            allocated += increase;
            chararray = realloc(chararray, allocated);
            increase *= 2;
        }
    }
    if ((mode == REGISTER_MODE) && tempChar == '\n')
    {
        ungetc(tempChar, stdin);
    }
    /*realloc to get the fixed size*/
    chararray = realloc(chararray, count_read);
    return chararray;
}