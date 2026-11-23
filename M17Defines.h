/*
 *   Copyright (C) 2020,2021 by Jonathan Naylor G4KLX
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

#if !defined(M17DEFINES_H)
#define  M17DEFINES_H

const unsigned int M17_FRAME_LENGTH_BITS  = 384U;
const unsigned int M17_FRAME_LENGTH_BYTES = M17_FRAME_LENGTH_BITS / 8U;

const unsigned int M17_SYNC_LENGTH_BITS  = 16U;
const unsigned int M17_SYNC_LENGTH_BYTES = M17_SYNC_LENGTH_BITS / 8U;

const unsigned int M17_LSF_LENGTH_BITS  = 240U;
const unsigned int M17_LSF_LENGTH_BYTES = M17_LSF_LENGTH_BITS / 8U;

const unsigned int M17_LICH_FRAGMENT_FEC_LENGTH_BITS  = 96U;
const unsigned int M17_LICH_FRAGMENT_FEC_LENGTH_BYTES = M17_LICH_FRAGMENT_FEC_LENGTH_BITS / 8U;

// FN and payload of a stream frame, and the payload and counter of a packet frame
const unsigned int M17_STREAM_DATA_LENGTH_BYTES = 18U;
const unsigned int M17_PACKET_DATA_LENGTH_BYTES = 26U;

// The encoded bits checked by the Viterbi decoder
const unsigned int M17_LSF_FEC_BITS    = 368U;
const unsigned int M17_STREAM_FEC_BITS = 272U;
const unsigned int M17_PACKET_FEC_BITS = 368U;

// The modem's M17 frame types
const unsigned char M17_TAG_LINK_SETUP = 0x45U;
const unsigned char M17_TAG_STREAM     = 0x46U;
const unsigned char M17_TAG_PACKET     = 0x47U;
const unsigned char M17_TAG_LOST       = 0x48U;
const unsigned char M17_TAG_EOT        = 0x49U;

#endif
