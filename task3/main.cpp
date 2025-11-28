#include <iostream>
#include <vector>
#include <utility>

std::pair<int, std::vector<int>> parse_input() {
    std::string line;
    getline(std::cin, line);

    size_t ind = line.find(' ', 1);
    int N = std::stoi(line.substr(1, ind-1));

    size_t prev_ind = ind;
    std::vector<int> tiles;
    while (ind < line.size()) {
        ind = line.find(' ', ind + 1);
        if (ind == std::string::npos) ind = line.size();

        tiles.push_back(std::stoi(line.substr(prev_ind + 1, ind - prev_ind - 1)));
        prev_ind = ind;
    }
    return {N, tiles};
}

int min_tiles_to_target(int N, std::vector<int>& tiles) {
    std::vector<int> dp(N + 1, 1e9);
    dp[0] = 0;

    for (int tile : tiles) {
        for (int i = N; i >= 0; i--) {
            if (i + tile <= N && dp[i] != 1e9) {
                dp[i + tile] = std::min(dp[i] + 1, dp[i + tile]);
            }
        }
    }

    return (dp[N] == 1e9) ? -1 : dp[N];
}

int main() {
    auto [N, tiles] = parse_input();
    std::cout << min_tiles_to_target(N, tiles) << std::endl;
    return 0;
}