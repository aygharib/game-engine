#pragma once

#include <map>
#include <memory>
#include <string>
#include <utility>

template <typename T>
class ResourceAllocator {
public:
    auto add(const std::string& filePath) -> int {
        auto it = resources.find(filePath);
        if (it != resources.end()) {
            return it->second.first;
        }

        auto resource = std::make_shared<T>();
        if (!resource->loadFromFile(filePath)) {
            return -1;
        }

        resources.insert(
            std::make_pair(filePath, std::make_pair(currentId, resource)));
        
        return currentId++;
    }

    auto remove(int id) -> void {
        for (auto it = resources.begin(); it != resources.end(); ++it) {
            if (it->second.first == id) {
                resources.erase(it->first);
            }
        }
    }

    auto get(int id) -> std::shared_ptr<T> {
        for (auto it = resources.begin(); it != resources.end(); ++it) {
            if (it->second.first == id) {
                return it->second.second;
            }
        }
    
        return nullptr;
    }

    auto has(int id) -> bool {
        return (get(id) != nullptr);
    }

private:
    int currentId;
    std::map<std::string, std::pair<int, std::shared_ptr<T>>> resources;
};