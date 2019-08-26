#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    //input
    int a,b;
    scanf("%d%d",&a,&b);

    int sum = a + b;
    if(sum < 0) { 
        printf("-");
        sum = -sum; 
    }
    /*
        0123456
        6543210
    */
    std::string strsum = std::to_string(sum);
    for(int i = 0;i < strsum.size(); ++i){
        printf("%c", strsum[i]);
        int tmp = strsum.size() - 1 - i;
        if(tmp % 3 == 0 && tmp != 0)
            printf(",");
    }
    return 0;
}