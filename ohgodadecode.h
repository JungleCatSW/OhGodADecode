// Copyright (c) 2017 OhGodACompany - OhGodAGirl & OhGodAPet

#ifndef __OHGODADECODE_H
#define __OHGODADECODE_H
#define u32 uint32_t
#pragma pack(push, 1)

typedef struct _SEQ_WR_CTL_D1_FORMAT {
  uint32_t DAT_DLY : 4;
  uint32_t DQS_DLY : 4;
  uint32_t DQS_XTR : 1;
  uint32_t DAT_2Y_DLY : 1;
  uint32_t ADR_2Y_DLY : 1;
  uint32_t CMD_2Y_DLY : 1;
  uint32_t OEN_DLY : 4;
  uint32_t OEN_EXT : 4;
  uint32_t OEN_SEL : 2;
  uint32_t Pad0 : 2;
  uint32_t ODT_DLY : 4;
  uint32_t ODT_EXT : 1;
  uint32_t ADR_DLY : 1;
  uint32_t CMD_DLY : 1;
  uint32_t Pad1 : 1;
} SEQ_WR_CTL_D1_FORMAT;

typedef struct _SEQ_WR_CTL_2_FORMAT {
  uint32_t DAT_DLY_H_D0 : 1;
  uint32_t DQS_DLY_H_D0 : 1;
  uint32_t OEN_DLY_H_D0 : 1;
  uint32_t DAT_DLY_H_D1 : 1;
  uint32_t DQS_DLY_H_D1 : 1;
  uint32_t OEN_DLY_H_D1 : 1;
  uint32_t WCDR_EN : 1;
  uint32_t Pad0 : 25;
} SEQ_WR_CTL_2_FORMAT;

typedef struct _SEQ_PMG_TIMING {
  u32 CKSRE : 4;
  u32 CKSRX : 4;
  u32 CKE_PULSE : 4;
  u32 CKE : 6;
  u32 SEQ_IDLE : 3;
  u32 : 11;
} SEQ_PMG_TIMING_FORMAT;

typedef struct _SEQ_RAS_TIMING {
  u32 RCDW : 5;    // # of cycles from active to write
  u32 RCDWA : 5;    // # of cycles from active to write with auto-precharge
  u32 RCDR : 5;    // # of cycles from active to read
  u32 RCDRA : 5;    // # of cycles from active to read with auto-precharge
  u32 RRD : 4;    // # of cycles from active bank a to active bank b
  u32 RC : 7;    // # of cycles from active to active/auto refresh
  u32 : 1;
} SEQ_RAS_TIMING_FORMAT;

typedef struct _SEQ_CAS_TIMING {
  u32 NOPW : 2;    // Extra cycle(s) between successive write bursts
  u32 NOPR : 2;    // Extra cycle(s) between successive read bursts
  u32 R2W : 5;    // Read to write turn
  u32 CCLD : 3;    // Cycles between r/w from bank A to r/w bank B
  u32 R2R : 4;    // Read to read time
  u32 W2R : 5;    // Write to read turn
  u32 : 3;
  u32 CL : 5;    // CAS to data return latency
  u32 : 3;
} SEQ_CAS_TIMING_FORMAT;

typedef struct _SEQ_MISC_TIMING {
  u32 RP_WRA : 7;    // From write with auto-precharge to active
  u32 RP_RDA : 7;    // From read with auto-precharge to active
  u32 TRP : 6;    // Precharge command period
  u32 RFC : 9;    // Auto-refresh command period
  u32 : 3;
} SEQ_MISC_TIMING_FORMAT;

typedef struct _SEQ_MISC_TIMING2 {
  u32 PA2RDATA : 3;
  u32 : 1;
  u32 PA2WDATA : 3;
  u32 : 1;
  u32 FAW : 5;        // The time window in wich four activates are allowed in the same rank
  u32 CRCRL : 3;
  u32 CRCWL : 5;
  u32 T32AW : 4;
  u32 : 3;
  u32 WDATATR : 4;
} SEQ_MISC_TIMING2_FORMAT;

typedef struct _SEQ_MISC3 {
  u32 : 22;
  u32 RAS : 6;
  u32 : 4;
} SEQ_MISC3_FORMAT;

typedef struct _ARB_DRAM_TIMING {
  u32 ACTRD : 8;
  u32 ACTWR : 8;
  u32 RASMACTRD : 8;
  u32 RASMACTWR : 8;
} ARB_DRAM_TIMING_FORMAT;

typedef struct _ARB_DRAM_TIMING2 {
  u32 RAS2RAS : 8;
  u32 RP : 8;
  u32 WRPLUSRP : 8;
  u32 BUS_TURN : 8;
} ARB_DRAM_TIMING2_FORMAT;

typedef struct _VBIOS_TIMING_FORMAT {
  SEQ_WR_CTL_D1_FORMAT SEQ_WR_CTL_D1;
  SEQ_WR_CTL_2_FORMAT SEQ_WR_CTL_2;
  SEQ_PMG_TIMING_FORMAT SEQ_PMG_TIMING;
  SEQ_RAS_TIMING_FORMAT SEQ_RAS_TIMING;
  SEQ_CAS_TIMING_FORMAT SEQ_CAS_TIMING;
  SEQ_MISC_TIMING_FORMAT SEQ_MISC_TIMING;
  SEQ_MISC_TIMING2_FORMAT SEQ_MISC_TIMING2;
  uint32_t SEQ_MISC1;
  SEQ_MISC3_FORMAT SEQ_MISC3;
  uint32_t SEQ_MISC8;
  ARB_DRAM_TIMING_FORMAT ARB_DRAM_TIMING;
  ARB_DRAM_TIMING2_FORMAT ARB_DRAM_TIMING2;
} VBIOS_TIMING_FORMAT;

#pragma pack(pop)

#endif
