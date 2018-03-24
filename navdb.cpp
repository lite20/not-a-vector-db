#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include <restinio/all.hpp>

std::vector<int> data;

int main(int argc, char **argv)
{
    restinio::run(
        restinio::on_this_thread()
        .port(8080)
        .address("localhost")
        .request_handler([](auto req) {
            return req->create_response().set_body("Hello, World!").done();
        }));
    return 0;
}

/**
int main(int argc, char **argv)
{
    httplib::Server svr;

    svr.get("/[A-Za-z0-9]+/[A-Za-z0-9]+/[A-Za-z0-9]+", [](const httplib::Request& req, httplib::Response& res) {
        std::cout << "hit" << std::endl;
        std::stringstream buffer;
        buffer << "{\"s\": \"ok\", \"data\": [";
        for(std::vector<int>::size_type i = 0; i != data.size(); i++)
            buffer << data.at(i) << ",";

        buffer << "]}";
        res.set_content(buffer.str().c_str(), "application/json");
    });

    svr.post("/[A-Za-z0-9]+", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("{\"s\": \"ok\"}", "application/json");
    });

    svr.listen("localhost", 90);
    return 0;
}
**/
