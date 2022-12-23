#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int priority(int prio)
{
    if (prio <= 96){ // A-Z
        prio = prio - 38;
    }
    else // a-z
    { 
        prio = prio - 96; 
    }
    return prio;
}

int part_one(vector<string> const& rows)
{        
    int sum{0};
    for (auto line = rows.begin(); line != rows.end(); ++line)
    { 
        string pack1{line->begin(), line->end() - line->size()/2};
        string pack2{line->end() - line->size()/2, line->end()};
        string intersection{};

        sort(pack1.begin(), pack1.end());
        sort(pack2.begin(), pack2.end());

        set_intersection(pack1.begin(), pack1.end(),
                        pack2.begin(), pack2.end(),
                        std::back_inserter(intersection));

        sum = sum + priority((int)intersection.at(0));
    }
    return sum;
}


int part_two(vector<string> const& rows)
{        
    int sum{0};
    for (int i{0}; i < (int)(rows.size()); i+=3)
    { 
        string intersection0{};
        string intersection{};

        string pack1{rows[i]};
        string pack2{rows[i+1]};
        string pack3{rows[i+2]};

        sort(pack1.begin(), pack1.end());
        sort(pack2.begin(), pack2.end());
        sort(pack3.begin(), pack3.end());
        
        set_intersection(pack1.begin(), pack1.end(),
                        pack2.begin(), pack2.end(),
                        std::back_inserter(intersection0));


        set_intersection(intersection0.begin(), intersection0.end(),
                        pack3.begin(), pack3.end(),
                        std::back_inserter(intersection));

        sum = sum + priority( (int)intersection.at(0) );
    }
    return sum;
}

int main()
{   
    string line;
    ifstream file;
    file.open("in.txt");
    if ( file.is_open() )
    {
        vector<string> rows{ istream_iterator<string>(file), istream_iterator<string>() };
        cout << endl << "Part one: " << endl;
        cout << part_one(rows) << endl;
        cout << endl << "Part two: " << endl;
        cout << part_two(rows) << endl;
    }
    file.close();
    return 0;
}

