#include<bits/stdc++.h>
using namespace std;

 int majorityElement(int a[], int n)
 {
        
        // your code here
        int first=a[0];
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(first == a[i])
             count++;
            else
             count--;
            
            if(count == 0)
            {
                first=a[i];
                count=1;
            }
        }
        count=0;
        for(int i=0;i<n;i++)
        {
            if(first == a[i])
             count++;
        }
        if(count > n/2)
         return first;
        else
         return -1;
}
vector <int> max_of_subarrays(vector<int>arr, int n, int k)
{
        // your code here
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        int i=0;
        for(i=0;i<k;i++)
        {
            pq.push({arr[i],i+1});
        }
        ans.push_back(pq.top().first);
        int x=1;
        
        for(i=k;i<n;i++)
        {
            pq.push({arr[i],i+1});
            while(pq.top().second - x <= 0)
            {
                pq.pop();
            }
            ans.push_back(pq.top().first);
            x++;
        }
        return ans;      
}
long long maxProduct(vector<int> arr, int n) 
{

	    long long ans=LONG_MIN;
	    long long prod=1;
	    for(int i=0;i<n;i++)
	    {
	        prod*=arr[i];
	        ans=max(ans,prod);
	        if(prod == 0)
	        {
	            prod=1;
	        }
	    }
	    prod=1;
	    for(int i=n-1;i>=0;i--)
	    {
	        prod*=arr[i];
	        ans=max(ans,prod);
	        if(prod == 0)
	        {
	            prod=1;
	        }
	    }
	    return ans;
	    // code here
}
 int kthSmallest(int arr[],int n, int k) 
 {
        //code here
        priority_queue<int>pq;
        
        for(int i=0;i<k;i++)
        {
            pq.push(arr[i]);
        }
        for(int i=k;i<n;i++)
        {
            if(arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
}

int kthlargest(int arr[],int n, int k) 
{
        //code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++)
        {
            pq.push(arr[i]);
        }
        for(int i=k;i<n;i++)
        {
            if(arr[i] > pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
}
bool find3Numbers(int a[], int n, int x)
{
        //Your Code Here
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            int low=i+1;
            int high=n-1;
            
            while(low < high)
            {
                int sum=a[i]+a[low]+a[high];
                if(sum == x)
                 return true;
                else if(sum > x)
                 high--;
                else
                 low++;
            }
        }
        return false;
}
void sort012(int a[], int n)
{
        // code here 
        int low=0,mid=0,high=n-1;
        
        while(mid <= high)
        {
            if(a[mid] == 0)
            {
                swap(a[low],a[mid]);
                low++;
                mid++;
            }
            else if(a[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(a[mid],a[high]);
                high--;
            }
        }
}
long long trappingWater(int arr[], int n)
{
        // code here
        
        vector<int>lmax(n);
        vector<int>rmax(n);
        lmax[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            lmax[i]=max(lmax[i-1],arr[i]);
        }
        rmax[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            rmax[i]=max(rmax[i+1],arr[i]);
        }
        long long sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=min(lmax[i],rmax[i])-arr[i];
        }
        return sum;
}

int countOfSubstrings(string s, int k) 
{
        // code here
	//Substrings of length k with k-1 distinct elements

        int n=s.size();
        map<char,int>mp;
        int count=0;
        
        for(int i=0;i<k;i++)
        {
            mp[s[i]]++;
        }
        int i=0;
        if(mp.size() == k-1)
         count++;
        
        for(int j=k;j<n;j++)
        {
            mp[s[j]]++;
            mp[s[i]]--;
        
            if(mp[s[i]] == 0)
             mp.erase(s[i]);
            
            if(mp.size() == k-1)
            {
                count++;
            }
            i++;
        }
        return count;
}
 int maxLenof0sum(vector<int>&A, int n)
 {
 	//Largest subarray with 0 sum
        unordered_map<int,int>mp;
        vector<int>prefix(n,0);   
        // Your code here
         prefix[0]=A[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+A[i];
        }
        int len=0;
        for(int i=0;i<n;i++)
        {
            if(prefix[i] == 0)
            {
                len=i+1;
            }
            if(mp.find(prefix[i]) != mp.end()) //sum[i,j]==0
                                               //prefix[j]-prefix[i-1] == 0
            {
                len=max(len,i-mp[prefix[i]]);
            }
            else
            {
                mp[prefix[i]]=i;
            }
        }
        return len;
}
int maxLenofksum(vector<int>&A, int n,int k)
 {
 	   //Largest subarray with k sum
        unordered_map<int,int>mp;
        vector<int>prefix(n,0);   
        // Your code here
         prefix[0]=A[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+A[i];
        }
        int len=0;
        for(int i=0;i<n;i++)
        {
            if(prefix[i] == 0)
            {
                len=i+1;
            }
            if(mp.find(prefix[i] - k) != mp.end()) //sum[i,j]==k
                                               //prefix[j]-k=prefix[i-1]
            {
                len=max(len,i-mp[prefix[i]]);
            }
            else
            {
                mp[prefix[i]]=i;
            }
        }
        return len;
}
 void combinationsum(int index,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds)
 {
       if(index == arr.size())
       {
           if(target == 0)
           {
               vector<int> temp = ds;
               sort(temp.begin(), temp.end());
               ans.push_back(temp);
           }
           return;
       }
       if(target >= arr[index])
       {
           ds.push_back(arr[index]);
           combinationsum(index,target-arr[index],arr,ans,ds);
           ds.pop_back();
       }
       combinationsum(index+1,target,arr,ans,ds);
}
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
        unordered_map<string, vector<string>> h;
        for(int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            h[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto m: h) 
            ans.push_back(m.second);
        return ans;
        
}
 int longestUniqueSubsttr(string s){
        //code
        unordered_map<char,int>mp;
        int n=s.size();
        int ans=0;
        int i=0,j=0;
        while(j < n)
        {
            mp[s[j]]++;
            while( i <= j && mp[s[j]] > 1)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                 mp.erase(s[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
}
class Solution {
  private:
  int countoffactors(int n)
  {
      int count=0;
      for(int i=1;i*i<=n;i++)
      {
          if(n % i == 0)
          {
              if(i == n/i)
                count++;
              else
                count=count+2;
          }
      }
      return count;
  }
  public:
    vector<int> primeRange(int M, int N) 
    {
        
        vector<int>ans;
        
        for(int i=M;i<=N;i++)
        {
            if(i == 1)
             continue;
            
            int var=countoffactors(i);
            if(var <= 2)
             ans.push_back(i);
        }
        return ans;
        
}
string longestCommonPrefix(vector<string>&ar) 
    {
        int n=ar.size();
        if (n == 0)
        return "";
   
  //If size is 1 then just return that character
    if (n == 1)
        return ar[0];
 
    // Sort the given array
    sort(ar.begin(),ar.end());
    for(int i=0;i<n;i++)
     cout<<ar[i]<<" ";
 
    // Find the minimum length from 
    // first and last string
    int en = min(ar[0].size(), 
                 ar[n - 1].size());
 
    // Now the common prefix in first and 
    // last string is the longest common prefix
    string first = ar[0], last = ar[n - 1];
    int i = 0;
    while (i < en && first[i] == last[i])
        i++;
 
    string pre = first.substr(0, i);
    return pre;
        
}

int main()
{

}