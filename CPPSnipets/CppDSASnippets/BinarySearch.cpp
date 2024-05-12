#include<bits/stdc++.h>
using namespace std;

int firstoccurance(int arr[],int x,int n)
{
        int low=0,high=n-1;
        int ans=-1;
        while(low <= high)
        {
            int mid=(low+high)/2;
            
            if(arr[mid] == x)
            {
                ans=mid;
                high=mid-1;
            }
            else if(x < arr[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
}
int lastoccurance(int arr[],int x,int n)
{
        int low=0,high=n-1;
        int ans=-1;
        
        while(low <= high)
        {
            int mid=(low+high)/2;
            if(arr[mid] == x)
            {
                ans=mid;
                low=mid+1;
            }
            else if(x > arr[mid])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
        // vector<int>ans;
        // int res1=firstoccurance(arr,x,n);
        // if(res1 == -1)
        // {
        //     ans.push_back(-1);
        //     ans.push_back(-1);
        //     return ans;
        // }
        // int res2=lastoccurance(arr,x,n);
        // ans.push_back(res1);
        // ans.push_back(res2);
        // return ans;
}
class Solution
{
long long count_banana(vector<int> &v,int num)
{
    long long sum=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=ceil(v[i]/(double)num);
    }
    return sum;
}
int minEatingSpeed(vector<int>& piles, int h) 
{
       int low=1;
       int high=*max_element(piles.begin(),piles.end());
       while(low<=high)
       {
           int mid=low +(high-low)/2;
           if(count_banana(piles,mid)<=h)
           {
               high=mid-1;
           }
           else{
               low=mid+1;
           }
       } 
       return low;
}
};
class Solution {
public:
    int minDays(vector<int>& bloomday, int m, int k) 
    {
        int low=*min_element(bloomday.begin(),bloomday.end());
        int high=*max_element(bloomday.begin(),bloomday.end());
        long long val=m * 1LL * k * 1LL;
        if(val > bloomday.size())
        {
            return -1;
        }
       while(low<=high)
       {
           int mid=low+(high-low)/2;
           if(possible(bloomday,mid,m,k))
           {
               high=mid-1;
           }
           else
           {
               low=mid+1;
           }
       }
       return low;   
    }
    bool possible(vector<int>&bloomday,int mid,int m,int k)
    {
        int count=0;
        int tot=0;
        for(int i=0;i<bloomday.size();i++)
        {
            if(bloomday[i]<=mid)
            {
                count++;
            }
            else
            {
                tot+=(count/k);
                count=0;
            }
        }
        tot+=(count/k);
        return tot>=m;
    }
};
class Solution {
public:
    bool isPossible(vector<int>& weights,int capacity,int days){
        int currWeight=0,NoOfDaysRequired=1;
        for(int i=0;i<weights.size();i++){
            if(currWeight+weights[i]<=capacity){
                currWeight+=weights[i];
            }
            else if(weights[i]<=capacity){
                NoOfDaysRequired++;
                currWeight=weights[i];
            }
            else{
                return false;
            }
        }
        return NoOfDaysRequired<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=accumulate(weights.begin(),weights.end(),0);
        int s=0,e=sum;
        int minimumNoOfDays=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(weights,mid,days)){
                minimumNoOfDays=min(minimumNoOfDays,mid);
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return minimumNoOfDays;
    }
};
class Solution
{
bool isPossible(vector<int> &stalls, int minDist, int k)
{
    int cows=1;               // we already place it at the first available slot i.e stalls[0]  ( GREEDY )
    int lastCowPosition=stalls[0];
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-lastCowPosition>=minDist)
        {
            cows++;
            lastCowPosition=stalls[i];
            if(cows>=k) return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=1,high=stalls[n-1]-stalls[0];              // just take low=0 and high = 1000000 any large number if this seems tricky
    int res;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(isPossible(stalls,mid,k))
        {
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return res;
}
};
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        //int res;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int ans=check(nums,mid);
            if(ans <= threshold)
            {
                //res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;  
    }
    long long check(vector<int>&nums,int mid)
    {
        long long tot=0;
        for(int i=0;i<nums.size();i++)
        {
            tot+=ceil((double)nums[i]/(double)mid);
        }
        return tot;
    }
};

class Solution {
  public:
    int search(vector<int>&A, int key) 
    {
      //search in rotated sorted array1.without diplicates
        int low=0;
        int high=n-1;
        
        while( low <= high)
        {
            int mid=low+(high-low)/2;
            
            if(A[mid] == key)
             return mid;
            
            else if(A[low] <= A[mid])
            {
                if(key >= A[low] && key <= A[mid])
                 high=mid-1;
                else
                 low=mid+1;
            }
            else
            {
                if(key >= A[mid] && key <= A[high])
                 low=mid+1;
                else
                 high=mid-1;
            }
        }
        return -1;
    }
};
class Solution {
  public:
    bool Search(int N, vector<int>& A, int key) 
    {
        // Search in rotated sorted array with duplicates
        
        int n=A.size();
        int low=0,high=n-1;
        
        while(low <= high)
        {
            int mid=low+(high-low)/2;
            
            if(A[mid] == key)
             return 1;
            
            if(A[low] == A[mid] && A[mid] == A[high])
            {
                low++;
                high--;
            }
            else if(A[low] <= A[mid])
            {
                if(key >= A[low] && key <= A[mid])
                 high=mid-1;
                else
                 low=mid+1;
            }
            else
            {
                if(key >= A[mid] && key <= A[high])
                 low=mid+1;
                else
                 high=mid-1;
            }
        }
        return 0;
    }
};


int main()
{

}
