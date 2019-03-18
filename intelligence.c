#include <kipr/botball.h>

int main()
{
    int a=0;
    while(a==a){
        motor(a%2,(analog(0)-2500)/(-25));
        a+=1;
    }
    
    ao();
    return 0;
}
