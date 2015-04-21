/******************************************************************************/
/* Tema 2 Protocoale de Comunicatie (Aprilie 2015)                            */
/******************************************************************************/

#include "sim.h"
#include <iostream>
#include "router.h"

#include <stdio.h>



void init_sim(int argc, char **argv , router ** routers) {

   std::cout << "argv[1] " << argv[1] << "\n" ;
   std::cout << "argv[2] " << argv[2] << "\n" ;
   std::cout << "argv[3] " << argv[3] << "\n" ;


   /* read from files */

   FILE * topologie_file = fopen (argv[1] , "r");
   FILE * message_file = fopen (argv[2] , "r");
   FILE * events_file = fopen (argv[3] , "r");

   /*
   Create the topology
   */
   int number_of_routers;
   char line[80];
   fgets(line, 80,topologie_file );
   sscanf (line, "%d", &number_of_routers);
   printf ("%d\n", number_of_routers);


 	 routers = new router*[number_of_routers];
    if(routers == NULL)
      cout << "Routers are NULL in sim" << "\n" ;

   /*
   Build the connection between routers
   */
   while(fgets(line, 80,topologie_file ) != NULL)
   {
     int r1 , r2 ; //end routers values
     int cost ; //cost between the two routers
	   sscanf (line, "%d %d %d", &r1 , &cost , &r2);
	   printf ("%d %d %d \n", r1 , cost , r2 );

     router * to = new router(r2);
     router * from = new router(r1);

     routers[r2] = to ;
     routers[r1] = from ;

     routers[r1] -> addLink(to);
     routers[r2] -> addLink(from);

   }



   fclose(topologie_file);
   fclose(message_file);
   fclose(events_file);

}

void clean_sim() {
  //TODO
}

void trigger_events() {
  //TODO
}

void process_messages() {
  //TODO
}

void update_routing_table() {
  //TODO
}
