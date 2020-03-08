#include <iostream>
#include <vector>
using namespace std;

int main()
{  
    int k;
    while (cin >> k)
    {
       vector<pair<int, int> > ans;
        for (int i = k + 1; i <= 2 * k; ++i)
            if ((k * i) % (i - k) == 0)
                ans.push_back(make_pair((k * i) / (i - k), i));
        cout << ans.size() << endl;
        for (size_t i = 0; i < ans.size(); ++i)
            cout << "1/"<<k<<" = 1/"<<ans[i].first<<" + 1/"<<ans[i].second<< endl;    
    }
    return 0;
}
