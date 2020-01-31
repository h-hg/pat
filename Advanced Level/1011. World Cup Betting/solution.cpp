#include <cstdio>
#include <algorithm>
using namespace std;
//W T L
int main() {
    double odd1, odd2, odd3, product = 1.0;
    for(int i = 0; i < 3; ++i) {
        scanf("%lf%lf%lf", &odd1, &odd2, &odd3);
        auto max_odd = max(odd1,max(odd2, odd3));
        if(max_odd == odd1)
            printf("W ");
        else if(max_odd == odd2)
            printf("T ");
        else
            printf("L ");
        product *= max_odd;
    }
    printf("%.2f", (product*0.65-1.0)*2.0);
    return 0;
}