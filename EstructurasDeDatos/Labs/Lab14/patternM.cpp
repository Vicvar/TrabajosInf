#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int bruteForcePM(string hs, string needle){
	for(int i=0; i<=hs.size()-needle.size(); i++){
		for(int j=0; j<needle.size(); j++){
			if(hs[i+j]!=needle[j]) 
				break;
			if(j==needle.size()-1)
				return i;
		}
	}
	return -1;
}

int knuthMorrisPrattPM(string hs, string needle){

}

int main(){

}