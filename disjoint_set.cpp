#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    private:
        int n;
        int *Parent;

    public:
        DisjointSet(int num)
        {
            n = num;
            Parent = (int*)malloc(n*sizeof(int));
            MakeSet();
        }

        void MakeSet()
        {
            //Initially all the elements are in their own set
            for(int i=0;i<n;i++)
                Parent[i] = i;
        }

        int Find(int x)
        {
            if(Parent[x] != x)
                Parent[x] = Find(Parent[x]);
            return Parent[x];
        }

        void Union(int i, int j)
        {
            int iRep = Find(i);
            int jRep = Find(j);

            Parent[iRep] = jRep;
        }
};

int main()
{
    int n = 7;
    cout<<"here\n";
    DisjointSet ds(n);
    cout<<"here\n";
    ds.Union(2, 3);
    cout<<"here\n";
    cout<<ds.Find(0)<<endl;
    cout<<"here\n";
    cout<<ds.Find(2)<<endl;
    cout<<ds.Find(3)<<endl;
}
