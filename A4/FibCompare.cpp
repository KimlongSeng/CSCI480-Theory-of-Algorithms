#include <iostream>

using namespace std;



int Top_down_Fib(int n)
{
    int memo[] = empty(); 
    int fib[n+1];
   
        if (memo[n] != empty())
        {
            return memo[n];
        }
        else if (n == 1 || n==2)
        {
            return 1;
        }
        else
        {
            memo[n] = fib[n-1]+fib[n-2];
        }
     return memo[n];
}

int Recursive_Fib(int n)
{
    int f[n+1];
    f[0]=0;
    f[1]=1;
        for(int i=2; i < n;i++)
        {
            f[i] = f[i-1] + f[i-2];
        }
     return f[n];
}


int main()
{
    int n;
    cout <<"Please enter a number" <<endl;
    cin >> n;
    cout << "Fibinacci number is" << Recursive_Fib(n) <<endl;


    return 0;
}