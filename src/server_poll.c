#include <string.h>
#include <sys/time.h>
#include <arpa/inet.h>

#include "../include/proto.h"

void init_clients(client_state_t *client_states) {

  for (int i = 0; i < MAX_CLIENTS; i++) {
    client_states[i].fd = -1;
    client_states[i].state = STATE_IDLE;
    memset(&client_states[i].buffer, '\0', BUFSIZE);
  }
}


int find_free_slot(client_state_t *client_states) {
  for (int i = 0; i < MAX_CLIENTS; i++) {
    if (client_states[i].fd == -1) {
      return i;
    }
  }
  return -1;
}

// can we use a map? hello c ?
int find_slot_by_fd(client_state_t *client_states, int fd) {
  for (int i = 0; i < MAX_CLIENTS; i++) {
    if (fd == client_states[i].fd) {
      return i;
    }
  }

  return -1;
}
