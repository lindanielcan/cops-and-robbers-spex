#include <iostream>
#include "fraction.cc"
#include "fraction.h"
#include "point.h"
#include "point.cc"

using namespace std;

int orientation(Point p, Point q, Point r); 
void convexHull(Point points[], int);

    int main()
{
    Fraction f1,f2;
    int orientation(Point , Point q, Point r) ;
    int police_num, robber_num,people_num,police_point,robber_point,people_point, k, s, t, d;
    cout << "Enter the number of police officers you want for the game: " << endl;
    cin >> police_num;
    cout << "Enter the number of robbers you want for the game: " << endl;
    cin >> robber_num;
    cout << "Enter the number of people you want to test in the program." << endl;
    cin >> people_num;
    cout << "Enter the location of your police officers: " << endl;
    for (int i=0; i < police_num; i ++)
        {
              cin >> police_point;
        }
    cout << "Enter the location of your robbers: " << endl;
    for (int i=0; i < robber_num; i ++)
        {
              cin >> robber_point;
        }
    cout << "Enter the location of your people" << endl;
    for (int i=0; i < people_num; i ++)
        {
              cin >> people_point;
        }
    cout << "The number of people are safe is: " << s << endl;
    cout << "The number of people are being robbed: " << t << endl;
    cout << "The number of people who are in danger is: " << d << endl;

    return 0;
}
    int orientation(Point p, Point q, Point r) 
{ 
    Fraction f1,f2
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
}
// Prints convex hull of a set of n points. 
void convexHull(Point points[], int n) 
{ 
    // There must be at least 3 points 
    if (n < 3) return; 
  
    // Initialize Result 
    vector<Point> hull; 
  
    // Find the leftmost point 
    int l = 0; 
    for (int i = 1; i < n; i++) 
        if (points[i].x < points[l].x) 
            l = i; 
  
    // Start from leftmost point, keep moving counterclockwise 
    // until reach the start point again.  This loop runs O(h) 
    // times where h is number of points in result or output. 
    int p = l, q; 
    do
    { 
        // Add current point to result 
        hull.push_back(points[p]); 
  
        // Search for a point 'q' such that orientation(p, x, 
        // q) is counterclockwise for all points 'x'. The idea 
        // is to keep track of last visited most counterclock- 
        // wise point in q. If any point 'i' is more counterclock- 
        // wise than q, then update q. 
        q = (p+1)%n; 
        for (int i = 0; i < n; i++) 
        { 
           // If i is more counterclockwise than current q, then 
           // update q 
           if (orientation(points[p], points[i], points[q]) == 2) 
               q = i; 
        } 
  
        // Now q is the most counterclockwise with respect to p 
        // Set p as q for next iteration, so that q is added to 
        // result 'hull' 
        p = q; 
  
    } while (p != l);  // While we don't come to first point 
  
    // Print Result 
    for (int i = 0; i < hull.size(); i++) 
        cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n"; 
} 
