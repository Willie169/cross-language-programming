#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <iostream>
#include <map>
#include <vector>

namespace py = pybind11;

int main() {
    try {
        std::cerr << "1\n";
        py::scoped_interpreter guard{};
        std::cerr << "2\n";
        py::module pd = py::module::import("pandas");
        std::cerr << "3\n";
        std::map<std::string, std::vector<int>> data;
        data["A"] = {1, 2, 3};
        data["B"] = {4, 5, 6};
        std::cerr << "4\n";
        py::object df = pd.attr("DataFrame")(py::cast(data));
        std::cerr << "5\n";        
        py::print(df);
        std::cerr << "6\n";
    } catch (py::error_already_set &e) {
        std::cerr << "Python error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception &e) {
        std::cerr << "C++ error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }

    return 0;
}