
typedef struct point{
    int x;
    int y;
}point;

typedef struct jump{
    point location;
    int step;
}jump;

bool canJump(int x,int y,int N){
    if(x < 0 || y < 0|| x >= N || y>= N){
        return false;
    }else{
        return true;
    }
}

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<double> dp(0.0,K+1);
        dp[0] = 1.00;
        printf("asdasd\n\r");
        queue<jump> moveQ;
        int step = 0;
        printf("asdasd\n\r");

        if(!canJump(r,c,N)){
            return 0.0;
        }
        printf("asdasd\n\r");

        /*initial*/
        jump start;
        start.location.x = r;
        start.location.y = c;
        start.step = step;
        moveQ.push(start);

        printf("asdasd\n\r");
        /*we will jump*/
        while(!moveQ.empty()){
            step++;
            if(step > K){
                break;
            }
            /*this level*/
            for(int i = 0;i < moveQ.size();++i){
                jump node = moveQ.front();
                moveQ.pop();
                node.step = step;
                /*step1:-1,-2*/
                if(canJump(r-1,c-2,N)){
                    node.location.x = r-1;
                    node.location.y = c-2;
                    dp[step] += pow(0.125,step);
                    moveQ.push(node);
                }
                /*step2:-2,-1*/
                if(canJump(r-2,c-1,N)){
                    node.location.x = r-2;
                    node.location.y = c-1;
                    dp[step] += pow(0.125,step);
                    moveQ.push(node);
                }
                /*step3:-2,1*/
                if(canJump(r-2,c+1,N)){
                    node.location.x = r-2;
                    node.location.y = c+1;
                    dp[step] += pow(0.125,step);
                    moveQ.push(node);
                }
                /*step4:-1,2*/
                if(canJump(r-1,c+2,N)){
                    node.location.x = r-1;
                    node.location.y = c+2;
                    dp[step] += pow(0.125,step);
                    moveQ.push(node);
                }
                /*step5:1,2*/
                if(canJump(r+1,c+2,N)){
                    node.location.x = r+1;
                    node.location.y = c+2;
                    dp[step] += pow(0.125,step);
                    moveQ.push(node);
                }
                /*step6:2,1*/
                if(canJump(r+2,c+1,N)){
                    node.location.x = r+2;
                    node.location.y = c+1;
                    dp[step] += pow(0.125,step);
                    moveQ.push(node);
                }
                /*step7:1,-2*/
                if(canJump(r+1,c-2,N)){
                    node.location.x = r+1;
                    node.location.y = c-2;
                    dp[step] += pow(0.125,step);
                    moveQ.push(node);
                }
                /*step8:2,-1*/
                if(canJump(r+2,c-1,N)){
                    node.location.x = r+2;
                    node.location.y = c-1;
                    dp[step] += pow(0.125,step);
                    moveQ.push(node);
                }
            }

        }

        return dp[K];
    }
};