#include <iostream>
#include <fstream>
#include <string>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

int fetch_input(int argc, char **argv, json &input);
void integration(const json &input, json &output);
void throw_darts(const json &input, json &output);

int main(int argc, char **argv) {
    // Read JSON input
    json inp_json;
    if (fetch_input(argc, argv, inp_json)) return EXIT_FAILURE;

    // Prepare JSON output
    json out_json;
    out_json["title"] = inp_json["title"];

    // Fetch computation method from input
    auto method = inp_json["method"].get<std::string>();
    if (method == "integration") {
        const auto &int_json = inp_json["Integration"].get<json>();
        integration(int_json, out_json);
    }
    if (method == "darts") {
        const auto &dart_json = inp_json["Darts"].get<json>();
        throw_darts(dart_json, out_json);
    }

    // Dump JSON input
    std::cout << "\n-------------- JSON input -----------------\n";
    std::cout << inp_json.dump(2) << std::endl;
    std::cout << "-------------------------------------------\n";

    // Dump JSON output
    std::cout << "\n-------------- JSON output ----------------\n";
    std::cout << out_json.dump(2) << std::endl;
    std::cout << "-------------------------------------------\n\n";

    return EXIT_SUCCESS;
}

int fetch_input(int argc, char **argv, json &input) {
    if (argc != 2) {
        std::cout << "Wrong number of arguments!" << std::endl;
        return 1;
    }

    std::ifstream ifs(argv[1], std::ios_base::in);
    if (ifs.fail()) {
        std::cout << "Failed to open file!" << std::endl;
        return 1;
    }

    ifs >> input;
    ifs.close();

    return 0;
}

void integration(const json &input, json &output) {
    auto n_steps = input["n_steps"].get<int>();
    auto step = 1.0 / n_steps;

    auto sum = 0.0;
    for (auto i = 0; i < n_steps; i++) {
        auto x = (i + 0.5) * step;
        auto f_x = 1.0 / (1.0 + x * x);
        sum += step * f_x;
    }

    output["method"] = "Numerical integration";
    output["pi"] = 4.0 * sum;
}

void throw_darts(const json &input, json &output) {
    auto n_darts = input["n_darts"].get<int>();
    auto seed = input["random_seed"].get<int>();

    // Seed the random number generator
    std::srand(seed);

    auto n_hits = 0;
    for (auto i = 0; i < n_darts; i++) {
        //creates 2 random numbers between 0 and 1
        auto x = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        auto y = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        auto r = std::sqrt(x*x + y*y);

        //counts how often the dart hits the circle
        if (r <= 1.0) n_hits++;
    }

    output["method"] = "Throwing darts";
    output["pi"] = 4.0 * n_hits / n_darts;
}

