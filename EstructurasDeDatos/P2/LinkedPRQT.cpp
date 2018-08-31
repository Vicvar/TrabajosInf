#include "LinkedPRQT.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>
using namespace std;

LinkedPRQT::LinkedPRQT(char * filename){
	ifstream inf;
	inf.open(filename,ifstream::in);
	root=new Node;

	root->state=0;

	root->prev_cuad=NULL;
	root->tl[0]=0;
	root->tl[1]=0;
	int x,y,n;
	inf>>x;
	root->br[0]=x-1;
	inf>>y;
	root->br[1]=y-1;
	inf>>n;
	for(int i=0;i<n;i++){
		inf>>x>>y;
		try{
			addPoint(x,y);
		}
		catch(char const* e){
		}
	}
}
LinkedPRQT::LinkedPRQT(int x, int y){
	root=new Node;
	root->prev_cuad=NULL;
	root->tl[0]=0;
	root->tl[1]=0;
	root->br[0]=x-1;
	root->br[1]=y-1;
}

LinkedPRQT::~LinkedPRQT(){
	destroyNode(root); 
}

void LinkedPRQT::addPoint(int x, int y){
	if(x<0||y<0||x>root->br[0]||y>root->br[1]){
		throw "Out of bounds!";
	}
	asPointLoc(x,y,root);
}

void LinkedPRQT::remPoint(int x, int y){
	Node *current=root;
	bool listo=false;
	while(!listo){
		switch(current->state){
			case 0:{
				throw "Point to remove not found!";
				listo=true;
				break;
			}
			case 1:{
				if(x==current->point[0] && y==current->point[1]){
					current->state=0;
					if(current->prev_cuad!=NULL) collapse(current->prev_cuad);
				}
				else{
					throw "Point to remove not found!";
				}
				listo=true;
				break;
			}
			case 2:{
				int cuad=belongsTo(x,y,current->tl,current->br);
				switch(cuad){
					case 0:{
						current=current->NW;
						break;
					}
					case 1:{
						current=current->SW;
						break;
					}
					case 2:{
						current=current->SE;
						break;
					}
					case 3:{
						current=current->NE;
						break;
					}
				}
				break;
			}
		}
	}
}

bool LinkedPRQT::search(int x, int y){
	Node *current=root;
	while(1){
		switch(current->state){
			case 0:{
				return false;
				break;
			}
			case 1:{
				if(x==current->point[0] && y==current->point[1]) return true;
				else return false;
				break;
			}
			case 2:{
				int cuad=belongsTo(x,y,current->tl,current->br);
				switch(cuad){
					case 0:{
						current=current->NW;
						break;
					}
					case 1:{
						current=current->SW;
						break;
					}
					case 2:{
						current=current->SE;
						break;
					}
					case 3:{
						current=current->NE;
						break;
					}
				}

			}
		}
	}
}

void LinkedPRQT::closest(int x,int y){
	double dist=(root->br[0]+root->br[1])*2, d;
	pdm[0]=-1;
	pdm[1]=-1;
	if(root->state==0)cout<<"No points"<<endl;
	else{
		d=minDist(root,dist,x,y);
		cout<<"Closest point: "<<"("<<pdm[0]<<","<<pdm[1]<<") at "<<d<<" from ("<<x<<","<<y<<")"<<endl;
	}
}

//****************************************************private

int *LinkedPRQT::childCount(Node *n){
	static int cc[3];
	int childc, pointc;
	if(n->NW->state!=0) childc++;
	if(n->SW->state!=0) childc++;
	if(n->SE->state!=0) childc++;
	if(n->NE->state!=0) childc++;
	
	if(n->NW->state==1){
		pointc++;
		cc[1]=n->NW->point[0];
		cc[2]=n->NW->point[1];
	}
	if(n->SW->state==1){
		pointc++;
		cc[1]=n->SW->point[0];
		cc[2]=n->SW->point[1];
	}
	if(n->SE->state==1){
		pointc++;
		cc[1]=n->SE->point[0];
		cc[2]=n->SE->point[1];
	}
	if(n->NE->state==1){
		pointc++;
		cc[1]=n->NE->point[0];
		cc[2]=n->NE->point[1];
	}

	if(childc==0){
		cc[0]=0;
	}
	else if(cc[0]==1 && pointc==1){
		cc[0]=1;
	}
	else cc[0]=-1;

	return cc;
}

