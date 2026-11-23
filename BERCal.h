/*
 *   Copyright (C) 2018 by Andy Uribe CA6JAU
 *   Copyright (C) 2018 by Bryan Biedenkapp N2PLL
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if !defined(BERCAL_H)
#define BERCAL_H

#include <cstdint>

class CBERCal {
public:
	CBERCal();
	~CBERCal();

	void DSTARFEC(const unsigned char* buffer, const unsigned char m_tag);
	void DMRFEC(const unsigned char* buffer, const unsigned char m_seq);
	void DMR1K(const unsigned char *buffer, const unsigned char m_seq);
	void YSFFEC(const unsigned char* buffer);
	void P25FEC(const unsigned char* buffer);
	void NXDNFEC(const unsigned char* buffer, const unsigned char m_tag);
	void M17FEC(const unsigned char* buffer, const unsigned char m_tag);

	void clock();

private:
	unsigned int m_errors;
	unsigned int m_bits;
	unsigned int m_frames;

	// A stream frame seen outside a transmission, kept until the next one confirms it
	bool         m_m17Pending;
	unsigned int m_m17PendingFN;
	unsigned int m_m17PendingErrs;

	unsigned int m_timeout;
	unsigned int m_timer;

	void NXDNScrambler(unsigned char* data);
	unsigned int regenerateDStar(unsigned int& a, unsigned int& b);
	unsigned int regenerateDMR(unsigned int& a, unsigned int& b, unsigned int& c);
	unsigned int regenerateIMBE(const unsigned char* bytes);
	unsigned int regenerateYSFDN(unsigned char* bytes);

	unsigned char countErrs(unsigned char a, unsigned char b);

	void M17Deinterleave(const unsigned char* in, unsigned char* out) const;
	bool M17CheckCRC(const unsigned char* data, unsigned int length) const;
	void M17Callsign(const unsigned char* encoded, char* callsign) const;
	void M17End(const char* reason);

	void timerStart();
	void timerStop();
};

#endif
