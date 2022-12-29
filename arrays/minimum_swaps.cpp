// https://practice.geeksforgeeks.org/problems/minimum-swaps/1
#include <bits/stdc++.h>
using namespace std;

static bool compSort(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}
int minSwaps(vector<int> &nums)
{
	// Code here
	vector<pair<int, int>> aux;
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		aux.push_back({nums[i], i});
	}

	sort(aux.begin(), aux.end(), compSort);

	vector<bool> isVisited(n, false);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int strt = aux[i].second;
		isVisited[i] = true;
		while (!isVisited[strt])
		{
			ans++;
			isVisited[strt] = true;
			strt = aux[strt].second;
		}
	}

	return ans;
}