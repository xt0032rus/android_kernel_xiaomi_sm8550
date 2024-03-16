/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2022, Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef UFS_QCOM_PHY_QMP_V4_H_
#define UFS_QCOM_PHY_QMP_V4_H_

#include "phy-qcom-ufs-i.h"

/* QCOM UFS PHY control registers */
#define COM_BASE	0x000
#define COM_SIZE	0x200
#define PHY_BASE	0x400
#define PHY_SIZE	0x258
#define PCS2_BASE	0x800
#define PCS2_SIZE	0x64
#define TX_BASE(n)	(0x1000 + (0x800 * n))
#define TX_SIZE		0x134
#define RX_BASE(n)	(0x1200 + (0x800 * n))
#define RX_SIZE		0x3D8
#define COM_OFF(x)	(COM_BASE + x)
#define PHY_OFF(x)	(PHY_BASE + x)
#define TX_OFF(n, x)	(TX_BASE(n) + x)
#define RX_OFF(n, x)	(RX_BASE(n) + x)

#define UFS_PHY_SW_RESET			PHY_OFF(0x8)
#define UFS_PHY_POWER_DOWN_CONTROL		PHY_OFF(0x4)
#define UFS_PHY_TX_LARGE_AMP_DRV_LVL		PHY_OFF(0x30)
#define UFS_PHY_RX_SIGDET_CTRL2			PHY_OFF(0x18C)
#define UFS_PHY_RX_HS_G5_SYNC_LENGTH_CAPABILITY	PHY_OFF(0x12C)

#define QSERDES_COM_SYSCLK_EN_SEL		COM_OFF(0x110)
#define QSERDES_COM_CMN_CONFIG_1		COM_OFF(0x174)
#define QSERDES_COM_HSCLK_SEL_1			COM_OFF(0x3C)
#define QSERDES_COM_HSCLK_HS_SWITCH_SEL_1	COM_OFF(0x9C)
#define QSERDES_COM_LOCK_CMP_EN			COM_OFF(0x120)
#define QSERDES_COM_PLL_IVCO			COM_OFF(0xF4)
#define QSERDES_COM_CMN_IETRIM			COM_OFF(0xFC)
#define QSERDES_COM_CMN_IPTRIM			COM_OFF(0x100)
#define QSERDES_COM_VCO_TUNE_INITVAL2		COM_OFF(0x148)
#define QSERDES_COM_DEC_START_MODE0		COM_OFF(0x88)
#define QSERDES_COM_CP_CTRL_MODE0		COM_OFF(0x70)
#define QSERDES_COM_PLL_RCTRL_MODE0		COM_OFF(0x74)
#define QSERDES_COM_PLL_CCTRL_MODE0		COM_OFF(0x78)
#define QSERDES_COM_LOCK_CMP1_MODE0		COM_OFF(0x80)
#define QSERDES_COM_LOCK_CMP2_MODE0		COM_OFF(0x84)

#define QSERDES_COM_DEC_START_MODE1		COM_OFF(0x28)
#define QSERDES_COM_CP_CTRL_MODE1		COM_OFF(0x10)
#define QSERDES_COM_PLL_RCTRL_MODE1		COM_OFF(0x14)
#define QSERDES_COM_PLL_CCTRL_MODE1		COM_OFF(0x18)
#define QSERDES_COM_LOCK_CMP1_MODE1		COM_OFF(0x20)
#define QSERDES_COM_LOCK_CMP2_MODE1		COM_OFF(0x24)

#define QSERDES_COM_VCO_TUNE_MAP		COM_OFF(0x140)

#define QSERDES_TX0_TX_FR_DCC_CTRL		TX_OFF(0, 0x108)
#define QSERDES_TX0_LANE_MODE_1			TX_OFF(0, 0x7C)
#define QSERDES_TX0_RES_CODE_LANE_OFFSET_TX	TX_OFF(0, 0x30)

