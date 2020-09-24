#include <stdio.h>

int main(){
    int i = 100;
    int * p = &i;
    printf("p   = %p\n", p);
    printf("p+2 = %p\n", p+2);
    return 0;
}