#ifndef _MODELDB_HPP
#define _MODELDB_HPP

//#include "leveldb/db.h"
#include "rocksdb/db.h"
#include <iostream>
//#include "work_queue.hpp"

#include <fstream>

#include <boost/asio/io_service.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind/protect.hpp> 
#include <boost/thread/mutex.hpp>
#include <iostream>

#include <memory> // shared_ptr
//http://think-async.com/Asio/Recipes

#define  my_thread_count 100

class ModelDb {
public:
  void init () {

    _work.reset( new boost::asio::io_service::work(_io_service) );

    for (std::size_t i = 0; i < my_thread_count; ++i)
      _threads.create_thread(boost::bind(&boost::asio::io_service::run, &_io_service));
    rocksdb::Options options;
    options.create_if_missing = true;
    rocksdb::Status status = rocksdb::DB::Open(options, "testdb", &_thedb);
    if (!status.ok()) std::cerr << status.ToString() << std::endl;
    assert(status.ok());
  }

  template <typename TFunc>
  void enqueue(TFunc fun) {
    _io_service.post(
		     boost::bind( &ModelDb::execute<TFunc>, this, fun )
		     );
  }


  static ModelDb* instance();

  rocksdb::DB* _thedb;

  void save(std::string cont) {
    std::cout << "writing!  -- " << cont << std::endl;

  }


  ModelDb() {}
  ~ModelDb() { _io_service.stop(); _threads.join_all();}
  ModelDb(ModelDb const&) {}
  ModelDb(std::string dataIn) {_data = dataIn;}

  boost::asio::io_service _io_service;
private:
  ModelDb& operator=(ModelDb const&) {return *_instance;};
  std::string _data;

  boost::shared_ptr<boost::asio::io_service::work> _work;
  boost::thread_group _threads;

  static ModelDb *_instance;

  //FIXME make this configurable
  
  template <typename TFunc>
  void execute(TFunc fun) {
    fun();
  }
};

struct ModelWriter {

  ModelWriter(std::string cont) {
    _data = cont;
  }
  ModelWriter() {}
  ~ModelWriter() {}
int save(std::string key, std::string value) {
    std::ofstream of;
    rocksdb::WriteOptions writeOptions;

    ModelDb::instance()->_thedb->Put(writeOptions, key.c_str(), value.c_str());

    of.open("_aa", std::fstream::app);
  
    of << "writing!  -- " << key << std::endl;
    of.close();

    return 1;
  }
private:
  std::string _data;
};

#endif
