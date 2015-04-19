//Nhlakanipho Calvin Nsindane
//210503824

#include <iostream>
#include <string.h>

using namespace std;

struct frac{            // numarator and denominator structure
	int num;            // initialize number
	int den;
};

frac addsub(frac, frac, int);
frac subdiv(frac, frac, int);
void print(frac, frac, string, frac);

int main()
{
	frac one;    //first fraction
	frac two;    //second fraction
	cout << "Enter fraction one" << endl << "numerator :";
	cin >> one.num;
	cout << "Denominator :";
	cin >> one.den;
	cout << endl << "Enter fraction two" << endl << "numerator :";
	cin >> two.num;
	cout << "Denominator :";
	cin >> two.den;

	frac ans = addsub(one, two, 1);       //Adding two numbers
	print(one, two, "+", ans);

	ans = addsub(one, two, 0);            //Subracting the number
	print(one, two, "-", ans);

	ans = subdiv(one, two, 0);            //Multiplication
	print(one, two, "*", ans);

	ans = subdiv(one, two, 1);            //Division
	print(one, two, "/", ans);

	system("pause");
	return 0;
}

//This function add and subtract fraction

frac addsub(frac a, frac b, int pick)
{
	frac c;
	c.den = a.den * b.den;                      //common denominator
	int first = a.num * b.den;
	int sec = b.num * a.den;
	if (pick == 1)                                           //addition
	{
		c.num = first + sec;
	}
	else                                                  //Subtraction
	{
		c.num = first - sec;
	}
	return c;
}

// This function performs divides and multiplies the number

frac subdiv(frac a, frac b, int pick)
{
	if (pick == 1)
	{
		int just = b.den;
		b.den = b.num;
		b.num = just;
	}
	frac c;
	c.num = a.num * b.num;
	c.den = a.den * b.den;
	return c;
}

//in this function negative answers are correctly displayed 

void print(frac a, frac b, string cun, frac ans)
{
	if (ans.num< 0 && ans.den<0 || ans.num> 0 && ans.den>0)                 //positive check
	{
		cout << a.num << "/" << a.den << " " << cun << " " << b.num << "/" << b.den << " = " << ans.num << "/" << ans.den << endl;
	}
	else                                                                        //negative check
	{
		if (ans.num<0)                                                           //removing negative sign from numnerator of answer
		{
			ans.num = -1 * ans.num;
		}
		if (ans.den<0)                                                           //removing negative sign from denominator of answer
		{
			ans.den = -1 * ans.den;
		}
		cout << a.num << "/" << a.den << " " << cun << " " << b.num << "/" << b.den << " = - " << ans.num << "/" << ans.den << endl;
	}

}