#define QSERDES_RX0_RX_MODE_RATE_0_1_B0		RX_OFF(0, 0x208)
#define QSERDES_RX0_RX_MODE_RATE_0_1_B1		RX_OFF(0, 0x20C)
#define QSERDES_RX0_RX_MODE_RATE_0_1_B3		RX_OFF(0, 0x214)
#define QSERDES_RX0_RX_MODE_RATE_0_1_B6		RX_OFF(0, 0x220)
#define QSERDES_RX0_RX_MODE_RATE2_B3		RX_OFF(0, 0x238)
#define QSERDES_RX0_RX_MODE_RATE2_B6		RX_OFF(0, 0x244)
#define QSERDES_RX0_RX_MODE_RATE3_B3		RX_OFF(0, 0x25C)
#define QSERDES_RX0_RX_MODE_RATE3_B4		RX_OFF(0, 0x260)
#define QSERDES_RX0_RX_MODE_RATE3_B5		RX_OFF(0, 0x264)
#define QSERDES_RX0_RX_MODE_RATE3_B8		RX_OFF(0, 0x270)
#define QSERDES_RX0_RX_MODE_RATE4_B3		RX_OFF(0, 0x280)
#define QSERDES_RX0_RX_MODE_RATE4_B4		RX_OFF(0, 0x284)
#define QSERDES_RX0_RX_MODE_RATE4_B6		RX_OFF(0, 0x28C)
#define QSERDES_RX0_RX_INTERFACE_MODE		RX_OFF(0, 0x1E0)
#define QSERDES_RX0_UCDR_FO_GAIN_RATE2		RX_OFF(0, 0xD4)
#define QSERDES_RX0_UCDR_FO_GAIN_RATE4		RX_OFF(0, 0xDC)
#define QSERDES_RX0_UCDR_SO_GAIN_RATE4		RX_OFF(0, 0xF0)
#define QSERDES_RX0_UCDR_PI_CONTROLS		RX_OFF(0, 0xF4)
#define QSERDES_RX0_VGA_CAL_MAN_VAL		RX_OFF(0, 0x178)
#define QSERDES_RX0_DLL0_FTUNE_CTRL		RX_OFF(0, 0x2F8)
#define QSERDES_RX0_RX_EQ_OFFSET_ADAPTOR_CNTRL1	RX_OFF(0, 0x1BC)
#define QSERDES_RX0_RX_OFFSET_ADAPTOR_CNTRL3	RX_OFF(0, 0x1C4)
#define QSERDES_RX0_UCDR_FASTLOCK_COUNT_HIGH_RATE4	RX_OFF(0, 0x54)
#define QSERDES_RX0_UCDR_FASTLOCK_FO_GAIN_RATE4	RX_OFF(0, 0x10)
#define QSERDES_RX0_UCDR_FASTLOCK_SO_GAIN_RATE4	RX_OFF(0, 0x24)

#define QSERDES_RX1_RX_MODE_RATE_0_1_B0		RX_OFF(1, 0x208)
#define QSERDES_RX1_RX_MODE_RATE_0_1_B1		RX_OFF(1, 0x20C)
#define QSERDES_RX1_RX_MODE_RATE_0_1_B3		RX_OFF(1, 0x214)
#define QSERDES_RX1_RX_MODE_RATE_0_1_B6		RX_OFF(1, 0x220)
#define QSERDES_RX1_RX_MODE_RATE2_B3		RX_OFF(1, 0x238)
#define QSERDES_RX1_RX_MODE_RATE2_B6		RX_OFF(1, 0x244)
#define QSERDES_RX1_RX_MODE_RATE3_B3		RX_OFF(1, 0x25C)
#define QSERDES_RX1_RX_MODE_RATE3_B4		RX_OFF(1, 0x260)
#define QSERDES_RX1_RX_MODE_RATE3_B5		RX_OFF(1, 0x264)
#define QSERDES_RX1_RX_MODE_RATE3_B8		RX_OFF(1, 0x270)
#define QSERDES_RX1_RX_MODE_RATE4_B3		RX_OFF(1, 0x280)
#define QSERDES_RX1_RX_MODE_RATE4_B4		RX_OFF(1, 0x284)
#define QSERDES_RX1_RX_MODE_RATE4_B6		RX_OFF(1, 0x28C)
#define QSERDES_RX1_RX_INTERFACE_MODE		RX_OFF(1, 0x1E0)
#define QSERDES_RX1_UCDR_FO_GAIN_RATE2		RX_OFF(1, 0xD4)
#define QSERDES_RX1_UCDR_FO_GAIN_RATE4		RX_OFF(1, 0xDC)
#define QSERDES_RX1_UCDR_SO_GAIN_RATE4          RX_OFF(1, 0xF0)
#define QSERDES_RX1_UCDR_PI_CONTROLS            RX_OFF(1, 0xF4)
#define QSERDES_RX1_VGA_CAL_MAN_VAL		RX_OFF(1, 0x178)
#define QSERDES_RX1_DLL0_FTUNE_CTRL		RX_OFF(1, 0x2F8)
#define QSERDES_RX1_RX_EQ_OFFSET_ADAPTOR_CNTRL1	RX_OFF(1, 0x1BC)
#define QSERDES_RX1_RX_OFFSET_ADAPTOR_CNTRL3    RX_OFF(1, 0x1C4)
#define QSERDES_RX1_UCDR_FASTLOCK_COUNT_HIGH_RATE4      RX_OFF(1, 0x54)
#define QSERDES_RX1_UCDR_FASTLOCK_FO_GAIN_RATE4 RX_OFF(1, 0x10)
#define QSERDES_RX1_UCDR_FASTLOCK_SO_GAIN_RATE4 RX_OFF(1, 0x24)


