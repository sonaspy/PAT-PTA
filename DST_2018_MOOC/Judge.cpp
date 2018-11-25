#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct UserNode {
	int total;
	int perfect;
	int *score;
}; 
UserNode *ranklist[10001];
 
bool cmp(int a, int b) {
	if (ranklist[a]->total > ranklist[b]->total)
		return true;
	else if (ranklist[a]->total == ranklist[b]->total) {
		if (ranklist[a]->perfect > ranklist[b]->perfect)
			return true;
		else if (ranklist[a]->perfect == ranklist[b]->perfect)
			if (a < b)return true;
	}
	return false;
}
 
int main() {
	int i, j, t, n, k, m, id, problem, score, flag, r, temp, s[5];
	vector<int> rlist;
	
	scanf("%d%d%d", &n, &k, &m);
	for (i = 0;i < k;i++)
		scanf("%d", &s[i]);
	for (i = 1;i <= n;i++)
		ranklist[i] = NULL;
	while (m--) {
		scanf("%d%d%d", &id, &problem, &score);
		if (!ranklist[id]) {
			ranklist[id] = new UserNode;
			ranklist[id]->score = new int[k];
			for (j = 0;j < k;j++)
				ranklist[id]->score[j] = -2;
			ranklist[id]->total = 0;
			ranklist[id]->perfect = 0;
		}
		if (ranklist[id]->score[problem - 1] < score) 	
			ranklist[id]->score[problem - 1] = score;
	}
	for (i = 1;i <= n;i++) {
		if (ranklist[i]) {
			flag = 0;
			for (j = 0;j < k;j++) {
				if (ranklist[i]->score[j] >= 0) {
					flag = 1;
					ranklist[i]->total += ranklist[i]->score[j];
				}	
				if (ranklist[i]->score[j] == s[j])
					ranklist[i]->perfect++;
			}
			if (flag) rlist.push_back(i);	
		}
	}
 
	sort(rlist.begin(), rlist.end(), cmp);
	temp = 1;
	for (i = 0;i < k;i++)
		temp += s[i];
	for (i = 0;i < rlist.size();i++) {
		t = rlist[i];
		if (ranklist[t]->total < temp) {
			r = i + 1;
			temp = ranklist[t]->total;
		}
		printf("%d %05d %d", r, t, ranklist[t]->total);
		for (j = 0;j < k;j++) {
			if (ranklist[t]->score[j] == -2)
				printf(" -");
			else if(ranklist[t]->score[j] == -1)
				printf(" 0");
			else
				printf(" %d", ranklist[t]->score[j]);
		}
		printf("\n");
		
	}
	return 0;
}