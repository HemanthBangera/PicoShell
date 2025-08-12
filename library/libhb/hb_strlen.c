#include "libhb.h"

size_t hb_strlen(const char* str){
    size_t i=0;

    if(!str[i]) return i;
    while(str[i]) i++;
    return i;
}