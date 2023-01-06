#include <stdio.h>
#include <stdlib.h>
#define SIZE 256

struct song{
    char str[SIZE];
    int ansccn, answoojin;
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
    printf("\nSongNum=%d\n",line);
    return line;
}

void identifyCCN(struct song s[],int N,FILE *fp,FILE *bonus){
    int i;
    for(i=0;i<N&&fgets(s[i].str,sizeof(s[i].str),fp)!=NULL;i++){
        printf("\nsong info - %s\n",s[i].str);
        printf("CCN did join?\n");
        printf("('1'= yes;'2'= no;'3'=bonusCCN;'0'= cancel): ");
        scanf("%d",&s[i].ansccn);

        printf("\nWoojin did join?\n");
        printf("('1'= yes;'2'= no;'3'=bonusCCN;'0'= cancel): ");
        scanf("%d",&s[i].answoojin);

        while(s[i].ansccn==0||s[i].ansccn==3){
            while(s[i].ansccn==0){
                printf("\nsong info - %s\n",s[i-1].str);
                printf("CCN did join?\n");
                printf("('1'= yes;'2'= no;'3'=bonusCCN;'0'= cancel): ");
                scanf("%d",&s[i-1].ansccn);
                printf("\nWoojin did join?\n");
                printf("('1'= yes;'2'= no;'3'=bonusCCN;'0'= cancel): ");
                scanf("%d",&s[i-1].answoojin);

                printf("\nsong info - %s\n",s[i].str);
                printf("CCN did join?\n");
                printf("('1'= yes;'2'= no;'3'=bonusCCN;'0'= cancel): ");
                scanf("%d",&s[i].ansccn);
                printf("\nWoojin did join?\n");
                printf("('1'= yes;'2'= no;'3'=bonusCCN;'0'= cancel): ");
                scanf("%d",&s[i].answoojin);
            }
        }

    }
}

int main(void){
    FILE* fp;
    
    /*Find SongNum*/
    int SongNum;
    SongNum= FindSongNum(fp);

    struct song s[SongNum];
    char str[SIZE];
    int a=0;

    /*Main Part*/
    fp=fopen("input.txt","r");

    if (fp==NULL){
        printf("cannot open file\n");
        exit(1);
    }

    FILE *bonus;
    bonus=fopen("bonusCCN.txt","r");
    if (bonus==NULL){
        printf("cannot open file\n");
        exit(1);
    }

    identifyCCN(s,SongNum,fp,bonus);
    fclose(fp);

    FILE *in;
    in=fopen("input.txt","r");
    if (in==NULL){
        printf("cannot open file\n");
        exit(1);
    }
    
    int i=0;

    FILE *out;
    out=fopen("output.txt","w");
    if (out==NULL){
        printf("cannot open file\n");
        exit(1);
    }

    int j=0;
    for(j=0;j<SongNum;j++){
        fgets(s[j].str,sizeof(s[j].str),in);
    }

    fprintf(out,"[CCN & Woojin]\n");

    fprintf(out,"Timestamps for CCN\n");
    for(i=0;i<SongNum;i++){
        if(s[i].ansccn==1){
            fprintf(out,"%s",s[i].str);
        }
    }

    fprintf(out,"\n\nTimestamps for Woojin\n");
    for(i=0;i<SongNum;i++){
        if(s[i].answoojin==1){
            fprintf(out,"%s",s[i].str);
        }
    }

    fclose(in);
    fclose(out);

    printf("\n***succeeded***\n");
    return 0;

}
