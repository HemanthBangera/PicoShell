#include "libhb.h"

size_t hb_strlen(char* str){
    size_t i=0;

    if(str[i]==NULL) return i;
    while(str[i]) i++;
    return i;
}