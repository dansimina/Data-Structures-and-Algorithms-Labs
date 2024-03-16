#include <iostream>

using namespace std;

void zaruriSuma(int n, int sum)
{
    static int a[10] = {0};
    static int k = 1;

    if(k == n + 1)
    {
        if(sum == 0)
        {
            for(int i = 1; i <= n; i++)
                cout << a[i];

            cout << endl;
        }
    }

    else
    {
        for(int i = 1; i <= 6; i ++)
            if(i <= sum)
        {
            a[k] = i;
            k++;
            zaruriSuma(n,sum - i);
            k--;
        }
    }
}

int main()
{

    zaruriSuma(3,7);

    return 0;
}
