#include "Timepp.hpp"


void void_sum () {
    // Simulate a complex function
    int sum = 0;
    for (int i = 0; i < 1000000; ++i) {
        sum += i;
    }
    assert(sum > 0 && "The sum should be greater than 0");
}

template <typename T, typename U>
U sum(T end) {
    // Simulate a complex function
    U sum = 0;
    for (int i = 0; i < end; ++i) {
        sum += i;
    }
    return sum;
}

// It should work with global variables
int64_t g_foo = timegb(sum<int64_t, int64_t>(1000000));

int main() {
    for (int i = 0; i < 23; ++i) {
        // It should work with templated functions
        timefn(sum<float, float>(1000000.0f));

        // It should work with lambdas
        timefn([] {
            return sum<int64_t, int64_t>(1000000);
        }());

        // It should work with void functions
        timefn(void_sum());

        // It should work with assignments in new scope
        timefn({
            const auto x2 = sum<int64_t, int64_t>(1000000);
            assert(x2 > 0 && "The sum should be greater than 0");
        });

        // It should work with assignments in function scope
        timest(const auto x1 = sum<int64_t, int64_t>(1000000));
        assert(x1 > 0 && "The sum should be greater than 0");

        timepush("My code block");
        const auto x3 = sum<float, int64_t>(1000000);
        assert(x3 > 0 && "The sum should be greater than 0");
        timepush(); // will get default code block name
        const auto x4 = sum<double, double>(1000000);
        assert(x4 > 0 && "The sum should be greater than 0");
        timepop();
        timepop();
    }

    return 0;
}