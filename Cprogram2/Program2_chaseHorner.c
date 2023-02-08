
#include <stdio.h>

void possible_scores(score){
    printf("Possible coombinations of scoring plays:\n");
    int td2, td1, td, fg, sft;
    for(td2 = 0; td2 <= score/8; td2++){
        for(td1 = 0; td1 <= score/7; td1++){
            for(td = 0; td <= score/6; td++){
                for(fg = 0; fg <= score/3; fg++){
                    for(sft = 0; sft <= score/2; sft++){
                        if(score == sft*2 + fg*3 + td*6 + td1*7 + td2*8){
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, sft); 
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int score=2;
    while (score != 0 && score !=1){
        printf("\n\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        if(score > 1) 
        possible_scores(score);
    }
}