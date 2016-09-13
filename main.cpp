//#include <QCoreApplication>
//#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    //Defining variables
    int m,k,j, n;
    cout << "Dimension of matrix:";
    cin >> n;

    double matr[n][n], vec[n];


    for (k = 0; k <= n; k++) {
        vec[k] = 1;
        // fill in matr
        matr[k][k] = 1;
        //cout << matr[k][k] << endl;
    }

    //}
    // wri
    //Algorithm forward substitution
    for (m = 0; m <= n; m++){
        for (j = m+1; j <= n; j++){
            for (k = j; k <= n; k++){

                //a^(m+1)_jk = a^m_jk - (a^m_jm * a^m_mk)/a^m_mm
                matr[j][k] = matr[j][k] - (matr[j][m]*matr[m][k])/matr[m][m];


            }
            //w^(m+1)_j = w^m_j - (a^m_jm * w^m_m)/a^m_mm
            vec[j] = vec[j]- (matr[j][m]*vec[m])/matr[m][m];
        }
    }

    //Defining variables for backward substitution
    double x[n], sum,term;
    //Defining the first solution
    x[n] = matr[n][n];

    //Algorithm for backward subtitution
    for (m = n - 1; m >= 0; m--){
        for (k=m+1; k<=n; k++){

            //cout << matr[m][k] << endl;
            //SUM_(k+1)^n (b_mk*x_k)
            term = matr[m][k]*x[k];
            sum += term;
            //cout << sum <<endl;
        }
        // x_m = (1/b_mm)*(y_m - SUM
        x[m]= (1.0/matr[m][m])*(vec[m]-sum);
    }
    cout <<  "Content of vector in subfunction:" << endl;
    for (m = 0; m <= n; m++){
    cout << x[m]<<endl;
    }
    return 0;
}
