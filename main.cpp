#include <QCoreApplication>
#include <cmath>

using namespace std;

int main()
{
    int m,k,j, i,  row = 3, col = 3;
    double w[3] = {0.0,1.0,0.5};
    double a[3][3] = {  {-1.0, 1.0, -4.0},
                         {2.0, 2.0, 0.0},
                         {3.0, 3.0, 2.0}
                      };

    //cout << a[1][3] << endl;
    for (m = 0; m < row; m++){
        for (j = m+1; j < row; j++){
            for (k = j; k < row; k++){

                a[j][k] = a[j][k] - (a[j][m]*a[m][k])/a[m][m];


            }
            w[j] = w[j]- (a[j][m]*w[m])/a[m][m];
        }
    }
}
