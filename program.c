#include <stdio.h>

void day(int);

int main(){
    int div[9][5][8]={{{0,0,0,0,0,0,1,1},{1,0,0,0,0,0,0,1},{0,0,0,0,0,0,1,1},{1,1,0,0,0,0,1,1},{0,0,0,0,0,1,1,1}},
    {{1,0,0,0,0,0,0,0},{1,1,0,0,0,0,1,1},{1,0,0,0,0,1,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,1,1}},
    {{1,1,0,0,0,0,0,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,1,1,1},{1,1,0,0,0,0,1,1}},
    {{1,0,0,0,0,0,1,1},{1,0,0,0,0,0,1,1},{1,0,0,0,0,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,1,1}},
    {{0,0,0,0,1,1,1,1},{1,1,1,0,0,0,0,0},{1,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,1},{1,0,0,0,0,1,1,1}},
    {{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{1,0,0,0,0,0,1,1}},
    {{1,0,0,0,0,0,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,1,1,1},{1,0,0,0,0,0,1,1}},
    {{1,0,0,0,0,0,1,1},{1,0,0,0,0,0,1,1},{1,1,0,0,0,0,0,1},{1,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,1}}};
    int class[8][5][8] ={{{1,1,22,22,1,1,22,22},{22,1,1,1,1,1,1,22},{22,22,1,1,22,22,22,22},{1,1,1,1,1,22,22,22},{22,1,1,1,1,22,22,22}},
    {{1,1,1,1,1,1,23,23},{23,23,23,23,1,1,23,23},{23,1,1,1,1,23,23,23},{23,23,1,1,23,1,1,23},{1,1,1,1,1,1,23,23}},
    {{24,1,1,1,1,1,24,24},{1,1,24,1,1,1,24,24},{24,24,1,1,1,1,24,24},{1,1,1,1,1,24,24,24},{24,1,1,1,1,1,24,24}},
    {{1,1,1,1,1,1,25,25},{25,25,1,1,1,1,25,25},{25,1,1,1,1,25,25,25},{25,1,1,1,1,25,25,25},{25,1,1,1,1,25,25,25}},
    {{26,1,1,1,1,1,26,26},{26,1,1,1,26,26,26,26},{26,1,1,1,26,1,1,26},{26,1,1,1,1,1,26,26},{1,1,1,1,26,26,1,26}},
    {{17,1,1,1,17,1,17,17},{17,1,1,1,1,1,17,17},{17,1,1,1,1,17,17,17},{1,1,1,1,17,17,17,17},{17,1,1,1,17,17,17,17}},
    {{11,11,11,11,11,11,11,11},{11,1,11,11,1,1,11,11},{11,11,1,11,11,11,11,11},{11,1,1,1,11,11,11,11},{11,11,11,11,1,11,11,11}},
    {{12,12,12,12,12,12,12,12},{12,12,1,1,12,12,12,12},{12,12,1,12,12,12,12,12},{12,12,1,1,12,12,12,12},{12,12,12,12,12,12,12,12}}};
    printf("0 --> Monday\n1 --> Tuesday\n2 --> Wednesday\n3 --> Thursday\n4 --> Friday\n");
    printf("How can we help you?\n 1. Check for Free Lecture\n 2. Want to conduct orientation\n");
    int opt,i,j;
    scanf("%d",&opt);
    switch(opt){
        case 1://Free Lecture
            printf("Enter day and class:\n");
            scanf("%d",&j);
            int k;
            scanf("%d",&k);
            for(int a=0;a<8;a++){
                if(div[k][j][a]==1)
                    printf(" \n On %c section %d period is free and can be conducted in classroom ",(char)(k+65),a+1);
                for(int m=0;m<8;m++){
                    if((div[k][j][a]==1) && (class[m][j][a]!=1))
                        printf(" %d ,",class[m][j][a]);
                }
            }
            printf("\n");
            break;
       


        case 2://Orientation
            printf("Choose by:\n 1. Day and Period\n 2. Day\n");
            int ch;
            scanf("%d",&ch);
            switch(ch){
                case 1://Day and period
                    int count=0,z;
                    printf("Enter the day and period: \n");
                    scanf("%d%d",&i,&z);
                    j = z-1;
                    day(i);
                    printf("\nSections free: ");
                    for(int a=0;a<=9;a++){
                        if(div[a][i][j]==1){
                            count++;
                            printf("\t %c",(char)(a+65));
                        }
                    }      
                    printf("\nTotal free sections: %d",count);
                    int students=count*75;
                    if(students == 0)
                    printf("\nNo free sections available");
                    else if(students>0&&students<=150)
                    printf("\nIt can be conducted in Instrumentation Building Auditorium");
                     else if(students>150&&students<=225)
                      printf("\nIt can be conducted in Mechanical Building Auditorium");
                      else if(students>225&&students<=375)
                      printf("\nIt can be conducted in IT Building Auditorium(KB Joshi Hall)");
                     else
                     printf("\nIt can be conducted in Main Building Quadrangle");
                     break;

                case 2://Day
                    int cnt[9];
                    printf("Enter day:\n");
                    scanf("%d",&i);
                    for(int b=0;b<8;b++){
                        for(int a=0;a<9;a++){
                            if(div[a][i][b]==1){
                            printf("On %c section %d period is free\n",(char)(a+65),(b+1));
                            cnt[b]++;
                            }
                        }
                        printf("\n");
                    }
                   
                    break;
                    }
               
        }



    return 0;

}

void day(int i){
    if(i == 0)
    printf("On Monday");
    if(i == 1)
    printf("On Tuesday");
    if(i == 2)
    printf("On Wednesday");
    if(i == 3)
    printf("On Thursday");
    if(i == 4)
    printf("On Friday");
   
}