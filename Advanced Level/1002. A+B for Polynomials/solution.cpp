#include <cstdio>
#include <map>
using namespace std;

void input(map<int,float> &poly) {
    int k, exp;
    float coeff;
    scanf("%d", &k);
    for(int i = 0;i < k;++i) {
        scanf("%d%f", &exp, &coeff);
        poly[exp] += coeff;
    }
}

int main()
{
	//input and add
    map<int,float> poly;
    input(poly);
    input(poly);
    //calc k of sum
    int k = 0;
    for(auto &p: poly) {
        if(p.second != 0.0)
            ++k;
    }
    //output
    printf("%d", k);
    for(auto iter = poly.rbegin(); iter != poly.rend(); ++iter) {
        if(iter->second != 0.0) {
            printf(" %d %.1f", iter->first, iter->second);
        }
    }

	return 0;
}