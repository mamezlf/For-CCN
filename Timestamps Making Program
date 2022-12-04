#include <stdio.h>
#include <stdlib.h>
#define SIZE 256

struct song{
    char str[SIZE];
    int ans;
};

int FindSongNum(FILE *fp){
    int c;
    int line=0;
    fp=fopen("input.txt","r");
    char buf[SIZE];

    if ((fp=fopen("input.txt","r"))==NULL){
        printf("failed to open the txt file.\n");
        return -1;
    }
    
    while(fgets(buf,SIZE,fp)!=NULL){
        line++;
    }

    fclose(fp);
    printf("SongNum=%d\n",line);
    return line;
}

void identifyCCN(struct song s[],int N,FILE *fp){
    int i;
    for(i=0;i<N&&fgets(s[i].str,sizeof(s[i].str),fp)!=NULL;i++){
        printf("Did CCN join dancing song - %s",s[i].str);
        printf("('1'= yes;'2'= no;'3'= bonusCCN;'0'= cancel)");
        scanf("%d",&s[i].ans);    
    }
}

int main(void){
    FILE* fp;
    
    int SongNum;
    SongNum= FindSongNum(fp);

    struct song s[SongNum];
    char str[SIZE];
    int a=0;

    fp=fopen("input.txt","r");

    if (fp==NULL){
        printf("cannot open file\n");
        exit(1);
    }
    identifyCCN(s,SongNum,fp);
    fclose(fp);

    FILE *in;
    in=fopen("input.txt","r");
    
    int i=0;

    FILE *out;
    out=fopen("output.txt","w");

    fprintf(out,"Timestamps for CCN\n");

    for(i=0;i<SongNum&&fgets(s[i].str,sizeof(s[i].str),in)!=NULL;i++){
        if(s[i].ans==1){
            fprintf(out,"%s",s[i].str);
        }
        
    }


    fclose(in);
    fclose(out);

    printf("***succeeded***\n");
    return 0;

}
