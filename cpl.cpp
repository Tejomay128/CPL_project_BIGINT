#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

typedef string bigInt;

bigInt add(bigInt a,bigInt b)                  //addition function
{
	bigInt c="";
	vector<int> a_val,b_val;
	int a_len,b_len,i,carry,max_len,val,lim;
	char ch;
	a_len = a.length();
	b_len = b.length();

	if(a[0]=='-')
		lim=1;
	else
		lim=0;

	for(i=a_len-1;i>=lim;i--)                  //storing the strings in polynomial form 
	{
		a_val.push_back(a[i] - '0');
	}

	if(b[0]=='-')
		lim=1;
	else
		lim=0;

	for(i=b_len-1;i>=lim;i--)
	{
		b_val.push_back(b[i] - '0');
	}

	max_len = (a_len>b_len) ? a_len:b_len;     //making equal sized vectors

	for(i=a_len;i<max_len;i++)
		a_val.push_back(0);
	for(i=b_len;i<max_len;i++)
		b_val.push_back(0);

	carry = 0;
	for(i=0;i<max_len;i++)                      //calculating sum
	{
		val = a_val[i]+b_val[i]+carry;
		ch = (val%10) + '0';
		c.push_back(ch);
		carry = val/10;
	}
	if(carry == 1)                              //if carry is generated for the highest power coefficient
		c.push_back('1');
	reverse(c.begin(),c.end());

	return c;
}

bool isGreater(bigInt a,bigInt b)              //returns true if a>b
{
	bool retval;
	int a_len,b_len;
	a_len = a.length();
	b_len = b.length();
	if(a_len>b_len)
		retval = true;
	else if(a_len<b_len)
		retval = false;
	else
	{
		bool flag = true;
		int i=0;
		while(i<a_len && flag)
		{
			
		}
	}
}

bigInt sub(bigInt a,bigInt b)
{
	bigInt c="";
	vector<int> a_val,b_val;
	int a_len,b_len,i,borrow,max_len,val,lim;
	char ch;
	a_len = a.length();
	b_len = b.length();

	if(a[0]=='-')
		lim=1;
	else
		lim=0;

	for(i=a_len-1;i>=lim;i--)                  //storing the strings in polynomial form 
	{
		a_val.push_back(a[i] - '0');
	}

	if(b[0]=='-')
		lim=1;
	else
		lim=0;
	
	for(i=b_len-1;i>=lim;i--)
	{
		b_val.push_back(b[i] - '0');
	}

	max_len = (a_len>b_len) ? a_len:b_len;     //making equal sized vectors

	for(i=a_len;i<max_len;i++)
		a_val.push_back(0);
	for(i=b_len;i<max_len;i++)
		b_val.push_back(0);

	borrow = 0;
	for(i=0;i<max_len;i++)
	{
		val = a_val[i]-b_val[i]-borrow;
		if(val<0)
		{
			borrow = 1;
			val = val+10;
		}
		else
			borrow = 0;
		ch = val+'0';
		c.push_back(ch);
	}
	if(borrow == 1)
		c.push_back('-');
	reverse(c.begin(),c.end());

	return c;
}

int main()
{
	bigInt a,b,c;
	getline(cin,a);
	getline(cin,b);
	c=sub(a,b);
	cout<<c;
	return 0;
}