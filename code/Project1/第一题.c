
/*int rom(int a) {
    scanf("%d", a);
}
int main(a)
{
    for (int i = 1;i <= a;i++) {
        if (a % 2 == 0) {
            printf("%d", a);
            break;
        }

    }return 0;

}*/
/*#include <stdio.h>
int main()
{
    int a;
    int m = 0;
    scanf_s("%d", &a);
    for (int i = 2;i < a;i++) {
        if (a % i == 0) {
            m = 1;
        }
    }

    if (m == 1) { printf("1"); }
    else { printf("0"); }


    return 0;
}*/
#include <stdio.h>
int main()
{
    int a;
    scanf_s("%d", &a);
    int b[10];
    for (int i = 0;i < a;i++)
    {
        scanf_s("%d", &b[i]);
    }
    int max, min = b[0];
    for (int c = 1;c < a;c++)
    {
        if (max < b[c]) { max = b[c]; }
        if (min > b[c]) { min = b[c]; }

    }
    printf("%d\n%d", max, min);
    return 0;
}