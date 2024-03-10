#ifndef TABLICA_ASOSACYJNA_MAP_H
#define TABLICA_ASOSACYJNA_MAP_H

#include "Employee.h"
#include <iostream>
#include <vector>

using namespace std;

template<typename Key, typename Value>
class Map{
private:
    vector<Key> keys;
    vector<Value> values;
public:
    void add(const Key& key, const Value& value) {
        keys.push_back(key);
        try{
			values.push_back(value);
		}catch(...){
			keys.pop_back();
			throw;
		}
    }

    Value* find(const Key& key) {
        size_t index = 0;
        for(auto& it: keys) {
            if(key == it){
                return &(values[index]);
            }
            ++index;
        }
        return nullptr;
    }

    friend ostream& operator<<(std::ostream& os, const Map& myMap) {
        for (size_t i = 0; i < myMap.keys.size(); ++i) {
            os << "Key: " << myMap.keys[i] << ", Value: " << myMap.values[i] << std::endl;
        }
        return os;
    }
    
    Map& operator=(const Map& m){
		Map new_map(m);
		new_map.keys.swap(keys);
		new_map.values.swap(values);
		return *this;
	}
};

#endif //TABLICA_ASOSACYJNA_MAP_H
