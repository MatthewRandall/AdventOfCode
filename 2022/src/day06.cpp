#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstddef>
#include <deque>
#include <map>

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

vector<string> readDataPacketStream(ifstream &_inputStream, vector<string> &_vStrings)
{
    char szReadLine[4096];
    while(!_inputStream.eof())
    {
        try
        {
            _inputStream.getline(szReadLine, 4096);
            _vStrings.push_back(szReadLine);
        }
        catch(const ifstream::failure& e)
        {
            if((_inputStream.rdstate() & ifstream::eofbit) != 0)
                break;

            std::cerr << e.what() << '\n';
        }
        
    }

    return _vStrings;
}

bool isMarker(string _sSub)
{
    int nSubPos{0};
    bool bAllDifferent{true};
    for(int j{1}; j < _sSub.length(); j++)
    {
        string sSubSub = _sSub.substr(j, _sSub.length() - j);
        nSubPos = _sSub.find(_sSub[j - 1], j);
        if(nSubPos != string::npos)
        {
            bAllDifferent = false;
            break;;
        }

    }

    return bAllDifferent;
}

int findMarker(string _sStreamData, int _nMarkerSize = 4)
{
    bool bAllDifferent = true;
    size_t nSubPos;
    for(int i{0}; i < _sStreamData.length(); i++)
    {
        string sSub = _sStreamData.substr(i, _nMarkerSize);
        if(sSub.length() < _nMarkerSize)
        {
            cout << "End-Of-File" << endl;
            break;
        }

        bAllDifferent = isMarker(sSub);
        if(bAllDifferent)
        {
            return i + _nMarkerSize;
        }

        bAllDifferent = true;
    }

    return -1;
}

int Part2()
{
    ifstream inputStream("./data/day06.txt", ifstream::in);
    inputStream.exceptions( ifstream::failbit | ifstream::badbit );
    if(!inputStream.is_open())
    {
        std::cerr << "Unable to open file './data/day06.txt'. Aborting!\n";
        return 1;
    }

    vector<string> vStrings;
    readDataPacketStream(inputStream, vStrings);

    for(string s: vStrings)
    {
        cout << "Result: " << findMarker(s, 14) << endl;
    }

    return 1;
}

int Part1()
{
    ifstream inputStream("./data/day06.txt", ifstream::in);
    inputStream.exceptions( ifstream::failbit | ifstream::badbit );
    if(!inputStream.is_open())
    {
        std::cerr << "Unable to open file './data/day06.txt'. Aborting!\n";
        return 1;
    }

    vector<string> vStrings;
    readDataPacketStream(inputStream, vStrings);

    for(string s: vStrings)
    {
        cout << "Result: " << findMarker(s) << endl;
    }

    return 0;
}
