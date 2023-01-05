//Instructions for TMP
//1. Choose the working folder in your computer.
//2. Make an txt file called 'input.txt' and another file called 'output.txt', saved them in the working folder.
//3. Copy and Paste the full timestamp text in the 'input.txt' file.
//4. Run the program and follow the step shown.
//5. The timestamps will show automatically in 'output.txt'.


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
    printf("\nSongNum=%d\n",line);
    return line;
}

void identifyCCN(struct song s[],int N,FILE *fp,FILE *bonus){
    int i;
    for(i=0;i<N&&fgets(s[i].str,sizeof(s[i].str),fp)!=NULL;i++){
        printf("\nDid CCN join dancing song - %s",s[i].str);
        printf("('1'= yes;'2'= no;'3'=bonusCCN;'0'= cancel): ");
        scanf("%d",&s[i].ans);

        while(s[i].ans==0||s[i].ans==3){
            while(s[i].ans==0){
                printf("change CCN info on the song- %s",s[i-1].str);
                printf("('1'= did join;'2'= didn't join;): ");
                scanf("%d",&s[i-1].ans);

                printf("Did CCN join dancing song - %s",s[i].str);
                printf("('1'= yes;'2'= no;'3'=bonusCCN;'0'= cancel): ");
                scanf("%d",&s[i].ans);
            }
            while(s[i].ans==3){
                int min,sec;
                char tmp;
                printf("please enter the bonus timestamps: \n");
                scanf("%d%c%d",&min,&tmp,&sec);
                fprintf(bonus, "%d%c%d\n",min,tmp,sec);
                printf("added\n\n");

                printf("Did CCN join dancing song - %s",s[i].str);
                printf("('1'= yes;'2'= no;'3'=bonusCCN;'0'= cancel): ");
                scanf("%d",&s[i].ans);
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

    fprintf(out,"Timestamps for CCN\n");

    for(i=0;i<SongNum&&fgets(s[i].str,sizeof(s[i].str),in)!=NULL;i++){
        if(s[i].ans==1){
            fprintf(out,"%s",s[i].str);
        }
    }

    fclose(in);
    fclose(out);

    printf("\n***succeeded***\n");
    return 0;

}
