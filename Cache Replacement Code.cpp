#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <unordered_set>
#include <ctime>
#include <cstdlib>
using namespace std;
int simulateFIFO(const int* pageReferences, int pageReferencesSize, int cacheSize) {
    std::deque<int> cache;
    int cacheHits = 0;

    for (int i = 0; i < pageReferencesSize; i++) {
        int page = pageReferences[i];
        bool found = false;

        // Search for 'page' in the cache
        for (int j = 0; j < cache.size(); j++) {
            if (cache[j] == page) {
                found = true;
                break;
            }
        }

        if (found) {
            cacheHits++;
        } else {
            if (cache.size() == cacheSize) {
                cache.pop_front();
            }
            cache.push_back(page);
        }
    }

    return cacheHits;
}




int simulateRandom(const int* pageReferences, int pageReferencesSize, int cacheSize) {
    std::unordered_set<int> cache;
    int cacheHits = 0;

    for (int i = 0; i < pageReferencesSize; i++) {
        int page = pageReferences[i];
        if (cache.find(page) != cache.end()) {
            cacheHits++;
        } else {
            if (cache.size() == cacheSize) {
                int randomIndex = rand() % cacheSize;
                auto it = cache.begin();
                std::advance(it, randomIndex);
                cache.erase(it);
            }
            cache.insert(page);
        }
    }

    return cacheHits;
}

int simulateLRU(const int* pageReferences, int pageReferencesSize, int cacheSize) {
    std::deque<int> cache;
    int cacheHits = 0;

    for (int i = 0; i < pageReferencesSize; i++) {
        int page = pageReferences[i];
        bool found = false;

        // Search for 'page' in the cache
        for (int j = 0; j < cache.size(); j++) {
            if (cache[j] == page) {
                found = true;
                // Move the found page to the back to represent it as the most recently used
                int temp = cache[j];
                cache.erase(cache.begin() + j);
                cache.push_back(temp);
                break;
            }
        }

        if (found) {
            cacheHits++;
        } else {
            if (cache.size() == cacheSize) {
                cache.pop_front();
            }
            cache.push_back(page);
        }
    }

    return cacheHits;
}


int main() {
    int array_Pages[] = {49, 50, 50, 52, 30, 49, 43, 49, 20, 31, 26, 37, 43, 43, 43, 43, 43, 20, 20, 30, 21, 25, 25, 25, 25, 25, 25, 31, 20, 20, 11, 11, 11, 12, 12, 49, 43, 50, 50, 20, 11, 43, 50, 12, 12, 49, 43, 50, 50, 50};
    int pageReferencesSize = sizeof(array_Pages) / sizeof(array_Pages[0]);
    int cacheSize = 6;

    //int numTests = 10000;
    int totalFIFOHits = 0;
    int totalRandomHits = 0;
    int totalLRUHits = 0;

    srand(static_cast<unsigned int>(time(NULL)));

    //for (int i = 0; i < numTests; i++) {
        totalFIFOHits = simulateFIFO(array_Pages, pageReferencesSize, cacheSize);
        totalRandomHits = simulateRandom(array_Pages, pageReferencesSize, cacheSize);
        totalLRUHits = simulateLRU(array_Pages, pageReferencesSize, cacheSize);
  //  }

    int FIFOmiss = 50 - totalFIFOHits;
    int LRUmiss = 50 - totalLRUHits;
    int Randommiss = 50 - totalRandomHits;


    std::cout << "Total FIFO Hit Rate: " << totalFIFOHits << std::endl;
    std::cout << "Total FIFO Miss Rate: " << FIFOmiss << std::endl;

    std::cout << "Total Random Hit Rate: " << totalRandomHits << std::endl;
    std::cout << "Total Random Miss Rate: " << Randommiss << std::endl;

    std::cout << "Total LRU Hit Rate: " << totalLRUHits << std::endl;
    std::cout << "Total LRU Miss Rate: " << LRUmiss << endl;

    return 0;
}