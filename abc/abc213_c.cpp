// 行がH、列がWの範囲内で数字付きのカードの座標(R,C)がN個与えられ、数の書かれていない行と列を取り除いて上もしくは左に詰める時、最終的に数字付きのカードはどの座標にいるのかを求める。
// [ 問題 ] HとWの最大値が10^9であり、そのまま線形探索をすると計算量が10^18となってしまい、TLEとなる。
// [ 解決 ] 数字付きのカードの座標のみに注目する。入力値の座標は上から1 ~ Nまでの数字であるため、どの数字がどの座標にいるかはわかる。そのためpair構造体を使って、数字とその数字の行または列を配列として保存する。
//         そのあと、それぞれのpair配列を行と列でソートする。その時にidx0番の行または列が新たな行列の1つ目の行または列となる。
//.        そのため新たな配列NrとNcに保存し、それを元々位置していた数字でソートを行う。すると、元々保存されていた数値が1 ~ Nの順で並ぶため、そのまま順にcoutすれば良い。

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W, N;

    cin >> H >> W >> N;

    int R;
    int C;
    //その行/列にあった数字とその行と列の位置を保存する。
    vector<pair<int, int>> rnum;
    vector<pair<int, int>> cnum;

    for (int i = 0; i < N; i++)
    {
        cin >> R >> C;
        rnum.push_back(make_pair(R, i + 1));
        cnum.push_back(make_pair(C, i + 1));
    }
    //ソートすることで、一番小さな行と列の数値を探し出す。
    sort(rnum.begin(), rnum.end());
    sort(cnum.begin(), cnum.end());

    vector<pair<int, int>> Nr;
    vector<pair<int, int>> Nc;

    int curR = 0;
    int curC = 0;
    int preR = 0;
    int preC = 0;
    //ここでcntを宣言しないとバグる
    //カウンタを作成することで、重複した時も行と列の値が飛び飛びにならないようにする。
    int rcnt = 0;
    int ccnt = 0;

    for (int i = 0; i < N; i++)
    {

        curR = rnum.at(i).first;
        curC = cnum.at(i).first;
        //重複を考える。重複があった場合新たな行/列は作り出さないためカウントを動かさない。
        if (curR == preR)
        {
            Nr.push_back(make_pair(rnum.at(i).second, rcnt));
        }
        else
        {
            rcnt++;
            Nr.push_back(make_pair(rnum.at(i).second, rcnt));
        }
        if (curC == preC)
        {
            Nc.push_back(make_pair(cnum.at(i).second, ccnt));
        }
        else
        {
            ccnt++;
            Nc.push_back(make_pair(cnum.at(i).second, ccnt));
        }
        preR = curR;
        preC = curC;
    }
    // ソートをすることで元々配置されていた数字が1 ~ Nの順に出てくる。
    sort(Nr.begin(), Nr.end());
    sort(Nc.begin(), Nc.end());

    for (int i = 0; i < N; i++)
    {
        cout << Nr.at(i).second << " " << Nc.at(i).second << endl;
    }
}