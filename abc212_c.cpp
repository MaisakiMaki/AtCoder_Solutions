// NとMの要素数を持つ数列A,Bの中の要素から|Ai - Bi|が最小になるような組み合わせを考える問題

// [ 問題 ] 全探索で求めると、O(N * M)となり、要素数は 1 <= N,M <= 2 * 10^5であるため 4 * 10^10となり、TLEとなる。
// [ 解決 ] 最小の組み合わせはAiとAiの値に最も近いBiである。したがって、Bをソートし、Aiと値の最も近いものをBの中で二分探索を行い、Biを見つければ良い。
// [ 方法 ] A[0]の値から順に二分探索を行う。ここで、BiはAi以上の最小のインデックスの要素であり、
//         それは二分探索のleftを用いて示される。したがって、二分探索を行った後のkを最小値の更新に使う必要性がある。
//         また、C++のstdメソッドであるlower_bound()関数を用いることで、Ai以上の最小のidxのイテレータを取ってくることが可能であり、
//         そこからkの値を取ってくることが可能である。

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int alen, blen;

    cin >> alen >> blen;

    vector<int> A;
    vector<int> B;

    for (int i = 0; i < alen; i++)
    {
        int anum;
        cin >> anum;
        A.push_back(anum);
    }

    for (int i = 0; i < blen; i++)
    {
        int bnum;
        cin >> bnum;
        B.push_back(bnum);
    }

    sort(B.begin(), B.end());

    int left = 0;
    int right = B.size() - 1;

    int minNum = 1000000001;

    for (int i = 0; i < alen; i++)
    {
        //int target = A.at(i);

        int center = 0;
        left = 0;
        right = B.size() - 1;
        while (left <= right)
        {
            center = left + (right - left) / 2;
            // cout << center << endl;

            if (A.at(i) > B.at(center))
            {
                left = center + 1;
            }
            else
            {
                right = center - 1;
            }
        }
        // while文の部分は
        // auto it = lower_bound(B.begin(), B.end(), target);
        // int k = distance(B.begin(), it);
        // でも可能

        int k = left;

        if (k < blen)
        {
            int lmin = abs(A.at(i) - B.at(k));
            if (lmin < minNum)
            {
                minNum = lmin;
            }
        }
        if (k > 0)
        {
            int rmin = abs(A.at(i) - B.at(k - 1));
            if (rmin < minNum)
            {
                minNum = rmin;
            }
        }
    }
    cout << minNum << endl;
}