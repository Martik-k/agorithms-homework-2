#include <iostream>
#include <string>
#include <unordered_map>

std::pair<int, std::unordered_map<std::string, int>> developers_number_of_projects() {
    std::string line;
    getline(std::cin, line);

    size_t first_space = line.find(' ');
    int k = stoi(line.substr(0, first_space));

    size_t i = first_space + 1;
    std::unordered_map<std::string, int> devs_nums_projects;
    while (i < line.size()) {
        size_t proj_ind = line.find(':', i);
        if (proj_ind == std::string::npos) break;

        size_t devs_ind = line.find(' ', proj_ind + 1);
        if (devs_ind == std::string::npos) devs_ind = line.size();

        size_t start = proj_ind + 1;
        while (start < devs_ind) {
            size_t dev_ind = line.find(',', start);
            if (dev_ind == std::string::npos || dev_ind > devs_ind)
                dev_ind = devs_ind;
            devs_nums_projects[line.substr(start, dev_ind - start)]++;
            start = dev_ind + 1;
        }
        i = devs_ind + 1;
    }
    return {k, devs_nums_projects};
}

int count_overloaded_developers() {
    auto [k, devs_nums_projects] = developers_number_of_projects();
    int result = 0;
    for (auto &p : devs_nums_projects) {
        if (p.second > k) result++;
    }
    return result;
}

int main() {
    std::cout << count_overloaded_developers() << std::endl;
    return 0;
}
