#include <vector>
#include <iostream>
#include <string>;
std::vector<std::string>tokens(std::string pp){
    std::vector<std::string>aa;
    std::string a="";
    int l=pp.size();
    for(int i=0;i<l;++i){

        if(pp[i]>='A' && pp[i]<='Z' || pp[i]>='a' && pp[i]<='z'){
            a+=pp[i];
        }
        else if(a.size()>0){
            aa.push_back(a);
            a="";
        }
    }
    if(a.size()>0){
        aa.push_back(a);
    }
    return aa;
}
int timedReading(int maxLength, std::string text) {
    std::vector <std::string> tok=tokens(text);
    //return tok.size();
    std::cout<<tok.size()<<"\n";
    for(int i=0;i<tok.size();++i){
        std::cout<<tok[i]<<"\n";
    }
    int c=0;
    for(int i=0;i<tok.size();++i){
        if(tok[i].size()>maxLength){
            break;
        }
        c++;
    }
  return c;
}

int main(){
    std::cout<<timedReading(4,"The Fox asked the stork, 'How is the soup?'")<<"\n";
}
