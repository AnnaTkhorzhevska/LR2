#include <iostream>
#include "httplib.h"
#include "func.h"
#include <chrono>
#include <vector>
#include <algorithm>

void handle_request(const httplib::Request&, httplib::Response& res) {
    Func myFunc;
    int n = 1000000;  // Кількість елементів (підібрати для 10 секунд)
    double x = 0.5;
    
    std::vector<double> results;
    for (int i = 0; i < n; ++i) {
        results.push_back(myFunc.FuncA(10, x));
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::sort(results.begin(), results.end());
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    res.set_content("Elapsed Time: " + std::to_string(elapsed.count()) + " seconds", "text/plain");
}

int main() {
    httplib::Server svr;
    svr.Get("/", handle_request);
    std::cout << "Server is running on http://localhost:8080\n";
    svr.listen("0.0.0.0", 8080);
}
