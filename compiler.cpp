#include <bits/stdc++.h>

using namespace std;

struct Token{
	int n;					//number of tokens
	string token[1024];
	string token_type[1024];
};

Token lexicalanalysis(string code){
	Token X;
	int n=0;
	int L=code.length();
	for(int i=0; i<L; ){
		if(code[i]==' ' || code[i]=='\t' || code[i]== '\n'){
			i++;
		}
		else if(code.substr(i, 3)=="int"){
			X.token[n]="int";
			X.token_type[n]="variable specifier";
			n++;
			i=i+3;
		}
		else if(code.substr(i, 4)=="char"){
			X.token[n]="char";
			X.token_type[n]="variable specifier";
			n++;
			i=i+4;
		}
		else if(code.substr(i, 5)=="float"){
			X.token[n]="float";
			X.token_type[n]="variable specifier";
			n++;
			i=i+5;
		}
		else if(code.substr(i, 3)=="for"){
			X.token[n]="for";
			X.token_type[n]="loop";
			n++;
			i=i+3;
		}
		else if(code.substr(i, 5)=="while"){
			X.token[n]="while";
			X.token_type[n]="loop";
			n++;
			i=i+5;
		}
		else if(code.substr(i, 2)=="if"){
			X.token[n]="if";
			X.token_type[n]="condition";
			n++;
			i=i+2;
		}
		else if(code.substr(i, 4)=="else"){
			X.token[n]="else";
			X.token_type[n]="condition";
			n++;
			i=i+4;
		}
		else if(code.substr(i, 6)=="switch"){
			X.token[n]="switch";
			X.token_type[n]="condition";
			n++;
			i=i+6;
		}
		else if(code.substr(i, 4)=="case"){
			X.token[n]="case";
			X.token_type[n]="condition";
			n++;
			i=i+4;
		}
		else if(code.substr(i, 5)=="break"){
			X.token[n]="break";
			X.token_type[n]="exit";
			n++;
			i=i+5;
		}
		else if(code.substr(i, 8)=="continue"){
			X.token[n]="continue";
			X.token_type[n]="exit";
			n++;
			i=i+8;
		}
		else if(code.substr(i, 4)=="goto"){
			X.token[n]="goto";
			X.token_type[n]="exit";
			n++;
			i=i+4;
		}
		else if(code.substr(i, 6)=="return"){
			X.token[n]="return";
			X.token_type[n]="exit";
			n++;
			i=i+6;
		}
		else if(code.substr(i, 7)=="printf"){
			X.token[n]="printf(";
			X.token_type[n]="SPECIAL FUNCTION";
			i=i+7;
			while(code[i]!=')'){
				X.token[n]+=code[i];
				i++;
			}
			X.token[n]+=")";
			n++;
		}
		else if(code.substr(i, 6)=="scanf("){
			X.token[n]="scanf(";
			X.token_type[n]="SPECIAL FUNCTION";
			i=i+6;
			while(code[i]!=')'){
				X.token[n]+=code[i];
				i++;
			}
			X.token[n]+=")";
			n++;
		}
		else if(code.substr(i, 4)=="main"){
			X.token[n]="main";
			X.token_type[n]="MAIN FUNCTION";
			n++;
			i=i+4;
		}
		else if(code[i]='{'){
			X.token[n]="{";
			X.token_type[n]="LEFT BRACES";
			n++;
			i++;
		}
		else if(code[i]='}'){
			X.token[n]="}";
			X.token_type[n]="RIGHT BRACES";
			n++;
			i++;
		}
		cout<<X.token[n-1]<<"\n";
	}
	X.n=n;
	return X;
}


int main(){
	// PATH is hard coded for now
	string PATH="test.c"; 
	string code="";
	ifstream file(PATH);
	string temp;
	while(getline(file, temp)){
		code=code+temp+"\n";
	}
	file.close();
	cout<<code<<"\n";
	cout<<"****** CODE READ SUCESSFULLY ******\n";
	
	Token code_tokens=lexicalanalysis(code);
	return 0;
}