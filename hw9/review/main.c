#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int *pa;

    int *pb;

    a = 1;
    pa = &a;
    pb = pa;
    printf("a is %d\n",a);
    printf("address of a is %x\n",&a);
    printf("pa is %x\n",pa);
    printf("value stored at the address in pb is %d\n",*pa);
    printf("pb is %x\n",pb);
    printf("value stored at the address in pb is %d\n",*pb);
    printf("a is %d\n",a);

    return 0;
}
