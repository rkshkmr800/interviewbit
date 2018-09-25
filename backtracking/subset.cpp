/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.

*/
vector<vector<int>> subset(vector<vector<int> > temp,vector<int> &A,int i,int j)
{
    if(i==j) return temp;
    vector<vector<int>> res;
    vector<int> p;
    for(int k=0;k<temp.size();k++)
    {
        p = temp[k];
        res.push_back(p);
        p.push_back(A[i]);
        res.push_back(p);
    }
    return subset(res,A,++i,j);
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> res,temp;
    vector<int> temp1;
    temp.push_back(temp1);
    sort(A.begin(),A.end());
    if(A.size()==0) return temp;
    temp1.push_back(A[0]);
    temp.push_back(temp1);
    res = subset(temp,A,1,A.size());
    sort(res.begin(),res.end());
    return res;
}
