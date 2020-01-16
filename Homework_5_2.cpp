
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> cities;
vector<string> fcity;
vector<int> grids;
vector<int> citynumbers;
vector<string> answerCity;

queue<string> routes;
queue<int> solutions;

unordered_map<string, int> citymap;
//unordered_map<int, int> solutionMap;
vector<int> solutionMap;

int hops;
int hCount;

int vertices;
int edges;

string instring;
string start;
string ending;

int sum = 0;
int failCount = 0;

//queue for routes
//reorganize the city vector to have the right city at the front.
//

void bfsearch(vector<int> vec, int size, vector<int> VGRID, int hops)
{
    sum = 0;
    failCount = 0;

    vector<int> temp;
    temp.push_back(0);
    for(int i = 0; i < vec.size(); i++)
    {
        int temp2 = vec[i];
        temp.push_back(temp2);
    }

    for(int i=0; i<hops; i++)
    {
        int j = temp[i+1];
        int temp3 = temp[i];
        int t_pos = (size*temp3) + j; //[i][j]
        if(VGRID[t_pos] > 0)
        {
            sum += VGRID[t_pos];
        }
        else if(VGRID[t_pos] == -1)
        {
            failCount += VGRID[t_pos];
        }
    }

    if(sum == hops)
    {
        for(int i=0; i<=hops; i++)
        {
            solutions.push(temp[i]);
            //cout << "PUSHED: " << temp[i] << "\n";
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

vector<int> findPermutations(vector<int> v, int s, vector<int> GRID, int hops)
{
    int factorial = findFactorial(s);
    vector<int> solution;
    do{
        bfsearch(v, s, GRID, hops);
    }while(next_permutation(v.begin(),v.end()));

    while(!solutions.empty())
    {
        //solutionMap[solutions.front()] = 1;
        solutionMap.push_back(solutions.front());
        solutions.pop();
    }

    vector<int>::iterator ip;

    sort(solutionMap.begin(), solutionMap.end());

    ip = unique(solutionMap.begin(), solutionMap.begin() + (solutionMap.size()));

    solutionMap.resize(distance(solutionMap.begin(), ip));

    /*for(int i = 0; i< solutionMap.size(); i++)
    {
        cout << "solution map @ " << i << " " << solutionMap[i] << "\n";
    }*/

    return solutionMap;
}

int main()
{
    cin >> vertices;
    getline(cin, instring); //patch fix, ignore first newline character after numcity input

    for(int i=0; i<vertices; i++)
    {
        getline(cin, instring);
        cities.push_back(instring);
        //cout << "ADDED: " << cities[i] << "\n";
    }

    cin >> edges;
    //cout << "this many edges: " << edges << "\n";
    getline(cin, instring); //patch fix, ignore first newline character after numcity input

    //cout << "STARTING THE QUEUE \n";
    for(int i=0; i<edges; i++)
    {
        //getline(cin, start);
        cin >> start;
        //getline(cin, ending);
        cin >> ending;
        routes.push(start);
        //cout << " ADDED : " << routes.back() << "\n"; 
        routes.push(ending);
        //cout << " ADDED : " << routes.back() << "\n";
    }

    getline(cin, instring); //clear input buffer

    getline(cin, instring);
    fcity.push_back(instring);
    cin >> hops;

    for(int i=0; i<cities.size(); i++)
    {
        if(cities[i] != fcity[0])
        {
            string temp = cities[i];
            fcity.push_back(temp);
            if(i>0)
            {
                citynumbers.push_back(i);
            }
        }
    }

    //put final vector values into the map
    for(int i=0; i<fcity.size(); i++)
    {
        string temp = fcity[i];
        citymap[temp] = i;
    }

    int grid[vertices][vertices];

    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            grid[i][j] = -1;
        }
    }

    while(!routes.empty())
    {
        string t_start = routes.front();
        routes.pop();
        string t_end = routes.front();
        routes.pop();

        grid[citymap.at(t_start)][citymap.at(t_end)] = 1;
    }

    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            int tempgrid = grid[i][j];
            grids.push_back(tempgrid);
        }
    }

    vector<int> answer = findPermutations(citynumbers, vertices, grids, hops);

    for(int i=0; i<answer.size(); i++)
    {
        string temp = fcity[answer[i]];
        //cout << "TEMP --> " << temp << "\n";
        answerCity.push_back(temp); 
    }

    sort(answerCity.begin(), answerCity.end());

    for(int i=0; i<answerCity.size(); i++)
    {
        cout << answerCity[i] << "\n";
    }

    /*cout << "HERE IS THE DATA COLLECTED:" << "\n";

    cout << "===================================" << "\n";

    cout << "original vector of cities" << "\n";

    for(int i=0; i<cities.size(); i++)
    {
        cout << cities[i] << " --> ";
    }

    cout << "\n";

    cout << "===================================" << "\n";
    cout << "===================================" << "\n";

    cout << "queue of routes" << "\n";

    int IRS = routes.size();

    while(!routes.empty())
    {
        cout << routes.front() << ", ";
        routes.pop();
        cout << routes.front() << "--> ";
        routes.pop();
    }

    cout << "\n";
    cout << "===================================" << "\n";
    cout << "===================================" << "\n";

    cout << "new vector" << "\n";

    for(int i=0; i<fcity.size(); i++)
    {
        cout << fcity[i] << " --> ";
    }

    cout << "\n";
    cout << "===================================" << "\n";
    cout << "===================================" << "\n";
    */

}
