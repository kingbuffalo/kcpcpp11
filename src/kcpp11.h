#ifndef __KCP_CPP11_H__
#define __KCP_CPP11_H__

#include <cstdint>
#include <vector>

class IKCPSEG{
	public:
		uint32_t conv;
		uint32_t cmd;
		uint32_t frg;
		uint32_t wnd;
		uint32_t ts;
		uint32_t una;
		uint32_t len;
		uint32_t resendts;
		uint32_t rto;
		uint32_t fastack;
		uint32_t xmit;
		char data[1];
};

class ikcpcb;
using OutputFuncPtr = int(const char* buf,int len,ikcpcb* kcp,void *user);

class ikcpcb{
	public:
		uint32_t conv,mtu,mss,state;
		uint32_t snd_una,snd_nxt,rcv_nxt;
		uint32_t ts_recent,ts_lastack,ssthresh;
		int32_t rx_rttval,rx_srtt,rx_rto,rx_minrot;
		uint32_t snd_wnd,rcv_wnd,rmt_wnd,cwnd,probe;
		uint32_t current,interval,ts_flush,xmit;
		uint32_t nrcv_buf,nsnd_buf;
		uint32_t nrcv_que,nsnd_que;
		uint32_t nodelay,updated;
		uint32_t ts_probe,probe_wait;
		uint32_t dead_link,incr;

		std::vector<int> acklist;
		uint32_t ackcount;
		uint32_t ackblock;
		void *user;
		char* buffer;
		int fastresend;
		int fastlimit;
		int nocwnd,stream;
		int logmask;
		OutputFuncPtr *output;

		ikcpcb(uint32_t conv, void * user);
		~ikcpcb();
		void setoutput( OutputFuncPtr *funPtr);
		int recv(char *buffer,int len);
		int send(const char *buffer,int len);
		void update(uint32_t current);
		uint32_t check(uint32_t current);
		int input(const char* data, long size);
		void flush();
		int peeksize() const;
		int setmtu(int mtu);
		int wndsize(int sndwnd,int recvwnd);
		int waitsnd()const;
		int nodelayFunc(int nodelay,int interval,int resend,int nc);
		int log(int mask, const char* fmt,...);
		uint32_t getConv();
};

enum class KCP_LOG{
	OUTPUT = 1<<0,
	INPUT = 1<<1,
	SEND = 1<<2,
	RECV = 1<<3,
	IN_DATA = 1<<4,
	IN_ACK = 1<<5,
	IN_PROBE = 1<<6,
	IN_WINS = 1<<7,
	OUT_DATA = 1<<8,
	OUT_ACK = 1<<9,
	OUT_PROBE = 1<<10,
	OUT_WINS = 1<<11,
};


#endif
