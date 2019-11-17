#include <iostream>
#include "fraction.h"
#include "point.h"

using namespace std;

bool turnsLeft(Point p, Point q, Point r);
bool turnsRight(Point p, Point q, Point r);
void insertionSort(Point list[], int n);
void findHull(Point P[], int k, Point hull[], int &nhull);
bool isInsideHull(Point p, Point H[], int r);

int main()
{
    int police_num, robber_num, people_num, k,z, s, t, d,nph,nrh;
    Point police_points[100],police_hull[100],robber_points[100],rob_hull[100],people_point;
    //==============
    //Read in information
    cout << "Enter the number of police officers you want for the game: " << endl;
    cout << "Enter the number of robbers you want for the game: " << endl;
    cout << "Enter the number of people you want to test in the program." << endl;
    cin >> police_num >> robber_num >> people_num;
    //====================================================================================================================
    //i need an array of police officer like points and locations;
    //three arrays , read all threee into arrays.
    //police_point[],robber_point[],people_point[]
    //====================================================================================
    //begin of read in
    cout << "Enter " << police_num << " locations of your police: " << endl;
    for (int i = 0; i < police_num; i++)
    {
        cin >> police_points[i];
    }

    cout << "Enter " << robber_num << " locations of your robbers: " << endl;
//    robber_points[robber_num];
    for (int i = 0; i < robber_num; i++)
    {
        cin >> robber_points[i];
    }
    cout << "Enter " << people_num << " locations of your people" << endl;
//    for (int i = 0; i < people_num; i++)
  //  {
    //    cin >> people_points[i];
    //}

    //End of read in
    //====================================================================================================================
    //find hull k.

// void findHull(Point P[], int k, Point hull[], int &nhull)


    findHull(police_points,police_num,police_hull,nph);
    findHull(robber_points, robber_num,rob_hull,nrh);
    for (int i=0;i<k;i++){
        cout << police_hull[i] <<"i"<< endl;}
    for (int i=0;i<k;i++)
    {cout << rob_hull[i] << "j" <<endl;}
    
    
    for(int w = 0; w < people_num; w++)
    {
        cin >> people_point;
        if(isInsideHull(people_point, police_hull,nph) == true)
        s++;
        else if (isInsideHull(people_point,rob_hull,nrh) == true)
        t++;
        else d++;
    }

    //Calculcations (Call your functions)
    //=================
    //Output the results

    cout << "The number of people are safe is: " << s << endl;
    cout << "The number of people are being robbed: " << t << endl;
    cout << "The number of people who are in danger is: " << d << endl;

    return 0;
}
//===========================================================================
bool turnsLeft(Point p, Point q, Point r)
{
    return ((q-p)*(r-p)>0);
}
//===========================================================================
bool turnsRight(Point p, Point q, Point r)
{
    return ((q-p)*(r-p)<0);
}
//===========================================================================
void insertionSort(Point list[], int n)
{
    Point tmp;
    int i;
    for(int s = 1; s < n ; s++)
    {
        tmp = list[s];
        for ( i = s-1; i >= 0 && (list[i].getX() > tmp.getX()||
        (list[i].getX()==tmp.getX()&&list[i].getY()>tmp.getY()));i--){
        list[i+1] = list[i];
        }
    list[i+1]=tmp;
    }
}
//===========================================================================
void findHull(Point P[], int k, Point hull[], int &phull)
{
insertionSort (P,k);
Point lower[100],upper[100];
int t,u;

lower[0]= P[0];
t = 0;

for(int i = 1; i < k ; i++)
{
    while( t > 0 && turnsLeft(lower[t-1],lower[t],P[i]) == false)
    {
        t = t - 1;
    }
    t = t + 1;
    lower[t] = P[i];
}
upper[0] =P[k-1];
u=0;

for(int i = (k - 2); i >=0 ; i--)
    {
        while(u > 0 && turnsLeft(upper[u-1],upper[u],P[i]) ==false)
        {
            u = u-1;
        }
        u = u + 1;
        upper[u] = P[i];
    }
phull = 0;

    for(int i = 0; i < t; i ++)
    {
        hull[phull] = lower[i];
        phull++;
    }
for(int i = 0; i < u; i++)
    {
        hull[phull] = upper[i];
        phull++;
    }
}
//===========================================================================
//isInsideHull
bool isInsideHull(Point P, Point H[], int k)
{
    int j;
    for (int i = 0; i < k ; i++)
    {
        j=(i+1)%k;
        if (turnsRight(P,H[i],H[j]))
        {
            return false;
        }
    }
    return true;
}
//==========================================================================

// ./runproject < test.dat
