#include <iostream>
#include <climits>
#include <chrono>

void run(bool do_bp)
{
    unsigned int max_ui = std::numeric_limits<unsigned int>::max();
    unsigned int count_odd = 0;
    unsigned int count_even = 0;
    unsigned int ttimes = 100;

    auto start = std::chrono::high_resolution_clock::now();
    if (do_bp) {
        for (unsigned int times = 0; times < ttimes; times++) {
            count_odd = 0;
            count_even = 0;
            for (unsigned int i = 1;i < max_ui; i += 2) {
                count_odd++;
            }
            for (unsigned int i = 0;i < max_ui - 1; i += 2) {
                count_even++;
            }
        }
    } else {
        for (unsigned int times = 0; times < ttimes; times++) {
            count_odd = 0;
            count_even = 0;
            for (unsigned int i = 0;i < max_ui; i++) {
                if (1 == i % 2) {
                    count_odd++;
                } else {
                    count_even++;
                }
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    std::string to_show;
    if (do_bp) {
        to_show = "True";
    } else {
        to_show = "False";
    }

    std::cout << "Counted: " << count_odd << " odd numbers and: "
        << count_even << " even numbers, in: " << duration.count() << "s with BP set to: " << to_show << std::endl;
}

int main(void)
{
    run(false);
    run(true);

    return 0;
}