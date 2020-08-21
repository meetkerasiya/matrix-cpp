#include <iostream>
using namespace std;
class matrix
{
private:
   int a[10][10];
   int tran[10][10];
   int m,n; /* data */
public:
    matrix(/* args */)
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
    int max()
    {   int b[10][10];
        b[0][0]=a[0][0];
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]>b[0][0])
                b[0][0]=a[i][j];
            }
        }
        return b[0][0];
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
    matrix add_matrix(matrix* &o)
    {   if(m==o->m && n==o->n)
    {
    
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j]=a[i][j]+o->a[i][j];
            }
        }
        
    }
    }
};



int main()
{
    matrix *m1=new matrix;
    matrix *m2=new matrix;
    cout<<"matrix 1"<<endl;
    m1->get();
    m1->set();
    cout<<" so your matrix 1 is :\n";
    m1->display();
    cout<<"matrix 2"<<endl;
    m2->get();
    m2->set();
    cout<<" so your matrix 2 is :\n";
    m2->display();
    cout<<"options : "<<endl;
    int n;
    cout<<"1 : get transpose of matrix \n 2 : get addition of matrix \n 3 : get maximum element of each matrix \n";
    cin>>n;
    switch (n)

    {
    case 1:
    {   m1->transpose();
        cout<<"transpose of matrix 1 is : \n";
        m1->display();
        m2->transpose();
        cout<<"transpose of matrix 2 is : \n";
        m2->display();
        
    }
    break;
    case 2:
    {
        m1->add_matrix(m2);
        cout<<"addition of two matrix is : \n";
        m1->display();
    }
    break;
    case 3:
    {
        cout<<"maximum element of matrix 1 is : "<<m1->max()<<endl;
        cout<<"maximum element of matrix 2 is : "<<m2->max()<<endl;

    }
    
        break;
    
    default:
    cout<<"you have enterd wrong number \n";
        break;
    
    }
    delete m1;
    delete m2;
    return 0;
}