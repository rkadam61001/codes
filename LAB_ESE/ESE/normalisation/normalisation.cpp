#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int findmin(vector<double>minmaxarr,int n)
{
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(mini>minmaxarr[i])
        {
            mini=minmaxarr[i];
        }
    }
    return mini;
}
int findmax(vector<double>minmaxarr,int n)
{
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
          if(maxi<minmaxarr[i])
        {
            maxi=minmaxarr[i];
        }
    }
    return maxi;
}
void norm(vector<double>minmaxarr,int new_min,int new_max,int old_min,int old_max)
{
    int n=minmaxarr.size();
    vector<double>normalval(minmaxarr.size());
    for(int i=0;i<n;i++)
    {
        normalval[i]=(((minmaxarr[i]-old_min)/(old_max-old_min))*(new_max-new_min))+new_min;
    }
    for(int i=0;i<n;i++)
    {
        cout<<normalval[i]<<" ";
    }
}
int avg(vector<double>minmaxarr,int n)
{
    double average;
    int sum=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        sum+=minmaxarr[i];
        average=sum/n;
        if(minmaxarr[i]>average)
        {
            cnt++;
        }
    }
    cout<<"value above avg is"<<cnt;
    return average;
}
int main()
{
    ifstream ifile("sample.txt",std::ios::in);
    vector<double>minmaxarr;
    double num=0.0;
    if(!ifile.is_open())
    {
        std::cerr<<"Error in opening file";
        exit(1);
    }
    while(ifile>>num)
    {
        minmaxarr.push_back(num);
    }
    int new_min,new_max,old_min,old_max;
    cin>>new_min>>new_max;
    old_min=findmin(minmaxarr,minmaxarr.size());
    old_max=findmax(minmaxarr,minmaxarr.size());
    norm(minmaxarr,new_min,new_max,old_min,old_max);
   double  average=avg(minmaxarr,minmaxarr.size());
    cout<<"z score normaization";
    vector<double>dummy(minmaxarr.size());
    double sd=0.0;
    for(int i=0;i<minmaxarr.size();i++)
    {
        sd+=pow((minmaxarr[i]-average),2);
    }
    sd=sqrt(sd/minmaxarr.size());
    for(int i=0;i<minmaxarr.size();i++)
    {
        dummy[i]=(minmaxarr[i]-average)/sd;
    }
    for(int i=0;i<minmaxarr.size();i++)
    {
        cout<<dummy[i]<<" ";
    }
}
