#include <vector>
#include <string>
#include <sstream>

#include "./httplib.h"

int main(int argc, char **argv)
{

    std::vector<int> data();

    httplib::Server svr;

    svr.get("/[A-Za-z0-9]+/[A-Za-z0-9]+/[A-Za-z0-9]+", [](const httplib::Request& req, httplib::Response& res) {
        std::stringstream buffer;
        buffer << "{\"s\": \"ok\", \"data\": [";
        for(std::vector<int>::size_type i = 0; i != data.size(); i++)
            buffer << data.at(i) << ",";

        buffer << "-]}";
        res.set_content(buffer.c_str(), "application/json");
    });

    svr.post("/[A-Za-z0-9]+", [](const httplib::Request& req, httplib::Response& res) {
        std::stringstream buffer();
        res.set_content("{\"s\": \"ok\"}", "application/json");
    });

    svr.listen("localhost", 90);
}
