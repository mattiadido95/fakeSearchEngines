/*
 * SPDX-FileCopyrightText: 2016 Mathieu Stefani
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
   Mathieu Stefani, 07 février 2016

   Example of a REST endpoint with routing
*/

#include <algorithm>

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include "rapidjson/filereadstream.h"
#include <rapidjson/writer.h>
#include <fstream>
#include <iostream>

using namespace Pistache;
using namespace std;
using namespace rapidjson;

void printCookies(const Http::Request &req)
{
    auto cookies = req.cookies();
    std::cout << "Cookies: [" << std::endl;
    const std::string indent(4, ' ');
    for (const auto &c : cookies)
    {
        std::cout << indent << c.name << " = " << c.value << std::endl;
    }
    std::cout << "]" << std::endl;
}

void logRequest(const Http::Request &request)
{
    auto req = request.headers();
}

void printLog()
{
    cout << "request" << std::endl;
    std::cout.flush();
}

string prepareResponse()
{
    ifstream ifs("data.json");
    IStreamWrapper isw(ifs);
    Document d;
    d.ParseStream(isw);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    d.Accept(writer);

    return buffer.GetString();
}

class StatsEndpoint
{
public:
    explicit StatsEndpoint(Address addr)
        : httpEndpoint(std::make_shared<Http::Endpoint>(addr))
    {
    }

    void init(size_t thr = 2)
    {
        auto opts = Http::Endpoint::options()
                        .threads(static_cast<int>(thr));
        httpEndpoint->init(opts);
        setupRoutes();
    }

    void start()
    {
        httpEndpoint->setHandler(router.handler());
        httpEndpoint->serve();
    }

private:
    void setupRoutes()
    {
        using namespace Rest;
        Routes::Post(router, "/list", Routes::bind(&StatsEndpoint::documentsList, this));
    }

    void documentsList(const Rest::Request &request, Http::ResponseWriter response)
    {
        using namespace Http;

        printLog();

        response.headers().add<Pistache::Http::Header::AccessControlAllowOrigin>("*");
        response.headers().add<Pistache::Http::Header::AccessControlAllowMethods>("POST");
        response.headers().add<Pistache::Http::Header::ContentType>(MIME(Application, Json));

        response.send(Http::Code::Ok, prepareResponse(), MIME(Application, Json));
    }

    std::shared_ptr<Http::Endpoint> httpEndpoint;
    Rest::Router router;
};

int main(int argc, char *argv[])
{
    Port port(9080);

    int thr = 2;

    if (argc >= 2)
    {
        port = static_cast<uint16_t>(std::stol(argv[1]));

        if (argc == 3)
            thr = std::stoi(argv[2]);
    }

    Address addr(Ipv4::any(), port);

    std::cout << "Cores = " << hardware_concurrency() << std::endl;
    std::cout << "Using " << thr << " threads" << std::endl;

    StatsEndpoint stats(addr);

    stats.init(thr);
    stats.start();
}