#include <iostream>
#include <vector>
using namespace std;

int LinearSearchLast(const vector<int>& test, int target, int id) {
    // just incase we reached the end
    if (id == test.size()) {
        return -1;  
    }

    // goes back to search for the index
    int result = LinearSearchLast(test, target, id + 1);

    // if found in the rest of the vector, it'll return the index
    if (result != -1) {
        return result;
    }

    // if it's found in the current index, returns it
    if (test[id] == target) {
        return id;
    }

    return -1;  // if not found, just returns -1
}

int main() {
    vector<int> test = { 1, 2, 3, 4, 5, 3, 7, 3 };
    //example and demenstration for this.
    int target = 3;
    // targets for last num

    int lastIdx = LinearSearchLast(test, target, 0);
    cout << "Last occurrence of " << target << " is at index " << lastIdx << endl;

    return 0;
}
