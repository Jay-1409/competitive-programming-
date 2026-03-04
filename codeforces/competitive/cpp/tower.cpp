#include <iostream>
int n, count, s, arr[10001], a;
main()
{
    std::cin >> n;
    while (std::cin >> a)
    {
        if (arr[a] == 0)
            count++;
        arr[a]++;
        s = std::max(s, arr[a]);
    }
    std::cout << s << " " << count;
}