#define QSERDES_TX1_LANE_MODE_1			TX_OFF(1, 0x7C)
#define QSERDES_TX1_TX_FR_DCC_CTRL		TX_OFF(1, 0x108)
#define QSERDES_TX1_RES_CODE_LANE_OFFSET_TX     TX_OFF(1, 0x30)

#define UFS_PHY_MULTI_LANE_CTRL1		PHY_OFF(0x1FC)
#define UFS_PHY_TX_MID_TERM_CTRL1		PHY_OFF(0x1F4)
#define UFS_PHY_PLL_CNTL			PHY_OFF(0x2C)

#define UFS_PHY_TX_HSGEAR_CAPABILITY		PHY_OFF(0x74)
#define UFS_PHY_RX_HSGEAR_CAPABILITY		PHY_OFF(0xBC)
#define UFS_PHY_RX_HSG5_SYNC_WAIT_TIME		PHY_OFF(0x220)

#define UFS_PHY_PHY_START			PHY_OFF(0x0)
#define UFS_PHY_PCS_READY_STATUS                PHY_OFF(0x1A8)
#define UFS_PHY_LINECFG_DISABLE			PHY_OFF(0x17C)

#define UFS_PHY_RX_LINECFG_DISABLE_BIT		BIT(1)
#define QSERDES_RX_INTERFACE_MODE_CLOCK_EDGE_BIT	BIT(6)

/*
 * This structure represents the v4 specific phy.
 * common_cfg MUST remain the first field in this structure
 * in case extra fields are added. This way, when calling
 * get_ufs_qcom_phy() of generic phy, we can extract the
 * common phy structure (struct ufs_qcom_phy) out of it
 * regardless of the relevant specific phy.
 */
struct ufs_qcom_phy_qmp_v4 {
	struct ufs_qcom_phy common_cfg;
};

static struct ufs_qcom_phy_calibration phy_cal_table_rate_A_g5[] = {
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_POWER_DOWN_CONTROL, 0x1),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_SYSCLK_EN_SEL, 0xD9),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_CMN_CONFIG_1, 0x16),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_HSCLK_SEL_1, 0x11),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_HSCLK_HS_SWITCH_SEL_1, 0x00),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_LOCK_CMP_EN, 0x01),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_PLL_IVCO, 0x1F),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_VCO_TUNE_INITVAL2, 0x00),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_DEC_START_MODE0, 0x41),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_CMN_IETRIM, 0x1B),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_CMN_IPTRIM, 0x1C),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_CP_CTRL_MODE0, 0x06),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_PLL_RCTRL_MODE0, 0x18),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_PLL_CCTRL_MODE0, 0x14),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_LOCK_CMP1_MODE0, 0x7F),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_LOCK_CMP2_MODE0, 0x06),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_TX0_LANE_MODE_1, 0x05),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_TX0_RES_CODE_LANE_OFFSET_TX, 0x07),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_UCDR_FO_GAIN_RATE2, 0x0C),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_UCDR_FO_GAIN_RATE4, 0x0C),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_UCDR_SO_GAIN_RATE4, 0x04),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_EQ_OFFSET_ADAPTOR_CNTRL1, 0x14),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_UCDR_PI_CONTROLS, 0x07),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_OFFSET_ADAPTOR_CNTRL3, 0x0E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_UCDR_FASTLOCK_COUNT_HIGH_RATE4, 0x02),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_UCDR_FASTLOCK_FO_GAIN_RATE4, 0x1C),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_UCDR_FASTLOCK_SO_GAIN_RATE4, 0x06),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_VGA_CAL_MAN_VAL, 0x08),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE_0_1_B0, 0xC2),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE_0_1_B1, 0xC2),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE_0_1_B3, 0x1A),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE_0_1_B6, 0x60),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE2_B3, 0x9E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE2_B6, 0x60),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE3_B3, 0x9E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE3_B4, 0x0E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE3_B5, 0x36),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE3_B8, 0x02),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE4_B3, 0xB9),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE4_B4, 0x4F),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE4_B6, 0xFF),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_DLL0_FTUNE_CTRL, 0x30),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_TX1_LANE_MODE_1, 0x05),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_TX1_RES_CODE_LANE_OFFSET_TX, 0x07),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_UCDR_FO_GAIN_RATE2, 0x0C),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_UCDR_FO_GAIN_RATE4, 0x0C),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_UCDR_SO_GAIN_RATE4, 0x04),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_EQ_OFFSET_ADAPTOR_CNTRL1, 0x14),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_UCDR_PI_CONTROLS, 0x07),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_OFFSET_ADAPTOR_CNTRL3, 0x0E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_UCDR_FASTLOCK_COUNT_HIGH_RATE4, 0x02),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_UCDR_FASTLOCK_FO_GAIN_RATE4, 0x1C),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_UCDR_FASTLOCK_SO_GAIN_RATE4, 0x06),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_VGA_CAL_MAN_VAL, 0x08),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE_0_1_B0, 0xC2),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE_0_1_B1, 0xC2),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE_0_1_B3, 0x1A),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE_0_1_B6, 0x60),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE2_B3, 0x9E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE2_B6, 0x60),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE3_B3, 0x9E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE3_B4, 0x0E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE3_B5, 0x36),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE3_B8, 0x02),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE4_B3, 0xB9),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE4_B4, 0x4F),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE4_B6, 0xFF),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_DLL0_FTUNE_CTRL, 0x30),

	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_MULTI_LANE_CTRL1, 0x00),
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_TX_MID_TERM_CTRL1, 0x43),
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_PLL_CNTL, 0x33),
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_TX_LARGE_AMP_DRV_LVL, 0x0F),
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_RX_SIGDET_CTRL2, 0x69),
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_RX_HS_G5_SYNC_LENGTH_CAPABILITY, 0x4F),
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_RX_HSG5_SYNC_WAIT_TIME, 0x9E),
};

