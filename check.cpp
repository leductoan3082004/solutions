#include <bits/stdc++.h>
using namespace std;
/// write the name of problems here
const string NAME = "codeforces";
const int NTEST = 300;
long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        /// code your input here

        inp<<10<<'\n';
        for(int i=1;i<=10;++i) inp<<Rand(1,1000)<<' ';

        /// code your input here
        inp.close();
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());

          if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
