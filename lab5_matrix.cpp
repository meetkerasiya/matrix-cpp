#include <iostream>
using namespace std;
class matrix
{
    int a[15][15];
    int tran[15][15];
    int m,n;
    public:
    matrix()
    {
        m=0;n=0;   
    }
    matrix(int m,int n)
    {
        m=m;
        n=n;
    }
    void get()
    {
        cout<<"please enter dimention of the matrix\n";
        cin>>m>>n;
    }
    void set()
    {
        cout<<"please enter elements of the matrix"<<endl;
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<"a("<<i<<","<<j<<")= \n";
                cin>>a[i][j];
            }
        }
    }
    matrix add_matrix(matrix o)
    {   
        matrix result;
        if(m==o.m && n==o.n)
        {
            int i;
            int j;
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    result.a[i][j]=a[i][j]+o.a[i][j];
                }
            }
        }
        return result;
    }
    void transpose()
    {
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                tran[j][i]=a[i][j];

            }
        }
         for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j]=tran[i][j];
            }
        }
    }
    matrix multi(matrix o)
    {
        matrix result;
        int i,j,k;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                result.a[i][j]=0;
                for(k=0;k<m;k++)
                {
                    result.a[i][j]=result.a[i][j]+(a[i][k]*a[k][j]);
                }
            }
        }
        return result;
    }
    void plus()
    {
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j] += 5;
            }
        }
    }
    void min()
    {
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j] = a[i][j]-5;
            }
        }
    }
    void display()
    {
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
                if(j==n-1)
                cout<<endl;
            }
        }
    }
};
int main()
{
    matrix m1,m2;
    cout<<"for matrix 1 \n";
    m1.get();
    m1.set();
    cout<<"for matrix 2 \n";
    m2.get();
    m2.set();
    cout<<"transpose of matrix 1\n";
    m1.transpose();
    m1.display();
    cout<<"transpose of matrix 2\n";
    m2.transpose();
    m2.display();
    m1.transpose();
    m2.transpose();
    cout<<"after adding 5 to every element in matrix 1 \n";
    m1.plus();
    m1.display();
    cout<<"after adding 5 to every element in matrix 2 \n";
    m2.plus();
    m2.display();
    m1.min();
    m2.min();
    cout<<"addition of  matrix is \n";
    m1.add_matrix(m2);
    m1.display();
    cout<<"multiplication of matrix is \n";
    m1.multi(m2);
    m1.display();
    return 0;
}