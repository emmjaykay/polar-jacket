polar-jacket
============

A simple key-value store with a REST interface. 

Should be as simple as 

    cmake 
    make
    ./src/main/pjd

#### Putting and getting data

URIs are the main way to communicate with pjd. 

Putting data in a matter of giving a a key value (1) to your data (file.dat in this case).

    curl -X POST http://localhost:8080/put/1 -d ./file.dat

Retreiving it should be as simple as

    curl http://localhost:8080/get/1

