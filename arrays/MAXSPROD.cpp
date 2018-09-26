int Solution::maxSpecialProduct(vector<int> &A) {
    vector<int> lsp,rsp;
    stack<int> st;
    st.push(0);lsp.push_back(0);
    for(int i=1;i<A.size();++i)
    {
        while(!st.empty() && A[st.top()]<=A[i])
            st.pop();
        if(st.empty())
            lsp.push_back(0);
        else
            lsp.push_back(st.top());
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    st.push(A.size()-1);rsp.push_back(0);
    for(int i=A.size()-2;i>=0;--i)
    {
        while(!st.empty() && A[st.top()]<=A[i])
            st.pop();
        if(st.empty())
            rsp.push_back(0);
        else
            rsp.push_back(st.top());
        st.push(i);
    }
    reverse(rsp.begin(),rsp.end());
    long long int res = 0,curr;
    for(int i=0;i<A.size();++i)
    {
        curr = ((long long int)lsp[i])*((long long int)rsp[i]);
        if(curr>res)
            res = curr;
    }
    return res%1000000007;
}
