#include "kcpp11.h"

const uint32_t IKCP_RTO_NDL = 30;		// no delay min rto
const uint32_t IKCP_RTO_MIN = 100;		// normal min rto
const uint32_t IKCP_RTO_DEF = 200;
const uint32_t IKCP_RTO_MAX = 60000;
const uint32_t IKCP_CMD_PUSH = 81;		// cmd: push data
const uint32_t IKCP_CMD_ACK  = 82;		// cmd: ack
const uint32_t IKCP_CMD_WASK = 83;		// cmd: window probe (ask)
const uint32_t IKCP_CMD_WINS = 84;		// cmd: window size (tell)
const uint32_t IKCP_ASK_SEND = 1;		// need to send IKCP_CMD_WASK
const uint32_t IKCP_ASK_TELL = 2;		// need to send IKCP_CMD_WINS
const uint32_t IKCP_WND_SND = 32;
const uint32_t IKCP_WND_RCV = 128;       // must >= max fragment size
const uint32_t IKCP_MTU_DEF = 1400;
const uint32_t IKCP_ACK_FAST	= 3;
const uint32_t IKCP_INTERVAL	= 100;
const uint32_t IKCP_OVERHEAD = 24;
const uint32_t IKCP_DEADLINK = 20;
const uint32_t IKCP_THRESH_INIT = 2;
const uint32_t IKCP_THRESH_MIN = 2;
const uint32_t IKCP_PROBE_INIT = 7000;		// 7 secs to probe window size
const uint32_t IKCP_PROBE_LIMIT = 120000;	// up to 120 secs to probe window
const uint32_t IKCP_FASTACK_LIMIT = 5;		// max times to trigger fastack

ikcpcb::ikcpcb(uint32_t conv, void * user){
	this->conv = conv;
	this->user = user;
	this->snd_una = 0;
	this->snd_nxt = 0;
	this->rcv_nxt = 0;
	this->ts_recent = 0;
	this->ts_lastack = 0;
	this->ts_probe = 0;
	this->probe_wait = 0;
	this->snd_wnd = IKCP_WND_SND;
	this->rcv_wnd = IKCP_WND_RCV;
	this->rmt_wnd = IKCP_WND_RCV;
	this->cwnd = 0;
	this->incr = 0;
	this->probe = 0;
	this->mtu = IKCP_MTU_DEF;
	this->mss =this->mtu - IKCP_OVERHEAD;
	this->stream = 0;
}


void ikcpcb::setoutput( OutputFuncPtr *output){
	this->output = output;
}

int ikcpcb::recv(char* buffer,int len){
	//TODO
	return 0;
}
