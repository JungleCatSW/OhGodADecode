// Copyright (c) 2017 OhGodACompany - OhGodAGirl & OhGodAPet

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "ohgodadecode.h"
/*
# Rx470 Samsung 1500
#strap = '555000000000000022CC1C00AD515A3EC0570E142D4A64080048C700030114207A8900A003000000150E2A3186272E16'
# Rx470 Samsung 1625
#strap = '555000000000000022CC1C00CE596B44D0570F1531CB2409004AE7000B0314207A8900A003000000170F2E36922A3217'
# Rx470 Samsung 1750
#strap = '777000000000000022CC1C0010626C49D0571016B50BD509004AE700140514207A8900A003000000191131399D2C3617'
# Rx470 Samsung 1900
#strap = '777000000000000022CC1C00106A7D4FE0571117B98CA50A004C07011C0714207A8900A0030000001B11353FAA2F3A18'
# custom 1625 w RRD=5, RC=3E, FAW&32AW=0, 555->777, OK@2000
#strap = '777000000000000022CC1C00CE595B3ED0570F1531CB2409004007000B0314207A8900A003000000170F2E36922A3217'
# custom 1750 w RRD=5, FAW&32AW=0
#strap = '777000000000000022CC1C0010625C49D0571016B50BD50900400700140514207A8900A003000000191131399D2C3617'
#laik2 + RAS2RAS 150, ACTRD=16
#strap = '777000000000000022CC1C00CE615C45C0571016B30CD50900400700140514207A8900A00300000010103139962C3617'
# Rx470 Hynix 1500
strap = '777000000000000022339D00CE516A3D9055111230CB4409004AE600740114206A8900A002003120150F292F94273116'
# H1500C
strap = '777000000000000022339D00CE515A3D9055111230CB440900400600740114206A8900A002003120100F292F94273116'
# H1625C - MISC from 1500
strap = '999000000000000022559D0010DE5B4480551312B74C450A00400600750414206A8900A00200312010112D34A42A3816'
# laik2 custom Hynix 1500
#strap = '777000000000000022339D00CE515A398055111230CB440900408400740114206A8900A002003120150F292F94273116'
 */


//777000000000000022CC1C00CE615C45C0571016B30CD50900400700140514207A8900A00300000 010103139962C3617


// Parameter len is the size in bytes of asciistr, meaning rawstr
// must have (len >> 1) bytes allocated
// Maybe asciistr just NULL terminated?
// Returns length of rawstr in bytes
int ASCIIHexToBinary(void *rawstr, const char *asciistr, size_t len)
{
	for(int i = 0, j = 0; i < len; ++i)
	{
		char tmp = asciistr[i];
		if(tmp < 'A') tmp -= '0';
		else if(tmp < 'a') tmp = (tmp - 'A') + 10;
		else tmp = (tmp - 'a') + 10;
		
		if(i & 1) ((uint8_t *)rawstr)[j++] |= tmp & 0x0F;
		else ((uint8_t *)rawstr)[j] = tmp << 4;
	}
	
	return(len >> 1);
}

int main(int argc, char **argv)
{
	uint32_t buf[12];
	VBIOS_TIMING_FORMAT *Timings = (VBIOS_TIMING_FORMAT *)buf;
		
	// Short circuited logic should prevent a segfault.
	if(argc != 2 || strlen(argv[1]) != 96)
	{
		printf("Usage: <96-char hex string>\n");
		return(1);
	}
	
	ASCIIHexToBinary(buf, argv[1], 96);
		
	printf("TRCDW = %d\n", Timings->SEQ_RAS_TIMING.TRCDW);
	printf("TRCDWA = %d\n", Timings->SEQ_RAS_TIMING.TRCDWA);
	printf("TRCDR = %d\n", Timings->SEQ_RAS_TIMING.TRCDR);
	printf("TRCDRA = %d\n", Timings->SEQ_RAS_TIMING.TRCDRA);
	printf("TRRD = %d\n", Timings->SEQ_RAS_TIMING.TRRD);
	printf("TRC = %d\n", Timings->SEQ_RAS_TIMING.TRC);
	printf("Pad0 = %d\n\n", Timings->SEQ_RAS_TIMING.Pad0);
	
	printf("TRP_WRA = %d\n", Timings->SEQ_MISC_TIMING.TRP_WRA);
	printf("Pad0 = %d\n", Timings->SEQ_MISC_TIMING.Pad0);
	printf("TRP_RDA = %d\n", Timings->SEQ_MISC_TIMING.TRP_RDA);
	printf("TRP = %d\n", Timings->SEQ_MISC_TIMING.TRP);
	printf("TRFC = %d\n\n", Timings->SEQ_MISC_TIMING.TRFC);
	
	printf("PA2RDATA = %d\n", Timings->SEQ_MISC_TIMING2.PA2RDATA);
	printf("Pad0 = %d\n", Timings->SEQ_MISC_TIMING2.Pad0);
	printf("PA2WDATA = %d\n", Timings->SEQ_MISC_TIMING2.PA2WDATA);
	printf("Pad1 = %d\n", Timings->SEQ_MISC_TIMING2.Pad1);
	printf("TFAW = %d\n", Timings->SEQ_MISC_TIMING2.TFAW);
	printf("TCRCRL = %d\n", Timings->SEQ_MISC_TIMING2.TCRCRL);
	printf("TCRCWL = %d\n", Timings->SEQ_MISC_TIMING2.TCRCWL);
	printf("TFAW32 = %d\n\n", Timings->SEQ_MISC_TIMING2.TFAW32);
	
	printf("MC_SEQ_MISC1: 0x%08X\n\n", Timings->SEQ_MISC1);
	printf("MC_SEQ_MISC3: 0x%08X\n\n", Timings->SEQ_MISC3);
	printf("MC_SEQ_MISC8: 0x%08X\n\n", Timings->SEQ_MISC8);
	
	printf("ACTRD = %d\n", Timings->ARB_DRAM_TIMING.ACTRD);
	printf("ACTWR = %d\n", Timings->ARB_DRAM_TIMING.ACTWR);
	printf("RASMACTRD = %d\n", Timings->ARB_DRAM_TIMING.RASMACTRD);
	printf("RASMACTWR = %d\n\n", Timings->ARB_DRAM_TIMING.RASMACTWR);
	
	printf("RAS2RAS = %d\n", Timings->ARB_DRAM_TIMING2.RAS2RAS);
	printf("RP = %d\n", Timings->ARB_DRAM_TIMING2.RP);
	printf("WRPLUSRP = %d\n", Timings->ARB_DRAM_TIMING2.WRPLUSRP);
	printf("BUS_TURN = %d\n\n", Timings->ARB_DRAM_TIMING2.BUS_TURN);
	
	return(0);
}
