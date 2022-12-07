#include<bits/stdc++.h>
using namespace std;
double calcEntropy(int y,int n)
{
    if(y==0||n==0)
    return 0;
    double s_entropy=-(y/(float)(y+n))*(log2(y/(float)(y+n)));
    s_entropy=s_entropy+(-(n/(float)(y+n))*(log2(n/(float)(y+n))));
    return s_entropy;
}
double calcgain(map<string,pair<int,int>>tmp,double s_entropy,int total)
{
 for(auto itr=tmp.begin();itr!=tmp.end();++itr)
 {
    double p_entropy=calcEntropy(itr->second.second,itr->second.first);
    double mul=(itr->second.second+itr->second.first);
    mul=mul/total;
    s_entropy-=((mul)*p_entropy);
 }
 return s_entropy;
}
double giniIndex(map<string,pair<int,int>>tmp,double s_entropy,int total)
{
    double gini=0.0;

    for(auto itr=tmp.begin();itr!=tmp.end();++itr)
 {
     double ans=1;
     int tot=itr->second.second+itr->second.first;
     ans-=pow(((float)itr->second.second/tot),2);
     ans-=pow(((float)itr->second.first/tot),2);
     gini+=(ans*((float)tot/total));

 }
 return gini;
}
int main()
{
    fstream fin("gini.csv",ios::in);
    vector<vector<string>> content;
    vector<string> row;
    map<string,pair<int,int>>outlook;
    map<string,pair<int,int>>temp;
    map<string,pair<int,int>>humidity;
    map<string,pair<int,int>>wind;
    string line, word;
    int cnty=0;
    int cntn=0;
    if(fin.is_open())
    {
        while(getline(fin,line))
        {
           // cout<<line<<endl;
            row.clear();
            stringstream s(line);
            while(getline(s,word,','))
            {
                    row.push_back(word);
            }
            content.push_back(row);
        }
    }
    for(int i=1;i<content.size();i++)
    {
        if(content[i][content[i].size()-1]=="No")
        {
            outlook[content[i][1]].first+=1;
            temp[content[i][2]].first+=1;
            humidity[content[i][3]].first+=1;
            wind[content[i][4]].first+=1;
            cntn++;
        }
        else
        {
            cnty++;
             outlook[content[i][1]].second+=1;
            temp[content[i][2]].second+=1;
            humidity[content[i][3]].second+=1;
            wind[content[i][4]].second+=1;
        }
    }

double s_entropy=calcEntropy(cnty,cntn);
cout<<"tot entropy: "<<s_entropy<<endl;
double infogain=calcgain(outlook,s_entropy,content.size()-1);
cout<<"InfoGain for outlook:--- "<<infogain<<endl;
 cout<<"InfoGain for temp:--- "<<infogain<<endl;
infogain=calcgain(humidity,s_entropy,content.size()-1);
 cout<<"InfoGain for humidity:---  "<<infogain<<endl;
 infogain=calcgain(wind,s_entropy,content.size()-1);
 cout<<"InfoGain for wind:--- "<<infogain<<endl;
 cout<<endl;
infogain=giniIndex(outlook,s_entropy,content.size()-1);
 cout<<"GiniIndex for outlook:--- "<<infogain<<endl;
 infogain=giniIndex(temp,s_entropy,content.size()-1);
 cout<<"GiniIndex for temp:--- "<<infogain<<endl;
infogain=giniIndex(humidity,s_entropy,content.size()-1);
 cout<<"GiniIndex for humidity:---  "<<infogain<<endl;
infogain=giniIndex(wind,s_entropy,content.size()-1);
 cout<<"GiniIndex for wind:--- "<<infogain<<endl;

}
