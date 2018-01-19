#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    ofstream fout;
    fout.open("values.txt");
    for(int i=0;i<10000;i++){
        fout<<311*sin(0.02*i+1)+20<<endl;
    }
    fout.close();
    return 0;
}
