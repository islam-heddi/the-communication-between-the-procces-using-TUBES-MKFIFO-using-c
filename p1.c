#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

bool isnumirique(char str[]){
	for(int i = 0 ; i < strlen(str);i++){
		if(str[i] < '0' || str[i] > '9'){
			return false;
		}
	}
	return true;
}

bool isoperation(char str[]){
	if(strlen(str) > 1) return false;
	return str[0] == '+' || str[0] == '-' || str[0] == '/' || str[0] == 'x';
}

int main(int argc,char* argc[]){
	if(argv < 4){
		printf("error\n");
		return -1;
	}
	if(isnumirique(argc[1])&&isnumirique(argc[3])&&isoperation(argc[3])){
		FILE* fp = fopen("tube1","w");
		fprintf(fp,"%s\n",argc[1]);
		fprintf(fp,"%s\n",argc[2]);
		fprintf(fp,"%s\n",argc[3]);
		fclose(fp);
		
		fp = fopen("tube3","r");
		char message[12];
		fgets(message,12,fp);
		fclose(fp);
		printf("la resultat : %s\n",message);
	}else{
		printf("error : tu dois ecrire sous forme la a (+ - / x) b\n");
	}
		
	return 0;
}
