#include "deleteSpace.h"
#include <cstring>
char *deleteSpace(char *str){
    str[strlen(str)-1]='\0';
    return str;
}   