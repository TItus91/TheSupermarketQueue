#include <vector>

long queueTime(std::vector<int> customers, int n) {

    int czas = 0;
    int pusto = 0;
    std::vector <int> kasy;
    for (int i = 0; i < n; i++)
        kasy.push_back(0);

    while (!customers.empty() || pusto != 0)
    {
        pusto = 0;
        for (int i = 0; i < n; i++)
        {
            if (kasy[i] == NULL && !customers.empty())
            {
                kasy[i] = customers.front();
                customers.erase(customers.begin());
            }

            if (kasy[i] > 0) kasy[i] -= 1;
            pusto += kasy[i];

        }
        czas += 1;

    }

    return czas;
}