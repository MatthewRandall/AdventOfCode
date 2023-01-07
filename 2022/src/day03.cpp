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

int fetchGroup(ifstream &_ifsInputStream, vector<string> &_vStrings)
{
    char szEntry[48];
    int nLongestLineLength=0;
    int nLongestLineIndex=0;
    try
    {
        for(int i = 0; i < 3; i++)
        {
            _ifsInputStream.getline(szEntry, 96);
            _vStrings[i] = string(szEntry);
            int nLength = strlen(szEntry);
            if( nLength > nLongestLineLength)
            {
                nLongestLineLength = nLength;
                nLongestLineIndex = i;
            }

        }

    }
    catch(const std::ifstream::failure e)
    {
        cerr << e.what() << '\n';
        return -1;
    }
    
    return nLongestLineIndex;
}

template<typename T>
bool isInVector(vector<T> &_vectorT, T _element)
{
    if(find(_vectorT.begin(), _vectorT.end(), _element) != _vectorT.end())
    {
        return true;
    }

    return false;
}

template<typename T>
vector<T> addToVector(vector<T> &_vectorT, T _elementToAdd)
{
    if(!isInVector(_vectorT, _elementToAdd))
    {
        _vectorT.push_back(_elementToAdd);
    }

    return _vectorT;
}

int Part2()
{
    ifstream inputStream("./data/day03.txt", ifstream::in);
    if(!inputStream.is_open())
    {
        cerr << "Unable to open file './data/day03.txt'. Aborting!\n";
        return 1;
    }

    vector<string> vEntries{"","",""};
    vector<char> vMatches;
    int nPrioritySum = 0;
    int nCount = 1;
    while(!inputStream.eof())
    {
        int nLongestEntryIndex = fetchGroup(inputStream, vEntries);
        int nScore = 0;
        for(int j{1}; j < 3; j++)
        {
            for(int i{0}; i <= vEntries[0].length(); i++)
            {
                if(vEntries[j].find(vEntries[0][i]) != string::npos)
                {
                    if(vEntries[0][i] == 0x0D || vEntries[0][i] == 0x0A)
                    {
                        break;
                    }

                    if(!isInVector(vMatches, vEntries[0][i]))
                    {
                        addToVector<char>(vMatches, vEntries[0][i]);
                    }

                }   

            }

            vEntries[0] = string(vMatches.data(), vMatches.size());
            if(vMatches.size() == 1)
            { 
                // found character
                if(vMatches[0] >= 0x61 && vMatches[0] <= 0x7A)
                {
                    // Lowercase
                    nScore = vMatches[0] - 0x60;
                }
                else if(vMatches[0] >= 0x41 && vMatches[0] <= 0x6A)
                {
                    // Uppercase
                    nScore = vMatches[0] - 0x26;
                }

                nPrioritySum += nScore;

            }

            vMatches.erase(vMatches.begin(), vMatches.end());
        }
    }

    cout << "[Day03-Part2] -> Sum of priorities is " << nPrioritySum <<  endl;
    inputStream.close();
    return 1;
}

int Part1()
{
    ifstream inputStream("./data/day03.txt", ifstream::in);
    if(!inputStream.is_open())
    {
        std::cerr << "Unable to open file './data/day03.txt'. Aborting!\n";
        return 1;
    }

    char szEntry[96];
    int nPrioritySum = 0;
    while(!inputStream.eof())
    {
        inputStream.getline(szEntry, 96);
        if(!strlen(szEntry)) { continue; }

        int nLength = strlen(szEntry);
        int leftLength = nLength / 2;
        int rightLength = nLength - leftLength;

        string sEntry(szEntry);
        string sLeft = sEntry.substr(0, leftLength);
        string sRight= sEntry.substr(leftLength, rightLength);

        for(int i=0; i < sLeft.length(); i++)
        {
            int nTempPriority = 0;
            if(sRight.find(sLeft[i]) != string::npos)
            {
                // found character
                if(sLeft[i] >= 0x61 && sLeft[i] <= 0x7A)
                {
                    // Lowercase
                    nTempPriority = sLeft[i] - 0x60;
                }
                else if(sLeft[i] >= 0x41 && sLeft[i] <= 0x6A)
                {
                    // Uppercase
                    nTempPriority = sLeft[i] - 0x26;
                }

                nPrioritySum += nTempPriority;
                break; 
            }

        }

    }
    
    cout << "[Day03-Part1] -> Sum of priorities is " << nPrioritySum <<  endl;
    inputStream.close();
    return 0;
}
