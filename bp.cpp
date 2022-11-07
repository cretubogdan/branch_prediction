#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <chrono>

void run(bool do_bp)
{
    int num = 1000000;
    int ttimes = 1000;
    int count = 0;
    std::vector<int> arr;

    for (int i = 0; i < num; i++)
    {
        arr.push_back(rand() % 2);
    }

    if (do_bp)
    {
        std::sort(arr.begin(), arr.end());
    }

    auto start = std::chrono::high_resolution_clock::now();

    for (int times = 0;times < ttimes; times++) {
        for (int i = 0;i < num; i++) {
            if (0 == arr[i]) {
                count += 1;
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    std::string to_show;
    if (do_bp) {
        to_show = "True";
    }
    else {
        to_show = "False";
    }

    std::cout << "[C11]: Counter: " << count << " with branch prediction: " << to_show << " in " << duration.count() << "s" << std::endl;
}

int main()
{
    run(false);
    run(true);
}