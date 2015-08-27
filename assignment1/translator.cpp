/*

	Translator to convert 32 bit assembly code of C program to 64 bit assembly code....

*/


#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main () {
	ifstream f32("asm32.asm");
	ofstream f64("out_asm64.asm");
	std::string content( (std::istreambuf_iterator<char>(f32) ),
                       (std::istreambuf_iterator<char>()    ) );
	
	map<string,string> mapping;
	mapping["\tSECTION .data"]="extern printf\nSECTION .data";
	mapping["msg:	db \"Hello World\",10	"]="msg:	db \"Hello World\", 0";
	mapping["len:	equ $-msg"]="fmt:    db \"%s\", 10, 0 ";
	mapping["\tmov	edx,len"]="push    rbp\nmov	rdi,fmt";
	mapping["\tmov	ecx,msg	"]="mov	rsi,msg";
	mapping["\tmov	ebx,1"]="mov	rax,0";
	mapping["\tint	0x80"]="";
	mapping["\tmov	eax,4"]="";
	mapping["\tmov	ebx,0"]="";
	mapping["\tmov	eax,1"]="";



	for(map<string,string>::iterator it=mapping.begin();it!=mapping.end();it++){
		size_t f= content.find(it->first);
		while(f!=std::string::npos){
			//cout<<"here";
			content.replace(f, (it->first).length(), it->second);
			f= content.find(it->first);
		}
	}
	content += "call    printf	\n\tpop		rbp	\n\tmov	rax,0	\n\tret";
	cout<<content<<endl;
	f32.close();
	f64.close();
	return 0;
}