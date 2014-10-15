#include <stdio.h>
#include "main.hpp"
#include <CivetServer.h>


int main() {

  const char * options[] = { "listening_ports", "8080", 
			     0
  };

  CivetServer server(options);

  server.addHandler("/put", new put());
  server.addHandler("/get", new get());

  ModelDb::instance();
  ModelDb::instance()->_io_service.run();

}
