/*
 - To install go to :
        https://pistacheio.github.io/pistache/docs/#installing-pistache

    sudo add-apt-repository ppa:pistache+team/unstable
    sudo apt update
    sudo apt install libpistache-dev

    INFO:
        - https://rapidjson.org/

 - To compile -> g++ -o server.out server.cpp -l pistache -ljsoncpp
 */

#include "pistache/endpoint.h"

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include "rapidjson/filereadstream.h"
#include <rapidjson/writer.h>

#include <fstream>
#include <iostream>

using namespace Pistache;
using namespace std;
using namespace rapidjson;

class CustomHandler : public Http::Handler
{
public:
    HTTP_PROTOTYPE(CustomHandler)

    void onRequest(const Http::Request &request, Http::ResponseWriter response)
    {

        ifstream ifs("data.json");
        IStreamWrapper isw(ifs);
        Document d;
        d.ParseStream(isw);

        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        d.Accept(writer);

        response.send(Http::Code::Ok, buffer.GetString());
    }
};

int main()
{
    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));
    auto opts = Pistache::Http::Endpoint::options()
                    .threads(1);

    Http::Endpoint server(addr);

    server.init(opts);
    server.setHandler(Http::make_handler<CustomHandler>());
    server.serve();
}