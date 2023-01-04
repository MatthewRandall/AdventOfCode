#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int Part1();
int Part2();

int main(int argc, char *argv[])
{
    if(Part1())
    {
        return 1;
    }

    if(Part2())
    {
        return 2;
    }


}

int Part2()
{
    ifstream inputStream("./data/day01.txt", ifstream::in);
    if(!inputStream.is_open())
    {
        std::cerr << "Unable to open file './data/day01.txt'. Aborting!\n";
        return 1;
    }

    int nElfIndex = 1;
    int nCalorieEntry = 0;
    int nCalorieTotal = 0;
    int nHighestCalorieTotal[3]{0,0,0};
    char szEntry[32];
    while(!inputStream.eof())
    {
        inputStream.getline(szEntry, 32);
        if(strlen(szEntry))
        {
            nCalorieEntry = atoi(szEntry);
            nCalorieTotal += nCalorieEntry;
            continue;
        }

        if(nCalorieTotal > nHighestCalorieTotal[0]) 
        {
            nHighestCalorieTotal[2] = nHighestCalorieTotal[1];
            nHighestCalorieTotal[1] = nHighestCalorieTotal[0];
            nHighestCalorieTotal[0] = nCalorieTotal;
        }
        else if(nCalorieTotal > nHighestCalorieTotal[1])
        {
            nHighestCalorieTotal[2] = nHighestCalorieTotal[1];
            nHighestCalorieTotal[1] = nCalorieTotal;
        } 
        else if(nCalorieTotal > nHighestCalorieTotal[2])
        {
            nHighestCalorieTotal[2] = nCalorieTotal;
        } 

        nCalorieTotal = 0;
        nElfIndex++;
    }

    int nTopThreeCalorieTotal = 0;
    for(int i{0};i<3;i++)
    {
        nTopThreeCalorieTotal+=nHighestCalorieTotal[i];
    }
    
    cout << "The Top 3 Elves carry a combined total of " << nTopThreeCalorieTotal << " Caloories." << endl;
    inputStream.close();
    return 0;
}

int Part1()
{
    ifstream inputStream("./data/day01.txt", ifstream::in);
    if(!inputStream.is_open())
    {
        std::cerr << "Unable to open file './data/day01.txt'. Aborting!\n";
        return 1;
    }

    int nElfIndex = 1;
    int nCalorieEntry = 0;
    int nCalorieTotal = 0;
    int nHighestCalorieTotal = 0;
    int nElfWithHighestCalorieTotal = 0;
    char szEntry[32];
    while(!inputStream.eof())
    {
        inputStream.getline(szEntry, 32);
        if(strlen(szEntry))
        {
            nCalorieEntry = atoi(szEntry);
            nCalorieTotal += nCalorieEntry;
            continue;
        }

        if(nCalorieTotal > nHighestCalorieTotal) 
        {
            nHighestCalorieTotal = nCalorieTotal;
            nElfWithHighestCalorieTotal = nElfIndex;
        }
        nCalorieTotal = 0;
        nElfIndex++;
    }

    cout << "Elf " << nElfWithHighestCalorieTotal << " is carrying the most calories with a total of " << nHighestCalorieTotal << endl;
    inputStream.close();
    return 0;
}
