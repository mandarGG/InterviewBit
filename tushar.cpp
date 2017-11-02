vector<int> Solution::solve(int A, vector<int> &B) {
    int n=B.size(),mymin=INT_MAX,minpos;
    unordered_map<int,int> my;
    for(int i=0;i<n;i++)
    {
        if(my.find(B[i])==my.end())
        {
            my[B[i]]=i;
        }
        if(mymin>B[i])
        {
            mymin=B[i];
            minpos=i;
        }
    }
    vector<int> final;
    int kicks=A/mymin,currmin=INT_MAX;
    int sum=kicks*mymin,index;
    vector<int> newS;
    for(int i=0;i<minpos;i++)
    {
        if(B[i]<currmin)
        {
            currmin=B[i];
            newS.push_back(B[i]);
        }
    }


    int count=0;
    for(int i=0;i<newS.size();i++)
    {
       while(sum-mymin+newS[i]<=A && count<kicks)
       {
           index=my[newS[i]];
           final.push_back(index);
           count++;
           sum=sum-mymin+newS[i];
       }
    }
    int num= kicks-final.size();
    if(final.size()<kicks)
    {

        for(int i=0;i<num;i++)
        {
            final.push_back(minpos);
        }
    }
    return final;
}
