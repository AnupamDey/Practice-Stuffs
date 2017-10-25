#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int check_prime(int val)
{
    for (int i = 2; i < (int) (sqrt(val)); ++i)
    {
        if (val%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int check_palindrome(int val)
{   
    int *num = (int *) calloc(7,sizeof(int));
    int i=-1;

    while (val)
    {   i++;
        num[i] = val%10;
        val = val/10;
    }

    for (int j = 0,k=i; j < (i+1)/2; ++j,--k)
    {   
        if (num[k]!=num[j])
        {   
            return 0;
        }
    }
    return 1;

}

int main(int argc, char const *argv[])
{   
    int val=0;
    scanf("%d",&val);

    while(val<=1003001)
    {
        if (check_palindrome(val) && check_prime(val))
        {
            printf("%d\n",val);
            break;
        }
        val++;
    }  
    return 0;
}
