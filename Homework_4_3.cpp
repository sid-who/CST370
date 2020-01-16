/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw4/challenges/tsp-2-1/submissions/code/1316571784
 * Title: hw4_3.cpp
 * Abstract: This program is meant to solve a Traveling Salesman Problem and return the lowest cost path for 
 * 			 the salesman in question to take. It achieves this by checking every permutation of the salesman's
 *			 path along the vertices of a graph, and returning the shortest path for the salesman to take to end
 * 			 the trip back in the starting city.
 * Author: Gurpreet Sidhu  
 * ID: 2486
 * Date: 9/26/19
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <limits>

using namespace std;

/*DATA STRUCTURES*/
vector<string> cities;
vector<int> citynumbers;
unordered_map<string, int> citymap;
int *grid;
vector<int> grids;

/*VARIABLES*/
int numcities;
int numroutes;
string instring;
string start;
string ending;
int rval;
int factorial;
int permCounter = 0;

/*SOLUTION VARIABLES AND DATA STRUCTURES*/
bool unreachable = false;
int sumCalc = 0;
int failCount = 0;
int sumSaved = numeric_limits<int>::max();
vector<int> solPath = {-1};

void pathMath(vector<int> vec, int size, vector<int> VGRID) //CHANGE PATHMATH TO RETURN A VECTOR
{
    failCount = 0;
    sumCalc = 0;
    
    vector<int> temp;
    temp.push_back(0);
    for(int i = 0; i < vec.size(); i++)
    {
        int temp2 = vec[i];
        temp.push_back(temp2);
    }

    for(int i = 0; i < size; i++)
    {
        if(i == (temp.size() - 1))//(vec[i] == vec.back())
        {
            int t_pos = (size * temp[i]) + 0; //[i][0]
            
            if(VGRID[t_pos] > 0)
            {
                sumCalc += VGRID[t_pos];
            }
            else if(VGRID[t_pos] == -1)
            {
                failCount += VGRID[t_pos];
            }
        }
        else
        {
            int j = temp[i+1];
            int temp3 = temp[i];
            int t_pos = (size*temp3) + j; //[i][j]
            //cout << "i = " << temp3 << "-- j = " << j << "-- position = " << t_pos << "-- VALUE = " << VGRID[t_pos] << "\n";
            if(VGRID[t_pos] > 0)
            {
                sumCalc += VGRID[t_pos];
            }
            else if(VGRID[t_pos] == -1)
            {
                failCount += VGRID[t_pos];
            }
        }  
    }//end of for loop
    if(failCount == 0)
    {
        if(sumCalc < sumSaved)
        {
            sumSaved = sumCalc;
            solPath.erase(solPath.begin(), solPath.end());
            solPath.push_back(0);
            for(int i = 0; i < vec.size(); i++)
            {
                int temp = vec[i];
                solPath.push_back(temp);
            }
            solPath.push_back(0);
        }
    }
}

int findFactorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return n * findFactorial(n-1);
}

vector<int> findPermutations(vector<int> v, int s, vector<int> GRID)
{
    int factorial = findFactorial(s);
    vector<int> solution;
    sort(v.begin(), v.end());
    do{
        pathMath(v, s, GRID);
    }while(next_permutation(v.begin(), v.end()));

    if(solPath[0] != -1)
    {
        for(int i = 0; i < solPath.size(); i++)
        {
            int temp = solPath[i];
            solution.push_back(temp);
        }
    }
    return solution;
}

int main()
{
    vector<int> answer = {-1};

    cin >> numcities;

    getline(cin, instring); //patch fix, ignore first newline character after numcity input

    for(int i=0; i < numcities; i++)
    {   
        getline(cin, instring);
        cities.push_back(instring);
        if(i > 0)
        {
            citynumbers.push_back(i);
        }
    }

    int grid[numcities][numcities];

    //fill the grid
    for(int i=0; i < numcities; i++)
    {
        for(int j=0; j < numcities; j++)
        {
            grid[i][j] = -1;
        }
    }

    //place cities and values in map
    for(int i=0; i < cities.size(); i++)
    {
        string temp = cities[i];
        citymap[temp] = i;
    }

    cin >> numroutes;

    getline(cin, instring);

    for(int i=0; i< numroutes; i++)
    {
        cin >> start;
        cin >> ending;
        cin >> rval;

        grid[citymap.at(start)][citymap.at(ending)] = rval;
    }

    for (int i = 0; i < numcities; i++) 
    { 
        if(i==numcities)
        {
            break;
        } 
        for (int j = 0; j < numcities; j++) 
        { 

            int tempgrid = grid[i][j];
            grids.push_back(tempgrid);
        }
    }//IT'S BREAKING AT THIS PART.

    /****************/
    //cout << "GOT HERE" << "\n";
    /***************/

    answer.erase(answer.begin(), answer.end());
    answer = findPermutations(citynumbers, numcities, grids);

    //if(answer[0] == -1)//WTF is happening here?
    if(answer.size() < numcities)
    {
        cout << "Path:" << "\n";
        cout << "Cost:-1";
    }
    else
    {
        
        cout << "Path:";
        for(int i=0; i < answer.size(); i++)
        {
            if(i == (answer.size()-1))
            {
                cout << cities[answer[i]];
            }
            else
            {
                cout << cities[answer[i]] << "->";
            }
        }
        cout << "\n" << "Cost:" << sumSaved;
    }

}
