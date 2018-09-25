/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

*/
vector<vector<int> > comb(vector<vector<int> >  res,int st ,int A,int B)
{
    if(B==0)
        return res;
    vector<vector<int> >  new_res;
    long long int i=0;
    vector<int> temp,temp2;
    while(res.size()!=0)
    {
        temp2 = res[0];
        res.erase(res.begin());
        for(i=st;i<=A-B+1;i++)
        {
            temp = temp2;
            if(temp.back()<i)
            {
                temp.push_back(i);
                new_res.push_back(temp);
            }
        }
    }
    return comb(new_res,++st,A,--B);
}
vector<vector<int> > Solution::combine(int A, int B) {

    vector<vector<int>> res;
    for(int i=1;i<=A-B+1;i++)
    {
        vector<int> temp;
        temp.push_back(i);
        res.push_back(temp);
    }
    res = comb(res,2,A,--B);
    return res;
}
