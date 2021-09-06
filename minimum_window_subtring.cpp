#include<bits/stdc++.h>
using namespace std;
   string minWindow(string s, string t) {
        int c=0;
        unordered_map<char,int>m1,m2;
        if(t.length()>s.length())
            return "";

        for(int i=0;i<t.length();i++)
        {
            m2[t[i]]++;
        }
        int i=0,j=0,mx=INT_MAX,k=0,e;


        while(j<s.length())
        {
            if(c<t.length())
            {
                m1[s[j]]++;
                if(m2[s[j]]>=m1[s[j]])
                {
                    c++;
                }
                j++;
            }
            else
            {
                if(j-i<mx)
                {
                    k=i;
                    e=j;
                    mx=j-i;
                }
                while(i<j)
                {
                    m1[s[i]]--;
                    if(m1[s[i]]<m2[s[i]])
                    {
                        i++;
                        c--;
                        break;
                    }
                    i++;
                 if(j-i<mx)
                {
                    k=i;
                    e=j;
                    mx=j-i;
                }
                }
            }
        }


        while(c>=t.length())
        {
         if(j-i<mx)
                {
                    k=i;
                    e=j;
                    mx=j-i;
                }
             while(i<j)
                {
                    m1[s[i]]--;
                    if(m1[s[i]]<m2[s[i]])
                    {
                        i++;
                        c--;
                        break;
                    }
                    i++;
                 if(j-i<mx)
                {
                    k=i;
                    e=j;
                    mx=j-i;
                }
                }
        }
  cout<<mx<<' ';

           if(mx==INT_MAX)
           {
               return "";
           }

            return s.substr(k,mx);

    }
int main()
{
    string a="akgcebetaqbc",b="bac";
    cout<<minWindow(a,b);

}
