#include <iostream>
#include <chrono>


//Collaborater: Jesse Hallon 

using namespace std;
int Top_Down_Fib(int n)
{
    long long int f[n+2];
    f[0]=0;
    f[1]=1;
        for(int i=2; i <= n;i++)
        {
            f[i] = f[i-1] + f[i-2];
        }
     return f[n];
}

 int recursive(int n)
 { 
    if(n<2)
    {
        return n;
    }
    return recursive(n-1)+recursive(n-2);
 }

int Bottom_up(int n)
{
    int memo[n];
    int fib[n];
    fib[0]=0;
    for (int k=1; k<=n; k++)
    {
        if(k<=2)
        {
            fib[k]=1;
        }
        else
        {
            fib[k]= memo[k-1] + memo[k-2];
        }
        memo[k]=fib[k];
    }
    return fib[n];
}

int main()
{
    int n;
    cout <<"Please enter a number" <<endl;
    cin >> n;
    cout <<endl;
    
    
    
 
  
    auto start = chrono::steady_clock::now();
   cout << "Fibinacci Top down number  is " << Top_Down_Fib(n)<< " ";
    auto end = chrono::steady_clock::now();
    cout << "Time spend on Top_Down DP = "<< chrono::duration_cast<chrono::microseconds>(end - start).count()<< " microseconds"<<endl;

      auto start1 = chrono::steady_clock::now();
    cout << "Fibinacci Bottom up number is " << Bottom_up(n)<< " ";
    auto end1 = chrono::steady_clock::now();
    cout << "Time spend on Bottom-up DP = "<< chrono::duration_cast<chrono::microseconds>(end1 - start1).count()<< " microseconds"<<endl;

    auto start2 = chrono::steady_clock::now();
   cout << "Fibinacci Recursive number is " << recursive(n)<<" ";
    auto end2 = chrono::steady_clock::now();
    cout << "Time spend on Recursive with DP = "<< chrono::duration_cast<chrono::microseconds>(end2 - start2).count()<< " microseconds"<<endl;

    return 0;
}