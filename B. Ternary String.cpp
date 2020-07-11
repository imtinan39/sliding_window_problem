#include<bits/stdc++.h>

using namespace std;

long long fr[10];

int sliding(long long a[],long long n,long long k)
{
    long long ans=2000000,cnt=0,right;
    memset(fr,0,sizeof(fr));

    for( right=1;right<=n;right++)
    {
        if(++fr[a[right]]==1)
        {
            cnt++;
        }
        if(cnt==k)
        {

            break;
        }
    }

    if(cnt<k)
    {
        return 0;
    }


    ans=right;

    for(long long left=2;left<=n;left++)
    {
        if(--fr[a[left-1]]==0)
        {
            cnt--;
        }
        while(right<n && cnt<k)
        {

            right++;
            if(++fr[a[right]]==1)
            {
                cnt++;
            }

            if(cnt==k)
            {
                break;
            }

        }

        if(cnt==k)
        {

            ans=min(ans,right-left+1);


        }


    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin>>t;
    while(t--)
    {


        string s;
        cin>>s;
        long long arr[s.size()+10];
        memset(arr,0,sizeof(arr));
        for(long long i=0;i<s.size();i++)
        {
            arr[i+1]=s[i]-'0';
        }


        cout<<sliding(arr,s.size(),3)<<endl;
    }

}
