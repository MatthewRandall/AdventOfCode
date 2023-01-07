#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

int Part1();
int Part2();

int main(int argc, char *argv[])
{
    if(Part1())
    {
        return 1;
    }

    cout << "--------------------------" << endl;

    if(Part2())
    {
        return 2;
    }

    return 0;
}

vector<string> split(const string &_sString, char _cDelimiter)
{
    stringstream ss(_sString);
    vector<string> vResult;
    string sLeft;
    while(getline(ss, sLeft, _cDelimiter))
    {
        vResult.push_back(sLeft);
    }

    return vResult;
}

int CountOverlappedTasks(pair<int, int> &_pLeftPair, pair<int, int> &_pRightPair)
{
    int nTotalOverlaps = 0;
    bool bExit = false;
    for(int i = _pRightPair.first; i <= _pRightPair.second; i++)
    {
        for(int j = _pLeftPair.first; j <= _pLeftPair.second; j++)
        {
            if(j == i)
            {
                nTotalOverlaps++;
                bExit = true;
                break;
            }

        }

        if(bExit)
        {
            break;
        }

    }

    return nTotalOverlaps;
}

int Part2()
{
    ifstream inputStream("./data/day04.txt", ifstream::in);
    if(!inputStream.is_open())
    {
        std::cerr << "Unable to open file './data/day04.txt'. Aborting!\n";
        return 1;
    }

    char szEntry[32];
    int nLineCount = 0;
    int nTotalOverlaps = 0;
    while(!inputStream.eof())
    {
        inputStream.getline(szEntry, 32);
        int nLength = strlen(szEntry);
        if(!nLength) { continue; }

        string sEntry(szEntry);
        vector<string> vGroup = split(sEntry, ',');
        vector<string> vLeftSet = split(vGroup[0], '-');
        pair<int, int> pLeftPair(atoi(vLeftSet[0].c_str()), atoi(vLeftSet[1].c_str()));
        vector<string> vRightSet= split(vGroup[1], '-');
        pair<int, int> pRightPair(atoi(vRightSet[0].c_str()), atoi(vRightSet[1].c_str()));
        nLineCount++;
        bool bExit = false;
        if((pLeftPair.second - pLeftPair.first) < (pRightPair.second - pRightPair.first))
        {
            nTotalOverlaps += CountOverlappedTasks(pLeftPair, pRightPair);
        }
        else
        {
            nTotalOverlaps += CountOverlappedTasks(pRightPair, pLeftPair);
        }

    }

    cout << "[Day04-Part2] -> Total of complete and partial overlapping assignments is " << nTotalOverlaps <<  endl;
    inputStream.close();
    return 0;
}

int Part1()
{
    ifstream inputStream("./data/day04.txt", ifstream::in);
    if(!inputStream.is_open())
    {
        std::cerr << "Unable to open file './data/day04.txt'. Aborting!\n";
        return 1;
    }

    char szEntry[32];
    int nLineCount = 0;
    int nTotalOverlaps = 0;
    while(!inputStream.eof())
    {
        inputStream.getline(szEntry, 32);
        int nLength = strlen(szEntry);
        if(!nLength) { continue; }

        string sEntry(szEntry);
        vector<string> vGroup = split(sEntry, ',');
        vector<string> vLeftSet = split(vGroup[0], '-');
        pair<int, int> pLeftPair(atoi(vLeftSet[0].c_str()), atoi(vLeftSet[1].c_str()));
        vector<string> vRightSet= split(vGroup[1], '-');
        pair<int, int> pRightPair(atoi(vRightSet[0].c_str()), atoi(vRightSet[1].c_str()));
        nLineCount++;
        if((pLeftPair.second - pLeftPair.first) < (pRightPair.second - pRightPair.first))
        {
            if(pLeftPair.first >= pRightPair.first && pLeftPair.second <= pRightPair.second)
            {
                nTotalOverlaps++;
            }

        }
        else
        {
            if(pRightPair.first >= pLeftPair.first && pRightPair.second <= pLeftPair.second)
            {
                nTotalOverlaps++;
            }

        }

    }

    cout << "[Day04-Part1] -> Total of completely overlapping assignments is " << nTotalOverlaps <<  endl;
    inputStream.close();
    return 0;
}
