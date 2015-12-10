#include <boost/network/protocol/http/client.hpp>
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {

  if(argc == 2) {
    std::string arg2(argv[1]);

    if(arg2 == "config") {
      std::cout << "graph_title Hackerspace Open" << std::endl
                << "graph_vlabel open" << std::endl
                << "open.label open" << std::endl;
      exit(0);
    }
  }
  
  boost::network::http::client client;
  boost::network::http::client::request request("http://hackeriet.no/door.json");
  request << boost::network::header("Connection", "close");
  boost::network::http::client::response response = client.get(request);

  std::string doorJson(body(response));

  if(doorJson.find("OPEN") != std::string::npos) {
    std::cout << "open.value 1.00" << std::endl;
  } else {
    std::cout << "open.value 0.00" << std::endl;
  }
}
