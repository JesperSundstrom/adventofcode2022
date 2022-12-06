#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{   
    string line;
    ifstream file;
    file.open ("day1.txt");
    if ( file.is_open() )
    {
        int elf_idx{0};
        int highest_cal{0};
        int highest_idx{0};
        int calories{0};
        while ( getline(file, line) )
        {
            try
            {
                calories = calories + stoi(line);   
            }
            catch (std::invalid_argument& e)
            {
                elf_idx = elf_idx + 1;
                if (calories > highest_cal)
                {
                    highest_idx = elf_idx;
                    highest_cal = calories;
                }
                calories = 0;
            }
        }
        cout << "calories: " << highest_cal << " elf: " << highest_idx << endl; 
    }
    return 0;
}