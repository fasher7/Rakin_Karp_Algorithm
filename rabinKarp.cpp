#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int charSize = 256;
const int myPrime = 1279; 

void searching(string mT, string mP, int steps, int hT, int hP, int c, int cP, int pS, int t)
{
    if (hT == hP)
    {
        for (int z = 0; z < pS; ++z)   
        {
            if (mT[t + z] == mP[z])
            {
                ++c;
            }
            else
            {
                break;
            }
        }
        if (c == pS)
        {
            cout << "Similar Pattern at Index[" << t << "]" << endl;
        }
    }

    if (t == steps)
    {
        return;
    }

    c = 0;
    hT = (hT - int(mT[t]) * cP) * charSize + int(mT[t + pS]);
    hT = hT % myPrime;
    if (hT < 0)
    {
        hT = myPrime + hT;
    }

    searching(mT, mP, steps, hT, hP, c, cP, pS, ++t);
}

void rabinKarp(string myText, string myPattern)
{

    int hashT = 0;
    int hashP = 0;
    int charPower = 0;
    int tSize = myText.size();                
    int pSize = myPattern.size();

    charPower = pow(charSize, pSize - 1);    
    charPower = charPower % myPrime;
    for (int x = 0; x < pSize; ++x)
    {
        hashT = hashT + (int(myText[x]) * pow(charSize, pSize - 1 - x));
        hashP = hashP + (int(myPattern[x]) * pow(charSize, pSize - 1 - x));
    }
    hashT = hashT % myPrime;
    hashP = hashP % myPrime;

    int counter = 0;
    int travel = 0;
    int steps = tSize - pSize;        

    searching(myText, myPattern, steps, hashT, hashP, counter, charPower, pSize, travel);
}

int main()
{
    string myText;
    string toFind;

    getline(cin, myText);
    getline(cin, toFind);

    rabinKarp(myText, toFind);

    return 0;
}