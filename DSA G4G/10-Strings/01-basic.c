#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "abc";
    char s2[] = "bcdef";

    printf("%d\n", strlen(s1));
    printf("%d\n", strlen(s2));

    int res = strcmp(s1, s2);
    if (res < 0)
        printf("%s\n", s1);
    else if (res == 0)
        printf("Equal\n");
    else
        printf("%s\n", s2);

    char s3[10];
    strcpy(s3, "Aditya");
    printf("%s\n", s3);
}