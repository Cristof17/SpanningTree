/******************************************************************************/
/* Tema 2 Protocoale de Comunicatie (Aprilie 2015)                            */
/******************************************************************************/

#include "api.h"
#include "sim.h"
#include "utils.h"
#include <iostream>


int main(int argc, char **argv)
{

  router ** routers = NULL;


	init_api(argc, argv);
	init_sim(argc, argv , routers );  //initializarea routere-lor si floodarea cu mesaje

	if(routers == NULL){
     std::cout << "Routers are nulL" << "\n";
  }


	loop {
		trigger_events(); //verifica timpii evenimentelor din lista si le marcheaza ca fiind pentru procesare "triggered"
		process_messages(); //va verifica care mesaj trebuie pornit -> va instiinta nodul responsabil de faptul ca trebuie sa proceseze mesajul //se retransmit mesaje de rutare si celelalte
		update_routing_table(); //fiecare router este anununtat ca a venit timpul sa-si recalculeze tabela de routare pe baza datelor acumulate
		api_update_state();
		if (api_simulation_ended())
			break;
	}

	clean_sim();
	clean_api();

	return 0;
}

//cand este triggered -> cele 2 routere vor fi instiintate de schimbare si vor incepe sa floodeze reteaua cu mesaje care contin vecinii direct conectati si costuri
//celelalte routere trebuie sa updateze topologia pe baza mesajelor primite si sa le faca forward mai departe la vecinii direct conectati
//routerele trebuie sa isi recalculeze tabela de routare 
