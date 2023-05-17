#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include "stock00.h"

using namespace std;

//Stock::Stock() {};
Stock::Stock(const string& co, long n, double pr) {
    company = co;
    if (n < 0)
    {
        std::cerr << "number of shares can't be negative;"
            << company << " shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
        share_val = pr;
        set_tot();

    }
}

void Stock::acquire(const std::string& co, long n, double pr) 
//��ʾ�״ι���(acquire)��Ʊ(�����ں���ġ�����(buy)��)��������������ֱ��ʾ�������Ʊ�����Ĺ�˾����(company)�����������Ʊ��(number)��,��ÿ�ɼ۸�(price)��
{
    company = co;
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative;" << company << "shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}


void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative." << "Transaction is aborted.\n";    
    }
    else
    {
        shares += num;
        share_val = price;    //��������ǰ��Ļ���������Ĺ�Ʊ����۸���������ڵ��г���
        set_tot();
    }

}

void Stock::sell(long num,double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares sold can't be negative." << "Transaction is aborted.\n";    
    }
    else if (shares < num)
    {
        std::cout << "   You can't sell more than you have!!!"
            << " Transaction is aborted.\n";

    }
    else 
    {
        shares -= num;
        share_val = price;
        set_tot();
    
    }

}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    std::cout << "Company: " << company
              << "   Shares: " << shares << '\n'
              << "   Share Price: $" << share_val
              << "   Total Worth: $" << total_val << "\n\n";
}


int main() {
    Stock kate;
    Stock fluffy_the_cat;
    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(3.0e5, 40.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(3.0e5, 0.125);
    fluffy_the_cat.show();
  

    system("pause");
    return 0;
}