static struct ufs_qcom_phy_calibration phy_cal_table_rate_A_g4[] = {
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_POWER_DOWN_CONTROL, 0x1),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_SYSCLK_EN_SEL, 0xD9),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_CMN_CONFIG_1, 0x16),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_HSCLK_SEL_1, 0x11),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_HSCLK_HS_SWITCH_SEL_1, 0x00),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_LOCK_CMP_EN, 0x01),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_VCO_TUNE_MAP, 0x04),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_PLL_IVCO, 0x0F),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_VCO_TUNE_INITVAL2, 0x00),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_DEC_START_MODE0, 0x41),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_CP_CTRL_MODE0, 0x0A),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_PLL_RCTRL_MODE0, 0x18),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_PLL_CCTRL_MODE0, 0x14),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_LOCK_CMP1_MODE0, 0x7F),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_LOCK_CMP2_MODE0, 0x06),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_DEC_START_MODE1, 0x4C),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_CP_CTRL_MODE1, 0x0A),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_PLL_RCTRL_MODE1, 0x18),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_PLL_CCTRL_MODE1, 0x14),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_LOCK_CMP1_MODE1, 0x99),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_LOCK_CMP2_MODE1, 0x07),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_TX0_LANE_MODE_1, 0x05),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_TX0_TX_FR_DCC_CTRL, 0x4C),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_TX0_RES_CODE_LANE_OFFSET_TX, 0x07),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_UCDR_FO_GAIN_RATE2, 0x0C),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_VGA_CAL_MAN_VAL, 0x0E),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE_0_1_B0, 0xC2),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE_0_1_B1, 0xC2),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE_0_1_B3, 0x1A),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE_0_1_B6, 0x60),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE2_B3, 0x9E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE2_B6, 0x60),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE3_B3, 0x9E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE3_B4, 0x0E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE3_B5, 0x36),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX0_RX_MODE_RATE3_B8, 0x02),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_TX1_LANE_MODE_1, 0x05),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_TX1_TX_FR_DCC_CTRL, 0x4C),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_TX1_RES_CODE_LANE_OFFSET_TX, 0x07),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_UCDR_FO_GAIN_RATE2, 0x0C),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_VGA_CAL_MAN_VAL, 0x0E),

	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE_0_1_B0, 0xC2),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE_0_1_B1, 0xC2),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE_0_1_B3, 0x1A),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE_0_1_B6, 0x60),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE2_B3, 0x9E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE2_B6, 0x60),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE3_B3, 0x9E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE3_B4, 0x0E),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE3_B5, 0x36),
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_RX1_RX_MODE_RATE3_B8, 0x02),

	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_MULTI_LANE_CTRL1, 0x00),

	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_TX_MID_TERM_CTRL1, 0x43),
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_PLL_CNTL, 0x2B),
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_TX_LARGE_AMP_DRV_LVL, 0x0F),
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_RX_SIGDET_CTRL2, 0x69),
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_TX_HSGEAR_CAPABILITY, 0x04),
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_RX_HSGEAR_CAPABILITY, 0x04),
};

static struct ufs_qcom_phy_calibration phy_cal_table_2nd_lane[] = {
	UFS_QCOM_PHY_CAL_ENTRY(UFS_PHY_MULTI_LANE_CTRL1, 0x02),
};

static struct ufs_qcom_phy_calibration phy_cal_table_rate_B[] = {
	UFS_QCOM_PHY_CAL_ENTRY(QSERDES_COM_VCO_TUNE_MAP, 0x44),
};

#endif
