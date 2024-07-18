#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	while(1){
		remove("tube3");
		remove("tube2");
		if(mkfifo("tube2",0600) < 0){
			perror("ERRRO");
			exit(EXIT_FAILURE);
		}
		FILE* fp =fopen("tube2","r");
		char message[12],message2[12],message3[12];
		fgets(message,12,fp);
		fgets(message2,12,fp);
		fgets(message2,12,fp);
		fgets(message3,12,fp);
		fgets(message3,12,fp);
		fclose(fp);
		unlink("tube2");
		printf("m1 : %s \n",message);
		printf("m2 : %s \n",message2);
		printf("m3 : %s \n",message3);
		int a = atoi(message);
		int b = atoi(message2);
		printf("a:%d\n",a);
		printf("b: %d\n",b);
		if(mkfifo("tube3",0600) < 0){
			perror("ERROR!!");
			exit(EXIT_FAILURE);
		}
		int result;
		char op = message3[0];
		switch(op){
			case '+':
				result = a + b;
				printf("ADD operation successfully\n");
			break;
			case '-':
				result = a - b;
				printf("SOUSSTRACTION operation successfully\n");
			break;
			case 'x':
				result = a * b;
				printf("PRODUIT operation successfully\n");
			break;
			case '/':
				if(b==0){
					printf("result will be -infini \n");
					result = -10000;
				}else{
					printf("DIVISION operation successfully \n");
					result = a / b;
				}
			break;
		}
		printf("result : %d\n",result);
		fp = fopen("tube3","w");
		fprintf(fp,"%d",result);
		fclose(fp);
	}
	return 0;
}
