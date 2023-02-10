#pragma once

#include <string>

class WorkingDirectory {
public:
    WorkingDirectory();

    [[nodiscard]] auto get() const -> const std::string& {
        return path;
    }
private:
    const std::string path;
};