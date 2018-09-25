#include "MapB.h"


MapB::MapB(){
	_size=0;
	max_s=11;
	Array=(pair<string,int> *)malloc(11*sizeof(pair<string,int>));
}

MapB::~MapB(){
	delete Array;
}

bool MapB::empty(){
	if(_size==0) return true;
	else return false;
}

int MapB::size(){
	return _size;
}

void MapB::insert(pair<string,int> p){
	if(_size==max_s) rehash();
	int loc = hash(p.first);
	for(int i=loc ; i<(loc+max_s) ; i++){
		if(Array[i%max_s].first=="" || (Array[i%max_s].first!="" && Array[i%max_s].second==-1)){
			Array[i%max_s].first=p.first;
			Array[i%max_s].second=p.second;
			break;
		}
		cout<<"				collision"<<endl;
	}
	_size++;
}

int MapB::at(string k){
	int loc = hash(k);
	for(int i=loc ; i<(loc+max_s) ; i++){
		if(Array[i%max_s].first==k && Array[i%max_s].second==-1){
			return Array[i%max_s].second;
		}
		else if(Array[i%max_s].first=="" && Array[i%max_s].second==0){
			throw "key not found";
			break;
		}
	}
}

void MapB::erase(string k){
	int loc = hash(k);
	for(int i=loc ; i<(loc+max_s) ; i++){
		if(Array[i%max_s].first==k && Array[i%max_s].second!=-1){
			Array[i%max_s].second=-1;
			break;
		}
		else if(Array[i%max_s].first=="" && Array[i%max_s].second==0){
			throw "key not found";
			break;
		}
	}
	_size--;
}

int MapB::hash(string k){
	int res=0;
	for(int i=0;i<k.size();i++){
		res=res+(int)k[i];
	}
	res=res%max_s;
	return res;
}

void MapB::rehash(){
	pair<string,int> * aux;
	max_s=nextPrime(2*max_s);
	cout<<"    "<<max_s<<endl;
	aux=(pair<string,int> *)calloc(max_s,sizeof(pair<string,int>));
	int loc;

	for(int i=0;i<_size;i++){
		
		loc = hash(Array[i].first);

		for(int j=loc ; j<(loc+max_s) ; j++){
			
			if(aux[j%max_s].first=="" || (aux[j%max_s].first!="" && aux[j%max_s].second==-1)){
				aux[j%max_s].first=Array[i].first;
				aux[j%max_s].second=Array[i].second;
				break;
			}
		}
	}

	free(Array);
	Array=aux;
}

int MapB::nextPrime(int n){
	int nop=0;
	for(int i=n; ; i++){
		for (int j=2;j<=i/2;j++){
			if(i%j==0){
				nop=1;
				break;
			}
		}
		if(!nop){
			return i;
		}
		nop=0;
	}
}