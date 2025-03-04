#include "./proto.h"

#ifndef SERVER_POLL_H
#define SERVER_POLL_H

void init_clients(client_state_t* client_state_t);
int find_free_slot(client_state_t* client_state_t);
int find_slot_by_fd(client_state_t* client_state_t,int fd);


#endif
