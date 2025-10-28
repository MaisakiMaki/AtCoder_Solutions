// 長さNの数列に含まれるA1 ~ ANにおいて、Mと互いに素である1 ~ Mまでの数字を出力する問題
// [ 問題 ] 互いに素である数字を見つけるために素因数分解をする必要があるが、愚直に素因数分解をすると間に合わない、また、互いに素を判定するときもそのまま計算すると計算量が多い。
// [ 解決 ] O(√2)の素数判定法とエラトステネスの篩の応用を使って計算量をNlog(logN)で回すようにする。

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> data;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        data.push_back(num);
    }

    vector<int> primeCnt(100001);
    for (int i = 0; i < data.size(); i++)
    {
        // O(√2)の素数判定法
        for (int k = 2; k * k <= M; k++)
        {
            if (data.at(i) % k == 0)
            {
                // 素因数分解をして禁止素数を炙り出す
                primeCnt.at(k)++;
                while (data.at(i) % k == 0)
                {
                    data.at(i) /= k;
                }
            }
        }
        if (data.at(i) > 1)
        {
            // 素因数分解で溢れた素因数を回収
            primeCnt.at(data.at(i))++;
        }
    }

    vector<bool> ans(M + 1);
    int cnt = M;

    for (int i = 1; i <= M; i++)
    {
        // エラトステネスの篩で最初に全てtrueにする
        ans.at(i) = true;
    }

    for (int i = 2; i <= M; i++)
    {
        // 禁止素数が使われているかどうかの確認
        if (primeCnt.at(i) != 0)
        {
            // cout << i << endl;
            ans.at(i) = false;
            cnt--;
            // 禁止素数の倍数をfalseにする
            for (int k = 2 * i; k <= M; k += i)
            {
                // 二重判定をしないようにする
                if (ans.at(k))
                {
                    ans.at(k) = false;
                    cnt--;
                }
            }
        }
    }

    cout << cnt << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans.at(i))
        {
            cout << i << endl;
        }
    }
}