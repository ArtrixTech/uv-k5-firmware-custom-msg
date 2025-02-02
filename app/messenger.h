#ifndef APP_MSG_H
#define APP_MSG_H

#ifdef ENABLE_MESSENGER

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "driver/keyboard.h"

typedef enum KeyboardType {
	UPPERCASE,
  	LOWERCASE,
  	NUMERIC,
  	END_TYPE_KBRD
} KeyboardType;

enum { 
	TX_MSG_LENGTH = 29,
	MSG_HEADER_LENGTH = 20,
	MAX_RX_MSG_LENGTH = TX_MSG_LENGTH + 3
};

enum { 
	MAX_MSG_STORED = 24,
    DISPLAY_MSG_COUNT = 6
};
//const uint8_t TX_MSG_LENGTH = 30;
//const uint8_t MAX_RX_MSG_LENGTH = TX_MSG_LENGTH + 2;

extern KeyboardType keyboardType;
extern uint16_t gErrorsDuringMSG;
extern char cMessage[TX_MSG_LENGTH];
extern char rxMessage[MAX_MSG_STORED][MAX_RX_MSG_LENGTH + 3];
extern uint8_t hasNewMessage;
extern uint8_t keyTickCounter;
extern uint8_t currDisplayMsgID;
extern uint8_t totalMsgsReceived;
extern bool canScrollUp;
extern bool canScrollDown;

void MSG_EnableRX(const bool enable);
void MSG_StorePacket(const uint16_t interrupt_bits);
void MSG_Init();
void MSG_ProcessKeys(KEY_Code_t Key, bool bKeyPressed, bool bKeyHeld);
void MSG_Send(const char txMessage[TX_MSG_LENGTH], bool bServiceMessage);

#endif

#endif
