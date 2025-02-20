#include <iostream>
#include "writing.h"
#include "HoffmanTree.h"
#include "benchmark.h"

using namespace std;

int main() {
    string tests[5] = {"txt-test/txt-test-1MB.txt", "txt-test/txt-test-10MB.txt", "txt-test/txt-test-25MB.txt", "txt-test/txt-test-50MB.txt", "txt-test/txt-test-100MB.txt"};
    startTests(tests, 2, "logs.txt");
}