#include "modeldb.hpp"
#include <fstream>
#include <iostream>

ModelDb *ModelDb::_instance = NULL;

ModelDb* ModelDb::instance() {

  if (!_instance) {
    //boost::mutex::scoped_lock  lock(_mutex) ;
    _instance = new ModelDb;
    _instance->init();
  }
  return _instance;
}
