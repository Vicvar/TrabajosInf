#include "LinkedPRQT.cpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
	int nf, nc, f, c;
	int opt;
	if(argc!=3){
		cout<<"./prueba filas columnas"<<endl;
		return 0;
	}
	nf=atoi(argv[1]);
	nc=atoi(argv[2]);
	LinkedPRQT *prqt=new LinkedPRQT(nf,nc);


	do{
		cout<<"0.-Exit"<<endl;
		cout<<"1.-Add point"<<endl;
		cout<<"2.-Remove point"<<endl;
		cout<<"3.-Look for point"<<endl;
		cin>>opt;
		cout<<endl;
		switch(opt){
			case 0: break;
			case 1:{
				cout<<"Enter row:";
				cin>>f;
				cout<<"Enter column:";
				cin>>c;
				try{
					prqt->addPoint(f,c);
				}catch(const char* e){
					cout<<e<<endl;
				}
				break;
			}
			case 2:{
				cout<<"Enter row:";
				cin>>f;
				cout<<"Enter column:";
				cin>>c;
				try{
					prqt->remPoint(f,c);
				}catch(const char* e){
					cout<<e<<endl;
				}
				break;
			}
			case 3:{
				cout<<"Enter row:";
				cin>>f;
				cout<<"Enter column:";
				cin>>c;
				if(prqt->search(f,c)) cout<<"Point found"<<endl;
				else cout<<"Point not found"<<endl;
				break;
			}
		}
	}while(opt!=0);
}