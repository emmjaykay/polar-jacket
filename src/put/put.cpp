#include "put.hpp"

bool put::handleGet(CivetServer *server, struct mg_connection *conn) {
        mg_printf(conn, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
        mg_printf(conn, "<html><body>");
        mg_printf(conn, "<h2>This is the AB handler!!!</h2>");
        mg_printf(conn, "</body></html>\n");
        return true;
}

bool put::handlePut(CivetServer *server, struct mg_connection *conn) {

  // test this with something like
  // curl -X PUT ~/line localhost:8080/put

  mg_request_info *inf;
  char ac[8192];

  ModelWriter mw;

  std::string value;

  while ( mg_read(conn, ac, 8192) != 0 ) { value.append(ac); }

  inf = mg_get_request_info(conn);

  std::string key(inf->uri);
  if (key.length() < 5)
    return false;

  std::cerr << "asdf: " <<  key.substr(5) << "\t";
  ModelDb::instance()->_io_service.post(boost::bind(&ModelWriter::save,mw, key.substr(5), value));

  mg_printf(conn, "HTTP/1.1 301 OK\r\nContent-Type: text/html\r\n\r\n");

  return true;
}
