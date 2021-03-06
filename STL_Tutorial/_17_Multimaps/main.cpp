#include <iostream> //use it for "cout"
#include <fstream> //use it read and open files
#include <sstream> //use it to write to and from strings
#include <string> //use it for "getline" function
#include <utility> //use it for std::pair 
#include <map>

using namespace std;

int main(){

    ifstream in("illiad.txt");
    multimap<string,pair<int,int>> wordPositions;
    int lineNumber=0, wordInLine=0;
    string line="";

    while(!in.eof()){
        lineNumber++;
        getline(in,line);
        istringstream iss(line); //get lines
        string word="";

        while(!iss.eof()){
            wordInLine++;
            iss>>word; //get words
            wordPositions.insert(make_pair(word,make_pair(lineNumber,wordInLine)));
        }
        wordInLine=0;
    }
    cout<<"read in "<<lineNumber<< " lines of text"<<endl;

    //Iterate on multimap
    for(auto it=wordPositions.cbegin(), it2=it; it!=wordPositions.cend(); it=it2){ 
    //cbegin, cend => c is used for const iterator
        unsigned int count=wordPositions.count(it->first);
        cout<<"\""<<it->first<< "\" occures " <<count<< " times, and is on: \n";

        for(; it2!=wordPositions.cend() && it2->first == it->first; ++it2){
            auto [line,word] = it2->second;
            cout<<"\tline "<<line <<", position " <<word << "\n";
        }
    }
    
    in.close();
    return 0;
}