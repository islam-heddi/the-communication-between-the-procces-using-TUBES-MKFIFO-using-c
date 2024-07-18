#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	while(1){
		remove("tube1");
		if(mkfifo("tube1",0600) < 0){
			perror("ERROR");
			exit(EXIT_FAILURE);
		}
		char message1[12];
		char message2[12];
		char message3[12];
		FILE* fp = fopen("tube1","r");
		fgets(message1,12,fp);
		fgets(message2,12,fp);
		fgets(message3,12,fp);
		fclose(fp);
		printf("m1 : %s \n",message1);
		printf("m2 : %s \n",message2);
		printf("m3 : %s \n",message3);
		fp = fopen("tube2","w");
		fprintf(fp,"%s\n",message1);
		fprintf(fp,"%s\n",message3);
		fprintf(fp,"%s\n",message2);
		fclose(fp);
		unlink("tube1");
	}
	return 0;
}
