#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("invalid usage.. usage: \"");printf("%s",argv[0]);printf(" <file1> <file2>\"\n");
	return 1;
    }
    FILE * file1;
    FILE * file2;
    file1 = fopen(argv[1],"rb");
    if (!file1){
	    printf("%s open error\n",argv[1]);
	    return 1;
    }
    file2 = fopen(argv[2],"rb");
   if (!file2){
	  printf("%s open error\n",argv[2]);
	  return 1;
   }
   if (fseek(file1,0,SEEK_END)){
	   printf("%s fseek error\n",argv[1]);
	   return 1;
   }
   int size1 = ftell(file1);
   if (size1==-1){
	   printf("%s ftell error\n",argv[1]);
	   return 1;
   }
   if (size1 != 4){
	   printf("%s is not 4byte file.\n",argv[1]);
	   return 1;
   }
   if (fseek(file1,0,SEEK_SET)){
	   printf("%s fseek error\n",argv[1]);
	   return 1;
   }





   if (fseek(file2,0,SEEK_END)){
           printf("%s fseek error\n",argv[2]);
           return 1;
   }
   int size2 = ftell(file2);
   if (size2==-1){
           printf("%s ftell error\n",argv[2]);
           return 1;
   }
   if (size2 != 4){
           printf("%s is not 4byte file.\n",argv[2]);
           return 1;
   }
   if (fseek(file2,0,SEEK_SET)){
           printf("%s fseek error\n",argv[2]);
           return 1;
   }

   uint32_t v1;
   uint32_t v2;
   if (!fread(&v1,4,1,file1)){
	   printf("%s fread error\n",argv[1]);
	   return 1;
   }



   if (!fread(&v2,4,1,file2)){
	   printf("%s fread error\n",argv[2]);
	   return 1;
   }
   v1 = (v1&0xff000000)>>24 | (v1&0xff0000)>>8 | (v1&0xff00)<<8 | (v1&0xff)<<24;
   v2 = (v2&0xff000000)>>24 | (v2&0xff0000)>>8 | (v2&0xff00)<<8 | (v2&0xff)<<24;

   printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",v1,v1,v2,v2,v1+v2,v1+v2);
   fclose(file1);
   fclose(file2);



   return 0;
}