void LinkedPRQT::subdivide(Node *n){

	n->NW=new Node;
	n->NW->prev_cuad=n;
	n->NW->tl[0]=n->tl[0];
	n->NW->tl[1]=n->tl[1];
	n->NW->br[0]=n->tl[0]+(n->br[0]-n->tl[0])/2;
	n->NW->br[1]=n->tl[1]+(n->br[1]-n->tl[1])/2;
	n->NW->state=0;

	n->SW=new Node;
	n->SW->prev_cuad=n;
	n->SW->tl[0]=n->br[0]-((n->br[0]-n->tl[0])/2);
	n->SW->tl[1]=n->tl[1];
	n->SW->br[0]=n->br[0];
	n->SW->br[1]=n->tl[1]+(n->br[1]-n->tl[1])/2;
	n->SW->state=0;

	n->NE=new Node;
	n->NE->prev_cuad=n;
	n->NE->tl[0]=n->tl[0];
	n->NE->tl[1]=n->br[1]-((n->br[1]-n->tl[1])/2);
	n->NE->br[0]=n->tl[0]+(n->br[0]-n->tl[0])/2;
	n->NE->br[1]=n->br[1];
	n->NE->state=0;

	n->SE=new Node;
	n->SE->prev_cuad=n;
	n->SE->tl[0]=n->br[0]-((n->br[0]-n->tl[0])/2);
	n->SE->tl[1]=n->br[1]-((n->br[1]-n->tl[1])/2);
	n->SE->br[0]=n->br[0];
	n->SE->br[1]=n->br[1];
	n->SE->state=0;
}

void LinkedPRQT::collapse(Node *n){
	int *cc=childCount(n);
	if(cc[0]==1){
		n->state=1;
		n->point[0]=cc[1];
		n->point[1]=cc[2];
		
		//reinicia los hijos
		delete n->NW;
		delete n->SW;
		delete n->SE;
		delete n->NE;
		subdivide(n);

		if(n->prev_cuad!=NULL) collapse(n->prev_cuad);
	}
	else if(cc[0]==0){
		n->state=0;
		delete n->NW;
		delete n->SW;
		delete n->SE;
		delete n->NE;
		if(n->prev_cuad!=NULL) collapse(n->prev_cuad);
	}
}

int LinkedPRQT::belongsTo(int x, int y, int *tl, int *br){
	if(x<=tl[0]+((br[0]-tl[0])/2)){
		if(y<=tl[1]+((br[1]-tl[1])/2))return 0;
		else return 3;
	}
	else{
		if(y<=tl[1]+((br[1]-tl[1])/2))return 1;
		else return 2;
	}
}


void LinkedPRQT::passPoint(int x, int y, Node *n){
	int cuad=belongsTo(x,y,n->tl,n->br);
	switch(cuad){
		case 0: {
			asPointLoc(x,y,n->NW);
			break;
		}
		case 1: {
			asPointLoc(x,y,n->SW);
			break;
		}
		case 2: {
			asPointLoc(x,y,n->SE);
			break;
		}
		case 3: {
			asPointLoc(x,y,n->NE);
			break;
		}
	}
}

void LinkedPRQT::asPointLoc(int x, int y, Node *n){
	switch(n->state){

		case 0:{
			n->state=1;
			n->point[0]=x;
			n->point[1]=y;
			subdivide(n);
			break;
		}

		case 1:{
			if(n->point[0]==x && n->point[1]==y){
				throw "Point allready added!";
			}
			else{
				passPoint(x,y,n);
				passPoint(n->point[0],n->point[1],n);
				n->state=2;
			}
			break;
		}

		case 2:{
			passPoint(x,y,n);
			break;
		}
	}
}

void LinkedPRQT::destroyNode(Node *n){
	if(n->state!=0){
		destroyNode(n->NW);
		destroyNode(n->SW);
		destroyNode(n->SE);
		destroyNode(n->NE);
	}
	delete n;
}

double LinkedPRQT::minDist(Node *n, double dist, int x, int y){
	double d;
	if(n->state!=0){
		d=sqrt(pow(n->point[0]-x,2)+pow(n->point[1]-y,2));
		if(d>dist)d=dist;
		else{
			pdm[0]=n->point[0];
			pdm[1]=n->point[1];
		}
		d=minDist(n->NW,d,x,y);
		d=minDist(n->SW,d,x,y);
		d=minDist(n->SE,d,x,y);
		d=minDist(n->NE,d,x,y);
		return d;
	}
	return dist;
}