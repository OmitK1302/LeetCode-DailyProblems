class NumberContainers {
public:
    NumberContainers() {}

    void change(int index, int number) {
        if (indexMap.count(index)) {
            int oldNumber = indexMap[index];
            numberMap[oldNumber].erase(index);
            if (numberMap[oldNumber].empty()) {
                numberMap.erase(oldNumber);
            }
        }

        indexMap[index] = number;
        numberMap[number].insert(index);
    }

    int find(int number) {
        if (numberMap.count(number) && !numberMap[number].empty()) {
            return *numberMap[number].begin();
        }
        return -1;
    }

private:
    unordered_map<int, int> indexMap;
    unordered_map<int, std::set<int>> numberMap;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */