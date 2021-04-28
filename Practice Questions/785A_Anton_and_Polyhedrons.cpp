#include<iostream>
using namespace std;
 
int total_faces(int n, string *shapes)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(shapes[i] == "Tetrahedron")
            sum += 4;
        else if(shapes[i] == "Cube")
            sum += 6;
        else if(shapes[i] == "Octahedron")
            sum += 8;
        else if(shapes[i] == "Dodecahedron")
            sum += 12;
        else if(shapes[i] == "Icosahedron")
            sum += 20;
    }
    return sum;
}
 
int main()
{
    int n;
    cin>>n;
    string shapes[n];
    for(int i=0;i<n;i++)
        cin>>shapes[i];
        
    cout<<total_faces(n,shapes);
    return 0;
}