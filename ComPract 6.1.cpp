#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int n;        // кількість будинків
int a[10];    // кількість телефонів у кожному будинку

void input()
{
    srand((unsigned)(time(NULL)));   // ініціалізую генератор випадкових чисел
    cout << "enter number of the houses (<=10)" << endl;
    cin >> n;                        
    for (int i = 0; i < n; i++)      
        a[i] = rand() % 30;
}

//============== виведення масиву =============
void output()
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

//============== пошук будинку для АТС =============
int station()
{
    int best = 0;          // номер найкращого будинку
    int minSum = -1;       // мінімальна сумарна довжина кабелів

    for (int k = 0; k < n; k++)          // кандидат на розташування АТС
    {
        int sum = 0;
        for (int i = 0; i < n; i++)      // відстань від АТС до кожного будинку
            sum += a[i] * abs(i - k);

        if (minSum == -1 || sum < minSum)
        {
            minSum = sum;
            best = k;
        }
    }
    return best;
}

int main()
{
    input();
    cout << "Phones in houses:" << endl;
    output();

    int k = station();
    cout << "ATS must be in house number " << k + 1 << endl;

    // обчислюю мінімальну довжину кабелів
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * abs(i - k);
    cout << "Minimal cable length: " << sum << endl;

    return 0;
}