#include "get.hpp"

bool get::handleGet(CivetServer *server, struct mg_connection *conn) {

  // test this with something like
  // curl localhost:8080/get

  mg_request_info *inf = mg_get_request_info(conn);

  ModelWriter mw;
  std::string a;
  std::string key(inf->uri);

  if (key.length() < 5) 
    return false;

  std::string value;


  rocksdb::Status status = ModelDb::instance()->_thedb->Get(rocksdb::ReadOptions(), key.substr(5), &value);

  mg_printf(conn, "%s", value.c_str());
  return true;
}
