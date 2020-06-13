#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <iomanip>

#define MAXWEIGHT 15
using namespace std;

        // -------------------------------------
        // |items:   1   2   3   4   5   6   7 |
        // -------------------------------------
        // |profit: 10  5  15   7   6   18  3  |
        // -------------------------------------
        // |weight: 2   3   5   7   1   4   1  |
        // -------------------------------------
        // max weight = 15
        // find weight set

void vecprint(string discr, vector<pair<int, int> > &weigh_profit )
{
    cout<<discr<<": \n";
     cout<<setw(weigh_profit.size()*4+11)<<setfill('=')<<'\n';
     cout<<setfill(' ');
    cout<<"weight: ";
    for(auto &e: weigh_profit)
        cout<<setw(4)<<e.first;
    cout<<endl;
    cout<<"profit: ";
    for(auto &e: weigh_profit)
        cout<<setw(4)<<e.second;

    cout<<'\n'<<setw(weigh_profit.size()*4+11)<<setfill('=')<<'\n';
    

}
void knapsack(vector<pair<int, int> > &weigh_profit ){

    //sort based on the ration between weight and profile
    sort(weigh_profit.begin(), weigh_profit.end(), [](auto &val1, auto &val2){
        float pw_ratio1 = val1.second/val1.first;
        float pw_ratio2 = val2.second/val2.first;
        return pw_ratio1 > pw_ratio2;
    });
    

    
    float acum_weight=0;
    float maxproft =0;
    for (vector<pair<int, int> >::iterator itr = weigh_profit.begin(); itr!= weigh_profit.end(); ++itr){ 
        if (acum_weight + (*itr).first <= MAXWEIGHT)
        {   
            cout<<(*itr).second<<" ";
            acum_weight +=(*itr).first;
            maxproft+=(*itr).second;
        }  
        else
        {
            float extra = ((*itr).first +acum_weight) - MAXWEIGHT;
            acum_weight+= (1-extra/(*itr).first) * (*itr).first;
            

            maxproft += (1-extra/(*itr).first) * (*itr).second;
            cout<< (1-extra/(*itr).first) * (*itr).second<<" ";

            
            break;
        }
        
            
          
    }

    vecprint("After algorithm (fraction allowed)", weigh_profit);
    cout<<"max weight="<<acum_weight<<" maxprofit="<<maxproft;
    cout<<endl;


};

int main(){ 
    
    // each pair contains weight as first value and profit second value
    vector<pair<int, int> > weight_prof{{2,10},{3,5},{5,15},{7,7},{1, 6},{4,18},{1,3}};
    
    vecprint("Initial list", weight_prof);
    knapsack(weight_prof);
    
    
}