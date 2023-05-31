#include <bits/stdc++.h>

using namespace std;

struct Token{
	int n, line;					//number of tokens
	string token[1024];
	string token_type[1024];
};

Token lexicalanalysis(string code){
	Token X;
	int n=0;
	int line=0;
	int L=code.length();
	for(int i=0; i<L; ){
		if(code[i]==' ' || code[i]=='\t' || code[i]== '\n'){
			i++;
		}
		else if(code[i]==';'){
			X.token[n]=";";
			X.token_type[n]="SEMICOLAN";
			n++;
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
		else if(code.substr(i, 6)=="printf"){
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
		else if(code.substr(i, 5)=="scanf"){
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
		else if(code[i]=='{'){
			X.token[n]="{";
			X.token_type[n]="LEFT BRACES";
			n++;
			i++;
		}
		else if(code[i]=='}'){
			X.token[n]="}";
			X.token_type[n]="RIGHT BRACES";
			n++;
			i++;
		}
		else if(code[i]=='('){
			X.token[n]="(";
			X.token_type[n]="LEFT PARENTHESES";
			n++;
			i++;
		}
		else if(code[i]==')'){
			X.token[n]=")";
			X.token_type[n]="RIGHT PARENTHESES";
			n++;
			i++;
		}
		else if(code[i]=='['){
			X.token[n]="[";
			X.token_type[n]="LEFT SQUARE BRACKET";
			n++;
			i++;
		}
		else if(code[i]==']'){
			X.token[n]="]";
			X.token_type[n]="RIGHT SQUARE BRACKET";
			n++;
			i++;
		}
		else if(code.substr(i, 2)=="+="){
			X.token[n]="+=";
			X.token_type[n]="ASSIGNMENT";
			n++;
			i=i+2;
		}
		else if(code.substr(i, 2)=="-="){
			X.token[n]="-=";
			X.token_type[n]="ASSIGNMENT";
			n++;
			i=i+2;
		}
		else if(code.substr(i, 2)=="*="){
			X.token[n]="*=";
			X.token_type[n]="ASSIGNMENT";
			n++;
			i=i+2;
		}
		else if(code.substr(i, 2)=="/="){
			X.token[n]="/=";
			X.token_type[n]="ASSIGNMENT";
			n++;
			i=i+2;
		}
		else if(code.substr(i, 2)=="%="){
			X.token[n]="%=";
			X.token_type[n]="ASSIGNMENT";
			n++;
			i=i+2;
		}
		else if(code[i]=='=' && code[i+1]!= '='){
			X.token[n]="=";
			X.token_type[n]="ASSIGNMENT";
			n++;
			i++;;
		}
		else if(code.substr(i, 2)=="=="){
			X.token[n]="==";
			X.token_type[n]="COMPARISON";
			n++;
			i=i+2;
		}
		else if(code.substr(i, 2)==">="){
			X.token[n]=">=";
			X.token_type[n]="COMPARISON";
			n++;
			i=i+2;
		}
		else if(code.substr(i, 2)=="<="){
			X.token[n]=">=";
			X.token_type[n]="COMPARISON";
			n++;
			i=i+2;
		}
		else if(code[i]=='<'){
			X.token[n]="<";
			X.token_type[n]="COMPARISON";
			n++;
			i++;
		}
		else if(code[i]=='>'){
			X.token[n]=">";
			X.token_type[n]="COMPARISON";
			n++;
			i++;
		}
		else if(code[i]=='!'){
			X.token[n]="!";
			X.token_type[n]="BOOLEAN OPERATOR";
			n++;
			i++;
		}
		else if(code.substr(i, 2)=="&&"){
			X.token[n]="&&";
			X.token_type[n]="BOOLEAN OPERATOR";
			n++;
			i=i+2;
		}
		else if(code.substr(i, 2)=="||"){
			X.token[n]="||";
			X.token_type[n]="BOOLEAN OPERATOR";
			n++;
			i=i+2;
		}
		else if(code[i]=='+'){
			X.token[n]="+";
			X.token_type[n]="ADDITION";
			n++;
			i++;
		}
		else if(code[i]=='-'){
			X.token[n]="-";
			X.token_type[n]="SUBTRACTION";
			n++;
			i++;
		}
		else if(code[i]=='*'){
			X.token[n]="*";
			X.token_type[n]="MULTIPLICATION";
			n++;
			i++;
		}
		else if(code[i]=='*'){
			X.token[n]="*";
			X.token_type[n]="DIVISION";
			n++;
			i++;
		}
		else if(code[i]=='%'){
			X.token[n]="%";
			X.token_type[n]="MOD";
			n++;
			i++;
		}
		else if(code[i]=='\"'){
			X.token[n]="\"";
			i++;
			while(code[i]!='\"'){
				X.token[n]+=code[i];
			}
			X.token[n]+='\"';
			X.token_type[n]="STRING LITERAL";
			n++;
			i++;
		}
		else if(code[i]=='\'' && code[i+2]=='\''){
			X.token[n]=code[i+1];
			X.token_type[n]="CHAR LITERAL";
			n++;
			i+=3;
		}
		else if(code[i]>='0' && code[i]<='9'){
			int check=1;
			int index=i;
			while(code[index]>='0' && code[index]<='9'){
				index++;
			}
			if(code[index]=='.'){
				check=0;
			}
			if(check){
				// interger
				X.token[n]="";
				while(code[i]>='0' && code[i]<='9'){
					X.token[n]+=code[i];
					i++;
				}
				X.token_type[n]="INT LITERAL";
				n++;
			}
			else{
				// float
				X.token[n]="";
				while(code[i]>='0' && code[i]<='9'){
					X.token[n]+=code[i];
					i++;
				}
				X.token[n]+=".";
				i++;
				while(code[i]>='0' && code[i]<='9'){
					X.token[n]+=code[i];
					i++;
				}
				X.token_type[n]="FLOAT LITERAL";
				n++;
			}
		}
		else if((code[i]>='a' &&code[i]<='z') || (code[i]>='A' &&code[i]<='Z') || code[i]=='_'){
			X.token[n]="";
			while((code[i]>='a' &&code[i]<='z') || (code[i]>='A' &&code[i]<='Z') || code[i]=='_'){
				X.token[n]+=code[i];
				i++;
			}
			X.token_type[n]="VARIABLE";
			n++;
		}
		cout<<X.token[n-1]<<"     "<< X.token_type[n-1]<<"\n";
	}
	X.n=n;
	X.line=line;
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