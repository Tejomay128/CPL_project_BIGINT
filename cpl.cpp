#include<iostream>                           //for cin and cout
#include<string>							 //for string class
#include<vector>                             //for vectors and related functions
#include<algorithm>                          //for reverse() function

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

	if(a[0]=='-')                              //the string may contain first character as '-' sign,if that is the case,we need to iterate till index 1 and not 0
		lim=1;
	else
		lim=0;

	for(i=a_len-1;i>=lim;i--)                  //storing the strings in polynomial form 
	{
		a_val.push_back(a[i] - '0');
	}
	if(lim == 1)
		a_len--;

	if(b[0]=='-')
		lim=1;
	else
		lim=0;

	for(i=b_len-1;i>=lim;i--)
	{
		b_val.push_back(b[i] - '0');
	}
	if(lim==1)
		b_len--;

	max_len = (a_len>b_len) ? a_len:b_len;     //making equal sized vectors by pushing zeros at the end of the shorter vector

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
	reverse(c.begin(),c.end());                 //reversing the string as calculated digits were pushed in reverse order

	return c;
}

bool isGreater(bigInt a,bigInt b)              //returns true if a>=b
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
			if(a[i]>=b[i])
			{
				flag=false;
				retval=true;
			}
			else if(a[i]<b[i])
			{
				flag=false;
				retval=false;
			}
			i++;
		}
	}
	return retval;
}

bigInt sub(bigInt a,bigInt b)                 //subtraction function 
{
	bigInt c="";
	vector<int> a_val,b_val;
	int a_len,b_len,i,borrow,max_len,val,lim;
	char ch;
	a_len = a.length();
	b_len = b.length();

	if(a[0]=='-')                              //the string may contain first character as '-' sign,if that is the case,we need to iterate till index 1 and not 0
		lim=1;
	else
		lim=0;

	for(i=a_len-1;i>=lim;i--)                  //storing the strings in polynomial form 
	{
		a_val.push_back(a[i] - '0');
	}
	if(lim == 1)
		a_len--;

	if(b[0]=='-')
		lim=1;
	else
		lim=0;
	
	for(i=b_len-1;i>=lim;i--)
	{
		b_val.push_back(b[i] - '0');
	}
	if(lim == 1)
		b_len--;

	max_len = (a_len>b_len) ? a_len:b_len;     //making equal sized vectors by pushing zeros at the end of the shorter vector

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
	i = c.length() - 1;
	while(i>=1 && c[i]=='0')
	{
		c.pop_back();
		i--;
	}	
	reverse(c.begin(),c.end());               //reversing the string as calculated digits were pushed in reverse order

	return c;
}

bigInt mul(bigInt a,bigInt b)
{
	bigInt c,temp;
	int a_len,b_len,val,carry,i,j,k,zero,lim_a,lim_b;
	char ch;
	a_len = a.length();
	b_len = b.length();
	carry = 0;
	c = temp = "";

	if(a[0]=='-')                               //the string may contain first character as '-' sign,if that is the case,we need to iterate till index 1 and not 0
		lim_a=1;
	else
		lim_a=0;

	if(b[0]=='-')
		lim_b=1;
	else
		lim_b=0;

	for(i=a_len-1;i>=lim_a;i--)                        
	{
		val = (a[i]-'0')*(b[b_len-1]-'0') + carry;      //multiplying the first no. with the last digit of second no. to get an initial value
		carry = val/10;
		val = val%10;
		ch = val+'0';
		c.push_back(ch);
	}
	c.push_back(carry + '0');
	reverse(c.begin(),c.end());                    //reversing the string as calculated digits were pushed in reverse order
	cout<<c<<" ";
	zero = 1;
	for(j=b_len-2;j>=lim_b;j--)
	{  
		carry = 0;
		temp = "";                                          
		for(i=a_len-1;i>=lim_a;i--)
		{
			val = (a[i]-'0')*(b[j]-'0') + carry;        //multiplying with the rest of the digits 
			carry = val/10;
			val = val%10;
			ch = val+'0';
			temp.push_back(ch);	
		}
		temp.push_back(carry + '0');
		reverse(temp.begin(),temp.end());
		for(k=0;k<zero;k++)
			temp.push_back('0');
		zero++;
		c = add(temp,c);
		cout<<c<<" ";
	}
	return c;
}

int main()
{
	bigInt a,b,c,minus;
	minus = "-";
	char opt;
	cout<<"Enter two numbers:\n";
	getline(cin,a);
	getline(cin,b);
	cout<<"Options:\n1)Addition\n2)Subtraction\n3)Multiplication\nChoose one of the above(1-3):";
	cin>>opt;
	switch(opt)
	{
		case '1': {
			if(a[0]=='-' && b[0]=='-')          //both numbers are negative
			{
				c = add(a,b);
				c.insert(0,minus);
			}
			else if(a[0]=='-')                   //first number is negative
			{
				if(isGreater(a,b))
				{
					c = sub(a,b);
					c.insert(0,minus);
				}
				else
					c = sub(b,a);
			}
			else if(b[0]=='-')                   //second number is negative
			{
				if(isGreater(a,b))
					c = sub(a,b);
				else
				{
					c = sub(b,a);
					c.insert(0,minus);
				}
			}
			else                                 //both numbers positive  
				c = add(a,b);
			break;
		}

		case '2': {
			if(a[0]=='-' && b[0]=='-')           //both numbers are negative
			{
				if(isGreater(a,b))
				{
					c = sub(a,b);
					c.insert(0,minus);
				}
				else
					c = sub(b,a);
			}
			else if(a[0]=='-')                    //first number is negative
			{
				c = add(a,b);
				c.insert(0,minus);
			}
			else if(b[0]=='-')                    //second number is negative
			{
				c = add(a,b);
			}
			else                                  //both numbers positive  
			{
				if(isGreater(a,b))
					c = sub(a,b);
				else
				{
					c = sub(b,a);
					c.insert(0,minus);
				}
			}
			break;
		}

		case '3': {
			if((a[0]=='-' && b[0]!='-') || (a[0]!='-' && b[0]=='-'))           //Either first or second no. is negative
			{
				c = mul(a,b);
				c.insert(0,minus); 
			}
			else
				c = mul(a,b);
			break;
		}
	}
	cout<<c<<"\n";
	return 0;
}
