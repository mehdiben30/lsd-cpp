#include<iostream>
#include<vector>

template <typename T>
T powrec(T a, int n){
    if (n == 0){
        return 1;
    }
    if (n % 2 == 0){
        return powrec(a*a, n/2);
    }
    return a * powrec(a*a, (n-1)/2);
}

template <typename T>
T powiter(T a, int n){
    T res=1;
    while(n>0)
    {
        if(n%2 == 0)
        {
            a= a*a;
            n=n/2;
        }
        res=res*a;
        n--;
    }
    return res;
}

int main(){
    std::cout << powiter(2, 3) << '\n';
    std::cout << powiter(1.2, 3) << '\n';
    std::cout << powrec(2, 3) << '\n';
    std::cout << powrec(1.2, 3) << '\n';
    return 0;
}

template <typename T>
using matrix<T> = vector<vector<T>>;

matrix<T> operator*(matrix<T> A,matrix<T> B)
{
    int m= a.size();
    int p = b[0].size();
    int n = b.size();
    matrixe<T> r;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<p;k++)
            {
                r[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return r
}

template <typename T>
matrixe <T> matpow(matrix<T> A,int k)
{
    if(a.size() != a(0).size()) exit(EXIT_FAILURE);
    a.size()=n
    if(k==0)
    {
        matrixe<T> identity(n,vector<T>(n));
        for(i=0;i<n;i++)
        {
            identity[i][i]=1;
        }
        return identity
    }
    if(k%2==0) return matpow(a*a,k/2);
    return a*matpow(a*a,(k-1)/2);
}


T powiter(T a,int n)
{
    while(n>0)
    {
        int res=1
        if(n%2)
        {
            a*=a;
            n/=2;
        }
        res*=a;
        n--;
    }
    return res
}



int main
{
    int n_nodes;
    cin >> n_nodes;
    Graph G;
    G.n_nodes=n_nodes;
    G.adj.resize(n_nodes)
    for(i)
        for(j)
        {
            int w;
            if
        }
}