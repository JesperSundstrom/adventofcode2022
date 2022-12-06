#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;


int resultingScore(int me, int opponent)
{
    map<pair<int,int>, int> rules{};
    // 1 = rock, 2 = bag/paper, 3 = scissors
    // make_pair(me,opponent)
    rules[make_pair(1,1)] = 3;
    rules[make_pair(1,2)] = 0;
    rules[make_pair(1,3)] = 6;

    rules[make_pair(2,1)] = 6;
    rules[make_pair(2,2)] = 3;
    rules[make_pair(2,3)] = 0;

    rules[make_pair(3,1)] = 0;
    rules[make_pair(3,2)] = 6;
    rules[make_pair(3,3)] = 3;
    return rules[make_pair(me,opponent)];
}

void changeMove(int* me, int opponent)
{
    map<pair<int,int>, int> newMove{};
    // 1 = rock, 2 = bag/paper, 3 = scissors
    // make_pair(me,opponent)
    // i need to lose
    newMove[make_pair(1,1)] = 3;
    newMove[make_pair(1,2)] = 1;
    newMove[make_pair(1,3)] = 2;
    // i need to make draw
    newMove[make_pair(2,1)] = 1;
    newMove[make_pair(2,2)] = 2;
    newMove[make_pair(2,3)] = 3;
    // i need to win
    newMove[make_pair(3,1)] = 2;
    newMove[make_pair(3,2)] = 3;
    newMove[make_pair(3,3)] = 1;
    *me = newMove[make_pair(*me,opponent)];
}

int main()
{   
    string line;
    ifstream file;
    file.open("in.txt");
    if ( file.is_open() )
    {
        int score{0};
        while ( getline(file, line) )
        {   
            int opponent{line.at(0) - 64}; // converts char to int
            int me{line.at(2) - 87};
            //changeMove(&me,opponent); // Uncomment this line to solve part 2
            score = score + me + resultingScore(me,opponent);
        }
        cout << "Score: " << score << endl;
    }
    file.close();
    return 0;
}

