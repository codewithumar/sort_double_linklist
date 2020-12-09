#include <iostream>
using namespace std;

class stack1
{private:
    char stack[20],x;
int tos=-1;
public:
    void push(char x)
    {
        stack[++tos]=x;
    }
char pop()
    {
        if(tos==-1)
        {
        return -2;
        }
        else{
        return stack[tos--];
        }
    }
int pref(char x)
    {
        if(x=='(')
            return 0;
        if(x=='+' || x=='-')
            return 1;
        if(x=='*' || x=='/' || x=='%')
            return 2;
    }
bool Isoperand(char c)
		{
		if ((c>='a'&& c<='z') || (c>='A'&& c<=' Z'))
			return true;
		else
			return false;

		}
    void postfix(char *e)
		{
		    while(*e!='\0')
    {
        if(Isoperand(*e))
        {
            cout<<*e<<"  ";
        }
        else if(*e=='(')
        {
            push(*e);
        }
        else if(*e==')')
        {
            while((x=pop())!='(')
            {
                cout<<x<<"  ";
            }
        }
        else
        {
            while(pref(stack[tos])>pref(*e))
            {
                cout<<pop()<<"  ";
            }
            push(*e);
        }
        e++;
    }
    while (tos!=-1)
    {

        cout<<pop()<<"  ";
    }

		}
};

int main()
{
    stack1 obj;
    char arr[20];
    char *e,x;
    cout<<"Please enter the Expresion ::";
    cin.getline(arr,30);
    e=arr;
    obj.postfix(e);

}
