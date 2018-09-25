/*
Given a collection of numbers, return all possible permutations.
*/
void permutations(vector<vector<int>> &res,vector<int> permut_set,vector<int> leftover,int size)
{
    if(size==0)
    {
        res.push_back(permut_set);return;
    }
    else
    {
        vector<int> temp,temp1;
        for(int i=0;i<leftover.size();++i)
        {
            temp = permut_set;
            temp.push_back(leftover[i]);
            temp1 = leftover;
            temp1.erase(temp1.begin()+i);
            permutations(res,temp,temp1,(size-1));
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> temp;
    permutations(res,temp,A,A.size());
    return res;
}
