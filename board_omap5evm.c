
#include <aboot/io.h>

/* Use CH (configuration header) to do the settings */

void board_mux_init(void) {}
void board_ddr_init(void) {}
void prcm_init(void) {}
void gpmc_init(void) {}
void scale_vcores(void) {}
void board_late_init(void)
{
	/* enable uart3 console */
	writel(2, 0x4A009550);
}
