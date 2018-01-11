struct fraction
{
    int upper;//分子
    int lower;//分母
};

struct fraction GetSum(struct fraction a,struct fraction b)
{
    int divider;//分子分母最大公约数
    struct fraction result;
    if(!(a.lower&&b.lower))//检查分母
    {
        printf("非法数值！");
        exit(0);
    }
    result.lower=a.lower*b.lower;
    result.upper=a.upper*b.lower+b.upper*a.lower;
    divider=result.lower>result.upper?result.upper:result.lower;
    do
    {
        if(result.upper%divider==0&&result.lower%divider==0)
        {
            result.lower/=divider;
            result.upper/=divider;
            return result;//约分后的情况
        }
    }while(--divider>1);
    return result;//不能再约分的情况
}

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
        vector<struct fraction> t(N,{1,1})；
        vector<<vector<struct fraction>> prob(t,N);
        vector<vector<vector<struct fraction>>> dp(K+1,prob);
        double sum = 0.0;

        if(!canJump(r,c,K)){
            return .0;
        }

        /*initial*/
        dp[0][r][c] = 1.0;

        for(int i = 0;i <= K; ++i){
            for(int j = 0;j < N; ++j){
                for(int k = 0;k < N; ++k){
                    if(dp[i][j][k] != 0.0 && i != K){
                         /*step1:-1,-2*/
                        if(canJump(j-1,k-2,N)){
                            dp[i+1][j-1][k-2] += dp[i][j][k]*0.125;
                        }
                        /*step2:-2,-1*/
                        if(canJump(j-2,k-1,N)){
                            dp[i+1][j-2][k-1] += dp[i][j][k]*0.125;
                        }
                        /*step3:-2,1*/
                        if(canJump(j-2,k+1,N)){
                            dp[i+1][j-2][k+1] += dp[i][j][k]*0.125;
                        }
                        /*step4:-1,2*/
                        if(canJump(j-1,k+2,N)){
                            dp[i+1][j-1][k+2] += dp[i][j-1][k+2]*0.125;
                        }
                        /*step5:1,2*/
                        if(canJump(j+1,k+2,N)){
                           dp[i+1][j+1][k+2] += dp[i][j][k]*0.125;
                        }
                        /*step6:2,1*/
                        if(canJump(j+2,k+1,N)){
                            dp[i+1][j+2][k+1] += dp[i][j][k]*0.125;
                        }
                        /*step7:1,-2*/
                        if(canJump(j+1,k-2,N)){
                            dp[i+1][j+1][k-2] += dp[i][j][k]*0.125;
                        }
                        /*step8:2,-1*/
                        if(canJump(j+2,k-1,N)){
                            dp[i+1][j+2][k-1] += dp[i][j][k]*0.125;
                        }
                    }

                    if(i == K){
                        sum += dp[i][j][k];
                    }
                }
            }
        }

        return sum;
    }
};