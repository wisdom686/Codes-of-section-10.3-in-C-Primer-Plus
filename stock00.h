#ifndef STOCK00_H_
#define STOCK00_H_
#include <string>
class Stock   //Class declaration
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; };
public:
	//Stock() {};

	Stock(const std::string& co = "Error", long n = 0, double pr = 0.0);//逆天！书上P354的代码少了std::,害得我找了1天的bug

	//Stock(const string &co, long n, double pr);
	void acquire( const std::string &co, long n, double pr );
	void buy(long num, double price);
	void sell(long num,double price);
	void update(double price);
	void show();
};   //Note semicolon at the end





#endif
