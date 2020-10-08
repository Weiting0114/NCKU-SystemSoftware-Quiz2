#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define ans_1 0x8080808080808080

bool is_ascii(const char str[], size_t size)
{
    if (size == 0)
        return false;
    int i = 0;
    while ((i + 8) <= size) {
        uint64_t payload;
        memcpy(&payload, str + i, 8);
        if (payload & ans_1)
            return false;
        i += 8;
    }
    while (i < size) {
        if (str[i] & 0x80)
            return false;
        i++;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    char t[] = {"sdsdsSDASrhjk"};
    char s[] = {"Abds@djilajdl~!]"};
    if (is_ascii(t, strlen(t)))
        printf("TRUE\n");
    if (is_ascii(s, strlen(s)))
        printf("TRUE\n");
}