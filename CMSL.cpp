#include<cstdio>  
#include<stack>  
#include<string>  
#include<cstring>  
#include<cmath>  
#include<ctype.h>
#include<iostream>

using namespace std;

int true_while = 1;

/*
string cmd 
char date 

*/
void command_if(string cmd,char date[200]){
	
	string date_str(date); 
	
	/*头文件输入*/
	if(cmd == "import"){
		cout<<"#include "<<date<<endl; 
	}else
	
	/*INT定义*/
	if(cmd == "int"){
		cout<<"int ";
		if(date_str == "main()"){
			cout<<"main(){\n";
		}else cout<<date<<";\n";
	}else
	if(cmd == "end" && date_str == "CMSL" || date_str == "cmsl"){
		cout<<"return 0;\n}\n";
		true_while = 0;
	}else{
		cout<<cmd<<" "<<date<<";\n";
	} 
}


int main(){
	
	
	
	
	
	
	char* in = "in.cmsl";
	char* out = "out.cpp";
	io:
		
	/*文 件 读 写*/
	cout << "CMSL编译器正在工作!\n";
	freopen(in,"r",stdin);
	freopen(out,"w",stdout);
	
	char str1[111];
	char command[100];
	int t=0;
	while(true_while){
		
		
		gets(str1);
		
		
		for(int i = 0;i<= strlen(str1)-1;i++){
			if (strlen(str1) == 0){
				break;
			}
			if (str1[i] == '>'||str1[i] == ';'){
				string str2(command); 
				string str3(str1);
				str3.erase(0,str2.length()+1);

				
				char str3_char[200];
				for(int i=0;i<=str3.length();i++){
					str3_char[i] = str3[i];
				}
				
				command_if(str2,str3_char);
				break;
			}else{
				command[t] = str1[i];
				t++;
			}
			
		}
		t=0;
		//cout<<command<<endl;
		memset(command,'\0',sizeof(command));
		
	}
	fclose(stdin);
	fclose(stdout);
	
	cout<<"编译成功\n";
	
}
