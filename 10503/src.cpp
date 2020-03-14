#include <bits/stdc++.h>
using namespace std;
 
int tiles[16][2], np, ns, si, lp;
long placed;
 
bool solve(int lds) {
    if (si == ns) 
        for (int id = 1; id <= np + 1 ; ++id)
            if ((placed & (1 << id)) == 0) 
	    {
                int ld = tiles[np + 1][0];
                if ((lds == tiles[id][0] && tiles[id][1] == ld)||(lds == tiles[id][1]&&tiles[id][0] == ld))
                    return true;
            }
    for (int id = 1; id <= np + 1 ; ++id)
	    if ((placed & (1 << id)) == 0) 
	    {
		    placed |= (1 << id);
		    si++;
		    lp = id;
		    if ((lds == tiles[id][0]&& solve(tiles[id][1]))||(lds == tiles[id][1]&&solve(tiles[id][0])))
			    return true;
		    --si;
		    placed &= ~(1 << id);
	    }
    return false;
}
 
int main()
{
    while (cin >> ns && ns != 0) {
        cin >> np;
        cin >> tiles[0][0];
        cin >> tiles[0][1];
        cin >> tiles[np + 1][0];
        cin >> tiles[np + 1][1];
        for (int i = 1; i < np + 1; ++i)
            for (int j = 0; j < 2; ++j)
                cin >> tiles[i][j];
        placed = 1 | (1 << (np + 1));
        si = 1;
	bool found=solve(tiles[0][1]);
        if (found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
