
#ifndef ROUTER_H
#define ROUTER_H

#include "api.h"
#include "topologie.h"
#include "table.h"

class router{

public:

  router(){
    id = 0 ;
    if(this-> to == NULL){
       this-> to = new topologie();
    }

    if(this-> tb == NULL){
       this-> tb = new table();
    }

    if(this->links == NULL){
    	this->links = new router*[20];
    }

  }

  router(int id){
    this-> id = id ;

    if(this-> to == NULL){
       this-> to = new topologie();
    }

    if(this-> tb == NULL){
       this-> tb = new table();
    }

    if(this->links == NULL){
       this->links = new router*[20];
    }
  }

  /*
  Returns the router ID
  */
  int getID(){
    return id ;
  }

  /*
  Adds a direcly connect router to the current router
  */
  void addLink(router * link){
    this->links[link->getID()] = link ;
  }

  ~router(){
    int i=  0 ;
    for (i = 0 ; i < 20 ; i++){
      delete links[i];
    }
      delete[] links;
  }

private :
  int id ;
  router ** links ;
  topologie *to;
  table *tb;

};

#endif // ROUTER_H
