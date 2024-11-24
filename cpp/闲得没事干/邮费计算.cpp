
#include <iostream>
int func()
{
    int weight;
    char is_urgent;
    int price;
    std::cin>>weight;
    std::cin>>is_urgent;
    if(weight<=1000)
    {
        price=8;
    }
    else
    {
        if((weight-1000)%500==0)
        {

            price=8+(weight-1000)/500*4;
        }
        else
        {
            price=8+(weight-1000)/500*4+4;
        }
    }
    if(is_urgent=='y')
    {
        return price+5;
    }
    else
    {
        return price;
    }
}

int main()
{

    std::cout<<func();

    return 0;
}