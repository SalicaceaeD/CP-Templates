/**
 * \author : Nguyen Duc Kien
 * \date : ./12/2020
 * \version : 6.3
 */

///Task name

/**--------------------------------------------------**/

#include <bits/stdc++.h>
#include <windows.h>
#include <direct.h>
#include <dirent.h>
#include <iostream>

using namespace std;

const int qty = 1000;
const string TASK = "SUM";
const int __mod = 1e9 + 7;

string a_exe_file, o_exe_file, inp_file, out_file, ans_file;
ifstream fio, fia;
ofstream fo;
vector <string> ores;
vector <string> ares;

namespace functions
{

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 rs(seed);

    int random(int x)
    {
        long long u = rand() % __mod;
        long long v = rand() % __mod;
        long long k = rand() % __mod;
        return ((u*v+k) % x + 1);
    }

    int random(int l, int r)
    {
        int x = random(r - l + 1);
        return l - 1 + x;
    }

    long long random(long long x)
    {
        int u = random(1000000000);
        int v = random(1000000000);
        int k = random(1000000000);
        return ((1ll*u*v+k)%x)+1;
    }

    long long random(long long l, long long r)
    {
        long long x = random(r - l + 1);
        return l - 1 + x;
    }

    vector <pair <int, int> > random_tree(int node_qty)
    {
        vector <pair <int, int> > e;
        e.clear();
        for (int i = 2; i <= node_qty; i ++)
        {
            int j = random(i - 1);
            e.push_back({i, j});
        }
        return e;
    }


    vector <pair <int, int> > random_graph(int node_qty, int edge_qty)
    {
        vector <pair <int, int> > g = random_tree(node_qty);
        edge_qty -= node_qty - 1;
        if(node_qty <= 4000)
        {
            vector<vector<int>> m(node_qty + 1,vector<int>(node_qty + 1));
            vector<pair<int,int>> q;
            for(auto e : g) m[e.first][e.second] = m[e.second][e.first] = 1;
            for(int i = 1;i <= node_qty;i++)
                for(int j = i + 1;j <= node_qty;j++) if(!m[i][j]) q.push_back({i,j});
            shuffle(q.begin(),q.end(),rs);
            for(int i = 0;i < edge_qty;i++)
            {
                int type = random(0,1);
                if(type)g.push_back({q[i].first,q[i].second});
                else g.push_back({q[i].second,q[i].first});
            }
        }
        else
        {
            map<pair<int,int>,bool> m;
            for(auto e : g) m[e] = m[{e.second,e.first}] = 1;
            for(int i = 0;i < edge_qty;i++)
            {
                int u = random(1,node_qty);
                int v = random(1,node_qty);
                while(u == v || m[{u,v}]) v = random(1,node_qty),u = random(1,node_qty);
                m[{u,v}] = m[{v,u}] = 1;
                g.push_back({u,v});
            }
        }
        return g;
    }


}
using namespace functions;

void MakeFileName()
{
    a_exe_file = "bf.exe";
    o_exe_file = TASK + ".exe";
    inp_file = TASK + ".INP";
    out_file = TASK + ".OUT";
    ans_file = TASK + ".ANS";
}

void CheckCompare()
{
    fio.open(ans_file);
    fia.open(out_file);
    string str;
    ores.clear(); ares.clear();
    while (fio >> str) ores.push_back(str);
    while (fia >> str) ares.push_back(str);
    //cerr << ores.size() << " " << ares.size() << "\n";
    if (ores.size() != ares.size()){
        cout << "OUTPUT IS TOO SHORT/LONG\n";
        exit(0);
    }
    for (int i = 0; i < (int)ores.size(); ++ i)
        if (ores[i] != ares[i]){
            cout << "WRONG ANSWER\nLine: " << i + 1 << "\n";
            cout << "ANS: " << ares[i] << "\n";
            cout << "OUT: " << ores[i] << "\n";
            exit(0);
        }
    fio.close();
    fia.close();

    cout << "ACCEPTED\n";
    cerr << "\n-----------------\n\n";
}

void make_inp()
{
    fo.open(inp_file);

    int a = random(150);
    fo << a << "\n";

    fo.close();
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	cerr << "Processing...\n\n";

	cout << "Making test...\n";
	srand((int)time(0));
	MakeFileName();
	for (int i = 1; i <= qty; i ++)
    {
        cout << "NUMBER OF TEST: " << i << "\n";
        DeleteFile(&inp_file[0]);
        DeleteFile(&out_file[0]);
        DeleteFile(&ans_file[0]);
        DeleteFile("check_code.depend");
        DeleteFile("check_code.layout");
        make_inp();

        int exitcode = system(&a_exe_file[0]);
        bool broken = 0;
        if (exitcode != 0) {cout << "The BF program was terminated with exitcode " << exitcode << "\n"; broken = 1;}
        else cout << "Test made!\n\n";
        cout << "Checking...\n";
        if (broken) return 69;
        string RenameCommand = "rename " + out_file + " " + ans_file;
        Sleep(200);
        exitcode = system(&RenameCommand[0]);
        if (exitcode){
            cout << "RTE !!! !!!";
            return 0;
        }
        cout << "Verdict : \n";
        exitcode = system(&o_exe_file[0]);
        broken = 0;
        if (exitcode != 0) {cout << "RUNTIME_ERROR\nExitcode is " << exitcode << "\n\n"; broken = 1;}
        if (broken) return 69;
        CheckCompare();
    }

	cerr << "\n\n--------------\n";
	return 0;
}
