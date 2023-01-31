#include <iostream>
#include <string>
using namespace std;

string add(string x, string y)
{
	string u;
	int z;
	z = stoi(x) + stoi(y);
	u = to_string(z);
	return u;
}

void pad(string & x, string & y, int check)
{
	int s1 = x.size();
	int s2 = y.size();
	
	if (check == 0)
	{
		for (int i = 1; i <s2; i++)
		{
			x = x + "0";
		}
		return;
	}
	
	if (!(s1 == s2) && check == 1)
	{
		
		if (s1 < s2)
		{
			for (int i = 0; i < s2 - s1; i++)
			{
				x = "0" + x;
			}
			s1 = x.size();
		}
		if (s1 > s2)
		{
			for (int i = 0; i < s1 - s2; i++)
			{
				y = "0" + y;
			}
			s2 = y.size();
		}
	}
	if (s1 == s2 && check == 1 && s1%2 != 0)
	{
		x = "0" + x;
		y = "0" + y;
		s1 = x.size();
		s2 = y.size();
	}
}

string multiply(string i1, string i2, const string arr[10][10])
{
	string ac, bd, o, adbc, temp2;
	string a, b, c, d;
	string result;
	string t1, t2, t3;
	int temp;
	int s1 = i1.size();
	int s2 = i2.size();
	
	
	if (s1 == 1)
	{
		if (s2 == 1)
		{
			return arr[stoi(i1)][stoi(i2)];
		}
	}
	pad(i1, i2, 1);
	s1 = i1.length();
	s2 = i2.length();
	if (s1%2 == 0)
	{
		a.resize(s1/2);
		b.resize(s1/2);
		c.resize(s2/2);
		d.resize(s2/2);
		for (int i = 0; i < (s1/2); i++)
		{
			a[i] = i1[i];
			c[i] = i2[i];
		}
		for (int i = (s1 / 2); i < s1; i++)
		{
			b[i- (s1/2)] = i1[i];
			d[i- (s1/2)] = i2[i];
		}
		ac = multiply(a, c, arr);
		bd = multiply(b, d, arr);
		t1 = add(a, b);
		t2 = add(c, d);
		o = multiply(t1,t2, arr);
		temp = stoi(o) - stoi(add(ac, bd));
		adbc = to_string(temp);
		temp = pow(10,s1);
		temp2 = to_string(temp);
		
		pad(ac,temp2,0);
		temp2.clear();
		temp = pow(10, (s1 / 2));
		temp2 = to_string(temp);
		pad(adbc, temp2, 0);
		result = add(add(ac, adbc),bd);
	}
	
	
	return result;
	
}


int main()
{
	int mult;
	string a[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			mult = i * j;
			a[i][j] = to_string(mult);
		}
	}
	string d = "2925";
	string b = "6872";

	string m = "292";
	string n = "687";

	string q = "2925";
	string z = "687";

	string result1, result2, result3;

	result1 = multiply(d, b, a);
	result2 = multiply(m, n, a);
	result3 = multiply(q, z, a);

	cout << d << " X " << b << " = "<< result1 << endl;
	cout << m << " X " << n << " = " << result2 << endl;
	cout << q << " X " << z << " = " << result3 << endl;

	system("pause");
	return 0;
}