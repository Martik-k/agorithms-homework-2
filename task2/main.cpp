#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Training {
    int start;
    int end;
};

std::pair<int, std::vector<Training>> parse_input() {
    std::string line;
    getline(std::cin, line);

    size_t first_space = line.find(' ', 1);
    int T = stoi(line.substr(1, first_space));

    std::vector<Training> trainings;

    size_t i = first_space + 1;
    while (i < line.size()) {
        size_t activity_ind = line.find(':', i);
        if (activity_ind == std::string::npos) break;

        size_t time_ind = line.find(' ', activity_ind + 1);
        if (time_ind == std::string::npos) time_ind = line.size();

        std::string times = line.substr(activity_ind + 1, time_ind - (activity_ind + 1));
        size_t dash = times.find('-');
        int start = stoi(times.substr(0, dash));
        int end = stoi(times.substr(dash + 1));

        trainings.push_back({start, end});
        i = time_ind + 1;
    }
    return {T, trainings};
}

int max_trainings(int T, std::vector<Training>& trainings) {
    std::sort(trainings.begin(), trainings.end(),
              [](const Training &a, const Training &b) {
                  return a.end < b.end;
              });

    int count = 0;
    int last_end = -1e9;

    for (auto &tr : trainings) {
        if (tr.start >= last_end + T) {
            count++;
            last_end = tr.end;
        }
    }
    return count;
}

int main() {
    auto [T, trainings] = parse_input();
    std::cout << max_trainings(T, trainings) << std::endl;
    return 0;
}
