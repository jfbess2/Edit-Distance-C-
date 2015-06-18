//Jacob Besse
//UVA 1207

//I used a dynamic approach instead of the brute-force, recursive approach we went over in class.
//Create an array, that mocks the one drawn on the broad in class, which was based off differences in letters.
//I return the bottom right element becuase this will be the minimum number of operations



using namespace std;

#include <iostream>
#include <array>
#include <string>
#include <algorithm>
   

char trace[1000][1000];


int count(string s1, string s2)
{
        int a = s1.length();
        int b = s2.length();
        for (int i = 0; i <= a; i++) {
                trace[i][0] = i;
        }
        for (int j = 0; j <= b; j++) {
                trace[0][j] = j;
        }
 
        for (int i = 1; i <= a; i++) {
                for (int j = 1; j <= b; j++) {
                        if (s1[i-1] == s2[j-1]) 
							{trace[i][j] = trace[i-1][j-1];}
                        else 
							{trace[i][j] = 1 + min(  min(trace[i][j-1], trace[i-1][j])  ,trace[i-1][j-1]);}
                }
        }
 
        return trace[a][b];
}


int main()
{
    int size1, size2;
    string s1, s2;

    while(cin>>size1>>s1>>size2>>s2)
    {

        cout<<count(s1, s2);
        cout<<endl;
    }
    return 0;
}


